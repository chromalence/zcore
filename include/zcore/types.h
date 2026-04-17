#ifndef ZTYPES_H
#define ZTYPES_H

#ifndef regztypes
#define regztypes 3
#endif

#if regztypes == 1

typedef signed char        schar;
typedef short              i16;
typedef int                i32;
typedef long long          i64;

typedef unsigned char      uchar;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;

typedef float              f32;
typedef double             f64;

#elif regztypes == 2

typedef signed char schar;
typedef short int16;
typedef int int32;
typedef long long int64;

typedef unsigned char uchar;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;

typedef float float32;
typedef double double64;

#elif regztypes == 3

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned long long u64;

typedef signed char    i8;
typedef short          i16;
typedef int            i32;
typedef long long      i64;

typedef float          f32;
typedef double         f64;

#else


#warning "(zcore/types.h) : invalid type version definition, check #define regztypes and make sure its 1-3 : default = 3"
#warning "(zcore/types.h) : hey its me types.h ill be defaulting to number 3 as a failsafe"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned long long u64;

typedef signed char    i8;
typedef short          i16;
typedef int            i32;
typedef long long      i64;

typedef float          f32;
typedef double         f64;

#endif

#endif
