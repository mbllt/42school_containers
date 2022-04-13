#------------- NAME -----------------
NAME=			containers
#------------------------------------


#------------- SRCS -----------------
SRCS_DIR=		tests
SRCS_FILES=		main.cpp\
				vectorTest.cpp
SRCS=			$(addprefix $(SRCS_DIR)/,$(SRCS_FILES))
# SRCS=			main.cpp\
				vectorTest.cpp
#------------------------------------


#-------------- OBJS ----------------
OBJS_DIR=		.objs
OBJS=			$(addprefix $(OBJS_DIR)/,$(SRCS:.cpp=.o))
#------------------------------------


#------------- COMPILER -------------
CC=				c++
FLAGS=			-Wall -Werror -Wextra -std=c++98
#------------------------------------


#------------- INCS -----------------
INCLUDES=		-Ivector/ -Iiterator/ -Itests/
#------------------------------------


#-------------- RM ------------------
RM=				/bin/rm -rf
#------------------------------------


ifeq ($(SAN), 1)
FLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address -g3
endif


all:		$(NAME)

$(NAME):	$(OBJS)
					@echo "$(GREEN)$(BOLD)Linking$(END) $(GREEN)$(NAME)$(END)"
					$(CC) $(FLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o:	%.cpp | $(OBJS_DIR)
					$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

$(OBJS_DIR):
					@mkdir -p $(OBJS_DIR)
					@mkdir -p $(OBJS_DIR)/tests
					@echo "$(GREEN)$(BOLD)Compiling$(END) $(GREEN)$(SRCS)$(END)"

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
