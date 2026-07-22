CC = gcc
CFLAGS = -g -Wall

#header groups
HUTIL = util/*.h

#source Groups
SUTIL = util/*.c

#emmett compilers
ECC = NOTHING YET
ECFLAGS = NOTHING YET

#pushpath
PUSHPATH = ~/.local/bin/


default: bdriver

#builds the driver
bdriver:
	$(CC) $(CFLAGS) driver/etcc_driver.c -o etcc

#builds the compiler
bcompiler:

#builds everything
build: driver compiler

#cleaners
c: clear
clear: clean
clean:
	rm etcc


#builds, and pushes the most recent binaries into the local bin so that they can be executed from anywhere
push: build
	#TODO write the push function in the makefile


