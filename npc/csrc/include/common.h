#ifndef __COMMON_H__
#define __COMMON_H__

#include <iostream> // std::cout , std::endl
#include <iomanip>  // std::hex  , std::setw , std::setfill
#include <cstdint>  // uint32_t
#include <cstring>  // memcpy
#include "utils/color.h"  // color
#include <cassert>
#include <cerrno>
#include <cinttypes>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <stdexcept>
#include <sys/mman.h>
#include <sys/time.h>
#include <unistd.h>


#define TRACE_DIR "./trace/"

typedef uint16_t ioaddr_t;
typedef int (*eprintf_handle_t)(const char *fmt, va_list ap);
int eprintf(const char *fmt, ...);

// process sleep time
#define WAIT_INTERVAL 5  
// max number of checkpoint process at a time
#define SLOT_SIZE 2  

#define PAGE_SHIFT        12
#define PAGE_SIZE         (1ul << PAGE_SHIFT)
#define PAGE_MASK         (PAGE_SIZE - 1)

#define Info(...)           \
  do {                      \
    if (sim_verbose) {      \
      eprintf(__VA_ARGS__); \
    }                       \
  } while (0)

#define Assert(cond, ...)           \
  do {                              \
    if (!(cond)) {                  \
      fflush(stdout);               \
      fprintf(stderr, "\33[1;31m"); \
      fprintf(stderr, __VA_ARGS__); \
      fprintf(stderr, "\33[0m\n");  \
      assert(cond);                 \
    }                               \
  } while (0)

#define panic(...) Assert(0, __VA_ARGS__)

#define fprintf_with_pid(stream, ...)   \
  do {                                  \
    fprintf(stream, "(%d) ", getpid()); \
    fprintf(stream, __VA_ARGS__);       \
  } while (0)

#define printf_with_pid(...)               \
  do {                                     \
    fprintf_with_pid(stdout, __VA_ARGS__); \
  } while (0)

#define TODO() panic("please implement me")

#define Log(format, ...) \
    _Log(ANSI_FMT("[%s:%d %s] " format, ANSI_FG_BLUE) "\n", \
        __FILE__, __LINE__, __func__, ## __VA_ARGS__)

#define ARRLEN(arr) (int)(sizeof(arr) / sizeof(arr[0]))

#define FAIT_EXIT    exit(EXIT_FAILURE);

#endif
