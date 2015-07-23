#include <ros/ros.h>

#include <mms/Cmd.h>
#include <mms/Sys_status.h>
//#include <mms/Ack_cmd.h>
#include <mavros/Global_position_int.h>
#include <mavros/Sonar.h>
//#include "Posmixer/Mission.h"

// STATES DEFINITION
/*#define NO_MISSION_LOADED 10
#define LOADING_MISSION 20
#define MISSION_LOADED 30
#define SENDING_MISSION_ITEM 40
#define WAITING_FOR_MISSION_ACCEPTED 50
#define WAITING_FOR_MISSION_ITEM_REACHED 60*/

class PosmixerNodeClass
{

public:
	PosmixerNodeClass(ros::NodeHandle& node)
        {

		n_=node;

		//subscribers
                subFromSonar_ = n_.subscribe("/sonar", 10, &MavRosNodeClass::readSonarMessage,this);
		subFromCmd_ = n_.subscribe("/sys_status", 10, &MmsNodeClass::readCmdMessage,this);

		// publishers
		pubToPos_ = n_.advertise<mavros::Global_position_int>("/Position_nav", 10);

		//Initializing outputPos_
		outputPos_.time_boot_ms = 0;
		outputPos_.lat = 0;
		outputPos_.lon = 0;
		outputPos_.alt = 0;
		outputPos_.relative_alt = 0;
		outputPos_.vx = 0;
		outputPos_.vy = 0;
		outputPos_.vz = 0;
                outputPos_.hdg = 0;

	}

	void readSonarMessage(const mavros::Sonar::ConstPtr& msg)
	{
		ROS_INFO("POSMIXER: SONAR_MSG_RECEIVED");
		inputSonar_.distance = msg -> distance;
	}

	void readCmdMessage(const mms::Cmd::ConstPtr& msg)
	{
		ROS_INFO("POSMIXER: CMD_RECEIVED");
		inputCmd_.command = msg -> command;
		inputCmd_.param1  = msg -> param1;
		inputCmd_.param2  = msg -> param2;
		inputCmd_.param3  = msg -> param3;
		inputCmd_.param4  = msg -> param4;
		inputCmd_.param5  = msg -> param5;
		inputCmd_.param6  = msg -> param6;
		inputCmd_.param7  = msg -> param7;
                inputCmd_.frame  = msg -> frame;

		/*Target_Position_.Latitude = inputCmd_.param5;
		Target_Position_.Longitude = inputCmd_.param6;
		Target_Position_.AltitudeRelative = inputCmd_.param7;
		Target_Position_.Yawangle = inputCmd_.param4;*/
		

		switch(inputCmd_.command)
		{
		case 16:  // MAV_CMD_NAV_WAYPOINT
			{
				ROS_INFO("MAV_CMD_DO_NAV_WAYPOINT. Params: %f - %f - %f - %f",inputCmd_.param5,inputCmd_.param6,inputCmd_.param7,inputCmd_.param4);
				target_.Latitude = (int)(inputCmd_.param5*10000000.0f);
				target_.Longitude = (int)(inputCmd_.param6*10000000.0f);
				target_.AltitudeRelative = (int)(inputCmd_.param7*1000.0f);
				target_.Yawangle = inputCmd_.param4;
				target_.Mode = 0;

		    		if (inputCmd_.frame == MAV_FRAME_GLOBAL_TERRAIN_ALT_INT)
				{
					if (sonar_ok)
	 				{
						WAYPOINT = true;
					}
					else
					{
						outputAckCmd_.mission_item_reached = false;
						outputAckCmd_.mav_mission_accepted = false;
						outputAckCmd_.mav_cmd_id = inputCmd_.command;
						pubToAckCmd_.publish(outputAckCmd_);
						ROS_INFO("MMS->GCS: MISSION_NOT_ACCEPTED");
		                                WAYPOINT = false;
					}
				} 
		                else // any of the remaining frames
				{				
					WAYPOINT = true;
				}			
				//MMS_Handle();
			} break;
		}

 ----------------------------------- FIN QUI -----------------------------------------------

	void set_events_false()
	{
		// INPUTS GCS -> Posmixer
		// MISSION_COUNT = false;
		// MISSION_CLEAR_ALL = false;
		// MISSION_START = false;
		// INPUTS MMS -> Posmixer
		MISSION_ACCEPTED = false;
		MISSION_ITEM_REACHED = false;
	}

	void Posmixer_Handle()
	{
		switch(currentState)

		{

		case NO_MISSION_LOADED:
			set_events_false();

			if (inputMission_.mission_item_number >= 1)
			{
				currentState = SENDING_MISSION_ITEM;
				ROS_INFO("Posmixer_CURRENT_STATE: SENDING_MISSION_ITEM");
				current_mission_item  = 1;
			}
			break;

			//		case LOADING_MISSION:
			//set_events_false();
			//break;

		    //case MISSION_LOADED:
			//set_events_false();
			//break;

		case SENDING_MISSION_ITEM:
			set_events_false();
			if (current_mission_item <= inputMission_.mission_item_number)
			{
				ROS_INFO("Posmixer - CURRENT MISSION ITEM: %d", current_mission_item);

				// SENDING THE i-th MISSION ITEM

				outputPos_.command = inputMission_.command[current_mission_item]; // 95 = MAV_CMD_NAV_LAST = NOT OPERATIVE
				outputPos_.param1 = inputMission_.param1[current_mission_item];
				outputPos_.param2 = inputMission_.param2[current_mission_item];
				outputPos_.param3 = inputMission_.param3[current_mission_item];
				outputPos_.param4 = inputMission_.param4[current_mission_item];
				outputPos_.param5 = inputMission_.param5[current_mission_item];
				outputPos_.param6 = inputMission_.param6[current_mission_item];
				outputPos_.param7 = inputMission_.param7[current_mission_item];
				pubToCmd_.publish(outputPos_);
				ROS_INFO("Posmixer->MMS: MISSION_ITEM_ID = %d", outputPos_.command);

				currentState = WAITING_FOR_MISSION_ACCEPTED;
				ROS_INFO("Posmixer_CURRENT_STATE: WAITING_FOR_MISSION_ACCEPTED");

				current_mission_item  = current_mission_item+1;
			}
			else
			{
				currentState = NO_MISSION_LOADED;
				ROS_INFO("Posmixer_CURRENT_STATE: NO_MISSION_LOADED");
			}

			break;

		case WAITING_FOR_MISSION_ACCEPTED:
			set_events_false();
			if (MISSION_ACCEPTED)
			{
				outputPos_.command = 300; // MAV_CMD_MISSION_START
				outputPos_.param1 = 0;
				outputPos_.param2 = 0;
				outputPos_.param3 = 0;
				outputPos_.param4 = 0;
				outputPos_.param5 = 0;
				outputPos_.param6 = 0;
				outputPos_.param7 = 0;
				pubToCmd_.publish(outputPos_);
				ROS_INFO("Posmixer->MMS: MAV_CMD_MISSION_START");

				currentState = WAITING_FOR_MISSION_ITEM_REACHED;
				ROS_INFO("Posmixer_CURRENT_STATE: WAITING_FOR_MISSION_ITEM_REACHED");
			}
			break;

		case WAITING_FOR_MISSION_ITEM_REACHED:
			set_events_false();
			if (MISSION_ITEM_REACHED)
			{
				currentState = SENDING_MISSION_ITEM;
				ROS_INFO("Posmixer_CURRENT_STATE: SENDING_MISSION_ITEM");
			}
			break;
		}

	}

	void run()
        {
		ros::Rate loop_rate(rate);

		while (ros::ok())
		{
			// ROS_INFO("MMS running");

			//Posmixer_Handle();
			ros::spinOnce();

			loop_rate.sleep();
		}
	}

protected:
	/*state here*/
	ros::NodeHandle n_;

	ros::Subscriber subFromAckCmd_;
	ros::Subscriber subFromMission_;
	mms::Ack_cmd inputAckCmd_;
	Posmixer::Mission inputMission_;

	ros::Publisher pubToCmd_;
	mms::Cmd outputPos_;

	
	// INPUTS GCS -> Posmixer
	// bool MISSION_COUNT = false;
	// bool MISSION_CLEAR_ALL = false;
	// bool MISSION_START = false;
	
	
	//ROS_INFO("Posmixer_CURRENT_STATE: NO_MISSION_LOADED");

	
	// int N=1; // number of mission items

	//int mission_item_number = 0; // set 0 as default      LASCIARE COMMENTATO
	int current_mission_item = 1; // set 1 as default
	int rate = 10;
	// INPUTS MMS -> Posmixer
	bool MISSION_ACCEPTED = false;
	bool MISSION_ITEM_REACHED = false;

	// STATE INITIALIZATION
	int currentState = NO_MISSION_LOADED;

// private:
};

int main(int argc, char **argv)
{
	ros::init(argc, argv, "Posmixer");
	ros::NodeHandle node;

	PosmixerNodeClass PosmixerNode(node);

	PosmixerNode.run();
	return 0;
}