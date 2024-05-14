IDIR=../include
ODIR=obj
LOGDIR=../logs

CC=gcc -g -O0 -DDEBUG=0
CFLAGS=-I$(IDIR)

_DEPS = binaryTree.h node.h 
DEPS = $(patsubst %, $(IDIR)/%,$(_DEPS))

_OBJ = binaryTree.o node.o
OBJ = $(patsubst %, $(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

redBlack: main.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

tests : mainTests.o $(OBJ) 
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean all

all : redBlack tests

clean:
	rm -f $(ODIR)/*.o $(LOGDIR)/*.log main.o mainTests.o redBlack tests
