/*
 * mocap_node.cpp
 *
 *  Created on: 02/02/2015
 *      Author:
 */

#include "socket.h"
#include <ros/ros.h>
#include <mavros/OverrideRCIn.h>
#include <geometry_msgs/TwistStamped.h>
#include <sensor_msgs/NavSatFix.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <mavros/RCIn.h>
#include <mavros_extras/LocalInt.h>
#include <mavros/Attitude.h>
#include <string>
#include <unistd.h>

const int LOCAL_PORT = 54321;

mavros::OverrideRCIn velocity_;
int flag2 = 0;
bool packetread = false;
int numBytes = 0;
int pos,i;
char ch_1[10], ch_2[10], ch_3[10], ch_4[10], ch_5[10], ch_6[10], ch_7[10], ch_8[10];
int lun, t;   
UdpSocket clientSocket(LOCAL_PORT);
std::string manual_mode="CMODE(0)";
std::string auto_mode="CMODE(2)";
geometry_msgs::TwistStamped gps_vel;
geometry_msgs::PoseWithCovarianceStamped global_position_local;
sensor_msgs::NavSatFix gps_fix;
mavros_extras::LocalInt global_position_int;
mavros::Attitude attitude;
char buff[200];


void stateCallback(const mavros::RCInConstPtr& state)
  {
	if (state->channels[4] <= 1326) flag2=0;
	if (state->channels[4] > 1326) flag2=1;
	//ROS_INFO("FLAG = %d",flag2);
  }

void globalPositionIntCallback(const mavros_extras::LocalInt::ConstPtr& msg){
	//ROS_INFO("gpsCallback");
	//gps_vel=msg;
	global_position_int.vx = msg->vx;
	global_position_int.vy = msg->vy;
	global_position_int.vz = msg->vz;
	//sprintf(buff,"S %f %f %f E",msg->twist.linear.x, msg->twist.linear.y, msg->twist.linear.z);
	//if (flag2 == 1)	clientSocket.send(buff);
	//sendto(udp_socket, buff, (int)sizeof(buff), 0, (sockaddr *)&remote_addr, (socklen_t*)&addr_len);
}

void attitudeCallback(const mavros::Attitude::ConstPtr& msg){
	attitude.header.frame_id = msg->header.frame_id;
	attitude.header.stamp = ros::Time::now();
	attitude.roll = msg->roll;
	attitude.pitch = msg->pitch;
	attitude.yaw = msg->yaw;
	attitude.rollspeed = msg->rollspeed;
	attitude.pitchspeed = msg->pitchspeed;
	attitude.yawspeed = msg->yawspeed;
}

void gpsVelCallback(const geometry_msgs::TwistStamped::ConstPtr& msg){
	//ROS_INFO("gpsCallback");
	//gps_vel=msg;
	gps_vel.twist.linear.x = msg->twist.linear.x;
	gps_vel.twist.linear.y = msg->twist.linear.y;
	gps_vel.twist.linear.z = msg->twist.linear.z;
	//sprintf(buff,"S %f %f %f E",msg->twist.linear.x, msg->twist.linear.y, msg->twist.linear.z);
	//if (flag2 == 1)	clientSocket.send(buff);
	//sendto(udp_socket, buff, (int)sizeof(buff), 0, (sockaddr *)&remote_addr, (socklen_t*)&addr_len);
}

void globalPositionCallback(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg){
	//ROS_INFO("gpsCallback");
	//global_position_local = msg;
	global_position_local.pose.pose.orientation.w = msg->pose.pose.orientation.w;
	global_position_local.pose.pose.orientation.x = msg->pose.pose.orientation.x;
	global_position_local.pose.pose.orientation.y = msg->pose.pose.orientation.y;
	global_position_local.pose.pose.orientation.z = msg->pose.pose.orientation.z;
	global_position_local.pose.pose.position.x = msg->pose.pose.position.x;
	global_position_local.pose.pose.position.y = msg->pose.pose.position.y;
	global_position_local.pose.pose.position.y = msg->pose.pose.position.y;
	//sendto(udp_socket, buff, (int)sizeof(buff), 0, (sockaddr *)&remote_addr, (socklen_t*)&addr_len);
}

void gpsFixCallback(const sensor_msgs::NavSatFix::ConstPtr& msg){
	//ROS_INFO("gpsCallback");
	gps_fix.latitude = msg->latitude;
	gps_fix.longitude = msg->longitude;
	//sendto(udp_socket, buff, (int)sizeof(buff), 0, (sockaddr *)&remote_addr, (socklen_t*)&addr_len);
}

int main( int argc, char* argv[] ){  
	ros::init(argc, argv, "mocap_node_gps");
	ros::NodeHandle n;
	ros::Subscriber state_subscriber_;
	ros::Subscriber attitude_subscriber_;
	ros::Subscriber gps_vel_subscriber_;
	ros::Subscriber global_position_local_subscriber_;
	ros::Subscriber gps_fix_subscriber_;
	ros::Subscriber global_position_int_subscriber_;
	ros::Publisher velocity_publisher_;
	ros::Rate r(50);
	velocity_publisher_ = n.advertise<mavros::OverrideRCIn>("mavros/rc/override", 10);	
	while (ros::ok()){
		state_subscriber_ = n.subscribe("mavros/rc/in", 5, stateCallback );
		gps_vel_subscriber_ = n.subscribe("mavros/gps_vel", 2, gpsVelCallback );
		global_position_local_subscriber_ = n.subscribe("mavros/global_position/local", 2, globalPositionCallback );
		gps_fix_subscriber_ = n.subscribe("mavros/fix", 100, gpsFixCallback );
		 global_position_int_subscriber_ = n.subscribe("mavros/global_local_int", 10, globalPositionIntCallback );
		attitude_subscriber_ = n.subscribe("mavros/attitude", 10, attitudeCallback );
		sprintf(buff,"S %f %f %f %f %f %f %f %f %f %f %f %f %d %d %d %f %f %f %f %f %f E", global_position_local.pose.pose.orientation.w,  global_position_local.pose.pose.orientation.x, global_position_local.pose.pose.orientation.y, global_position_local.pose.pose.orientation.z, global_position_local.pose.pose.position.x,  global_position_local.pose.pose.position.y, global_position_local.pose.pose.position.z, gps_vel.twist.linear.x, gps_vel.twist.linear.y, gps_vel.twist.linear.z, gps_fix.latitude, gps_fix.longitude, global_position_int.vx, global_position_int.vy, global_position_int.vz, attitude.roll, attitude.pitch, attitude.yaw, attitude.rollspeed, attitude.pitchspeed, attitude.yawspeed);
		//ROS_INFO("ROS OK");
	   	if (flag2 == 0){
			//ROS_INFO("MANUALE");
			velocity_.channels[0] = 0;
			velocity_.channels[1] = 0;
			velocity_.channels[2] = 0;
			velocity_.channels[3] = 0;
			velocity_.channels[4] = 0;
			velocity_.channels[5] = 0;
			velocity_.channels[6] = 0;
			velocity_.channels[7] = 0;
			velocity_publisher_.publish(velocity_);					
		}
		if (flag2 == 1){
			
			
			clientSocket.send(buff);
			//ROS_INFO("Learning");
			do{
				numBytes = clientSocket.recv();
				//Parse mocap dat
				if( numBytes > 0 ){
					const char* buffer = clientSocket.getBuffer();
					unsigned short lenghtPack = *((unsigned short*)(&buffer[0]));
					//printf("packet length:%d\n",lenghtPack);
					// Look for the beginning of a NatNet package
					// printf("%c\n",buffer[0]);
					pos=0;
					if (buffer[0]=='S'){
											//elaborazione pacchetto udp
											pos=2;
											//lettura lenght
											i=0;
											while(buffer[pos]!=' '){
												ch_1[i]=buffer[pos];
												i++;
												pos++;
											}
											ch_1[i]='\0';
											velocity_.channels[0]=flag2*atoi(ch_1);
											//salto lo spazio
											pos++;
											//lettura type
											i=0;
											while(buffer[pos]!=' '){
												ch_2[i]=buffer[pos];
												i++;
												pos++;
											}
											ch_2[i]='\0';
											velocity_.channels[1]=flag2*atoi(ch_2);
											//salto lo spazio
											pos++;
											//lettura x
											i=0;
											while(buffer[pos]!=' '){
												ch_3[i]=buffer[pos];
												i++;
												pos++;
											}
											ch_3[i]='\0';
											velocity_.channels[2]=flag2*atoi(ch_3);
											//salto lo spazio
											pos++;
											//lettura y
											i=0;
											while(buffer[pos]!=' '){
												ch_4[i]=buffer[pos];
												i++;
												pos++;
											}
											ch_4[i]='\0';
											velocity_.channels[3]=flag2*atoi(ch_4);
											//salto lo spazio
											pos++;
											//lettura z
											i=0;
											while(buffer[pos]!=' '){
												ch_5[i]=buffer[pos];
												i++;
												pos++;
											}
											ch_5[i]='\0';
											velocity_.channels[4]=atoi(ch_5);
											//salto lo spazio
											pos++;
											//lettura q1
											i=0;
											while(buffer[pos]!=' '){
												ch_6[i]=buffer[pos];
												i++;
												pos++;
											}
											ch_6[i]='\0';
											velocity_.channels[5]=flag2*atoi(ch_6);
											//salto lo spazio
											pos++;
											//lettura q2
											i=0;
											while(buffer[pos]!=' '){	
												ch_7[i]=buffer[pos];
												i++;
												pos++;
											}
											ch_7[i]='\0';
											velocity_.channels[6]=flag2*atoi(ch_7);
											//salto lo spazio
											pos++;
											//lettura q3
											i=0;
											while(buffer[pos]!=' '){
												ch_8[i]=buffer[pos];
												i++;
												pos++;
											}
											ch_8[i]='\0';
											velocity_.channels[7]=flag2*atoi(ch_8);
											//salto lo spazio
											pos++;	
											//if(buffer[pos]=='E') printf("End of the message\n");
											//printf("info pacchetto: ch_1:%d ch_2:%d ch_3:%d ch_4:%d ch_5:%d ch_6:%d ch_7:%d ch_8:%d \n",velocity_.channels[0], velocity_.channels[1], velocity_.channels[2], velocity_.channels[3], velocity_.channels[4], velocity_.channels[5], velocity_.channels[6], velocity_.channels[7]);
											//invio messaggi sul topic
											//velocity_publisher_.publish(velocity_);
											//loop_rate.sleep();
										}
									
										}
									}while( numBytes > 0 );
								// Don't try again immediately
								//if( !packetread ){
								//	usleep( 10 );
								velocity_publisher_.publish(velocity_);
		}//flag2=1
		
		r.sleep();
		ros::spinOnce();
	}//while ros::ok
	// Process mocap data until SIGINT
	return 0;
}//main
