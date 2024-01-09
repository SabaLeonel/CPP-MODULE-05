# Updated Makefile for the phonebook project

# Name of your executable
TARGET = Bureaucrat

# Compiler to use
CXX = c++
# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -O3 #-fsanitize=address

# Source files
SRC = main.cpp \
	Bureaucrat.cpp \
	AForm.cpp \
	ShrubberyCreationForm.cpp \
	RobotomyRequestForm.cpp \
	PresidentialPardonForm.cpp \
	Intern.cpp	\

# Object files
OBJ = $(SRC:.cpp=.o)

# Build target
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

# Phony targets
.PHONY: all clean re fclean
