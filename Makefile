CC = gcc
CFLAGS = -g -wall

ECC = NOTHING YET
ECFLAGS = NOTHING YET

PUSHPATH = ~/.local/bin/


default: build


build:


#builds, and pushes the most recent binaries into the local bin so that they can be executed from anywhere
push: build
	#TODO write the push function in the makefile

