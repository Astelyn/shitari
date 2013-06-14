CC = gcc
CFLAGS = -c -O3 -fomit-frame-pointer

all: shitari

shitari: main.o cpu.o rom.o
	$(CC) main.o cpu.o rom.o -o shitari

main.o: main.c
	$(CC) $(CFLAGS) -Irom -Icpu main.c

cpu.o: cpu/cpu.c
	$(CC) $(CFLAGS) -I. cpu/cpu.c

rom.o: rom/rom.c
	$(CC) $(CFLAGS) -I. rom/rom.c

clean:
	rm -rf *.o

