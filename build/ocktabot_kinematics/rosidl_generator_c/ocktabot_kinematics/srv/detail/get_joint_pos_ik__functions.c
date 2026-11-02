// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ocktabot_kinematics:srv/GetJointPosIK.idl
// generated code does not contain a copyright notice
#include "ocktabot_kinematics/srv/detail/get_joint_pos_ik__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
ocktabot_kinematics__srv__GetJointPosIK_Request__init(ocktabot_kinematics__srv__GetJointPosIK_Request * msg)
{
  if (!msg) {
    return false;
  }
  // target
  return true;
}

void
ocktabot_kinematics__srv__GetJointPosIK_Request__fini(ocktabot_kinematics__srv__GetJointPosIK_Request * msg)
{
  if (!msg) {
    return;
  }
  // target
}

bool
ocktabot_kinematics__srv__GetJointPosIK_Request__are_equal(const ocktabot_kinematics__srv__GetJointPosIK_Request * lhs, const ocktabot_kinematics__srv__GetJointPosIK_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // target
  for (size_t i = 0; i < 6; ++i) {
    if (lhs->target[i] != rhs->target[i]) {
      return false;
    }
  }
  return true;
}

bool
ocktabot_kinematics__srv__GetJointPosIK_Request__copy(
  const ocktabot_kinematics__srv__GetJointPosIK_Request * input,
  ocktabot_kinematics__srv__GetJointPosIK_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // target
  for (size_t i = 0; i < 6; ++i) {
    output->target[i] = input->target[i];
  }
  return true;
}

ocktabot_kinematics__srv__GetJointPosIK_Request *
ocktabot_kinematics__srv__GetJointPosIK_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ocktabot_kinematics__srv__GetJointPosIK_Request * msg = (ocktabot_kinematics__srv__GetJointPosIK_Request *)allocator.allocate(sizeof(ocktabot_kinematics__srv__GetJointPosIK_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ocktabot_kinematics__srv__GetJointPosIK_Request));
  bool success = ocktabot_kinematics__srv__GetJointPosIK_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ocktabot_kinematics__srv__GetJointPosIK_Request__destroy(ocktabot_kinematics__srv__GetJointPosIK_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ocktabot_kinematics__srv__GetJointPosIK_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence__init(ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ocktabot_kinematics__srv__GetJointPosIK_Request * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(ocktabot_kinematics__srv__GetJointPosIK_Request)) {
      return false;
    }
    data = (ocktabot_kinematics__srv__GetJointPosIK_Request *)allocator.zero_allocate(size, sizeof(ocktabot_kinematics__srv__GetJointPosIK_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ocktabot_kinematics__srv__GetJointPosIK_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ocktabot_kinematics__srv__GetJointPosIK_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence__fini(ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ocktabot_kinematics__srv__GetJointPosIK_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence *
ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence * array = (ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence *)allocator.allocate(sizeof(ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence__destroy(ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence__are_equal(const ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence * lhs, const ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ocktabot_kinematics__srv__GetJointPosIK_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence__copy(
  const ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence * input,
  ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(ocktabot_kinematics__srv__GetJointPosIK_Request)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(ocktabot_kinematics__srv__GetJointPosIK_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ocktabot_kinematics__srv__GetJointPosIK_Request * data =
      (ocktabot_kinematics__srv__GetJointPosIK_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ocktabot_kinematics__srv__GetJointPosIK_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ocktabot_kinematics__srv__GetJointPosIK_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ocktabot_kinematics__srv__GetJointPosIK_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
// Member `name`
#include "rosidl_runtime_c/string_functions.h"

bool
ocktabot_kinematics__srv__GetJointPosIK_Response__init(ocktabot_kinematics__srv__GetJointPosIK_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    ocktabot_kinematics__srv__GetJointPosIK_Response__fini(msg);
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__Sequence__init(&msg->name, 0)) {
    ocktabot_kinematics__srv__GetJointPosIK_Response__fini(msg);
    return false;
  }
  // motor_positions
  // pose
  return true;
}

void
ocktabot_kinematics__srv__GetJointPosIK_Response__fini(ocktabot_kinematics__srv__GetJointPosIK_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
  // name
  rosidl_runtime_c__String__Sequence__fini(&msg->name);
  // motor_positions
  // pose
}

bool
ocktabot_kinematics__srv__GetJointPosIK_Response__are_equal(const ocktabot_kinematics__srv__GetJointPosIK_Response * lhs, const ocktabot_kinematics__srv__GetJointPosIK_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // motor_positions
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->motor_positions[i] != rhs->motor_positions[i]) {
      return false;
    }
  }
  // pose
  for (size_t i = 0; i < 6; ++i) {
    if (lhs->pose[i] != rhs->pose[i]) {
      return false;
    }
  }
  return true;
}

bool
ocktabot_kinematics__srv__GetJointPosIK_Response__copy(
  const ocktabot_kinematics__srv__GetJointPosIK_Response * input,
  ocktabot_kinematics__srv__GetJointPosIK_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // motor_positions
  for (size_t i = 0; i < 3; ++i) {
    output->motor_positions[i] = input->motor_positions[i];
  }
  // pose
  for (size_t i = 0; i < 6; ++i) {
    output->pose[i] = input->pose[i];
  }
  return true;
}

ocktabot_kinematics__srv__GetJointPosIK_Response *
ocktabot_kinematics__srv__GetJointPosIK_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ocktabot_kinematics__srv__GetJointPosIK_Response * msg = (ocktabot_kinematics__srv__GetJointPosIK_Response *)allocator.allocate(sizeof(ocktabot_kinematics__srv__GetJointPosIK_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ocktabot_kinematics__srv__GetJointPosIK_Response));
  bool success = ocktabot_kinematics__srv__GetJointPosIK_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ocktabot_kinematics__srv__GetJointPosIK_Response__destroy(ocktabot_kinematics__srv__GetJointPosIK_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ocktabot_kinematics__srv__GetJointPosIK_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence__init(ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ocktabot_kinematics__srv__GetJointPosIK_Response * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(ocktabot_kinematics__srv__GetJointPosIK_Response)) {
      return false;
    }
    data = (ocktabot_kinematics__srv__GetJointPosIK_Response *)allocator.zero_allocate(size, sizeof(ocktabot_kinematics__srv__GetJointPosIK_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ocktabot_kinematics__srv__GetJointPosIK_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ocktabot_kinematics__srv__GetJointPosIK_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence__fini(ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ocktabot_kinematics__srv__GetJointPosIK_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence *
ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence * array = (ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence *)allocator.allocate(sizeof(ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence__destroy(ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence__are_equal(const ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence * lhs, const ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ocktabot_kinematics__srv__GetJointPosIK_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence__copy(
  const ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence * input,
  ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(ocktabot_kinematics__srv__GetJointPosIK_Response)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(ocktabot_kinematics__srv__GetJointPosIK_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ocktabot_kinematics__srv__GetJointPosIK_Response * data =
      (ocktabot_kinematics__srv__GetJointPosIK_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ocktabot_kinematics__srv__GetJointPosIK_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ocktabot_kinematics__srv__GetJointPosIK_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ocktabot_kinematics__srv__GetJointPosIK_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "ocktabot_kinematics/srv/detail/get_joint_pos_ik__functions.h"

bool
ocktabot_kinematics__srv__GetJointPosIK_Event__init(ocktabot_kinematics__srv__GetJointPosIK_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    ocktabot_kinematics__srv__GetJointPosIK_Event__fini(msg);
    return false;
  }
  // request
  if (!ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence__init(&msg->request, 0)) {
    ocktabot_kinematics__srv__GetJointPosIK_Event__fini(msg);
    return false;
  }
  // response
  if (!ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence__init(&msg->response, 0)) {
    ocktabot_kinematics__srv__GetJointPosIK_Event__fini(msg);
    return false;
  }
  return true;
}

void
ocktabot_kinematics__srv__GetJointPosIK_Event__fini(ocktabot_kinematics__srv__GetJointPosIK_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence__fini(&msg->request);
  // response
  ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence__fini(&msg->response);
}

bool
ocktabot_kinematics__srv__GetJointPosIK_Event__are_equal(const ocktabot_kinematics__srv__GetJointPosIK_Event * lhs, const ocktabot_kinematics__srv__GetJointPosIK_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
ocktabot_kinematics__srv__GetJointPosIK_Event__copy(
  const ocktabot_kinematics__srv__GetJointPosIK_Event * input,
  ocktabot_kinematics__srv__GetJointPosIK_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

ocktabot_kinematics__srv__GetJointPosIK_Event *
ocktabot_kinematics__srv__GetJointPosIK_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ocktabot_kinematics__srv__GetJointPosIK_Event * msg = (ocktabot_kinematics__srv__GetJointPosIK_Event *)allocator.allocate(sizeof(ocktabot_kinematics__srv__GetJointPosIK_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ocktabot_kinematics__srv__GetJointPosIK_Event));
  bool success = ocktabot_kinematics__srv__GetJointPosIK_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ocktabot_kinematics__srv__GetJointPosIK_Event__destroy(ocktabot_kinematics__srv__GetJointPosIK_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ocktabot_kinematics__srv__GetJointPosIK_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ocktabot_kinematics__srv__GetJointPosIK_Event__Sequence__init(ocktabot_kinematics__srv__GetJointPosIK_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ocktabot_kinematics__srv__GetJointPosIK_Event * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(ocktabot_kinematics__srv__GetJointPosIK_Event)) {
      return false;
    }
    data = (ocktabot_kinematics__srv__GetJointPosIK_Event *)allocator.zero_allocate(size, sizeof(ocktabot_kinematics__srv__GetJointPosIK_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ocktabot_kinematics__srv__GetJointPosIK_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ocktabot_kinematics__srv__GetJointPosIK_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ocktabot_kinematics__srv__GetJointPosIK_Event__Sequence__fini(ocktabot_kinematics__srv__GetJointPosIK_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ocktabot_kinematics__srv__GetJointPosIK_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ocktabot_kinematics__srv__GetJointPosIK_Event__Sequence *
ocktabot_kinematics__srv__GetJointPosIK_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ocktabot_kinematics__srv__GetJointPosIK_Event__Sequence * array = (ocktabot_kinematics__srv__GetJointPosIK_Event__Sequence *)allocator.allocate(sizeof(ocktabot_kinematics__srv__GetJointPosIK_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ocktabot_kinematics__srv__GetJointPosIK_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ocktabot_kinematics__srv__GetJointPosIK_Event__Sequence__destroy(ocktabot_kinematics__srv__GetJointPosIK_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ocktabot_kinematics__srv__GetJointPosIK_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ocktabot_kinematics__srv__GetJointPosIK_Event__Sequence__are_equal(const ocktabot_kinematics__srv__GetJointPosIK_Event__Sequence * lhs, const ocktabot_kinematics__srv__GetJointPosIK_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ocktabot_kinematics__srv__GetJointPosIK_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ocktabot_kinematics__srv__GetJointPosIK_Event__Sequence__copy(
  const ocktabot_kinematics__srv__GetJointPosIK_Event__Sequence * input,
  ocktabot_kinematics__srv__GetJointPosIK_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(ocktabot_kinematics__srv__GetJointPosIK_Event)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(ocktabot_kinematics__srv__GetJointPosIK_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ocktabot_kinematics__srv__GetJointPosIK_Event * data =
      (ocktabot_kinematics__srv__GetJointPosIK_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ocktabot_kinematics__srv__GetJointPosIK_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ocktabot_kinematics__srv__GetJointPosIK_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ocktabot_kinematics__srv__GetJointPosIK_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
