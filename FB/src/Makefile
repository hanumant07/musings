# Set compiler to use
CC=gcc
INC=../include
CFLAGS=-I$(INC)
ODIR=obj

_DEPS = recval.h debug.h
DEPS = $(patsubst %,$(INC)/%,$(_DEPS))

_OBJ = parser.o record_last_val.o record_max_val.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

parser: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o *~ core $(INC)/*~
	rm -f parser
