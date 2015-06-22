"""autogenerated by genpy from casy_rover/ControllerOutput.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class ControllerOutput(genpy.Message):
  _md5sum = "14e8f32f6dc13cd7db7fdae805a6677b"
  _type = "casy_rover/ControllerOutput"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """# Based on MAVLink 1.0 Messages: NAV_CONTROLLER_OUTPUT
# See common.xml in MAVLink Messages

# Outputs of the ArduPilot Mega controller.

# Current Desired Roll, Pitch, and Yaw in degrees
float32 nav_roll
float32 nav_pitch
int16 nav_bearing

# Current error in altitude, airspeed, and crosstrack
float32 alt_error
float32 air_spd_error
float32 xtrack_error

"""
  __slots__ = ['nav_roll','nav_pitch','nav_bearing','alt_error','air_spd_error','xtrack_error']
  _slot_types = ['float32','float32','int16','float32','float32','float32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       nav_roll,nav_pitch,nav_bearing,alt_error,air_spd_error,xtrack_error

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(ControllerOutput, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.nav_roll is None:
        self.nav_roll = 0.
      if self.nav_pitch is None:
        self.nav_pitch = 0.
      if self.nav_bearing is None:
        self.nav_bearing = 0
      if self.alt_error is None:
        self.alt_error = 0.
      if self.air_spd_error is None:
        self.air_spd_error = 0.
      if self.xtrack_error is None:
        self.xtrack_error = 0.
    else:
      self.nav_roll = 0.
      self.nav_pitch = 0.
      self.nav_bearing = 0
      self.alt_error = 0.
      self.air_spd_error = 0.
      self.xtrack_error = 0.

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_struct_2fh3f.pack(_x.nav_roll, _x.nav_pitch, _x.nav_bearing, _x.alt_error, _x.air_spd_error, _x.xtrack_error))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 22
      (_x.nav_roll, _x.nav_pitch, _x.nav_bearing, _x.alt_error, _x.air_spd_error, _x.xtrack_error,) = _struct_2fh3f.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_struct_2fh3f.pack(_x.nav_roll, _x.nav_pitch, _x.nav_bearing, _x.alt_error, _x.air_spd_error, _x.xtrack_error))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 22
      (_x.nav_roll, _x.nav_pitch, _x.nav_bearing, _x.alt_error, _x.air_spd_error, _x.xtrack_error,) = _struct_2fh3f.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_2fh3f = struct.Struct("<2fh3f")
