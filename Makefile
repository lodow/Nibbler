##
## Makefile for nibbler in /home/maxime/projet/actu/cpp_nibbler
##
## Made by Maxime
## Login   <maxime@epitech.net>
##
## Started on  Wed Mar 12 15:15:11 2014 Maxime
## Last update Wed Mar 12 16:56:30 2014 Maxime
##

NAME_EXE 	=	nibbler
SRC_EXE 	=	src/main.cpp \
			src/Fault.cpp \
			src/Nibbler.cpp

OBJ_EXE 	=	$(SRC_EXE:.cpp=.o)


NAME_LIB 	=	libsdl.so
SRC_LIB 	=	src_sdl/Graphique.cpp
OBJ_LIB 	=	$(SRC_LIB:.cpp=.o)

LDFLAGS 	+=	-ldl
CXXFLAGS 	+=	-fPIC -W -Wall -Wextra -Werror

CXX 		=	g++

all: 			$(NAME_LIB) $(NAME_EXE)

$(NAME_EXE): 		$(OBJ_EXE)
			$(CXX) -o $(NAME_EXE) $(OBJ_EXE) $(LDFLAGS)

$(NAME_LIB): 		$(OBJ_LIB)
			$(CXX) -shared -o $(NAME_LIB) $(OBJ_LIB)

clean:
			rm -f $(OBJ_LIB) $(OBJ_EXE)

fclean: 		clean
			rm -f $(NAME_EXE) $(NAME_LIB)

re: 			fclean all
