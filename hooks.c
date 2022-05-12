/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 21:23:50 by anfreire          #+#    #+#             */
/*   Updated: 2022/05/12 12:23:34 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	key_press(int keycode, t_param *param)
{
	static int	a = 0;
	static int	exits = 0;

	if (a == 0)
		exits = exit_true(param);
	if (exit_true(param) != exits)
		if (keycode > -1)
			exit (0);
	if (keycode == KEY_W)
		a += move_up(param);
	else if (keycode == KEY_S)
		a += move_down(param);
	else if (keycode == KEY_A)
		a += move_left(param);
	else if (keycode == KEY_D)
		a += move_right(param);
	else if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_W || keycode == KEY_S
		|| keycode == KEY_A || keycode == KEY_D)
		ft_printf("Steps taken to reach the exit: %d\n\n", a);
	setting_img(param, (-1), (-1));
	return (0);
}

int	move_down(t_param	*param)
{
	int	x;
	int	y;

	x = param->x;
	y = param->y;
	if (param->matrix[x + 1][y] == '1')
		return (0);
	else if (param->matrix[x + 1][y] == 'E' && !chests_true(param))
	{
		param->matrix[x][y] = '0';
		param->matrix[x + 1][y] = 'P';
		param->x++;
		ft_printf("You've made it to the end of the map!");
		ft_printf("\nPress any key to leave the game.\nTotal ");
		return (1);
	}
	else if (param->matrix[x + 1][y] == 'C' || param->matrix[x + 1][y] == '0')
	{
		param->matrix[x][y] = '0';
		param->matrix[x + 1][y] = 'P';
		param->x++;
		return (1);
	}
	else
		return (0);
}

int	move_up(t_param	*param)
{
	int	x;
	int	y;

	x = param->x;
	y = param->y;
	if (param->matrix[x - 1][y] == '1')
		return (0);
	else if (param->matrix[x - 1][y] == 'E' && !chests_true(param))
	{
		param->matrix[x][y] = '0';
		param->matrix[x - 1][y] = 'P';
		param->x--;
		ft_printf("You've made it to the end of the map!");
		ft_printf("\nPress any key to leave the game.\nTotal ");
		return (1);
	}
	else if (param->matrix[x - 1][y] == 'C' || param->matrix[x - 1][y] == '0')
	{
		param->matrix[x][y] = '0';
		param->matrix[x - 1][y] = 'P';
		param->x--;
		return (1);
	}
	else
		return (0);
}

int	move_right(t_param	*param)
{
	int	x;
	int	y;

	x = param->x;
	y = param->y;
	if (param->matrix[x][y + 1] == '1')
		return (0);
	else if (param->matrix[x][y + 1] == 'E' && !chests_true(param))
	{
		param->matrix[x][y] = '0';
		param->matrix[x][y + 1] = 'P';
		param->y++;
		ft_printf("You've made it to the end of the map!");
		ft_printf("\nPress any key to leave the game.\nTotal ");
		return (1);
	}
	else if (param->matrix[x][y + 1] == 'C' || param->matrix[x][y + 1] == '0')
	{
		param->matrix[x][y] = '0';
		param->matrix[x][y + 1] = 'P';
		param->y++;
		return (1);
	}
	else
		return (0);
}

int	move_left(t_param	*param)
{
	int	x;
	int	y;

	x = param->x;
	y = param->y;
	if (param->matrix[x][y - 1] == '1')
		return (0);
	else if (param->matrix[x][y - 1] == 'E' && !chests_true(param))
	{
		param->matrix[x][y] = '0';
		param->matrix[x][y - 1] = 'P';
		param->y--;
		ft_printf("You've made it to the end of the map!");
		ft_printf("\nPress any key to leave the game.\nTotal ");
		return (1);
	}
	else if (param->matrix[x][y - 1] == 'C' || param->matrix[x][y - 1] == '0')
	{
		param->matrix[x][y] = '0';
		param->matrix[x][y - 1] = 'P';
		param->y--;
		return (1);
	}
	else
		return (0);
}
