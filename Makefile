NAME_S = server
NAME_C = client
PRINTFLIB = ft_printf/libftprintf.a
SOURCES_S = 	server.c\
			add_func.c

SOURCES_C = client.c\
			add_func.c


OBJS_S = $(SOURCES_S:.c=.o)
OBJS_C = $(SOURCES_C:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

all:$(NAME_S) $(NAME_C)

$(PRINTFLIB):
	make -C ft_printf

$(NAME_S):$(OBJS_S) $(PRINTFLIB)
	cc -o $(NAME_S) $(OBJS_S) $(PRINTFLIB)

$(NAME_C):$(OBJS_C)
	cc -o $(NAME_C) $(OBJS_C)

clean:
	rm -rf $(OBJS_S) $(OBJS_C)
	make clean -C ft_printf

fclean: clean
	rm -rf $(NAME_S) $(NAME_C)
	make fclean -C ft_printf

re: fclean all