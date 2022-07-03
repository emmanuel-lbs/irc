##############################  SOURCE & OBJETS  ###############################

SRCS =	srcs/main.cpp \
		srcs/socket.cpp\
		srcs/server.cpp

INCLUDE =  includes/include.hpp

OBJS = $(SRCS:.cpp=.o)

################################  VARIABLES  ###################################

NAME = IRC

RM = rm -f

CC = c++

GCCF = $(CC) -Wall -Wextra -Werror -std=c++98 -I includes/

##################################  RULES  #####################################

all :	$(NAME)

$(NAME):	$(INCLUDE) $(OBJS) 
	$(GCCF) $(OBJS) -o $(NAME)

%.o:	%.cpp $(INCLUDE) 
	${GCCF} -c $< -o $@ 

############################  CLEAN & RE & phony  ##############################

clean:
	${RM} ${OBJS} 

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
	#################################### FIN  ######################################
