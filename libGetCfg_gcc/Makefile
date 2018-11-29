Q               := @
CC              := g++
SRCS            := ../src/lib_get_cfg.cpp
OBJS            := $(SRCS:.cpp=.o)
LIBS			:= 
TARGET          := lib_get_cfg.a
XINSTALL		:= ../../../factory/iPacker/$(TARGET)
XINSTALL_linux	:= ../example_makefile/$(TARGET)

CFLAGS          := -Wall -I ../src/include -std=c++11

LDFLAGS         += $(LIBS) 

.PHONY: all clean distclean

all: .depend $(TARGET)

%.o : %.cpp Makefile
	$(Q)echo "  Compiling '$<' ..."
	$(Q)$(CC) $(CFLAGS) -o $@ -c $<

$(TARGET): $(OBJS)
	$(Q)echo "  Building '$@', LIB name=$(TARGET) ..."
#	$(Q)$(CC) -shared -Wl, $(LIB_LINK) -o $@ $(OBJS) $(LDFLAGS)
#	gcc -shared -o DLL_file OBJ_files -Wl,--kill-at,--output-def,DEF_file
	$(Q)ar rcs $@ $(OBJS) $(LDFLAGS)
#	$(Q)strip $(TARGET)
	$(Q)echo "  Copy $(TARGET) to $(XINSTALL)  $(XINSTALL_linux)"
	$(Q)cp $(TARGET) $(XINSTALL)
	$(Q)cp $(TARGET) $(XINSTALL_linux)

	
clean distclean:
	$(Q)echo "  Cleaning '$(TARGET)' ..."
	$(Q)rm -rf .depend *~ $(OBJS) $(TARGET)	*.bak
	$(Q)rm -rf $(XINSTALL)/$(TARGET)

.depend dep depend:
	$(Q)echo "  Generating '$@' ..."
	$(Q)$(CC) $(CFLAGS) -M ../src/lib_get_cfg.cpp > $@

ifeq (.depend, $(wildcard .depend))
	include .depend
endif
