// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from rc_interfaces:msg/ImuRc.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "rc_interfaces/msg/detail/imu_rc__struct.h"
#include "rc_interfaces/msg/detail/imu_rc__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool geometry_msgs__msg__pose__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * geometry_msgs__msg__pose__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool geometry_msgs__msg__twist__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * geometry_msgs__msg__twist__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool geometry_msgs__msg__accel__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * geometry_msgs__msg__accel__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool rc_interfaces__msg__imu_rc__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[32];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("rc_interfaces.msg._imu_rc.ImuRc", full_classname_dest, 31) == 0);
  }
  rc_interfaces__msg__ImuRc * ros_message = _ros_message;
  {  // name
    PyObject * field = PyObject_GetAttrString(_pymsg, "name");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->name, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // msg_count
    PyObject * field = PyObject_GetAttrString(_pymsg, "msg_count");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->msg_count = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // mp_time
    PyObject * field = PyObject_GetAttrString(_pymsg, "mp_time");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->mp_time = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // mp_lat
    PyObject * field = PyObject_GetAttrString(_pymsg, "mp_lat");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->mp_lat = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // mp_longt
    PyObject * field = PyObject_GetAttrString(_pymsg, "mp_longt");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->mp_longt = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // mp_bearing
    PyObject * field = PyObject_GetAttrString(_pymsg, "mp_bearing");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->mp_bearing = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // yaw_angle
    PyObject * field = PyObject_GetAttrString(_pymsg, "yaw_angle");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->yaw_angle = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pose
    PyObject * field = PyObject_GetAttrString(_pymsg, "pose");
    if (!field) {
      return false;
    }
    if (!geometry_msgs__msg__pose__convert_from_py(field, &ros_message->pose)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // twist
    PyObject * field = PyObject_GetAttrString(_pymsg, "twist");
    if (!field) {
      return false;
    }
    if (!geometry_msgs__msg__twist__convert_from_py(field, &ros_message->twist)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // accel
    PyObject * field = PyObject_GetAttrString(_pymsg, "accel");
    if (!field) {
      return false;
    }
    if (!geometry_msgs__msg__accel__convert_from_py(field, &ros_message->accel)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * rc_interfaces__msg__imu_rc__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ImuRc */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("rc_interfaces.msg._imu_rc");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ImuRc");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  rc_interfaces__msg__ImuRc * ros_message = (rc_interfaces__msg__ImuRc *)raw_ros_message;
  {  // name
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->name.data,
      strlen(ros_message->name.data),
      "strict");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "name", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // msg_count
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->msg_count);
    {
      int rc = PyObject_SetAttrString(_pymessage, "msg_count", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mp_time
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->mp_time);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mp_time", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mp_lat
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->mp_lat);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mp_lat", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mp_longt
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->mp_longt);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mp_longt", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mp_bearing
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->mp_bearing);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mp_bearing", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // yaw_angle
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->yaw_angle);
    {
      int rc = PyObject_SetAttrString(_pymessage, "yaw_angle", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pose
    PyObject * field = NULL;
    field = geometry_msgs__msg__pose__convert_to_py(&ros_message->pose);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "pose", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // twist
    PyObject * field = NULL;
    field = geometry_msgs__msg__twist__convert_to_py(&ros_message->twist);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "twist", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // accel
    PyObject * field = NULL;
    field = geometry_msgs__msg__accel__convert_to_py(&ros_message->accel);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "accel", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
