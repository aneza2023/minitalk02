
NAME = libftprintf.a
SOURCES =	ft_printf.c\
			print_digit.c\
			print_format.c\
			print_lodig.c\
			print_char.c\
			print_pointer.c\
			print_string.c\
			print_unsigndig.c\
			print_uppdig.c\
			
OBJS = $(SOURCES:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra

all:$(NAME)

$(NAME):$(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
