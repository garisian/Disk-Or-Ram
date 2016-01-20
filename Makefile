HEADERS = structures.h

default: disk_ram

disk_ram.o: disk_ram.c $(HEADERS)
	gcc -c disk_ram.c -o disk_ram.o

disk_ram: disk_ram.o
	gcc disk_ram.o -o disk_ram

clean:
	-rm -f disk_ram.o
	-rm -f disk_ram 
