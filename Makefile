CC = gcc
CFLAGS = -c -O3 -fomit-frame-pointer

all: shitari

shitari: main.o cpu.o mmu.o
	$(CC) main.o cpu.o mmu.o -o shitari

main.o: main.c
	$(CC) $(CFLAGS) main.c

cpu.o: cpu.c
	$(CC) $(CFLAGS) cpu.c

mmu.o: mmu.c
	$(CC) $(CFLAGS) mmu.c

clean:
	rm -rf *.o

