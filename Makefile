CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I.
SRCSDIR		= ./srcs
SRCS		= ft_printf.c ft_itoa_base.c ft_libft.c ft_convert_numtostr.c ft_printf_sub.c ft_printf_convert.c
OBJS		= $(notdir $(SRCS:.c=.o))
BOBJS		= $(notdir $(BSRUS:.c=.o))
INCLUDEDIR	= ./includes
NAME		= libftprintf.a

all:			$(NAME)

clean:
				rm -f $(OBJS)
				rm -f $(BOBJS)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

$(NAME):		$(OBJS)
				ar rc $(NAME) $(OBJS)

bonus:			$(NAME)