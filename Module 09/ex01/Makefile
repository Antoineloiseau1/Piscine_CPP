NAME	=	RPN	

SRCS	=	main.cpp RPN.cpp

HDRS	=	RPN.hpp

OBJS	=	${SRCS:.cpp=.o}

CC		=	c++ -std=c++98

FLAGS	=	-Wall -Werror -Wextra

RM		=	rm -rf

.cpp.o:
			${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

all:		${NAME}

${NAME}:	${HDRS} ${OBJS}
			${CC} ${FLAGS} ${OBJS} -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
