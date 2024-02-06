IDIR=../include
ODIR=obj

CC=gcc
CFLAGS=-I$(IDIR)

_DEPS = binaryTree.h
DEPS = $(patsubst %, $(IDIR)/%,$(_DEPS))

_OBJ = main.o binaryTree.o
OBJ = $(patsubst %, $(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

redBlack: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o redBlack
