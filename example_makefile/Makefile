Q               := @
CC              := g++
SRCS            := $(wildcard *.cpp)
OBJS            := $(SRCS:.cpp=.o)
TARGET          := iPacker_mk_exp.exe
LIBS			:= lib_get_cfg.a

CFLAGS          += -Wall -I ../src/include
LDFLAGS			+= $(LIBS)

.PHONY: all clean distclean

all: .depend $(TARGET) 

%.o: %.cpp Makefile
	$(Q)echo "  Compiling '$<' ..."
	$(Q)$(CC) $(CFLAGS) -o $@ -c $<

$(TARGET): $(OBJS)
	$(Q)echo "  Building $(LIBS) ..."
	$(Q)make -C ../libGetCfg_gcc/
	$(Q)echo "  Building '$@' ..."
	$(Q)$(CC) -o $@ $(OBJS) $(LDFLAGS) 
	$(Q)strip $(TARGET)
	
clean distclean: 
	$(Q)echo "  Cleaning '$(TARGET)' ..."
	$(Q)rm -f .depend *~ $(OBJS) $(TARGET) *.bak *.res

.depend dep depend:
	$(Q)echo "  Generating '$@' ..."
	$(Q)$(CC) $(CFLAGS) -M *.cpp > $@

ifeq (.depend, $(wildcard .depend))
    include .depend
endif

