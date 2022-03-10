// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from rc_interfaces:msg/RcStatus.idl
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
#include "rc_interfaces/msg/detail/rc_status__struct.h"
#include "rc_interfaces/msg/detail/rc_status__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool rc_interfaces__msg__rc_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[38];
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
    assert(strncmp("rc_interfaces.msg._rc_status.RcStatus", full_classname_dest, 37) == 0);
  }
  rc_interfaces__msg__RcStatus * ros_message = _ros_message;
  {  // test_index
    PyObject * field = PyObject_GetAttrString(_pymsg, "test_index");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->test_index = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // test_phase
    PyObject * field = PyObject_GetAttrString(_pymsg, "test_phase");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->test_phase = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // path_dist
    PyObject * field = PyObject_GetAttrString(_pymsg, "path_dist");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->path_dist = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // desire_speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "desire_speed");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->desire_speed = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pf_test_true
    PyObject * field = PyObject_GetAttrString(_pymsg, "pf_test_true");
    if (!field) {
      return false;
    }
    assert(PyBytes_Check(field));
    ros_message->pf_test_true = PyBytes_AS_STRING(field)[0];
    Py_DECREF(field);
  }
  {  // max_path_err_left
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_path_err_left");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->max_path_err_left = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // max_path_err_right
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_path_err_right");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->max_path_err_right = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // current_path_exit_index
    PyObject * field = PyObject_GetAttrString(_pymsg, "current_path_exit_index");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->current_path_exit_index = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // dl_status_1
    PyObject * field = PyObject_GetAttrString(_pymsg, "dl_status_1");
    if (!field) {
      return false;
    }
    assert(PyBytes_Check(field));
    ros_message->dl_status_1 = PyBytes_AS_STRING(field)[0];
    Py_DECREF(field);
  }
  {  // dl_status_2
    PyObject * field = PyObject_GetAttrString(_pymsg, "dl_status_2");
    if (!field) {
      return false;
    }
    assert(PyBytes_Check(field));
    ros_message->dl_status_2 = PyBytes_AS_STRING(field)[0];
    Py_DECREF(field);
  }
  {  // dl_test_procedure_state
    PyObject * field = PyObject_GetAttrString(_pymsg, "dl_test_procedure_state");
    if (!field) {
      return false;
    }
    assert(PyBytes_Check(field));
    ros_message->dl_test_procedure_state = PyBytes_AS_STRING(field)[0];
    Py_DECREF(field);
  }
  {  // test_in_progress
    PyObject * field = PyObject_GetAttrString(_pymsg, "test_in_progress");
    if (!field) {
      return false;
    }
    assert(PyBytes_Check(field));
    ros_message->test_in_progress = PyBytes_AS_STRING(field)[0];
    Py_DECREF(field);
  }
  {  // ar_control_mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "ar_control_mode");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ar_control_mode = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // mp_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "mp_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->mp_status = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // g_sr_err_1
    PyObject * field = PyObject_GetAttrString(_pymsg, "g_sr_err_1");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->g_sr_err_1 = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // br_ar_err_2
    PyObject * field = PyObject_GetAttrString(_pymsg, "br_ar_err_2");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->br_ar_err_2 = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // cr_gr_err_3
    PyObject * field = PyObject_GetAttrString(_pymsg, "cr_gr_err_3");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->cr_gr_err_3 = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // sr_mp_err_4
    PyObject * field = PyObject_GetAttrString(_pymsg, "sr_mp_err_4");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->sr_mp_err_4 = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // syn_temp_err_5
    PyObject * field = PyObject_GetAttrString(_pymsg, "syn_temp_err_5");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->syn_temp_err_5 = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // dl_err_1
    PyObject * field = PyObject_GetAttrString(_pymsg, "dl_err_1");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->dl_err_1 = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // dl_err_2
    PyObject * field = PyObject_GetAttrString(_pymsg, "dl_err_2");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->dl_err_2 = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * rc_interfaces__msg__rc_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of RcStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("rc_interfaces.msg._rc_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "RcStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  rc_interfaces__msg__RcStatus * ros_message = (rc_interfaces__msg__RcStatus *)raw_ros_message;
  {  // test_index
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->test_index);
    {
      int rc = PyObject_SetAttrString(_pymessage, "test_index", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // test_phase
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->test_phase);
    {
      int rc = PyObject_SetAttrString(_pymessage, "test_phase", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // path_dist
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->path_dist);
    {
      int rc = PyObject_SetAttrString(_pymessage, "path_dist", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // desire_speed
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->desire_speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "desire_speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pf_test_true
    PyObject * field = NULL;
    field = PyBytes_FromStringAndSize((const char *)&ros_message->pf_test_true, 1);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "pf_test_true", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_path_err_left
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->max_path_err_left);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_path_err_left", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_path_err_right
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->max_path_err_right);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_path_err_right", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // current_path_exit_index
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->current_path_exit_index);
    {
      int rc = PyObject_SetAttrString(_pymessage, "current_path_exit_index", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // dl_status_1
    PyObject * field = NULL;
    field = PyBytes_FromStringAndSize((const char *)&ros_message->dl_status_1, 1);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "dl_status_1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // dl_status_2
    PyObject * field = NULL;
    field = PyBytes_FromStringAndSize((const char *)&ros_message->dl_status_2, 1);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "dl_status_2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // dl_test_procedure_state
    PyObject * field = NULL;
    field = PyBytes_FromStringAndSize((const char *)&ros_message->dl_test_procedure_state, 1);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "dl_test_procedure_state", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // test_in_progress
    PyObject * field = NULL;
    field = PyBytes_FromStringAndSize((const char *)&ros_message->test_in_progress, 1);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "test_in_progress", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ar_control_mode
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->ar_control_mode);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ar_control_mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mp_status
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->mp_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mp_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // g_sr_err_1
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->g_sr_err_1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "g_sr_err_1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // br_ar_err_2
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->br_ar_err_2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "br_ar_err_2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cr_gr_err_3
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->cr_gr_err_3);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cr_gr_err_3", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sr_mp_err_4
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->sr_mp_err_4);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sr_mp_err_4", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // syn_temp_err_5
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->syn_temp_err_5);
    {
      int rc = PyObject_SetAttrString(_pymessage, "syn_temp_err_5", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // dl_err_1
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->dl_err_1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "dl_err_1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // dl_err_2
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->dl_err_2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "dl_err_2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
