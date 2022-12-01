CC = gcc
FLAGS = -Wall
TARGET = test
SRCS = main.c register.c print.c library.c decorder.c decorder.c alu.c fpu.c grad_list.c error.c read.c log.c exec.c
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) -c $(SRCS)

all: clean $(OBJS) $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)