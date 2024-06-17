CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -g
SOURCES = main.c opciones_agenda.c terminal.c
OBJECTS = $(SOURCES:.c=.o)

TARGET = agenda

.PHONY: clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(TARGET)


run : $(TARGET)
	./$(TARGET)