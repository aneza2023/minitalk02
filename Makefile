NAME_S = server
NAME_C = client
PRINTFLIB = libftprintf.a
SOURCES_S = 	server.c\
			add_func.c

SOURCES_C = client.c\
			add_func.c


OBJS_S = $(SOURCES_S:.c=.o)
OBJS_C = $(SOURCES_C:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

all:$(NAME_S) $(NAME_C)

$(NAME_S):$(OBJS_S)
	cc -o $(NAME_S) $(OBJS_S) $(PRINTFLIB)

$(NAME_C):$(OBJS_C)
	cc -o $(NAME_C) $(OBJS_C)

clean:
	rm -rf $(OBJS_S) $(OBJS_C)

fclean: clean
	rm -rf $(NAME_S) $(NAME_C)

re: fclean all