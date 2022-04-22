CC = gcc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra -I

all: server client

server: server.o
	$(CC) $(CFLAGS) $< -o $@

client: client.o
	$(CC) $(CFLAGS) $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) *.o

fclean: clean
	$(RM) server client

re: fclean all

.PHONY: all clean fclean re
