CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
SRCSDIR		= ./srcs
SRCS		= ft_print.c
BSRUS		= 
OBJS		= $(notdir $(SRCS:.c=.o))
BOBJS		= $(notdir $(BSRUS:.c=.o))
INCLUDEDIR	= ./includes
NAME		= libftprintf.a

ifdef WITH_BONUS
	SRCS += $(BSRUS)
endif

all:			$(NAME)

clean:
				rm -f $(OBJS)
				rm -f $(BOBJS)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

$(NAME):		$(OBJS)
				ar rc $(NAME) $(OBJS)

bonus:			
				make WITH_BONUS=1
