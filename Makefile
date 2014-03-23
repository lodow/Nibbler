##
## Makefile for Make in /home/moriss
##
## Made by hugues morisset
## Login   <moriss_h@epitech.net>
##
## Started on  Mon Oct 22 09:20:28 2012 hugues morisset
## Last update Sun Mar  9 23:19:26 2014 Hugues
##

NAME	=	nibbler/libs

SUBDIRS	=	nibutils \
			nibblercore \
			lib_mlx \
			lib_opengl \
			lib_sdl

RULES	=	nibbler \
			lib_nibbler_sdl.so \
			lib_nibbler_opengl.so \
			lib_nibbler_mlx.so

RM	=	rm -f

$(NAME):
	@for dir in $(SUBDIRS); do \
	echo "--- $$dir ---"; make --no-print-directory -C $$dir all; \
	done

all: $(NAME)

clean:
	@for dir in $(SUBDIRS); do \
	echo "--- $$dir ---"; make --no-print-directory -C $$dir clean; \
	done

fclean:
	$(RM) $(RULES)
	@for dir in $(SUBDIRS); do \
	echo "--- $$dir ---"; make --no-print-directory -C $$dir fclean; \
	done

re: fclean all

.PHONY:	all clean fclean re $(SUBDIRS)
