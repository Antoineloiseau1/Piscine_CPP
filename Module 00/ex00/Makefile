NAME	=	megaphone

SRCS	= 	megaphone.cpp

OBJS	=	${SRCS:.cpp=.o}

CC		=	c++

FLAGS	=	-std=c++98 -Wall -Werror -Wextra

.cpp.o:
			${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

all:		${NAME}

{NAME}:		${OBJS}
			${CC} ${FLAGS} ${OBJS} -o ${NAME}

clean:
			rm -rf ${OBJS}

fclean:		clean
			rm -rf ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

