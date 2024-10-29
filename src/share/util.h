#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include <inttypes.h>
#include <stdarg.h>

/** Visibility attribute */
#if defined(__GNUC__) && __GNUC__ >= 4
#define JJ_EXPORT __attribute__ ((visibility("default")))
#else
#define JJ_EXPORT
#endif