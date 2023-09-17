default: writer.o
	$(CROSS_COMPILE)gcc writer.o -o writer
writer.o:
	$(CROSS_COMPILE)gcc -c writer.c
.PHONY: clean
clean:
	rm -f writer.o writer

