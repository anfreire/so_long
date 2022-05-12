/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:43:36 by anfreire          #+#    #+#             */
/*   Updated: 2022/05/12 11:46:23 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <mlx.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# define DEFAULT_ERROR "Error"
# define NFOUND "File not found."
# define MCV2 "Invalid Components! (Missing Exit or Chests or Player)"
# define MCV3 "Map data is corrupted, and there is an empty new line between the \
map data."
# define MCV4 "The map is distorted, it is not a rectangular map."
# define MCV5 "There are no walls surrounding the entire map."
# define MORE "\nThere could be additional errors, therefore fix this one \
to continue."
# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define BUFFER_SIZE 10

typedef struct s_img
{
	int		img_width;
	int		img_height;
	void	*caminho;
	void	*chest;
	void	*exit;
	void	*player_b;
	void	*player_l;
	void	*player_r;
	void	*player_f;
	void	*wall;
}				t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		lenght;
	int		height;
}				t_mlx;

typedef struct s_param
{
	int		x;
	int		y;
	char	**matrix;
	t_mlx	mlx;
	t_img	img;

}				t_param;

char	*get_next_line(int fd);
int		exit_true(t_param	*param);
int		key_press(int keycode, t_param *param);
void	move_forward(t_param *param);
void	print_matrix(t_param	*param);
int		move_down(t_param	*param);
int		move_up(t_param	*param);
int		move_left(t_param	*param);
int		move_right(t_param	*param);
int		matrix_heigh(char **matrix);
char	**heigh_calc(int fd, t_param *param);
void	get_init(t_param *param);
void	put_img_mlx(t_param *param);
void	setting_img(t_param	*param, int hei, int len);
char	**map_reciever(int fd);
char	**map_reciever_v2(char **matrix);
char	*map_checker_v1(int fd);
char	*map_checker_v2(char *str);
char	**map_checker_v3(char *str);
char	**map_checker_v4(char **matrix);
char	**map_checker_v5(char **matrix);
int		ft_printf(const char *fmt, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_hex_len(unsigned long long num);
int		ft_print_ptr(unsigned long long ptr);
int		ft_nbr_cntr(int nb);
int		ft_putnbr(int nb);
int		ft_num_len(unsigned	int num);
char	*ft_uitoa(unsigned int n);
int		ft_print_unsigned_hex(unsigned int n, const char format);
void	ft_put_hex(unsigned long long num, const char format);
int		ft_print_hex(unsigned int num, const char format);
char	*only_one_player(char	*str);
int		chests_true(t_param *param);
#endif
