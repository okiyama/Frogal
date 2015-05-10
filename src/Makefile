#Originally from: http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
#But will be heavily modified
IDIR =../include
CXX=g++
CXXFLAGS= 
CPPFLAGS=-Wall -I$(IDIR) -std=c++11

#ODIR=obj
LDIR =../lib
LDFLAGS=-L$(LDIR)

LDLIBS=-lSDL2 -lSDL2_image

_DEPS = sdl_class.h 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

OBJ = sdl_class.o tests.o 
#OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS) $(CPPFLAGS) 

sdl_class.o tests.o: $(DEPS)

debug: CXXFLAGS += -g
debug: LDFLAGS += -g
debug: all

all: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS)  $(LDLIBS)

.PHONY: clean

clean:
	rm -f *.o *~ core $(IDIR)/*~ 
