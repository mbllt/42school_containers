#-------------- NAME-----------------
NAME=			containers
#------------------------------------


#-------------- SRCS-----------------
SRCS=			main.cpp
#------------------------------------


#-------------- OBJS-----------------
OBJS_DIR=		.objs
OBJS=			$(addprefix $(OBJS_DIR)/,$(SRCS:.cpp=.o))
#------------------------------------


#-------------- COMPILER-------------
CC=				c++
FLAGS=			-Wall -Werror -Wextra  -std=c++98 -Ivector/
#------------------------------------


#-------------- INCS-----------------
INC_VEC=		vector
INC_FILES=		Vector.hpp
INCLUDES=		$(addprefix $(INC_VEC)/,$(INC_FILES))
#------------------------------------


#-------------- RM-------------------
RM=				/bin/rm -rf
#------------------------------------


all:		$(NAME)

$(NAME):	$(OBJS)
					@echo "$(GREEN)$(BOLD)Linking$(END) $(GREEN)$(NAME)$(END)"
					$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o:	%.cpp $(INCLUDES) | $(OBJS_DIR)
					@echo "$(GREEN)$(BOLD)Compiling$(END) $(GREEN)$<$(END)"
					$(CC) $(FLAGS) -o $@ -c $<

$(OBJS_DIR):
					@mkdir -p $(OBJS_DIR)

clean:
					@echo "$(GREEN)$(BOLD)Deleting$(END) $(GREEN)object files$(END)"
					@$(RM) $(OBJS)

fclean:		clean
					@echo "$(GREEN)$(BOLD)Deleting$(END) $(GREEN)executable, objs_dir$(END)"
					@$(RM) $(NAME)
					@$(RM) $(OBJS_DIR)

re:			fclean all

.PHONY:		all clean fclean re

#-----------------------COLORS-----------------------
GREEN	= \033[32m
END		= \033[0m
BOLD	= \033[1m
#----------------------------------------------------