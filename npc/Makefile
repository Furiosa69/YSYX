ifeq ($(VERILATOR_ROOT),)
VERILATOR = verilator
VERILATOR_COVERAGE = verilator_coverage
else
export VERILATOR_ROOT
VERILATOR = $(VERILATOR_ROOT)/bin/verilator
VERILATOR_COVERAGE = $(VERILATOR_ROOT)/bin/verilator_coverage
endif

TOP_MODULE := ysyx_24080018
OBJ_DIR := $(NPC_HOME)/obj_dir

VERILATOR_FLAGS += -cc --exe --build -MMD --trace --trace-fst
VERILATOR_FLAGS += -x-assign fast
#VERILATOR_FLAGS += --timescale "1ns/1ns" --no-timing
VERILATOR_FLAGS += --top-module $(TOP_MODULE)\
                   -I$(NPC_HOME)/vsrc


CXXFLAGS += -DTOP_NAME="\"V$(TOP_MODULE)\""\
						-DTOP_ROOT="\"V$(TOP_MODULE)___024root\""\
						-DTOP_DPI="\"V$(TOP_MODULE)__Dpi\""
CXXFLAGS += -g $(shell llvm-config --cxxflags | sed 's/-D__STDC_[A-Z_]*//g') -fPIE \
            -I$(NPC_HOME)/csrc/include \
            -I$(NPC_HOME)/csrc/mem \
            -I$(NPC_HOME)/csrc/sim \
            -I/usr/local/share/verilator/include
CFLAGS += -Wall -O0 -I$(NPC_HOME)/csrc
CXX_SRC := $(shell find $(NPC_HOME)/csrc -name "*.cpp" -o -name "*.c")

LIBS += $(shell llvm-config --libs all) -lpthread -lrt -ldl -latomic -ledit -lSDL2

V_SRC   += $(shell find $(NPC_HOME)/vsrc -name "*.v") 

BIN      := $(OBJ_DIR)/V$(TOP_MODULE)
NPC_EXEC := ${BIN}

CONFIG_FTRACE = $(shell grep -q "CONFIG_FTRACE 1" $(NPC_HOME)/csrc/include/config/config.h && echo 1 || echo 0)
CONFIG_ETRACE = $(shell grep -q "CONFIG_ETRACE 1" $(NPC_HOME)/csrc/include/config/config.h && echo 1 || echo 0)
CONFIG_MTRACE = $(shell grep -q "CONFIG_MTRACE 1" $(NPC_HOME)/csrc/include/config/config.h && echo 1 || echo 0)
TRACE_NEED = $(shell [ $(CONFIG_FTRACE) -eq 1 -o $(CONFIG_ETRACE) -eq 1 -o $(CONFIG_MTRACE) -eq 1 ] && echo 1 || echo 0)

ifeq ($(TRACE_NEED),1)
TRACE_DIR = $(NPC_HOME)/trace
$(shell mkdir -p $(TRACE_DIR))
endif

# Trace
IMG  ?=  $(NPC_HOME)/bin/dummy-riscv32e-npc.bin
#ARGS += -d $(NEMU_HOME)/build/riscv32-nemu-interpreter-so
#ARGS += -f $(NPC_HOME)/bin/microbench-riscv32e-npc.elf
ARGC ?= ${IMG}

default: run

run: obj_dir/V$(TOP_MODULE)
	@echo "-- RUNNING  ---------------"
	${NPC_EXEC} ${ARGS} ${ARGC}
	@echo "-- DONE --------------------"

config:
	python3 $(NPC_HOME)/csrc/include/config/config_cli.py

gdb:CXXFLAGS += -ggdb3
gdb:CFLAGS   += -ggdb3
gdb: 
	@echo "-- RUNNING (GDB DEBUG MODE) ---------------"
	gdb --args ${NPC_EXEC} ${ARGS} ${ARGC}

wave:
	gtkwave wave.fst

obj_dir/V$(TOP_MODULE): $(CXX_SRC) $(V_SRC)
	@echo "-- VERILATE ---------------"
	$(VERILATOR) $(VERILATOR_FLAGS) $(CXX_SRC) $(V_SRC) --CFLAGS "$(CXXFLAGS)" --LDFLAGS "$(LIBS)"
	$(MAKE) -C obj_dir -f V$(TOP_MODULE).mk LDLIBS="$(LDLIBS)"

clean: 
	rm -r  $(OBJ_DIR) 
	@if [ $(TRACE_NEED) -eq 1 ]; then \
		rm -rf $(TRACE_DIR); \
	fi
