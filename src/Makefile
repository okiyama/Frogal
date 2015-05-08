#Originally from: http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
#But will be heavily modified
IDIR =../include
CC=g++
CFLAGS=-w -I$(IDIR)

#ODIR=obj
LDIR =../lib

LIBS=-lSDL2

_DEPS = sdl_class.h 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

OBJ = sdl_class.o tests.o 
#OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

tests: tests.o
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

all: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *.o *~ core $(INCDIR)/*~ 
