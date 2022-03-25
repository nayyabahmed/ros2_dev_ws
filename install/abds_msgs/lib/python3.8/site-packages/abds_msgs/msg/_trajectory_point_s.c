// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from abds_msgs:msg/TrajectoryPoint.idl
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
#include "abds_msgs/msg/detail/trajectory_point__struct.h"
#include "abds_msgs/msg/detail/trajectory_point__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool builtin_interfaces__msg__duration__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * builtin_interfaces__msg__duration__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool geometry_msgs__msg__pose__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * geometry_msgs__msg__pose__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool abds_msgs__msg__trajectory_point__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[48];
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
    assert(strncmp("abds_msgs.msg._trajectory_point.TrajectoryPoint", full_classname_dest, 47) == 0);
  }
  abds_msgs__msg__TrajectoryPoint * ros_message = _ros_message;
  {  // time_from_start
    PyObject * field = PyObject_GetAttrString(_pymsg, "time_from_start");
    if (!field) {
      return false;
    }
    if (!builtin_interfaces__msg__duration__convert_from_py(field, &ros_message->time_from_start)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // datum_bearing
    PyObject * field = PyObject_GetAttrString(_pymsg, "datum_bearing");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->datum_bearing = (float)PyFloat_AS_DOUBLE(field);
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
  {  // dist_along_path
    PyObject * field = PyObject_GetAttrString(_pymsg, "dist_along_path");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->dist_along_path = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // longitudinal_velocity
    PyObject * field = PyObject_GetAttrString(_pymsg, "longitudinal_velocity");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->longitudinal_velocity = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // lateral_velocity
    PyObject * field = PyObject_GetAttrString(_pymsg, "lateral_velocity");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->lateral_velocity = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // acceleration
    PyObject * field = PyObject_GetAttrString(_pymsg, "acceleration");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->acceleration = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // heading_rate
    PyObject * field = PyObject_GetAttrString(_pymsg, "heading_rate");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->heading_rate = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // instantanious_curvature
    PyObject * field = PyObject_GetAttrString(_pymsg, "instantanious_curvature");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->instantanious_curvature = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * abds_msgs__msg__trajectory_point__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of TrajectoryPoint */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("abds_msgs.msg._trajectory_point");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "TrajectoryPoint");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  abds_msgs__msg__TrajectoryPoint * ros_message = (abds_msgs__msg__TrajectoryPoint *)raw_ros_message;
  {  // time_from_start
    PyObject * field = NULL;
    field = builtin_interfaces__msg__duration__convert_to_py(&ros_message->time_from_start);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "time_from_start", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // datum_bearing
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->datum_bearing);
    {
      int rc = PyObject_SetAttrString(_pymessage, "datum_bearing", field);
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
  {  // dist_along_path
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->dist_along_path);
    {
      int rc = PyObject_SetAttrString(_pymessage, "dist_along_path", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // longitudinal_velocity
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->longitudinal_velocity);
    {
      int rc = PyObject_SetAttrString(_pymessage, "longitudinal_velocity", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // lateral_velocity
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->lateral_velocity);
    {
      int rc = PyObject_SetAttrString(_pymessage, "lateral_velocity", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // acceleration
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->acceleration);
    {
      int rc = PyObject_SetAttrString(_pymessage, "acceleration", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // heading_rate
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->heading_rate);
    {
      int rc = PyObject_SetAttrString(_pymessage, "heading_rate", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // instantanious_curvature
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->instantanious_curvature);
    {
      int rc = PyObject_SetAttrString(_pymessage, "instantanious_curvature", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
