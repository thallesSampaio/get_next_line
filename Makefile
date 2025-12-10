CC = cc

RM = rm -f
AR = ar -rcs
RUN = valgrind --leak-check=full ./a.out

CFLAGS = -Wall -Wextra -Werror

SRCS = get_next_line.c \
	   get_next_line_utils.c

clean:
	$(RM) a.out

test:
	$(CC) $(CFLAGS) main.c $(SRCS)
	$(RUN)

.PHONY: clean
