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
 * Auto-generated by genmsg_cpp from file /home/odroid/catkin_ws/src/vision_opencv-indigo/opencv_apps/msg/Moment.msg
 *
 */


#ifndef OPENCV_APPS_MESSAGE_MOMENT_H
#define OPENCV_APPS_MESSAGE_MOMENT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <opencv_apps/Point2D.h>

namespace opencv_apps
{
template <class ContainerAllocator>
struct Moment_
{
  typedef Moment_<ContainerAllocator> Type;

  Moment_()
    : m00(0.0)
    , m10(0.0)
    , m01(0.0)
    , m20(0.0)
    , m11(0.0)
    , m02(0.0)
    , m30(0.0)
    , m21(0.0)
    , m12(0.0)
    , m03(0.0)
    , mu20(0.0)
    , mu11(0.0)
    , mu02(0.0)
    , mu30(0.0)
    , mu21(0.0)
    , mu12(0.0)
    , mu03(0.0)
    , nu20(0.0)
    , nu11(0.0)
    , nu02(0.0)
    , nu30(0.0)
    , nu21(0.0)
    , nu12(0.0)
    , nu03(0.0)
    , center()
    , length(0.0)
    , area(0.0)  {
    }
  Moment_(const ContainerAllocator& _alloc)
    : m00(0.0)
    , m10(0.0)
    , m01(0.0)
    , m20(0.0)
    , m11(0.0)
    , m02(0.0)
    , m30(0.0)
    , m21(0.0)
    , m12(0.0)
    , m03(0.0)
    , mu20(0.0)
    , mu11(0.0)
    , mu02(0.0)
    , mu30(0.0)
    , mu21(0.0)
    , mu12(0.0)
    , mu03(0.0)
    , nu20(0.0)
    , nu11(0.0)
    , nu02(0.0)
    , nu30(0.0)
    , nu21(0.0)
    , nu12(0.0)
    , nu03(0.0)
    , center(_alloc)
    , length(0.0)
    , area(0.0)  {
    }



   typedef double _m00_type;
  _m00_type m00;

   typedef double _m10_type;
  _m10_type m10;

   typedef double _m01_type;
  _m01_type m01;

   typedef double _m20_type;
  _m20_type m20;

   typedef double _m11_type;
  _m11_type m11;

   typedef double _m02_type;
  _m02_type m02;

   typedef double _m30_type;
  _m30_type m30;

   typedef double _m21_type;
  _m21_type m21;

   typedef double _m12_type;
  _m12_type m12;

   typedef double _m03_type;
  _m03_type m03;

   typedef double _mu20_type;
  _mu20_type mu20;

   typedef double _mu11_type;
  _mu11_type mu11;

   typedef double _mu02_type;
  _mu02_type mu02;

   typedef double _mu30_type;
  _mu30_type mu30;

   typedef double _mu21_type;
  _mu21_type mu21;

   typedef double _mu12_type;
  _mu12_type mu12;

   typedef double _mu03_type;
  _mu03_type mu03;

   typedef double _nu20_type;
  _nu20_type nu20;

   typedef double _nu11_type;
  _nu11_type nu11;

   typedef double _nu02_type;
  _nu02_type nu02;

   typedef double _nu30_type;
  _nu30_type nu30;

   typedef double _nu21_type;
  _nu21_type nu21;

   typedef double _nu12_type;
  _nu12_type nu12;

   typedef double _nu03_type;
  _nu03_type nu03;

   typedef  ::opencv_apps::Point2D_<ContainerAllocator>  _center_type;
  _center_type center;

   typedef double _length_type;
  _length_type length;

   typedef double _area_type;
  _area_type area;




  typedef boost::shared_ptr< ::opencv_apps::Moment_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::opencv_apps::Moment_<ContainerAllocator> const> ConstPtr;

}; // struct Moment_

typedef ::opencv_apps::Moment_<std::allocator<void> > Moment;

typedef boost::shared_ptr< ::opencv_apps::Moment > MomentPtr;
typedef boost::shared_ptr< ::opencv_apps::Moment const> MomentConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::opencv_apps::Moment_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::opencv_apps::Moment_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace opencv_apps

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'opencv_apps': ['/home/odroid/catkin_ws/src/vision_opencv-indigo/opencv_apps/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::opencv_apps::Moment_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::opencv_apps::Moment_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::opencv_apps::Moment_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::opencv_apps::Moment_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::opencv_apps::Moment_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::opencv_apps::Moment_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::opencv_apps::Moment_<ContainerAllocator> >
{
  static const char* value()
  {
    return "560ee3fabfffb4ed4155742d6db8a03c";
  }

  static const char* value(const ::opencv_apps::Moment_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x560ee3fabfffb4edULL;
  static const uint64_t static_value2 = 0x4155742d6db8a03cULL;
};

template<class ContainerAllocator>
struct DataType< ::opencv_apps::Moment_<ContainerAllocator> >
{
  static const char* value()
  {
    return "opencv_apps/Moment";
  }

  static const char* value(const ::opencv_apps::Moment_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::opencv_apps::Moment_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# spatial moments\n\
float64 m00\n\
float64 m10\n\
float64 m01\n\
float64 m20\n\
float64 m11\n\
float64 m02\n\
float64 m30\n\
float64 m21\n\
float64 m12\n\
float64 m03\n\
\n\
# central moments\n\
float64 mu20\n\
float64 mu11\n\
float64 mu02\n\
float64 mu30\n\
float64 mu21\n\
float64 mu12\n\
float64 mu03\n\
\n\
# central normalized moments\n\
float64 nu20\n\
float64 nu11\n\
float64 nu02\n\
float64 nu30\n\
float64 nu21\n\
float64 nu12\n\
float64 nu03\n\
\n\
# center of mass m10/m00, m01/m00\n\
Point2D center\n\
float64 length\n\
float64 area\n\
\n\
================================================================================\n\
MSG: opencv_apps/Point2D\n\
float64 x\n\
float64 y\n\
\n\
";
  }

  static const char* value(const ::opencv_apps::Moment_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::opencv_apps::Moment_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.m00);
      stream.next(m.m10);
      stream.next(m.m01);
      stream.next(m.m20);
      stream.next(m.m11);
      stream.next(m.m02);
      stream.next(m.m30);
      stream.next(m.m21);
      stream.next(m.m12);
      stream.next(m.m03);
      stream.next(m.mu20);
      stream.next(m.mu11);
      stream.next(m.mu02);
      stream.next(m.mu30);
      stream.next(m.mu21);
      stream.next(m.mu12);
      stream.next(m.mu03);
      stream.next(m.nu20);
      stream.next(m.nu11);
      stream.next(m.nu02);
      stream.next(m.nu30);
      stream.next(m.nu21);
      stream.next(m.nu12);
      stream.next(m.nu03);
      stream.next(m.center);
      stream.next(m.length);
      stream.next(m.area);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct Moment_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::opencv_apps::Moment_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::opencv_apps::Moment_<ContainerAllocator>& v)
  {
    s << indent << "m00: ";
    Printer<double>::stream(s, indent + "  ", v.m00);
    s << indent << "m10: ";
    Printer<double>::stream(s, indent + "  ", v.m10);
    s << indent << "m01: ";
    Printer<double>::stream(s, indent + "  ", v.m01);
    s << indent << "m20: ";
    Printer<double>::stream(s, indent + "  ", v.m20);
    s << indent << "m11: ";
    Printer<double>::stream(s, indent + "  ", v.m11);
    s << indent << "m02: ";
    Printer<double>::stream(s, indent + "  ", v.m02);
    s << indent << "m30: ";
    Printer<double>::stream(s, indent + "  ", v.m30);
    s << indent << "m21: ";
    Printer<double>::stream(s, indent + "  ", v.m21);
    s << indent << "m12: ";
    Printer<double>::stream(s, indent + "  ", v.m12);
    s << indent << "m03: ";
    Printer<double>::stream(s, indent + "  ", v.m03);
    s << indent << "mu20: ";
    Printer<double>::stream(s, indent + "  ", v.mu20);
    s << indent << "mu11: ";
    Printer<double>::stream(s, indent + "  ", v.mu11);
    s << indent << "mu02: ";
    Printer<double>::stream(s, indent + "  ", v.mu02);
    s << indent << "mu30: ";
    Printer<double>::stream(s, indent + "  ", v.mu30);
    s << indent << "mu21: ";
    Printer<double>::stream(s, indent + "  ", v.mu21);
    s << indent << "mu12: ";
    Printer<double>::stream(s, indent + "  ", v.mu12);
    s << indent << "mu03: ";
    Printer<double>::stream(s, indent + "  ", v.mu03);
    s << indent << "nu20: ";
    Printer<double>::stream(s, indent + "  ", v.nu20);
    s << indent << "nu11: ";
    Printer<double>::stream(s, indent + "  ", v.nu11);
    s << indent << "nu02: ";
    Printer<double>::stream(s, indent + "  ", v.nu02);
    s << indent << "nu30: ";
    Printer<double>::stream(s, indent + "  ", v.nu30);
    s << indent << "nu21: ";
    Printer<double>::stream(s, indent + "  ", v.nu21);
    s << indent << "nu12: ";
    Printer<double>::stream(s, indent + "  ", v.nu12);
    s << indent << "nu03: ";
    Printer<double>::stream(s, indent + "  ", v.nu03);
    s << indent << "center: ";
    s << std::endl;
    Printer< ::opencv_apps::Point2D_<ContainerAllocator> >::stream(s, indent + "  ", v.center);
    s << indent << "length: ";
    Printer<double>::stream(s, indent + "  ", v.length);
    s << indent << "area: ";
    Printer<double>::stream(s, indent + "  ", v.area);
  }
};

} // namespace message_operations
} // namespace ros

#endif // OPENCV_APPS_MESSAGE_MOMENT_H
