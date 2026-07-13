VSRC = $(wildcard vsrc/*.v)
CSRC = sim_main.cpp ./csrc/utils/state.cpp ./csrc/utils/dpi.cpp
VERILATOR = verilator
VCD_FILE = wave.vcd
JOBS = -j 4
CFLAGS += -g

all: 
	@echo "Write this Makefile by your self."

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "-- VERILATE & BUILD --------"
	$(VERILATOR) \
		--top-module top \
		--debug \
		-I./vsrc \
		-cc \
		--trace \
		$(VSRC) \
		--exe $(CSRC) \
		-CFLAGS "$(CFLAGS)" \
		--build $(JOBS) >/dev/null
	@echo "-- RUN SIMULATION --------"
	obj_dir/Vtop

gdb:
	gdb ./obj_dir/Vtop

wave:
	gtkwave $(VCD_FILE)

clean:
	-rm -rf obj_dir *.log *.vcd $(VCD_FILE)


-include ../Makefile
include $(NPC_HOME)/scripts/build.mk

.PHONY: all sim clean wave