NAME = fractol

CFILES = src/main.c \
			src/fractol.c \
			src/callbacks.c \

LIBS = libft.a \
		minilibx/libmlx.a

FRAMEWORKS = -framework OpenGL -framework AppKit

HEADERS = inc

all : $(CFILES)
		@gcc -Wall -Wextra -Werror -o $(NAME) -I $(HEADERS) $(FRAMEWORKS) $(LIBS) $(CFILES)
debug : 
		 @gcc -g -o $(NAME) -I $(HEADERS) $(FRAMEWORKS) $(LIBS) $(CFILES)
clean : 
		rm -f minlibx/*.o

fclean : clean
		rm -f fractol

re: fclean all
