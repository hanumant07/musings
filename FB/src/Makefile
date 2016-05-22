# Check env variable
ifneq ($(PARSER_ENV_SETUP),DONE)
$(error Environment not setup. Please read usage instruction in README.txt)
endif

# Set variables to use
CC=gcc
INC=../include
CFLAGS=-I$(INC)
ODIR=obj
BINDIR=../tests/
INSTALL= mv

_DEPS = recval.h debug.h
DEPS = $(patsubst %,$(INC)/%,$(_DEPS))

ifeq ($(TOOL),test)
CFLAGS += -DTEST
endif

ifeq ($(TOOL),test)
_OBJ = test_parser.o record_max_val.o
else
_OBJ = parser.o record_last_val.o record_max_val.o
endif

OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ifneq ($(TOOL),test)
parser: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
else
test_parser: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
endif

.PHONY: install

ifneq ($(TOOL),test)
install : parser
else
install :  test_parser
	$(INSTALL) $^ $(BINDIR)
endif

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o *~ core $(INC)/*~
	rm -f $(BINDIR)test_parser
