#ifndef CPP_MOTOR_THREAD__VISIBILITY_CONTROL_H_
#define CPP_MOTOR_THREAD__VISIBILITY_CONTROL_H_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define CPP_MOTOR_THREAD_EXPORT __attribute__ ((dllexport))
    #define CPP_MOTOR_THREAD_IMPORT __attribute__ ((dllimport))
  #else
    #define CPP_MOTOR_THREAD_EXPORT __declspec(dllexport)
    #define CPP_MOTOR_THREAD_IMPORT __declspec(dllimport)
  #endif
  #ifdef CPP_MOTOR_THREAD_BUILDING_DLL
    #define CPP_MOTOR_THREAD_PUBLIC CPP_MOTOR_THREAD_EXPORT
  #else
    #define CPP_MOTOR_THREAD_PUBLIC CPP_MOTOR_THREAD_IMPORT
  #endif
  #define CPP_MOTOR_THREAD_PUBLIC_TYPE CPP_MOTOR_THREAD_PUBLIC
  #define CPP_MOTOR_THREAD_LOCAL
#else
  #define CPP_MOTOR_THREAD_EXPORT __attribute__ ((visibility("default")))
  #define CPP_MOTOR_THREAD_IMPORT
  #if __GNUC__ >= 4
    #define CPP_MOTOR_THREAD_PUBLIC __attribute__ ((visibility("default")))
    #define CPP_MOTOR_THREAD_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define CPP_MOTOR_THREAD_PUBLIC
    #define CPP_MOTOR_THREAD_LOCAL
  #endif
  #define CPP_MOTOR_THREAD_PUBLIC_TYPE
#endif

#ifdef __cplusplus
}
#endif

#endif  // CPP_MOTOR_THREAD__VISIBILITY_CONTROL_H_