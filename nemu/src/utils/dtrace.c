#include <utils.h>
#include <device/map.h>

FILE *dtrace_file = NULL;

void init_dtrace() {
  const char *nemu_home = getenv("NEMU_HOME");
  char dtrace_path[64];
  snprintf(dtrace_path,sizeof(dtrace_path),"%s/build/dtrace",nemu_home);
  dtrace_file = fopen(dtrace_path,"a");
}
