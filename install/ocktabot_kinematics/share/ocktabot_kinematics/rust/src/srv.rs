#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to ocktabot_kinematics__srv__GetJointPosIK_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetJointPosIK_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub target: [f64; 6],

}



impl Default for GetJointPosIK_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetJointPosIK_Request::default())
  }
}

impl rosidl_runtime_rs::Message for GetJointPosIK_Request {
  type RmwMsg = super::srv::rmw::GetJointPosIK_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        target: msg.target,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        target: msg.target,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      target: msg.target,
    }
  }
}


// Corresponds to ocktabot_kinematics__srv__GetJointPosIK_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetJointPosIK_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,

    /// motor names, same order as /motor_jointstate
    pub name: Vec<std::string::String>,

    /// in the units of /motor_jointstate
    pub motor_positions: [f64; 3],

    /// full end-effector pose reached at that solution
    pub pose: [f64; 6],

}



impl Default for GetJointPosIK_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetJointPosIK_Response::default())
  }
}

impl rosidl_runtime_rs::Message for GetJointPosIK_Response {
  type RmwMsg = super::srv::rmw::GetJointPosIK_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        message: msg.message.as_str().into(),
        name: msg.name
          .into_iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        motor_positions: msg.motor_positions,
        pose: msg.pose,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        message: msg.message.as_str().into(),
        name: msg.name
          .iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        motor_positions: msg.motor_positions,
        pose: msg.pose,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      message: msg.message.to_string(),
      name: msg.name
          .into_iter()
          .map(|elem| elem.to_string())
          .collect(),
      motor_positions: msg.motor_positions,
      pose: msg.pose,
    }
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


