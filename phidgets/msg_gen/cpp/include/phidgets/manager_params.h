/* Auto-generated by genmsg_cpp for file /home/floribot/ros_workspace/phidgets/msg/manager_params.msg */
#ifndef PHIDGETS_MESSAGE_MANAGER_PARAMS_H
#define PHIDGETS_MESSAGE_MANAGER_PARAMS_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"

#include "std_msgs/Header.h"
#include "std_msgs/String.h"

namespace phidgets
{
template <class ContainerAllocator>
struct manager_params_ {
  typedef manager_params_<ContainerAllocator> Type;

  manager_params_()
  : header()
  , attached(false)
  , name()
  , serial(0)
  , device_class(0)
  , device_id(0)
  , version(0)
  {
  }

  manager_params_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , attached(false)
  , name(_alloc)
  , serial(0)
  , device_class(0)
  , device_id(0)
  , version(0)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef uint8_t _attached_type;
  uint8_t attached;

  typedef  ::std_msgs::String_<ContainerAllocator>  _name_type;
   ::std_msgs::String_<ContainerAllocator>  name;

  typedef int32_t _serial_type;
  int32_t serial;

  typedef int32_t _device_class_type;
  int32_t device_class;

  typedef int32_t _device_id_type;
  int32_t device_id;

  typedef int32_t _version_type;
  int32_t version;


  typedef boost::shared_ptr< ::phidgets::manager_params_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::phidgets::manager_params_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct manager_params
typedef  ::phidgets::manager_params_<std::allocator<void> > manager_params;

typedef boost::shared_ptr< ::phidgets::manager_params> manager_paramsPtr;
typedef boost::shared_ptr< ::phidgets::manager_params const> manager_paramsConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::phidgets::manager_params_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::phidgets::manager_params_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace phidgets

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::phidgets::manager_params_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::phidgets::manager_params_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::phidgets::manager_params_<ContainerAllocator> > {
  static const char* value() 
  {
    return "5af5478c0ef338e575359b515492c3c1";
  }

  static const char* value(const  ::phidgets::manager_params_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x5af5478c0ef338e5ULL;
  static const uint64_t static_value2 = 0x75359b515492c3c1ULL;
};

template<class ContainerAllocator>
struct DataType< ::phidgets::manager_params_<ContainerAllocator> > {
  static const char* value() 
  {
    return "phidgets/manager_params";
  }

  static const char* value(const  ::phidgets::manager_params_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::phidgets::manager_params_<ContainerAllocator> > {
  static const char* value() 
  {
    return "Header header\n\
bool attached\n\
std_msgs/String name\n\
int32 serial\n\
int32 device_class\n\
int32 device_id\n\
int32 version\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.secs: seconds (stamp_secs) since epoch\n\
# * stamp.nsecs: nanoseconds since stamp_secs\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: std_msgs/String\n\
string data\n\
\n\
";
  }

  static const char* value(const  ::phidgets::manager_params_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::phidgets::manager_params_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::phidgets::manager_params_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::phidgets::manager_params_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.attached);
    stream.next(m.name);
    stream.next(m.serial);
    stream.next(m.device_class);
    stream.next(m.device_id);
    stream.next(m.version);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct manager_params_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::phidgets::manager_params_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::phidgets::manager_params_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "attached: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.attached);
    s << indent << "name: ";
s << std::endl;
    Printer< ::std_msgs::String_<ContainerAllocator> >::stream(s, indent + "  ", v.name);
    s << indent << "serial: ";
    Printer<int32_t>::stream(s, indent + "  ", v.serial);
    s << indent << "device_class: ";
    Printer<int32_t>::stream(s, indent + "  ", v.device_class);
    s << indent << "device_id: ";
    Printer<int32_t>::stream(s, indent + "  ", v.device_id);
    s << indent << "version: ";
    Printer<int32_t>::stream(s, indent + "  ", v.version);
  }
};


} // namespace message_operations
} // namespace ros

#endif // PHIDGETS_MESSAGE_MANAGER_PARAMS_H

