NAME	=	intern

SRCS	=	main.cpp Bureaucrat.cpp AForm.cpp ShrubberryCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

OBJS	=	${SRCS:.cpp=.o}

CC		=	c++ -std=c++98

FLAGS	=	-Wall -Werror -Wextra

RM		=	rm -rf

.cpp.o:
			${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${FLAGS} ${OBJS} -o ${NAME}

clean:
			${RM} ${OBJS} *_shrubberry

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re