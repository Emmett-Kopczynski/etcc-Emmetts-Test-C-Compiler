CC = gcc
CFLAGS = -g -Wall


default: build


build:
	$(CC) $(CFLAGS) driver_utils.c flag_table.c etcc_driver.c -o etcc

c: clear
clear: clean
clean:
	rm etcc


