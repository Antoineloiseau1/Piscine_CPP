NAME	=	megaphone

SCRS	= 	megaphone.cpp

OBJS	=	${SRCS:.cpp=.o}

CC		=	c++

FLAGS	=	-std=c++98 -Wall -Werror -Wextra


all:		${NAME}

{NAME}:		${OBJS}
			${CC} ${FLAGS} ${OBJS} -o ${NAME}

clean:
			rm -rf ${OBJS}

fclean:		clean
			rm -rf ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

