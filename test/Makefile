NAME	=	test

SCRS	=	test.cpp Sample.cpp

OBJS	= 	${SCRS:.cpp=.o}

CC		= 	c++

FLAGS	= 	-Wall -Werror -Wextra -std=c++98

RM		= 	rm -rf

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${FLAGS} ${OBJS} -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all re fclean clean