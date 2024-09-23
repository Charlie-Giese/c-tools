OFILES = random-pbm.o xmalloc.o
TARGET = random-pbm

CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -o2
$(TARGET) : $(OFILES)
			$(CC) $(OFILES) -o $@

clean:
	rm -f $(OFILES) $(TARGET)

random-pbm.o: random-pbm.c array.h xmalloc.h
xmalloc.o: xmalloc.c xmalloc.h