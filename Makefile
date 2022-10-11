CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I.
SRCSDIR		= ./srcs
SRCS		= ft_printf.c ft_itoa.c ft_put_fd.c ft_strdup.c
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
