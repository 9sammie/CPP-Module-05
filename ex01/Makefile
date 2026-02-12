################################################################################
###									PROGRAM									 ###
################################################################################

NAME		=		BureaucratsAndForms

CXX			=		c++

CXXFLAGS	=		-std=c++98 -Wall -Wextra -Werror -MMD -MP

MAKEFLAGS	+=		--no-print-directory -j$(nproc)

################################################################################
###									DIRECTORY								 ###
################################################################################

OBJ_DIR		=		obj

################################################################################
###									FILES									 ###
################################################################################

SRC			=		main.cpp Bureaucrat.cpp Form.cpp

OBJ			=		$(SRC:%.cpp=$(OBJ_DIR)/%.o)

DEP			=		$(OBJ:%.o=%.d)

################################################################################
###									ARCHIVES								 ###
################################################################################

all: $(NAME)

$(NAME): $(OBJ) Makefile
			$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
			$(CXX) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR):
			mkdir -p $(OBJ_DIR)

-include $(DEP)

re: fclean
			$(MAKE) all

fclean: clean
			rm -f $(NAME)
			rm -f garden_shrubbery

clean: 
			rm -rf $(OBJ_DIR)

.PHONY: all clean fclean re