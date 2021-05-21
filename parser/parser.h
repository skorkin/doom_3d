#ifndef PARSER_H
# define PARSER_H

# include "../cub3d.h"

typedef struct s_map
{
	char	**map;
	int		count;
	int		max_len;
	int		begin_row;
}t_map;

typedef struct s_resolution
{
	int			width;
	int			heigth;
}t_resolution;

typedef struct s_path
{
	char		*north_path;
	char		*south_path;
	char		*west_path;
	char		*east_path;
	char		*sprite_path;
}				t_path;

typedef struct s_color
{
	int			red;
	int			blue;
	int			green;

}				t_color;

int		is_empty_row(char *line);

void	parser_map_count(t_map *map, int fd, char *line);
void	parser_resolution(char *line, t_resolution *resol);
void	parser_path(char *line, t_path *path);
#endif