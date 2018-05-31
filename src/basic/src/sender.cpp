#include<ros/ros.h>
#include<std_msgs/String.h>
#include<sstream>
using namespace std;
int main(int argc, char* argv[])
{
    ros::init(argc,argv,"sender");
    //controls for the amount of info displayed


    ros::NodeHandle n;
    ros::Rate loop(1);
    //publishes a topic
    ros::Publisher pub=n.advertise<std_msgs::String>("Output",10);

   int count=0;
    while(ros::ok){
        count++;
        //string stream
        stringstream ss;
        ss<<"HelloWorld "<<count;
        std_msgs::String msg;
        //retrieving character informarmation in strinf=g stream
        msg.data=ss.str();
        pub.publish(msg);
        //ensuring information is sent
        ROS_INFO("Sent Information [%s]",msg.data.c_str());
        ros::spinOnce();
        loop.sleep();
    }
    return 0;
}
