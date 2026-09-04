CC = gcc
CFLAGS = -g -Wall
OUT = etcc

#source Groups
SUTIL = NOTHING YET # util sources
SDRIVER = driver/driver_utils.c  driver/flag_table.c  driver/etcc_driver.c # driver sources
SCOMP = compiler/compiler.c compiler/token.c  # general compiler sources
SLEX = compiler/lexer/lexer.c  compiler/lexer/lexer_utils.c  # lexer sources
SPAR = compiler/parser/parser.c compiler/parser/parser_utils.c # parser sources
SGEN = compiler/codegen/codegen.c compiler/codegen/codegen_utils.c #codegen sources
SEMI = compiler/emission/emission.c compiler/emission/emission_utils.c #emission sources


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

