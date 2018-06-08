// Generated by gencpp from file catkin_startup/myserviceResponse.msg
// DO NOT EDIT!


#ifndef CATKIN_STARTUP_MESSAGE_MYSERVICERESPONSE_H
#define CATKIN_STARTUP_MESSAGE_MYSERVICERESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace catkin_startup
{
template <class ContainerAllocator>
struct myserviceResponse_
{
  typedef myserviceResponse_<ContainerAllocator> Type;

  myserviceResponse_()
    : success(false)  {
    }
  myserviceResponse_(const ContainerAllocator& _alloc)
    : success(false)  {
  (void)_alloc;
    }



   typedef uint8_t _success_type;
  _success_type success;




  typedef boost::shared_ptr< ::catkin_startup::myserviceResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::catkin_startup::myserviceResponse_<ContainerAllocator> const> ConstPtr;

}; // struct myserviceResponse_

typedef ::catkin_startup::myserviceResponse_<std::allocator<void> > myserviceResponse;

typedef boost::shared_ptr< ::catkin_startup::myserviceResponse > myserviceResponsePtr;
typedef boost::shared_ptr< ::catkin_startup::myserviceResponse const> myserviceResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::catkin_startup::myserviceResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::catkin_startup::myserviceResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace catkin_startup

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'catkin_startup': ['/home/waxz/refloc_ws/src/catkin_startup/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::catkin_startup::myserviceResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::catkin_startup::myserviceResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::catkin_startup::myserviceResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::catkin_startup::myserviceResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::catkin_startup::myserviceResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::catkin_startup::myserviceResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::catkin_startup::myserviceResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "358e233cde0c8a8bcfea4ce193f8fc15";
  }

  static const char* value(const ::catkin_startup::myserviceResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x358e233cde0c8a8bULL;
  static const uint64_t static_value2 = 0xcfea4ce193f8fc15ULL;
};

template<class ContainerAllocator>
struct DataType< ::catkin_startup::myserviceResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "catkin_startup/myserviceResponse";
  }

  static const char* value(const ::catkin_startup::myserviceResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::catkin_startup::myserviceResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool success\n\
";
  }

  static const char* value(const ::catkin_startup::myserviceResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::catkin_startup::myserviceResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.success);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct myserviceResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::catkin_startup::myserviceResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::catkin_startup::myserviceResponse_<ContainerAllocator>& v)
  {
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CATKIN_STARTUP_MESSAGE_MYSERVICERESPONSE_H
