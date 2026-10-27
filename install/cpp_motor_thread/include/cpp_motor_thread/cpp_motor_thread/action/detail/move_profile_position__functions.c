// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cpp_motor_thread:action/MoveProfilePosition.idl
// generated code does not contain a copyright notice
#include "cpp_motor_thread/action/detail/move_profile_position__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
cpp_motor_thread__action__MoveProfilePosition_Goal__init(cpp_motor_thread__action__MoveProfilePosition_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // node
  // goal_position
  return true;
}

void
cpp_motor_thread__action__MoveProfilePosition_Goal__fini(cpp_motor_thread__action__MoveProfilePosition_Goal * msg)
{
  if (!msg) {
    return;
  }
  // node
  // goal_position
}

bool
cpp_motor_thread__action__MoveProfilePosition_Goal__are_equal(const cpp_motor_thread__action__MoveProfilePosition_Goal * lhs, const cpp_motor_thread__action__MoveProfilePosition_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // node
  if (lhs->node != rhs->node) {
    return false;
  }
  // goal_position
  if (lhs->goal_position != rhs->goal_position) {
    return false;
  }
  return true;
}

bool
cpp_motor_thread__action__MoveProfilePosition_Goal__copy(
  const cpp_motor_thread__action__MoveProfilePosition_Goal * input,
  cpp_motor_thread__action__MoveProfilePosition_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // node
  output->node = input->node;
  // goal_position
  output->goal_position = input->goal_position;
  return true;
}

cpp_motor_thread__action__MoveProfilePosition_Goal *
cpp_motor_thread__action__MoveProfilePosition_Goal__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_motor_thread__action__MoveProfilePosition_Goal * msg = (cpp_motor_thread__action__MoveProfilePosition_Goal *)allocator.allocate(sizeof(cpp_motor_thread__action__MoveProfilePosition_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cpp_motor_thread__action__MoveProfilePosition_Goal));
  bool success = cpp_motor_thread__action__MoveProfilePosition_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cpp_motor_thread__action__MoveProfilePosition_Goal__destroy(cpp_motor_thread__action__MoveProfilePosition_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cpp_motor_thread__action__MoveProfilePosition_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cpp_motor_thread__action__MoveProfilePosition_Goal__Sequence__init(cpp_motor_thread__action__MoveProfilePosition_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_motor_thread__action__MoveProfilePosition_Goal * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(cpp_motor_thread__action__MoveProfilePosition_Goal)) {
      return false;
    }
    data = (cpp_motor_thread__action__MoveProfilePosition_Goal *)allocator.zero_allocate(size, sizeof(cpp_motor_thread__action__MoveProfilePosition_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cpp_motor_thread__action__MoveProfilePosition_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cpp_motor_thread__action__MoveProfilePosition_Goal__fini(&data[i - 1]);
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
cpp_motor_thread__action__MoveProfilePosition_Goal__Sequence__fini(cpp_motor_thread__action__MoveProfilePosition_Goal__Sequence * array)
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
      cpp_motor_thread__action__MoveProfilePosition_Goal__fini(&array->data[i]);
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

cpp_motor_thread__action__MoveProfilePosition_Goal__Sequence *
cpp_motor_thread__action__MoveProfilePosition_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_motor_thread__action__MoveProfilePosition_Goal__Sequence * array = (cpp_motor_thread__action__MoveProfilePosition_Goal__Sequence *)allocator.allocate(sizeof(cpp_motor_thread__action__MoveProfilePosition_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cpp_motor_thread__action__MoveProfilePosition_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cpp_motor_thread__action__MoveProfilePosition_Goal__Sequence__destroy(cpp_motor_thread__action__MoveProfilePosition_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cpp_motor_thread__action__MoveProfilePosition_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cpp_motor_thread__action__MoveProfilePosition_Goal__Sequence__are_equal(const cpp_motor_thread__action__MoveProfilePosition_Goal__Sequence * lhs, const cpp_motor_thread__action__MoveProfilePosition_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cpp_motor_thread__action__MoveProfilePosition_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cpp_motor_thread__action__MoveProfilePosition_Goal__Sequence__copy(
  const cpp_motor_thread__action__MoveProfilePosition_Goal__Sequence * input,
  cpp_motor_thread__action__MoveProfilePosition_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(cpp_motor_thread__action__MoveProfilePosition_Goal)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(cpp_motor_thread__action__MoveProfilePosition_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cpp_motor_thread__action__MoveProfilePosition_Goal * data =
      (cpp_motor_thread__action__MoveProfilePosition_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cpp_motor_thread__action__MoveProfilePosition_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cpp_motor_thread__action__MoveProfilePosition_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cpp_motor_thread__action__MoveProfilePosition_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
cpp_motor_thread__action__MoveProfilePosition_Result__init(cpp_motor_thread__action__MoveProfilePosition_Result * msg)
{
  if (!msg) {
    return false;
  }
  // end_position
  return true;
}

void
cpp_motor_thread__action__MoveProfilePosition_Result__fini(cpp_motor_thread__action__MoveProfilePosition_Result * msg)
{
  if (!msg) {
    return;
  }
  // end_position
}

bool
cpp_motor_thread__action__MoveProfilePosition_Result__are_equal(const cpp_motor_thread__action__MoveProfilePosition_Result * lhs, const cpp_motor_thread__action__MoveProfilePosition_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // end_position
  if (lhs->end_position != rhs->end_position) {
    return false;
  }
  return true;
}

bool
cpp_motor_thread__action__MoveProfilePosition_Result__copy(
  const cpp_motor_thread__action__MoveProfilePosition_Result * input,
  cpp_motor_thread__action__MoveProfilePosition_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // end_position
  output->end_position = input->end_position;
  return true;
}

cpp_motor_thread__action__MoveProfilePosition_Result *
cpp_motor_thread__action__MoveProfilePosition_Result__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_motor_thread__action__MoveProfilePosition_Result * msg = (cpp_motor_thread__action__MoveProfilePosition_Result *)allocator.allocate(sizeof(cpp_motor_thread__action__MoveProfilePosition_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cpp_motor_thread__action__MoveProfilePosition_Result));
  bool success = cpp_motor_thread__action__MoveProfilePosition_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cpp_motor_thread__action__MoveProfilePosition_Result__destroy(cpp_motor_thread__action__MoveProfilePosition_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cpp_motor_thread__action__MoveProfilePosition_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cpp_motor_thread__action__MoveProfilePosition_Result__Sequence__init(cpp_motor_thread__action__MoveProfilePosition_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_motor_thread__action__MoveProfilePosition_Result * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(cpp_motor_thread__action__MoveProfilePosition_Result)) {
      return false;
    }
    data = (cpp_motor_thread__action__MoveProfilePosition_Result *)allocator.zero_allocate(size, sizeof(cpp_motor_thread__action__MoveProfilePosition_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cpp_motor_thread__action__MoveProfilePosition_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cpp_motor_thread__action__MoveProfilePosition_Result__fini(&data[i - 1]);
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
cpp_motor_thread__action__MoveProfilePosition_Result__Sequence__fini(cpp_motor_thread__action__MoveProfilePosition_Result__Sequence * array)
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
      cpp_motor_thread__action__MoveProfilePosition_Result__fini(&array->data[i]);
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

cpp_motor_thread__action__MoveProfilePosition_Result__Sequence *
cpp_motor_thread__action__MoveProfilePosition_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_motor_thread__action__MoveProfilePosition_Result__Sequence * array = (cpp_motor_thread__action__MoveProfilePosition_Result__Sequence *)allocator.allocate(sizeof(cpp_motor_thread__action__MoveProfilePosition_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cpp_motor_thread__action__MoveProfilePosition_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cpp_motor_thread__action__MoveProfilePosition_Result__Sequence__destroy(cpp_motor_thread__action__MoveProfilePosition_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cpp_motor_thread__action__MoveProfilePosition_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cpp_motor_thread__action__MoveProfilePosition_Result__Sequence__are_equal(const cpp_motor_thread__action__MoveProfilePosition_Result__Sequence * lhs, const cpp_motor_thread__action__MoveProfilePosition_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cpp_motor_thread__action__MoveProfilePosition_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cpp_motor_thread__action__MoveProfilePosition_Result__Sequence__copy(
  const cpp_motor_thread__action__MoveProfilePosition_Result__Sequence * input,
  cpp_motor_thread__action__MoveProfilePosition_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(cpp_motor_thread__action__MoveProfilePosition_Result)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(cpp_motor_thread__action__MoveProfilePosition_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cpp_motor_thread__action__MoveProfilePosition_Result * data =
      (cpp_motor_thread__action__MoveProfilePosition_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cpp_motor_thread__action__MoveProfilePosition_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cpp_motor_thread__action__MoveProfilePosition_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cpp_motor_thread__action__MoveProfilePosition_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
cpp_motor_thread__action__MoveProfilePosition_Feedback__init(cpp_motor_thread__action__MoveProfilePosition_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // current_position
  return true;
}

void
cpp_motor_thread__action__MoveProfilePosition_Feedback__fini(cpp_motor_thread__action__MoveProfilePosition_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // current_position
}

bool
cpp_motor_thread__action__MoveProfilePosition_Feedback__are_equal(const cpp_motor_thread__action__MoveProfilePosition_Feedback * lhs, const cpp_motor_thread__action__MoveProfilePosition_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // current_position
  if (lhs->current_position != rhs->current_position) {
    return false;
  }
  return true;
}

bool
cpp_motor_thread__action__MoveProfilePosition_Feedback__copy(
  const cpp_motor_thread__action__MoveProfilePosition_Feedback * input,
  cpp_motor_thread__action__MoveProfilePosition_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // current_position
  output->current_position = input->current_position;
  return true;
}

cpp_motor_thread__action__MoveProfilePosition_Feedback *
cpp_motor_thread__action__MoveProfilePosition_Feedback__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_motor_thread__action__MoveProfilePosition_Feedback * msg = (cpp_motor_thread__action__MoveProfilePosition_Feedback *)allocator.allocate(sizeof(cpp_motor_thread__action__MoveProfilePosition_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cpp_motor_thread__action__MoveProfilePosition_Feedback));
  bool success = cpp_motor_thread__action__MoveProfilePosition_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cpp_motor_thread__action__MoveProfilePosition_Feedback__destroy(cpp_motor_thread__action__MoveProfilePosition_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cpp_motor_thread__action__MoveProfilePosition_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cpp_motor_thread__action__MoveProfilePosition_Feedback__Sequence__init(cpp_motor_thread__action__MoveProfilePosition_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_motor_thread__action__MoveProfilePosition_Feedback * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(cpp_motor_thread__action__MoveProfilePosition_Feedback)) {
      return false;
    }
    data = (cpp_motor_thread__action__MoveProfilePosition_Feedback *)allocator.zero_allocate(size, sizeof(cpp_motor_thread__action__MoveProfilePosition_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cpp_motor_thread__action__MoveProfilePosition_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cpp_motor_thread__action__MoveProfilePosition_Feedback__fini(&data[i - 1]);
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
cpp_motor_thread__action__MoveProfilePosition_Feedback__Sequence__fini(cpp_motor_thread__action__MoveProfilePosition_Feedback__Sequence * array)
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
      cpp_motor_thread__action__MoveProfilePosition_Feedback__fini(&array->data[i]);
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

cpp_motor_thread__action__MoveProfilePosition_Feedback__Sequence *
cpp_motor_thread__action__MoveProfilePosition_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_motor_thread__action__MoveProfilePosition_Feedback__Sequence * array = (cpp_motor_thread__action__MoveProfilePosition_Feedback__Sequence *)allocator.allocate(sizeof(cpp_motor_thread__action__MoveProfilePosition_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cpp_motor_thread__action__MoveProfilePosition_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cpp_motor_thread__action__MoveProfilePosition_Feedback__Sequence__destroy(cpp_motor_thread__action__MoveProfilePosition_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cpp_motor_thread__action__MoveProfilePosition_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cpp_motor_thread__action__MoveProfilePosition_Feedback__Sequence__are_equal(const cpp_motor_thread__action__MoveProfilePosition_Feedback__Sequence * lhs, const cpp_motor_thread__action__MoveProfilePosition_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cpp_motor_thread__action__MoveProfilePosition_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cpp_motor_thread__action__MoveProfilePosition_Feedback__Sequence__copy(
  const cpp_motor_thread__action__MoveProfilePosition_Feedback__Sequence * input,
  cpp_motor_thread__action__MoveProfilePosition_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(cpp_motor_thread__action__MoveProfilePosition_Feedback)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(cpp_motor_thread__action__MoveProfilePosition_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cpp_motor_thread__action__MoveProfilePosition_Feedback * data =
      (cpp_motor_thread__action__MoveProfilePosition_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cpp_motor_thread__action__MoveProfilePosition_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cpp_motor_thread__action__MoveProfilePosition_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cpp_motor_thread__action__MoveProfilePosition_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "cpp_motor_thread/action/detail/move_profile_position__functions.h"

bool
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__init(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!cpp_motor_thread__action__MoveProfilePosition_Goal__init(&msg->goal)) {
    cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__fini(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  cpp_motor_thread__action__MoveProfilePosition_Goal__fini(&msg->goal);
}

bool
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__are_equal(const cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request * lhs, const cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!cpp_motor_thread__action__MoveProfilePosition_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__copy(
  const cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request * input,
  cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!cpp_motor_thread__action__MoveProfilePosition_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request *
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request * msg = (cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request *)allocator.allocate(sizeof(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request));
  bool success = cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__destroy(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__Sequence__init(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request)) {
      return false;
    }
    data = (cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request *)allocator.zero_allocate(size, sizeof(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__fini(&data[i - 1]);
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
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__Sequence__fini(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__Sequence * array)
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
      cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__fini(&array->data[i]);
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

cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__Sequence *
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__Sequence * array = (cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__Sequence *)allocator.allocate(sizeof(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__Sequence__destroy(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__Sequence__are_equal(const cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__Sequence * lhs, const cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__Sequence__copy(
  const cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__Sequence * input,
  cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request * data =
      (cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__init(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__fini(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__are_equal(const cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response * lhs, const cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__copy(
  const cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response * input,
  cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response *
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response * msg = (cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response *)allocator.allocate(sizeof(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response));
  bool success = cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__destroy(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__Sequence__init(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response)) {
      return false;
    }
    data = (cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response *)allocator.zero_allocate(size, sizeof(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__fini(&data[i - 1]);
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
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__Sequence__fini(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__Sequence * array)
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
      cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__fini(&array->data[i]);
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

cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__Sequence *
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__Sequence * array = (cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__Sequence *)allocator.allocate(sizeof(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__Sequence__destroy(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__Sequence__are_equal(const cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__Sequence * lhs, const cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__Sequence__copy(
  const cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__Sequence * input,
  cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response * data =
      (cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__copy(
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
// #include "cpp_motor_thread/action/detail/move_profile_position__functions.h"

bool
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__init(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__fini(msg);
    return false;
  }
  // request
  if (!cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__Sequence__init(&msg->request, 0)) {
    cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__fini(msg);
    return false;
  }
  // response
  if (!cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__Sequence__init(&msg->response, 0)) {
    cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__fini(msg);
    return false;
  }
  return true;
}

void
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__fini(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__Sequence__fini(&msg->request);
  // response
  cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__Sequence__fini(&msg->response);
}

bool
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__are_equal(const cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event * lhs, const cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event * rhs)
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
  if (!cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__copy(
  const cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event * input,
  cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event * output)
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
  if (!cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event *
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event * msg = (cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event *)allocator.allocate(sizeof(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event));
  bool success = cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__destroy(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__Sequence__init(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event)) {
      return false;
    }
    data = (cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event *)allocator.zero_allocate(size, sizeof(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__fini(&data[i - 1]);
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
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__Sequence__fini(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__Sequence * array)
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
      cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__fini(&array->data[i]);
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

cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__Sequence *
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__Sequence * array = (cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__Sequence *)allocator.allocate(sizeof(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__Sequence__destroy(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__Sequence__are_equal(const cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__Sequence * lhs, const cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__Sequence__copy(
  const cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__Sequence * input,
  cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event * data =
      (cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__init(cpp_motor_thread__action__MoveProfilePosition_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__fini(cpp_motor_thread__action__MoveProfilePosition_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__are_equal(const cpp_motor_thread__action__MoveProfilePosition_GetResult_Request * lhs, const cpp_motor_thread__action__MoveProfilePosition_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__copy(
  const cpp_motor_thread__action__MoveProfilePosition_GetResult_Request * input,
  cpp_motor_thread__action__MoveProfilePosition_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

cpp_motor_thread__action__MoveProfilePosition_GetResult_Request *
cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_motor_thread__action__MoveProfilePosition_GetResult_Request * msg = (cpp_motor_thread__action__MoveProfilePosition_GetResult_Request *)allocator.allocate(sizeof(cpp_motor_thread__action__MoveProfilePosition_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cpp_motor_thread__action__MoveProfilePosition_GetResult_Request));
  bool success = cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__destroy(cpp_motor_thread__action__MoveProfilePosition_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__Sequence__init(cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_motor_thread__action__MoveProfilePosition_GetResult_Request * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(cpp_motor_thread__action__MoveProfilePosition_GetResult_Request)) {
      return false;
    }
    data = (cpp_motor_thread__action__MoveProfilePosition_GetResult_Request *)allocator.zero_allocate(size, sizeof(cpp_motor_thread__action__MoveProfilePosition_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__fini(&data[i - 1]);
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
cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__Sequence__fini(cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__Sequence * array)
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
      cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__fini(&array->data[i]);
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

cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__Sequence *
cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__Sequence * array = (cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__Sequence *)allocator.allocate(sizeof(cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__Sequence__destroy(cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__Sequence__are_equal(const cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__Sequence * lhs, const cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__Sequence__copy(
  const cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__Sequence * input,
  cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(cpp_motor_thread__action__MoveProfilePosition_GetResult_Request)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(cpp_motor_thread__action__MoveProfilePosition_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cpp_motor_thread__action__MoveProfilePosition_GetResult_Request * data =
      (cpp_motor_thread__action__MoveProfilePosition_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "cpp_motor_thread/action/detail/move_profile_position__functions.h"

bool
cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__init(cpp_motor_thread__action__MoveProfilePosition_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!cpp_motor_thread__action__MoveProfilePosition_Result__init(&msg->result)) {
    cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__fini(cpp_motor_thread__action__MoveProfilePosition_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  cpp_motor_thread__action__MoveProfilePosition_Result__fini(&msg->result);
}

bool
cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__are_equal(const cpp_motor_thread__action__MoveProfilePosition_GetResult_Response * lhs, const cpp_motor_thread__action__MoveProfilePosition_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!cpp_motor_thread__action__MoveProfilePosition_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__copy(
  const cpp_motor_thread__action__MoveProfilePosition_GetResult_Response * input,
  cpp_motor_thread__action__MoveProfilePosition_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!cpp_motor_thread__action__MoveProfilePosition_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

cpp_motor_thread__action__MoveProfilePosition_GetResult_Response *
cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_motor_thread__action__MoveProfilePosition_GetResult_Response * msg = (cpp_motor_thread__action__MoveProfilePosition_GetResult_Response *)allocator.allocate(sizeof(cpp_motor_thread__action__MoveProfilePosition_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cpp_motor_thread__action__MoveProfilePosition_GetResult_Response));
  bool success = cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__destroy(cpp_motor_thread__action__MoveProfilePosition_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__Sequence__init(cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_motor_thread__action__MoveProfilePosition_GetResult_Response * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(cpp_motor_thread__action__MoveProfilePosition_GetResult_Response)) {
      return false;
    }
    data = (cpp_motor_thread__action__MoveProfilePosition_GetResult_Response *)allocator.zero_allocate(size, sizeof(cpp_motor_thread__action__MoveProfilePosition_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__fini(&data[i - 1]);
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
cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__Sequence__fini(cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__Sequence * array)
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
      cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__fini(&array->data[i]);
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

cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__Sequence *
cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__Sequence * array = (cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__Sequence *)allocator.allocate(sizeof(cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__Sequence__destroy(cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__Sequence__are_equal(const cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__Sequence * lhs, const cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__Sequence__copy(
  const cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__Sequence * input,
  cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(cpp_motor_thread__action__MoveProfilePosition_GetResult_Response)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(cpp_motor_thread__action__MoveProfilePosition_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cpp_motor_thread__action__MoveProfilePosition_GetResult_Response * data =
      (cpp_motor_thread__action__MoveProfilePosition_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
// already included above
// #include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "cpp_motor_thread/action/detail/move_profile_position__functions.h"

bool
cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__init(cpp_motor_thread__action__MoveProfilePosition_GetResult_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__fini(msg);
    return false;
  }
  // request
  if (!cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__Sequence__init(&msg->request, 0)) {
    cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__fini(msg);
    return false;
  }
  // response
  if (!cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__Sequence__init(&msg->response, 0)) {
    cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__fini(msg);
    return false;
  }
  return true;
}

void
cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__fini(cpp_motor_thread__action__MoveProfilePosition_GetResult_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__Sequence__fini(&msg->request);
  // response
  cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__Sequence__fini(&msg->response);
}

bool
cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__are_equal(const cpp_motor_thread__action__MoveProfilePosition_GetResult_Event * lhs, const cpp_motor_thread__action__MoveProfilePosition_GetResult_Event * rhs)
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
  if (!cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__copy(
  const cpp_motor_thread__action__MoveProfilePosition_GetResult_Event * input,
  cpp_motor_thread__action__MoveProfilePosition_GetResult_Event * output)
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
  if (!cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

cpp_motor_thread__action__MoveProfilePosition_GetResult_Event *
cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_motor_thread__action__MoveProfilePosition_GetResult_Event * msg = (cpp_motor_thread__action__MoveProfilePosition_GetResult_Event *)allocator.allocate(sizeof(cpp_motor_thread__action__MoveProfilePosition_GetResult_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cpp_motor_thread__action__MoveProfilePosition_GetResult_Event));
  bool success = cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__destroy(cpp_motor_thread__action__MoveProfilePosition_GetResult_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__Sequence__init(cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_motor_thread__action__MoveProfilePosition_GetResult_Event * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(cpp_motor_thread__action__MoveProfilePosition_GetResult_Event)) {
      return false;
    }
    data = (cpp_motor_thread__action__MoveProfilePosition_GetResult_Event *)allocator.zero_allocate(size, sizeof(cpp_motor_thread__action__MoveProfilePosition_GetResult_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__fini(&data[i - 1]);
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
cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__Sequence__fini(cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__Sequence * array)
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
      cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__fini(&array->data[i]);
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

cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__Sequence *
cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__Sequence * array = (cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__Sequence *)allocator.allocate(sizeof(cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__Sequence__destroy(cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__Sequence__are_equal(const cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__Sequence * lhs, const cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__Sequence__copy(
  const cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__Sequence * input,
  cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(cpp_motor_thread__action__MoveProfilePosition_GetResult_Event)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(cpp_motor_thread__action__MoveProfilePosition_GetResult_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cpp_motor_thread__action__MoveProfilePosition_GetResult_Event * data =
      (cpp_motor_thread__action__MoveProfilePosition_GetResult_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "cpp_motor_thread/action/detail/move_profile_position__functions.h"

bool
cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__init(cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!cpp_motor_thread__action__MoveProfilePosition_Feedback__init(&msg->feedback)) {
    cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__fini(cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  cpp_motor_thread__action__MoveProfilePosition_Feedback__fini(&msg->feedback);
}

bool
cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__are_equal(const cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage * lhs, const cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!cpp_motor_thread__action__MoveProfilePosition_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__copy(
  const cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage * input,
  cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!cpp_motor_thread__action__MoveProfilePosition_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage *
cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage * msg = (cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage *)allocator.allocate(sizeof(cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage));
  bool success = cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__destroy(cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__Sequence__init(cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage)) {
      return false;
    }
    data = (cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage *)allocator.zero_allocate(size, sizeof(cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__fini(&data[i - 1]);
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
cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__Sequence__fini(cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__Sequence * array)
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
      cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__fini(&array->data[i]);
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

cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__Sequence *
cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__Sequence * array = (cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__Sequence *)allocator.allocate(sizeof(cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__Sequence__destroy(cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__Sequence__are_equal(const cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__Sequence * lhs, const cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__Sequence__copy(
  const cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__Sequence * input,
  cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage * data =
      (cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
