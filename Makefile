#------------- NAME -----------------
NAME=			containers
#------------------------------------


#------------- SRCS -----------------
SRCS_DIR=		tests
SRCS_FILES=		main.cpp\
				vectorTest.cpp
SRCS=			$(addprefix $(SRCS_DIR)/,$(SRCS_FILES))
#------------------------------------


#-------------- OBJS ----------------
OBJS_DIR=		.objs
OBJS=			$(addprefix $(OBJS_DIR)/,$(SRCS:.cpp=.o))
PATH_OBJS=		tests
#------------------------------------


#------------- COMPILER -------------
CC=				c++
FLAGS=			-Wall -Werror -Wextra -std=c++98 -Iincludes/  -fsanitize=address -g3
#------------------------------------


#------------- INCS -----------------
INC_DIR=		includes
INC_FILES=		vector.hpp\
				iterator.hpp\
				reverse_iterator.hpp\
				tests.hpp\
				test_vector.hpp\
				meta.hpp
INCLUDES=		$(addprefix $(INC_DIR)/,$(INC_FILES))
#------------------------------------


#-------------- RES -----------------
RES_PATH=		res
RES_FILES=		res/res_myvector.txt\
				res/res_vector.txt
RES=			$(addprefix $(RES_PATH)/,$(RES_FILES))
#------------------------------------


#-------------- RM ------------------
RM=				/bin/rm -rf
#------------------------------------


ifeq ($(SAN), 1)
FLAGS = -Wall -Werror -Wextra -std=c++98 #-fsanitize=address -g3
endif


all:		$(NAME)

$(NAME):	$(OBJS)
					@echo "$(GREEN)$(BOLD)Linking$(END) $(GREEN)$(NAME)$(END)"
					$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o:	%.cpp $(INCLUDES) | $(OBJS_DIR)
					@echo "$(GREEN)$(BOLD)Compiling$(END) $(GREEN)$<$(END)"
					$(CC) $(FLAGS) -o $@ -c $<

$(OBJS_DIR):
					@mkdir -p $(OBJS_DIR) $(addprefix $(OBJS_DIR)/,$(PATH_OBJS))
					@mkdir -p $(RES_PATH)

clean:
					@echo "$(GREEN)$(BOLD)Deleting$(END) $(GREEN)object files$(END)"
					@$(RM) $(OBJS)
					@$(RM) $(RES)

fclean:		clean
					@echo "$(GREEN)$(BOLD)Deleting$(END) $(GREEN)executable, objs_dir$(END)"
					@$(RM) $(NAME)
					@$(RM) $(OBJS_DIR)
					@$(RM) $(RES_PATH)

re:			fclean all

.PHONY:		all clean fclean re


#------------- COLORS --------------
GREEN	= \033[32m
END		= \033[0m
BOLD	= \033[1m
#------------------------------------
