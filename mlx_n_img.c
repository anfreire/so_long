/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_n_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:43:30 by anfreire          #+#    #+#             */
/*   Updated: 2022/05/11 12:57:57 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	matrix_heigh(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

char	**heigh_calc(int fd, t_param *param)
{
	char	**matrix;

	matrix = map_reciever(fd);
	param->mlx.lenght = (int)ft_strlen(*matrix);
	param->mlx.height = matrix_heigh(matrix);
	return (matrix);
}

void	get_init(t_param *param)
{
	int	hei;
	int	len;

	hei = 0;
	while (hei < param->mlx.height)
	{
		len = 0;
		while (len < param->mlx.lenght)
		{
			if (param->matrix[hei][len] == 'P')
			{
				param->x = hei;
				param->y = len;
				return ;
			}	
			len++;
		}
		hei++;
	}
	return ;
}

void	put_img_mlx(t_param *param)
{
	param->img.caminho = mlx_xpm_file_to_image(param->mlx.mlx,
			"imagens/path.xpm", &param->img.img_width, &param->img.img_height);
	param->img.chest = mlx_xpm_file_to_image(param->mlx.mlx,
			"imagens/chest1.xpm", &param->img.img_width,
			&param->img.img_height);
	param->img.exit = mlx_xpm_file_to_image(param->mlx.mlx, "imagens/exit.xpm",
			&param->img.img_width, &param->img.img_height);
	param->img.player_f = mlx_xpm_file_to_image(param->mlx.mlx,
			"imagens/player_f.xpm", &param->img.img_width,
			&param->img.img_height);
	param->img.wall = mlx_xpm_file_to_image(param->mlx.mlx, "imagens/wall.xpm",
			&param->img.img_width, &param->img.img_height);
}

void	setting_img(t_param	*param, int hei, int len)
{
	while (++hei < param->mlx.height)
	{
		len = -1;
		while (++len < param->mlx.lenght)
		{
			if (param->matrix[hei][len] == '1')
				mlx_put_image_to_window(param->mlx.mlx, param->mlx.win,
					param->img.wall, len * 64, hei * 64);
			else
				mlx_put_image_to_window(param->mlx.mlx, param->mlx.win,
					param->img.caminho, len * 64, hei * 64);
			if (param->matrix[hei][len] == 'C')
				mlx_put_image_to_window(param->mlx.mlx, param->mlx.win,
					param->img.chest, len * 64, hei * 64);
			if (param->matrix[hei][len] == 'P')
				mlx_put_image_to_window(param->mlx.mlx, param->mlx.win,
					param->img.player_f, len * 64, hei * 64);
			if (param->matrix[hei][len] == 'E')
				mlx_put_image_to_window(param->mlx.mlx, param->mlx.win,
					param->img.exit, len * 64, hei * 64);
		}
	}
}
