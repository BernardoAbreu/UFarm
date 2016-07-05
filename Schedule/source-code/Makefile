
# Let’s leave a place holder for additional include directories

INCLUDES =

# Compilation options:
# -g for debugging info and -Wall enables all warnings

CFLAGS   = -g -Wall $(INCLUDES)
CXXFLAGS = -g -Wall $(INCLUDES)

# Linking options:
# -g for debugging info

LDFLAGS = -g

# List the libraries you need to link with in LDLIBS
# For example, use "-lm" for the math library

LDLIBS = -lrf24


#schedule_system: schedule_system.o schedule.o valve_info.o reset.o time.o valve.o
test: test.o rfsignal.o
#schedule_system.o: schedule.h

#schedule.o: schedule.h valve_info.h

#valve_info.o:  valve_info.h valve.h reset.h time.h

#reset.o: reset.h time.h

#time.o: time.h

#valve.o: valve.h

rfsignal.o: rfsignal.h


.PHONY: clean
clean:
	rm -f *.o a.out core schedule_system

# "all" target is useful if your Makefile builds multiple programs.
# Here we’ll have it first do "clean", and rebuild the main target.

.PHONY: all
all: clean schedule_system