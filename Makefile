VERSION = 0.02
CFLAGS  = -Wall # -g -D_REENTRANT -DVERSION=\"$(VERSION)\"
LDFLAGS = -lm
OUT = $(shell uname -m)

CC      = /usr/bin/g++




OBJ = linux_ecmg.o irdeto_core.o parser_long.o 

all: $(OBJ)
	$(CC) $(CFLAGS) -o irdeto-ecmg.$(OUT) $(OBJ) $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o *.$(OUT)