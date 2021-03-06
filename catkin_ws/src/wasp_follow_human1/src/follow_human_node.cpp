#include "ros/ros.h"
#include "wasp_follow_human1/Operator.h"
#include "guidance_node_amsl/Reference.h"

char const * packName="wasp_follow_human";

class FollowHumanNodeClass{
  public:
    FollowHumanNodeClass(ros::NodeHandle& node){
      ROS_INFO("[%s:] node started!",packName);
      subFromOperator_=node.subscribe("/operator",10,&FollowHumanNodeClass::readOperatorMessage,this);
      pubToReference_=node.advertise<guidance_node_amsl::Reference>("/reference",10);
    }

    void run(){
      ros::Rate loopRate(1);
      while(ros::ok()){
	ros::spinOnce();
	loopRate.sleep();
      }
    }

    void readOperatorMessage(const wasp_follow_human1::Operator::ConstPtr& msg)
    {
      ROS_INFO("[%s:] operator message received!",packName);
      inputOperator_.Latitude=msg->Latitude;	
      inputOperator_.Longitude=msg->Longitude;	
      inputOperator_.AltitudeRelative=msg->AltitudeRelative;
      inputOperator_.Yawangle=msg->Yawangle;
      inputOperator_.Distance=msg->Distance;
      inputOperator_.Direction=msg->Direction;
      meridionalCurvatureRadius=earthEquatorialRadius*(1-earthFlattening*earthFlattening)/pow(1-pow(earthFlattening*sin(inputOperator_.Latitude),2),3/2);
//      ROS_INFO("%f",meridionalCurvatureRadius);
      primeVerticalCurvatureRadius=earthEquatorialRadius/sqrt(1-pow(earthFlattening*sin(inputOperator_.Latitude),2));
//      ROS_INFO("%f",primeVerticalCurvatureRadius);
      outputReference_.Latitude=inputOperator_.Latitude+(int)((float)inputOperator_.Distance*cos(inputOperator_.Direction)/meridionalCurvatureRadius*1E7);
      outputReference_.Longitude=inputOperator_.Longitude+(int)((float)inputOperator_.Distance*sin(inputOperator_.Direction)/primeVerticalCurvatureRadius*cos(inputOperator_.Latitude)*1E7);
      outputReference_.AltitudeRelative=inputOperator_.AltitudeRelative;
      outputReference_.Yawangle=inputOperator_.Yawangle;
      outputReference_.Mode=0;
      pubToReference_.publish(outputReference_);
      ROS_INFO("[%s:] reference message sent! Current Values: LAT %d LON %d",packName,outputReference_.Latitude,outputReference_.Longitude);
    }

  protected:
    ros::Subscriber subFromOperator_;
    wasp_follow_human1::Operator inputOperator_;
    ros::Publisher pubToReference_;
    guidance_node_amsl::Reference outputReference_;
    const static float earthEquatorialRadius=6378137;
    const static float earthFlattening=1/298.257223563;
    float meridionalCurvatureRadius;
    float primeVerticalCurvatureRadius;
};

int main(int argc,char **argv){
	ros::init(argc,argv,"wasp_follow_human");
	ros::NodeHandle node;
	ROS_INFO("[%s:] initialising node ...",packName);

	FollowHumanNodeClass followHumanNode(node);
        followHumanNode.run();
	return 0;
}
