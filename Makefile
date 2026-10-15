CC = gcc
CFLAGS = -g -Wall
OUT = etcc

#source Groups
SUTIL = NOTHING YET # util sources
SDRIVER = src/driver/driver_utils.c  src/driver/flag_table.c  src/driver/main.c # driver sources
SCOMP = src/compiler.c src/token.c  # general compiler sources
SLEX = src/lexer/lexer.c  src/lexer/lexer_utils.c  # lexer sources
SPAR = src/parser/parser.c src/parser/parser_utils.c # parser sources
SGEN = src/codegen/codegen.c src/codegen/codegen_utils.c #codegen sources
SEMI = src/emission/emission.c src/emission/emission_utils.c #emission sources


#emmett compilers
ECC = etcc
ECFLAGS = NOTHING YET

#pushpath
PUSHPATH = ~/.local/bin/$(OUT)

#default command
default: build

#builds everything
build: 
	$(CC) $(CFLAGS) $(SDRIVER) $(SCOMP) $(SLEX) $(SAST) $(SPAR) $(SGEN) $(SEMI) -o bin/$(OUT)

#cleaners
c: clear
clear: clean
clean:
	rm bin/$(OUT)


#builds, and pushes the most recent binaries into the local bin so that they can be executed from anywhere
push: build
	cp bin/$(OUT) $(PUSHPATH)

