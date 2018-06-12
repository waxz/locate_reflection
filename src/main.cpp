#include <iostream>
#include <chrono>
#include <boost/bind.hpp>
// node msg and srv
#include <catkin_startup/mytopic.h>
#include <catkin_startup/myservice.h>
#include <cpp_utils/container.h>
#include <cpp_utils/listener.h>

#include <ros/ros.h>
#include <ros/callback_queue.h> //  ros::CallbackQueue queue
#include "tf/message_filter.h"  // filter message with tf
#include <message_filters/subscriber.h>


//sensor data
#include <sensor_msgs/LaserScan.h>
#include <sensor_msgs/Image.h>

//geometry transformation
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Point.h>
#include <tf/tf.h>

#include <XmlRpc.h>

#include <vector>
#include <string>
#include <map>
#include <tuple>
#include <thread>
using std::vector;
using std::string;
using std::map;
using std::tuple;
namespace node=catkin_startup;

class Threading {
public:
    template<class T>
    void createThread(T task) {
        boost::thread thread(task);
    }

};

template<class T>
struct Task {
    std::shared_ptr<T> data_;

    Task(std::shared_ptr<T> data) {
        data_ = data;
    }

    void operator()() {
        while (1) {
            std::cout << "=====================" << data_.get()->cmd.data << std::endl;

            ros::Rate(5).sleep();
        }
    };

};

void f(int a, int b) {
    std::cout << 6666 << a << b;
}
int main(int argc, char **argv) {




//    return 0;

    std::cout << "Hello, World!" << std::endl;
    //init a node
    ros::init(argc, argv, "start_up");
    ros::NodeHandle nh;
    ros::NodeHandle nh_private("~");

    //**** topic
    // publish on o topic
    ros::Publisher chat_pub = nh.advertise<node::mytopic>("chat",1);

    util::Listener l(nh, nh_private);
    std::shared_ptr<node::mytopic> p1 = l.getChat<node::mytopic>("chat");
    if (p1)
        ROS_INFO("%s",p1.get()->cmd.data.c_str());
    node::mytopic msg;
    msg.header.frame_id = "node";

//    boost::shared_ptr<node::mytopic> data = boost::shared_ptr<node::mytopic>(new node::mytopic());
//    data->cmd.data = "sd";
    ros::spinOnce();
    ros::Rate(1).sleep();

#if 1
    auto res = l.createSubcriber<node::mytopic>("chat", 2);
    std::shared_ptr<node::mytopic> data = std::get<0>(res);
#endif
    //filter
    auto res2 = l.createSubcriberFilteredTf<node::mytopic>("chat",2,"map");
    std::shared_ptr<node::mytopic> data2 = std::get<0>(res2);

    tf::Transform transform;
    l.getTransform("map", "node", transform);

    Threading t;
    Task<node::mytopic> task(data);
    t.createThread<Task<node::mytopic>>(task);


    ros::Rate rate(10);
//    return 0;
    int i=0;
    while (ros::ok()){
        i++;
        chat_pub.publish(msg);


        char tmp[200];
        sprintf(tmp,"start %d",i);
        msg.cmd.data =string(tmp) ;
        ros::spinOnce();

//        l.getOneMessage("chat",0.1);
//        if(data){
//            ROS_INFO("local receive %s",data.get()->cmd.data.c_str());
//        }
#if 1
        l.getOneMessage("chat",0.1);
        if(data){
            ROS_INFO("local receive %s",data.get()->cmd.data.c_str());
        }
#endif



        rate.sleep();
        ros::spinOnce();

    }

    // test code



    return 0;
}