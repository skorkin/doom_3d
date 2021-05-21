#include "minilibx_mms_20200219/mlx.h"
#include "cub3d.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define CEILING_TEXTURE 5

static int	compare(const void *first, const void *second)
{
	if (*(int *)first > *(int *)second)
		return (1);
	else if (*(int *)first < *(int *)second)
		return (-1);
	else
		return (0);
}

void	draw(t_info *info)
{
	int	y;
	int	x;

	y = -1;
	while (++y < info->resol.heigth)
	{
		x = -1;
		while (++x < info->resol.width)
			info->img.data[y * info->resol.width + x] = info->buf[y][x];
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

int	main_loop(t_info *info)
{
	floor_cast(info);
	wall_cast(info);
	sprite_cast(info);
	draw(info);
	key_update(info);
	if (info->flag_save == 1)
		create_screenshot(info);
	return (0);
}

void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	t_vec_int	cord;

	img->img = mlx_xpm_file_to_image(info->mlx, path,
			&img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp,
			&img->size_l, &img->endian);
	cord.y = -1;
	while (++cord.y < img->img_height)
	{
		cord.x = -1;
		while (++cord.x < img->img_width)
			texture[img->img_width * cord.y + cord.x]
				= img->data[img->img_width * cord.y + cord.x];
	}
	mlx_destroy_image(info->mlx, img->img);
}

int	main(int argc, char *argv[])
{
	t_info		info;

	info.mlx = mlx_init();
	info_init(&info);
	is_save(argv, &info, argc);
	set_cub(&info, argv, argc);
	parser(&info);
	sort_sprite(&info);
	set_texture(&info);
	load_texture(&info);
	info.move_speed = 0.15;
	info.rot_speed = 0.05;
	info.win = mlx_new_window(info.mlx, info.resol.width,
			info.resol.heigth, "mlx");
	info.img.img = mlx_new_image(info.mlx, info.resol.width, info.resol.heigth);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp,
			&info.img.size_l, &info.img.endian);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, 2, 0, &key_press, &info);
	mlx_hook(info.win, 3, 0, &key_release, &info);
	mlx_loop(info.mlx);
}
