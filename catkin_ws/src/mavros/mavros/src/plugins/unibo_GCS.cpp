#include <mavros/mavros_plugin.h>
#include <pluginlib/class_list_macros.h>


#include <mms/Cmd.h>
#include <mms/Ack_cmd.h>
#include <mms/Sys_status.h>
#include <guidance_node_amsl/Position.h>
#include <camera_handler_SHERPA/Camera.h>


namespace mavplugin {
/**
 * @brief Mavros plugin
 */
class UniboGCSPlugin : public MavRosPlugin {
public:
	UniboGCSPlugin() :
		nodeHandle(),
		uas(nullptr)
	{};

	void initialize(UAS &uas_)
	{
		uas = &uas_;
		
		
		ack_sub = nodeHandle.subscribe("/ack_cmd", 10, &UniboGCSPlugin::ack_callback, this);
		command_pub = nodeHandle.advertise<mms::Cmd>("/command", 10);
		camera_pub = nodeHandle.advertise<camera_handler_SHERPA::Camera>("/camera_trigger", 10);
		position_sub= nodeHandle.subscribe("/position", 10, &UniboGCSPlugin::position_callback, this);
		status_sub = nodeHandle.subscribe("/system_status", 10, &UniboGCSPlugin::status_callback, this);

		/*nodeHandle.param("guidance_node_amsl/param/sat_xy", v_xy_max, 3.0);
		nodeHandle.param("guidance_node_amsl/param/sat_z", v_z_max, 1.5);
		nodeHandle.param("guidance_node_amsl/param/sat_yaw", v_psi_max, 3.14);*/
	}

	//should be logic mapping between id number and message type
	const message_map get_rx_handlers() {
		return {
			MESSAGE_HANDLER(MAVLINK_MSG_ID_MISSION_ITEM, &UniboGCSPlugin::handle_mission_item),
			MESSAGE_HANDLER(MAVLINK_MSG_ID_POSITION_TARGET_GLOBAL_INT, &UniboGCSPlugin::handle_pos_target_global_int)			
		};
	}

private:
	ros::NodeHandle nodeHandle;
	UAS *uas;

	ros::Subscriber ack_sub;
	ros::Publisher command_pub;
	ros::Publisher	camera_pub;
	ros::Subscriber	position_sub;
	ros::Subscriber	status_sub;

	void handle_mission_item(const mavlink_message_t *msg, uint8_t sysid, uint8_t compid) {
		ROS_INFO("Inside Mission Item");
		mavlink_mission_item_t mission_item;
		mavlink_msg_mission_item_decode(msg, &mission_item);
		auto mission_item_msg = boost::make_shared<mms::Cmd>();
		auto camera_msg = boost::make_shared<camera_handler_SHERPA::Camera>();

		switch (mission_item.command){
			case MAV_CMD_IMAGE_START_CAPTURE:   //MAV_CMD_IMAGE_START_CAPTURE:
			camera_msg->take_pic = true;
			camera_msg->take_vid = false;
			camera_pub.publish(camera_msg);
			break;

			//case MAV_CMD_IMAGE_STOP_CAPTURE:           NOT SURE TO USE THIS
			//break;

			case MAV_CMD_VIDEO_START_CAPTURE:                  //MAV_CMD_VIDEO_START_CAPTURE:
			camera_msg->take_pic = false;
			camera_msg->take_vid = true;
			camera_pub.publish(camera_msg);
			break;

			case MAV_CMD_VIDEO_STOP_CAPTURE:                 //MAV_CMD_VIDEO_STOP_CAPTURE:
			camera_msg->take_pic = false;
			camera_msg->take_vid = false;
			camera_pub.publish(camera_msg);
			break;

		}
		mission_item_msg->command = mission_item.command;
		mission_item_msg->param1 = mission_item.param1;
		mission_item_msg->param2 = mission_item.param2;
		mission_item_msg->param3 = mission_item.param3;
		mission_item_msg->param4 = mission_item.param4;
		mission_item_msg->param5 = mission_item.x;
		mission_item_msg->param6 = mission_item.y;	
		mission_item_msg->param7 = mission_item.z;		
		//publish topic Command
		ROS_INFO("Command: %d",mission_item.command);
		command_pub.publish(mission_item_msg);
	}

	void handle_pos_target_global_int(const mavlink_message_t *msg_in, uint8_t sysid, uint8_t compid) {
		ROS_INFO("Inside Position Target");
		/*mavlink_message_t msg;
		enum MAV_MISSION_RESULT type = MAV_MISSION_ACCEPTED;
		mavlink_msg_mission_ack_pack_chan(UAS_PACK_CHAN(uas),&msg,UAS_PACK_TGT(uas),type);
		UAS_FCU(uas)->send_message(&msg);		*/
		//mavlink_position_target_global_int_t pos_target;
		//mavlink_msg_position_target_global_int_decode(msg, &pos_target);
		//auto pos_target_msg = boost::make_shared<mms::Cmd>();     //TODO put the topic created in MMS for the commands the name can be different
	}

	void ack_callback(const mms::Ack_cmd::ConstPtr msg_ack){
		mavlink_message_t msg;		
		if (msg_ack->mission_item_reached){           //TODO maybe separate topics....bad implementation
			mavlink_msg_mission_item_reached_pack_chan(UAS_PACK_CHAN(uas),&msg,msg_ack->mav_cmd_id);      //1 is the sequence that we are not considering right now
			UAS_FCU(uas)->send_message(&msg);
			ROS_INFO("Sent message ITEM_REACHED");
		} else {
			if (msg_ack->mav_mission_accepted){
				enum MAV_MISSION_RESULT type = MAV_MISSION_ACCEPTED;
				mavlink_msg_mission_ack_pack_chan(UAS_PACK_CHAN(uas),&msg,UAS_PACK_TGT(uas),type);
				UAS_FCU(uas)->send_message(&msg);
				ROS_INFO("Sent message MISSION_ACCEPTED");
			} else {
				enum MAV_MISSION_RESULT type = MAV_MISSION_ERROR;
				mavlink_msg_mission_ack_pack_chan(UAS_PACK_CHAN(uas),&msg,UAS_PACK_TGT(uas),type);
				UAS_FCU(uas)->send_message(&msg);
				ROS_INFO("Sent message MISSION_ERROR");
			}
		}	
	}

	void position_callback(const guidance_node_amsl::Position::ConstPtr& msg){
		mavlink_message_t msg_mav;
		int16_t yaw_int;
		yaw_int = (int16_t)(msg->Yawangle * 180.0f / 3.14f * 100);       // rad --> degrees * 100
		if (yaw_int<0){
			yaw_int += 36000;    //if negative adding 360 degree because heading is uint16_t from 0 o 359.99
		}
		//ROS_INFO("Yaw: %d",yaw_int);
		mavlink_msg_global_position_int_pack_chan(UAS_PACK_CHAN(uas),&msg_mav,msg->Timestamp,msg->Latitude,msg->Longitude,msg->AltitudeAMSL,msg->AltitudeRelative, 0, 0, 0, yaw_int);
		UAS_FCU(uas)->send_message(&msg_mav);	
	}
	
	void status_callback(const mms::Sys_status::ConstPtr& msg){
		mavlink_message_t msg_mav;
		//ROS_INFO("Battery: %d",msg->voltage_battery);
		mavlink_msg_sys_status_pack_chan(UAS_PACK_CHAN(uas), &msg_mav, 1, 1, 1, 500, msg->voltage_battery, 0, 50, 0, 0, 0, 0, 0, 0);           //only voltage battery is sent
		UAS_FCU(uas)->send_message(&msg_mav);	
	}
};
};	// namespace mavplugin

PLUGINLIB_EXPORT_CLASS(mavplugin::UniboGCSPlugin, mavplugin::MavRosPlugin)
