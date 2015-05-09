#Originally from: http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
#But will be heavily modified
IDIR =../include
CC=g++
CFLAGS=-w -I$(IDIR)

#ODIR=obj
LDIR =../lib

LIBS=-lSDL2

_DEPS = sdl_class.h SDL_image.h 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

OBJ = sdl_class.o tests.o 
#OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


%.o: %.cpp $(DEPS)
	@echo "in o"
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

tests: sdl_class.o tests.o
	@echo "in tests"
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

all: $(OBJ)
	@echo "in all"
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *.o *~ core $(IDIR)/*~ 
