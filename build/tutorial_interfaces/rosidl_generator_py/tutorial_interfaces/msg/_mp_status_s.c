// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from tutorial_interfaces:msg/MpStatus.idl
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
#include "tutorial_interfaces/msg/detail/mp_status__struct.h"
#include "tutorial_interfaces/msg/detail/mp_status__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool tutorial_interfaces__msg__mp_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[44];
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
    assert(strncmp("tutorial_interfaces.msg._mp_status.MpStatus", full_classname_dest, 43) == 0);
  }
  tutorial_interfaces__msg__MpStatus * ros_message = _ros_message;
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

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * tutorial_interfaces__msg__mp_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of MpStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("tutorial_interfaces.msg._mp_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "MpStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  tutorial_interfaces__msg__MpStatus * ros_message = (tutorial_interfaces__msg__MpStatus *)raw_ros_message;
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

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
