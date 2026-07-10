VSRC = $(wildcard vsrc/*.v)
VERILATOR = verilator
VCD_FILE = wave.vcd

all:
	@echo "Write this Makefile by your self."

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!

	@echo "-- VERILATE & BUILD --------"
	$(VERILATOR) -I./vsrc -cc $(VSRC) --exe --build -j sim_main.cpp --trace
	@echo "-- RUN ---------------------"
	obj_dir/Vtop

wave:
	gtkwave $(VCD_FILE)

clean:
	-rm -rf obj_dir *.log $(VCD_FILE)

include ../Makefile

.PHONY:all sim clean wave