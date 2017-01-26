/* GPLv2 or OpenIB.org BSD (MIT) See COPYING file */
#ifndef UTIL_COMPILER_H
#define UTIL_COMPILER_H

/* Use to tag a variable that causes compiler warnings. Use as:
    int uninitialized_var(sz)

   This is only enabled for old compilers. gcc 6.x and beyond have excellent
   static flow analysis. If code solicits a warning from 6.x it is almost
   certainly too complex for a human to understand.
*/
#if __GNUC__ >= 6 || defined(__clang__)
#define uninitialized_var(x) x
#else
#define uninitialized_var(x) x = x
#endif

#ifndef likely
#ifdef __GNUC__
#define likely(x)       __builtin_expect(!!(x), 1)
#else
#define likely(x)      (x)
#endif
#endif

#ifndef unlikely
#ifdef __GNUC__
#define unlikely(x)      __builtin_expect(!!(x), 0)
#else
#define unlikely(x)    (x)
#endif
#endif

#endif
