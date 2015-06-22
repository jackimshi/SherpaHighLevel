/* Software License Agreement (BSD License)
 *
 * Copyright (c) 2011, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *  * Neither the name of Willow Garage, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Auto-generated by genmsg_cpp from file /home/odroid/catkin_ws/src/mms/msg/Ack_arm.msg
 *
 */


#ifndef MMS_MESSAGE_ACK_ARM_H
#define MMS_MESSAGE_ACK_ARM_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace mms
{
template <class ContainerAllocator>
struct Ack_arm_
{
  typedef Ack_arm_<ContainerAllocator> Type;

  Ack_arm_()
    : mav_result(false)  {
    }
  Ack_arm_(const ContainerAllocator& _alloc)
    : mav_result(false)  {
    }



   typedef uint8_t _mav_result_type;
  _mav_result_type mav_result;




  typedef boost::shared_ptr< ::mms::Ack_arm_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mms::Ack_arm_<ContainerAllocator> const> ConstPtr;

}; // struct Ack_arm_

typedef ::mms::Ack_arm_<std::allocator<void> > Ack_arm;

typedef boost::shared_ptr< ::mms::Ack_arm > Ack_armPtr;
typedef boost::shared_ptr< ::mms::Ack_arm const> Ack_armConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mms::Ack_arm_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mms::Ack_arm_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace mms

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'mms': ['/home/odroid/catkin_ws/src/mms/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::mms::Ack_arm_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mms::Ack_arm_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mms::Ack_arm_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mms::Ack_arm_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mms::Ack_arm_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mms::Ack_arm_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mms::Ack_arm_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3e2f901d362039bf545384d626e33dae";
  }

  static const char* value(const ::mms::Ack_arm_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3e2f901d362039bfULL;
  static const uint64_t static_value2 = 0x545384d626e33daeULL;
};

template<class ContainerAllocator>
struct DataType< ::mms::Ack_arm_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mms/Ack_arm";
  }

  static const char* value(const ::mms::Ack_arm_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mms::Ack_arm_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# false = cmd not executed, true = cmd accepted and executed\n\
bool mav_result\n\
";
  }

  static const char* value(const ::mms::Ack_arm_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mms::Ack_arm_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.mav_result);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct Ack_arm_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mms::Ack_arm_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mms::Ack_arm_<ContainerAllocator>& v)
  {
    s << indent << "mav_result: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.mav_result);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MMS_MESSAGE_ACK_ARM_H
