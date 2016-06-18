
# Set variables to use
CC=g++
CFLAGS=-std=c++11
ODIR=obj
_OBJ = parser.o

OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

parser: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o *~ core $(INC)/*~
	rm -f parser
