#ifndef __MACROS_H_
#define __MACROS_H_

/* Define a macro needed on windows to make nessessairy classes and functions
   available to external shared objects. */
#ifdef WIN32
  #ifdef CORE_SOURCE
    #define COREDLL __declspec (dllexport)
  #else
    #define COREDLL __declspec (dllimport)
  #endif
  #define DLLEXPORT __declspec (dllexport)
#else
  #define COREDLL
  #define DLLEXPORT
#endif

/** \def Find the minimum between two given values. */
#ifndef MIN
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif /* MIN */

/** \def Find the maximum betwen two given values. */
#ifndef MAX
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif /* MAX */

/** \def Clamp a value in a range. */
#ifndef CLAMP
#define CLAMP(a, l, u) (((a) < (l)) ? (l) : ((a) > (u)) ? (u) : (a))
#endif /* CLAMP */

/** \def Floating point errors, so we have a tolerance for rays. */
#ifndef RAY_EPSILON
#define RAY_EPSILON 1e-3f
#endif /* RAY_EPSILON */

/* MATH FUNCTIONS */

/* We need pi */
#ifndef M_PI
#include <math.h>
#endif

/** \def Convert degrees to radians. */
#ifndef DEG2RAD
#define DEG2RAD(d) ((d) * M_PI / 180.0f)
#endif /* DEG2RAD */

/** \def Convert radians to degrees. */
#ifndef RAD2DEG
#define RAD2DEG(r) ((r) * 180.0f / M_PI)
#endif /* RAD2DEG */

#endif /* __MACROS_H_ */
