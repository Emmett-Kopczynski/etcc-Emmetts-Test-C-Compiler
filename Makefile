CC = gcc
CFLAGS = -g -Wall
OUT = etcc

#source Groups
SUTIL = NOTHING YET #util sources
SDRIVER = driver/driver_utils.c  driver/flag_table.c  driver/etcc_driver.c #driver sources
SCOMP = compiler/compiler.c #compiler sources
SLEX = compiler/lexer.c  compiler/token.c #lexer sources


#emmett compilers
ECC = etcc
ECFLAGS = NOTHING YET

#pushpath
PUSHPATH = ~/.local/bin/$(OUT)

#default command
default: build

#builds everything
build: 
	$(CC) $(CFLAGS) $(SDRIVER) $(SCOMP) $(SLEX) -o $(OUT)

#cleaners
c: clear
clear: clean
clean:
	rm $(OUT)


#builds, and pushes the most recent binaries into the local bin so that they can be executed from anywhere
push: build
	cp etcc $(PUSHPATH)

