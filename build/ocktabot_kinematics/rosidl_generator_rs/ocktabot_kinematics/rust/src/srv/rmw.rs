#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "ocktabot_kinematics__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ocktabot_kinematics__srv__GetJointPosIK_Request() -> *const std::ffi::c_void;
}

#[link(name = "ocktabot_kinematics__rosidl_generator_c")]
extern "C" {
    fn ocktabot_kinematics__srv__GetJointPosIK_Request__init(msg: *mut GetJointPosIK_Request) -> bool;
    fn ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetJointPosIK_Request>, size: usize) -> bool;
    fn ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetJointPosIK_Request>);
    fn ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetJointPosIK_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetJointPosIK_Request>) -> bool;
}

// Corresponds to ocktabot_kinematics__srv__GetJointPosIK_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetJointPosIK_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub target: [f64; 6],

}



impl Default for GetJointPosIK_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ocktabot_kinematics__srv__GetJointPosIK_Request__init(&mut msg as *mut _) {
        panic!("Call to ocktabot_kinematics__srv__GetJointPosIK_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetJointPosIK_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetJointPosIK_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetJointPosIK_Request where Self: Sized {
  const TYPE_NAME: &'static str = "ocktabot_kinematics/srv/GetJointPosIK_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ocktabot_kinematics__srv__GetJointPosIK_Request() }
  }
}


#[link(name = "ocktabot_kinematics__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ocktabot_kinematics__srv__GetJointPosIK_Response() -> *const std::ffi::c_void;
}

#[link(name = "ocktabot_kinematics__rosidl_generator_c")]
extern "C" {
    fn ocktabot_kinematics__srv__GetJointPosIK_Response__init(msg: *mut GetJointPosIK_Response) -> bool;
    fn ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetJointPosIK_Response>, size: usize) -> bool;
    fn ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetJointPosIK_Response>);
    fn ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetJointPosIK_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetJointPosIK_Response>) -> bool;
}

// Corresponds to ocktabot_kinematics__srv__GetJointPosIK_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetJointPosIK_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

    /// motor names, same order as /motor_jointstate
    pub name: rosidl_runtime_rs::Sequence<rosidl_runtime_rs::String>,

    /// in the units of /motor_jointstate
    pub motor_positions: [f64; 3],

    /// full end-effector pose reached at that solution
    pub pose: [f64; 6],

}



impl Default for GetJointPosIK_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ocktabot_kinematics__srv__GetJointPosIK_Response__init(&mut msg as *mut _) {
        panic!("Call to ocktabot_kinematics__srv__GetJointPosIK_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetJointPosIK_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetJointPosIK_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetJointPosIK_Response where Self: Sized {
  const TYPE_NAME: &'static str = "ocktabot_kinematics/srv/GetJointPosIK_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ocktabot_kinematics__srv__GetJointPosIK_Response() }
  }
}






#[link(name = "ocktabot_kinematics__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__ocktabot_kinematics__srv__GetJointPosIK() -> *const std::ffi::c_void;
}

// Corresponds to ocktabot_kinematics__srv__GetJointPosIK
#[allow(missing_docs, non_camel_case_types)]
pub struct GetJointPosIK;

impl rosidl_runtime_rs::Service for GetJointPosIK {
    type Request = GetJointPosIK_Request;
    type Response = GetJointPosIK_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__ocktabot_kinematics__srv__GetJointPosIK() }
    }
}


