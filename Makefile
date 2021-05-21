NAME		= cub3d

CC			= gcc -O3
#-fsanitize=address

HEADER		= cub3d.h

PARSERDIR	= parser/

VECTORDIR	= vector/

SRC			=	save.c \
				screenshot.c \
				error.c \
				ft_cub3d_utils.c \
				init.c \
				texture.c \
				key/key_update.c \
				key/key_left_right.c \
				key/key_press_release.c \
				cast/wall_cast.c \
				cast/wall_cast_utils.c \
				cast/floor_cast.c \
				sprite/sprite.c \
				sprite/sprite_sort.c \
				$(PARSERDIR)parser_color.c \
				$(PARSERDIR)parser_map.c \
				$(PARSERDIR)parser_resolution.c \
				$(PARSERDIR)parser_path.c \
				$(PARSERDIR)parser.c \
				$(PARSERDIR)map_check.c \
				$(PARSERDIR)rook_turn.c \
				$(VECTORDIR)vector_dou.c \
				$(VECTORDIR)vector_int.c \
				

OBJS		= ${SRC:.c=.o}

#CFLAGS		= -Wall -Wextra -Werror

MLXFLAGS	= -lmlx -framework OpenGL -framework AppKit

LIB			= libft.a

LIBFTDIR	= libft/

$(NAME): 
	make -C libft
	${CC} ${CFLAGS} ${MLXFLAGS} ${SRC} libft.a

all: $(NAME)

clean:
	make clean -C $(LIBFTDIR)
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(LIBFTDIR)
	rm -rf $(NAME)
	
re: fclean all

.PHONY:clean fclean
