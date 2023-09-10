default: writer.o
	$(CROSS-COMPILE)gcc writer.o -o writer
writer.o:
	$(CROSS-COMPILE)gcc -c writer.c
.PHONY: clean
clean:
	rm -f writer.o writer

