CC = gcc
FLAGS = -Wall
TARGET = test
SRCS = main.c library.c print.c register.c decorder.c alu.c grad_list.c error.c read.c exec.c log.c
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

all: clean $(OBJS) $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)