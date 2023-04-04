NAME	=	zoo

SRCS	=	main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp

OBJS	=	${SRCS:.cpp=.o}

CC		=	c++

FLAGS	=	-Wall -Werror -Wextra -std=c++98

RM		=	rm -rf

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${FLAGS} ${OBJS} -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re