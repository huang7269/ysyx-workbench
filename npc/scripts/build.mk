WORK_DIR = $(shell pwd)

INC_PATH := $(WORK_DIR)/include $(INC_PATH)

INCLUDES = $(addprefix -I, $(INC_PATH))
CFLAGS  := -O2 -MMD -Wall -Werror $(INCLUDES) $(CFLAGS)
