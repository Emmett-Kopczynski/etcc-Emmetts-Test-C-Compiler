CC = gcc
CFLAGS = -g -Wall
OUT = etcc

default: build


build:
	$(CC) $(CFLAGS) driver_utils.c flag_table.c etcc_driver.c -o $(OUT)

c: clear
clear: clean
clean:
	rm etcc

push: build
	cp $(OUT) ~/.local/bin/$(OUT)

