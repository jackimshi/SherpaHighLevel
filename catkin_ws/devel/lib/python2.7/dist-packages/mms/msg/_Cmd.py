"""autogenerated by genpy from mms/Cmd.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class Cmd(genpy.Message):
  _md5sum = "5b4f669afd135795e40aa7e9dcc1c4f4"
  _type = "mms/Cmd"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """# see MISSION_ITEM in MAVlink
uint16 command
float32 param1
float32 param2
float32 param3
float32 param4
float32 param5
float32 param6
float32 param7

"""
  __slots__ = ['command','param1','param2','param3','param4','param5','param6','param7']
  _slot_types = ['uint16','float32','float32','float32','float32','float32','float32','float32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       command,param1,param2,param3,param4,param5,param6,param7

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(Cmd, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.command is None:
        self.command = 0
      if self.param1 is None:
        self.param1 = 0.
      if self.param2 is None:
        self.param2 = 0.
      if self.param3 is None:
        self.param3 = 0.
      if self.param4 is None:
        self.param4 = 0.
      if self.param5 is None:
        self.param5 = 0.
      if self.param6 is None:
        self.param6 = 0.
      if self.param7 is None:
        self.param7 = 0.
    else:
      self.command = 0
      self.param1 = 0.
      self.param2 = 0.
      self.param3 = 0.
      self.param4 = 0.
      self.param5 = 0.
      self.param6 = 0.
      self.param7 = 0.

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
      buff.write(_struct_H7f.pack(_x.command, _x.param1, _x.param2, _x.param3, _x.param4, _x.param5, _x.param6, _x.param7))
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
      end += 30
      (_x.command, _x.param1, _x.param2, _x.param3, _x.param4, _x.param5, _x.param6, _x.param7,) = _struct_H7f.unpack(str[start:end])
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
      buff.write(_struct_H7f.pack(_x.command, _x.param1, _x.param2, _x.param3, _x.param4, _x.param5, _x.param6, _x.param7))
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
      end += 30
      (_x.command, _x.param1, _x.param2, _x.param3, _x.param4, _x.param5, _x.param6, _x.param7,) = _struct_H7f.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_H7f = struct.Struct("<H7f")
