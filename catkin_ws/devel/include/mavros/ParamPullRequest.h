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
 * Auto-generated by genmsg_cpp from file /home/odroid/catkin_ws/src/mavros/mavros/srv/ParamPull.srv
 *
 */


#ifndef MAVROS_MESSAGE_PARAMPULLREQUEST_H
#define MAVROS_MESSAGE_PARAMPULLREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace mavros
{
template <class ContainerAllocator>
struct ParamPullRequest_
{
  typedef ParamPullRequest_<ContainerAllocator> Type;

  ParamPullRequest_()
    : force_pull(false)  {
    }
  ParamPullRequest_(const ContainerAllocator& _alloc)
    : force_pull(false)  {
    }



   typedef uint8_t _force_pull_type;
  _force_pull_type force_pull;




  typedef boost::shared_ptr< ::mavros::ParamPullRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mavros::ParamPullRequest_<ContainerAllocator> const> ConstPtr;

}; // struct ParamPullRequest_

typedef ::mavros::ParamPullRequest_<std::allocator<void> > ParamPullRequest;

typedef boost::shared_ptr< ::mavros::ParamPullRequest > ParamPullRequestPtr;
typedef boost::shared_ptr< ::mavros::ParamPullRequest const> ParamPullRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mavros::ParamPullRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mavros::ParamPullRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace mavros

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'mavros': ['/home/odroid/catkin_ws/src/mavros/mavros/msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'diagnostic_msgs': ['/opt/ros/indigo/share/diagnostic_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::mavros::ParamPullRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mavros::ParamPullRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mavros::ParamPullRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mavros::ParamPullRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros::ParamPullRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros::ParamPullRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mavros::ParamPullRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "16415b4e049d3f92df764eeb461102b7";
  }

  static const char* value(const ::mavros::ParamPullRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x16415b4e049d3f92ULL;
  static const uint64_t static_value2 = 0xdf764eeb461102b7ULL;
};

template<class ContainerAllocator>
struct DataType< ::mavros::ParamPullRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mavros/ParamPullRequest";
  }

  static const char* value(const ::mavros::ParamPullRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mavros::ParamPullRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
\n\
\n\
\n\
bool force_pull\n\
";
  }

  static const char* value(const ::mavros::ParamPullRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mavros::ParamPullRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.force_pull);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct ParamPullRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mavros::ParamPullRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mavros::ParamPullRequest_<ContainerAllocator>& v)
  {
    s << indent << "force_pull: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.force_pull);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MAVROS_MESSAGE_PARAMPULLREQUEST_H
