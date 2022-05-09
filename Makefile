TARGET = schedule
DTARGET = schedule_debug
OBJECTS = main.c schedule.o manager.o saveload.o
CFLAGS = -W -Wall
CC = gcc

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(DTARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^

clean :
	rm *.o $(TARGET) $(DTARGET)