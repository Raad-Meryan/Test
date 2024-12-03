SRCS	= ft_buffer.c ft_helpers.c ft_numUtils.c ft_parser.c \
		ft_printf.c ft_printingNum.c ft_renderStr.c \
		ft_renderChar.c ft_renderNum.c
		

OBJS		= $(SRCS:.c=.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
NAME		= ft_printf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean all re
