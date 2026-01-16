################################################################################
###									PROGRAM ###
################################################################################

NAME					=		BureaucratsAndForms

################################################################################
###									COMPILE ###
################################################################################

CXX						=		c++

################################################################################
###									DIRECTORY ###
################################################################################

OBJ_DIR					=		obj

################################################################################
###									FLAGS	 ###
################################################################################

CFLAGS					=		-std=c++98 -Wall -Wextra -Werror

################################################################################
###									FILES	 ###
################################################################################

HEADERS					=		Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp \
								RobotomyRequestForm.hpp ShrubberyCreationForm.hpp \
								Intern.hpp

SRC						=		main.cpp Bureaucrat.cpp AForm.cpp \
								PresidentialPardonForm.cpp RobotomyRequestForm.cpp \
								ShrubberyCreationForm.cpp Intern.cpp

OBJ						=		$(SRC:%.cpp=$(OBJ_DIR)/%.o)

################################################################################
###									ARCHIVES ###
################################################################################

all: $(NAME)

$(NAME): $(OBJ)
			$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp $(HEADERS) | $(OBJ_DIR)
			$(CXX) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR):
			mkdir -p $(OBJ_DIR)

re: fclean
			$(MAKE) all

fclean: clean
			rm -f $(NAME)
			rm garden_shrubbery

clean: 
			rm -rf $(OBJ_DIR)

.PHONY: all clean fclean re