NAME	=	PhoneBook

SRCS	=	main.cpp ./Classes/PhoneBook.cpp ./Classes/Contact.cpp

OBJS	=	${SRCS:.cpp=.o}

CC		= 	c++

FLAGS	= 	-Wall -Werror -Wextra -std=c++98

RM		= 	rm -rf

.cpp.o:
			${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${FLAGS} ${OBJS} -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all re fclean clean