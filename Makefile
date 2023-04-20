SRCS	=	ft_printf.c \
			ft_putaddrhex.c \
			ft_putnbr_base.c \
			ft_prints.c
OBJS	= ${SRCS:.c=.o}
HEADER	= ft_printf.h
NAME	= libftprintf.a
LIBFT	= ./libft/libft.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

%.o: %.c ${HEADER} ${LIBFT}
	${CC} ${CFLAGS} -c $< -o $@

all:	${NAME}

${NAME}: ${OBJS}
	make -C ./libft
	cp ${LIBFT} ${NAME}
	ar -rcs ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}
	make clean -C ./libft

fclean:	clean
	rm -f ${NAME}
	make fclean -C ./libft

re:	fclean all

.PHONY:	all clean fclean re bonus
