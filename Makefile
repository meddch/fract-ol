RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;34m
CC = cc
CFLAGS = -Ofast -Wall -Wextra -Werror 
FRAMEWORK = -lmlx -framework OpenGL -framework AppKit
RM = rm -f
NAME = fractol
FILE_M = src/color src/fractal src/draw src/key src/main src/math src/mouse src/outils
HEADER = src/fractol.h 

SRCS_M = $(addsuffix .c, $(FILE_M))
OBJS_M = $(addsuffix .o, $(FILE_M))


%.o : %.c $(HEADER)
	@echo "$(BLUE)Building project ⏳.."
	@$(CC) $(CFLAGS) -c -o $@ $<
	
all : $(NAME)
	@echo  "$(GREEN)Building done successfully ✅"

$(NAME): $(OBJS_M) 
	@$(CC) $(OBJS_M) $(FRAMEWORK) -o $(NAME)

clean:
	@$(RM) $(OBJS_M) $(OBJS_B)
	@echo  "$(RED)ALL DELETED ☠ "

bonus : all

fclean: clean
	@$(RM) $(NAME)

re: fclean all 


.PHONY: all clean fclean re bonus

