# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Makefile for building Verilated archive or executable
#
# Execute this makefile from the object directory:
#    make -f Vysyx_24080018.mk

default: Vysyx_24080018

### Constants...
# Perl executable (from $PERL, defaults to 'perl' if not set)
PERL = perl
# Python3 executable (from $PYTHON3, defaults to 'python3' if not set)
PYTHON3 = python3
# Path to Verilator kit (from $VERILATOR_ROOT)
VERILATOR_ROOT = /usr/local/share/verilator
# SystemC include directory with systemc.h (from $SYSTEMC_INCLUDE)
SYSTEMC_INCLUDE ?=
# SystemC library directory with libsystemc.a (from $SYSTEMC_LIBDIR)
SYSTEMC_LIBDIR ?=

### Switches...
# C++ code coverage  0/1 (from --prof-c)
VM_PROFC = 0
# SystemC output mode?  0/1 (from --sc)
VM_SC = 0
# Legacy or SystemC output mode?  0/1 (from --sc)
VM_SP_OR_SC = $(VM_SC)
# Deprecated
VM_PCLI = 1
# Deprecated: SystemC architecture to find link library path (from $SYSTEMC_ARCH)
VM_SC_TARGET_ARCH = linux

### Vars...
# Design prefix (from --prefix)
VM_PREFIX = Vysyx_24080018
# Module prefix (from --prefix)
VM_MODPREFIX = Vysyx_24080018
# User CFLAGS (from -CFLAGS on Verilator command line)
VM_USER_CFLAGS = \
  -DTOP_NAME="Vysyx_24080018" -DTOP_ROOT="Vysyx_24080018___024root" -DTOP_DPI="Vysyx_24080018__Dpi" -g -I/usr/include -std=c++17   -fno-exceptions -funwind-tables -D_GNU_SOURCE -DEXPERIMENTAL_KEY_INSTRUCTIONS    -fPIE -I/home/furiosa/Projects/MyCode/ysyx-workbench/npc/csrc/include -I/home/furiosa/Projects/MyCode/ysyx-workbench/npc/csrc/mem -I/home/furiosa/Projects/MyCode/ysyx-workbench/npc/csrc/sim -I/usr/local/share/verilator/include \

# User LDLIBS (from -LDFLAGS on Verilator command line)
VM_USER_LDLIBS = \
  -lz \
  -lLLVM-21 -lpthread -lrt -ldl -latomic -ledit -lSDL2 \

# User .cpp files (from .cpp's on Verilator command line)
VM_USER_CLASSES = \
  lightsss \
  main \
  memory \
  sim \
  debug \
  disasm \
  dut \
  ftrace \
  iring \
  reg \
  expr \
  sdb \
  watchpoint \

# User .cpp directories (from .cpp's on Verilator command line)
VM_USER_DIR = \
  .. \
  ../csrc \
  ../csrc/mem \
  ../csrc/sim \
  ../csrc/utils \
  ../csrc/utils/sdb \

### Default rules...
# Include list of all generated classes
include Vysyx_24080018_classes.mk
# Include global rules
include $(VERILATOR_ROOT)/include/verilated.mk

### Executable rules... (from --exe)
VPATH += $(VM_USER_DIR)

lightsss.o: /home/furiosa/Projects/MyCode/ysyx-workbench/npc/csrc/lightsss.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
main.o: /home/furiosa/Projects/MyCode/ysyx-workbench/npc/csrc/main.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
memory.o: /home/furiosa/Projects/MyCode/ysyx-workbench/npc/csrc/mem/memory.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
sim.o: /home/furiosa/Projects/MyCode/ysyx-workbench/npc/csrc/sim/sim.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
debug.o: /home/furiosa/Projects/MyCode/ysyx-workbench/npc/csrc/utils/debug.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
disasm.o: /home/furiosa/Projects/MyCode/ysyx-workbench/npc/csrc/utils/disasm.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
dut.o: /home/furiosa/Projects/MyCode/ysyx-workbench/npc/csrc/utils/dut.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
ftrace.o: /home/furiosa/Projects/MyCode/ysyx-workbench/npc/csrc/utils/ftrace.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
iring.o: /home/furiosa/Projects/MyCode/ysyx-workbench/npc/csrc/utils/iring.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
reg.o: /home/furiosa/Projects/MyCode/ysyx-workbench/npc/csrc/utils/reg.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
expr.o: /home/furiosa/Projects/MyCode/ysyx-workbench/npc/csrc/utils/sdb/expr.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
sdb.o: /home/furiosa/Projects/MyCode/ysyx-workbench/npc/csrc/utils/sdb/sdb.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
watchpoint.o: /home/furiosa/Projects/MyCode/ysyx-workbench/npc/csrc/utils/sdb/watchpoint.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<

### Link rules... (from --exe)
Vysyx_24080018: $(VK_USER_OBJS) $(VK_GLOBAL_OBJS) $(VM_PREFIX)__ALL.a
	$(LINK) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) $(LIBS) $(SC_LIBS) -o $@

# Verilated -*- Makefile -*-
