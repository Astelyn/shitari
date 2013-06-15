CC = gcc
CFLAGS = -c -O3 -fomit-frame-pointer

all: shitari

shitari: main.o cpu.o mem.o tia.o
	$(CC) main.o cpu.o mem.o tia.o -o shitari

main.o: main.c
	$(CC) $(CFLAGS) -Imem -Icpu main.c

cpu.o: cpu/cpu.c
	$(CC) $(CFLAGS) -I. cpu/cpu.c

mem.o: mem/mem.c
	$(CC) $(CFLAGS) -I. mem/mem.c

tia.o: mem/tia.c
	$(CC) $(CFLAGS) -I. mem/tia.c

clean:
	rm -rf *.o

