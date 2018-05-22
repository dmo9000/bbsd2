CPP=g++
#CPPFLAGS=-std=c++14 -g -ggdb 
CPPFLAGS=-std=c++14 
OBJECTS=object.o thread.o netthread.o acceptthread.o echothread.o bbsd.o
LDFLAGS=-pthread
HEADERS := $(shell ls -1 *.h)

all: bbsd

bbsd: $(OBJECTS) 
	$(CPP) $(LDFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f bbsd $(OBJECTS)
