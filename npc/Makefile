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
REGRESS_NAME ?= regression_mem_branch
REGRESS_STEM := $(NPC_HOME)/bin/$(REGRESS_NAME)
REGRESS_ASM  := $(REGRESS_STEM).S
REGRESS_BIN  := $(REGRESS_STEM).bin

VERILATOR_FLAGS += -cc --exe --build -MMD --trace --trace-fst
VERILATOR_FLAGS += -x-assign fast
#VERILATOR_FLAGS += --timescale "1ns/1ns" --no-timing
VERILATOR_FLAGS += --top-module $(TOP_MODULE)\
                   -I$(NPC_HOME)/vsrc

VERILATOR_JOBS :=
ifneq ($(filter -j,$(MAKEFLAGS)),)
VERILATOR_JOBS := 0
else ifneq ($(filter -j%,$(MAKEFLAGS)),)
VERILATOR_JOBS := $(patsubst -j%,%,$(firstword $(filter -j%,$(MAKEFLAGS))))
endif

ifneq ($(VERILATOR_JOBS),)
VERILATOR_FLAGS += -j $(VERILATOR_JOBS)
endif


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
CONFIG_DIFFTEST = $(shell grep -q "CONFIG_DIFFTEST 1" $(NPC_HOME)/csrc/include/config/config.h && echo 1 || echo 0)
TRACE_NEED = $(shell [ $(CONFIG_FTRACE) -eq 1 -o $(CONFIG_ETRACE) -eq 1 -o $(CONFIG_MTRACE) -eq 1 ] && echo 1 || echo 0)

RUN_ARGS :=

ifeq ($(TRACE_NEED),1)
TRACE_DIR = $(NPC_HOME)/trace
$(shell mkdir -p $(TRACE_DIR))
endif

ifeq ($(CONFIG_DIFFTEST),1)
RUN_ARGS += -d $(NEMU_HOME)/build/riscv32-nemu-interpreter-so
endif

ifeq ($(CONFIG_FTRACE),1)
RUN_ARGS += -f $(NPC_HOME)/bin/microbench-riscv32e-npc.elf
endif

# Trace
IMG  ?=  $(NPC_HOME)/bin/string-riscv32e-npc.bin
ARGC ?= ${IMG}

default: run

.PHONY: default run regress config gdb wave clean

run: obj_dir/V$(TOP_MODULE)
	@echo "-- RUNNING  ---------------"
	${NPC_EXEC} ${RUN_ARGS} ${ARGS} ${ARGC}
	@echo "-- DONE --------------------"

regress: obj_dir/V$(TOP_MODULE) $(REGRESS_BIN)
	@echo "-- REGRESSION -------------"
	${NPC_EXEC} -b $(REGRESS_BIN)
	@echo "-- DONE --------------------"

config:
	python3 $(NPC_HOME)/csrc/include/config/config_cli.py

gdb:CXXFLAGS += -ggdb3
gdb:CFLAGS   += -ggdb3
gdb: 
	@echo "-- RUNNING (GDB DEBUG MODE) ---------------"
	gdb --args ${NPC_EXEC} ${RUN_ARGS} ${ARGS} ${ARGC}

wave:
	gtkwave wave.fst

obj_dir/V$(TOP_MODULE): $(CXX_SRC) $(V_SRC)
	@echo "-- VERILATE ---------------"
	$(VERILATOR) $(VERILATOR_FLAGS) $(CXX_SRC) $(V_SRC) --CFLAGS "$(CXXFLAGS)" --LDFLAGS "$(LIBS)"

$(REGRESS_BIN): $(REGRESS_ASM) $(NPC_HOME)/bin/huibian.sh
	@echo "-- ASSEMBLE $(REGRESS_NAME) -------"
	@bash $(NPC_HOME)/bin/huibian.sh $(REGRESS_ASM) > /dev/null

clean: 
	rm -r  $(OBJ_DIR) 
	rm -f $(REGRESS_STEM).bin $(REGRESS_STEM).elf $(REGRESS_STEM).txt
	@if [ $(TRACE_NEED) -eq 1 ]; then \
		rm -rf $(TRACE_DIR); \
	fi
