#include "common.h"
#include "utils/sdb.h"
#include "main.h"

int main(int argc, char *argv[]) {
		printf("Command \n");
  	for (int i = 0; i < argc; i++)
  	{
    	printf(ANSI_FG_BLUE "arg %d: %s\n" ANSI_NONE,i,argv[i]);
  	}

		init_monitor(argc, argv);

		engine_start();

		return is_exit_status_bad();
}
