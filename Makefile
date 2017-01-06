ifeq ($(OS),LINUX)
	CROSS_COMPILE=
	CROSS_COMPILE32=
endif
ifeq ($(OS), WIN32)
	CROSS_COMPILE=i686-w64-mingw32-
	CROSS_COMPILE32=i686-w64-mingw32-
else
	CROSS_COMPILE=x86_64-w64-mingw32-
	CROSS_COMPILE32=i686-w64-mingw32-
endif
export CXX=$(CROSS_COMPILE)g++
export GCC=$(CROSS_COMPILE)gcc
export CXX32=$(CORSS_COMPILE32)g++
export GCC32=$(CORSS_COMPILE32)gcc

PROGRAM=ts3-topic-as-date.dll
CPPFLAG= -Wall --std=c++11 -Ipluginsdk/include -static-libstdc++ -static-libgcc

obj/%.o :
	@echo "-Compile" $@
	@$(CXX) -c -Wall -o $@ $(CPPFLAG) $<

all: obj $(PROGRAM)
obj:
	mkdir -p obj

OBJS=main export date

OBJECTS=$(patsubst %,obj/%.o,$(OBJS))

obj/date.o: src/date.cpp
obj/main.o: src/main.cpp
obj/export.o: src/export.cpp src/export.hpp src/main.hpp
$(PROGRAM): $(OBJECTS)
	@echo "============ Compile" $@ "=============="
	@$(CXX) $^ -fPIC -shared -o $@ $(CPPFLAG)
	
clean:
	@(rm obj/* || true)
	@(rm $(PROGRAM) || true)