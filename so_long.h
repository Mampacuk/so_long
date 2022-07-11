/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:30:00 by aisraely          #+#    #+#             */
/*   Updated: 2022/07/11 21:30:01 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 1

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_keys
{
	char	up;
	char	down;
	char	left;
	char	right;
	char	lock;
	int		keycode;
}				t_keys;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		linelen;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_screen
{
	void	*mlx;
	void	*win;
	void	*loss;
	void	*victory;
	t_img	img;
}				t_screen;

typedef struct s_map
{
	int		w;
	int		h;
	char	**m;
}				t_map;

typedef struct s_player
{
	int	x;
	int	y;
	int	items;
	int	moves;
	int	goal;
}				t_player;

typedef struct s_exit
{
	int	x;
	int	y;
}				t_exit;

typedef struct s_parsed
{
	int			i;
	int			j;
	int			x;
	int			y;
	int			frame;
	int			unitsize;
	int			texx;
	int			texy;
	int			state;
	double		time;
	t_map		map;
	t_player	player;
	t_exit		exit;
	t_screen	scr;
	t_keys		keys;
	t_img		sprite;
	t_img		texwall;
	t_img		texpl;
	t_img		texitem;
	t_img		texexit;
	t_img		texfloor;
	t_img		*texfire;
	t_img		texwin;
	t_img		texloss;
}				t_parsed;

int				ft_getmapwidth(char *mappath);
int				ft_getmapheight(char *mappath);
void			ft_setup_map(t_parsed *res, char *mappath);
void			ft_writerow(char *line, t_parsed *res, int x);
int				get_next_line(int fd, char **line);
char			*ft_strchr(char *s, int c);
void			ft_exit(char *str);
void			ft_mlx_pixel_set(t_img *image, int x, int y, int color);
unsigned int	ft_mlx_pixel_get(t_img *image, int x, int y);
int				ft_mlx_pressed(int keycode, t_keys *keys);
int				ft_mlx_released(int keycode, t_keys *keys);
int				ft_check_extension(char *path, char *ext);
int				ft_ismaprow(char *str);
void			ft_checkwalls(char **map, int height, int width);
t_parsed		ft_parser(char *mappath);
void			ft_getworldmap(char *mappath, t_parsed *res);
void			ft_initparser(t_parsed *res);
void			ft_initplayer(t_parsed *res, int posx, int posy);
void			ft_loadtextures1(t_parsed *res);
void			ft_loadtextures2(t_parsed *res);
void			ft_loadtextures3(t_parsed *res);
void			ft_loadtextures4(t_parsed *res);
void			ft_setunitsize(t_parsed *res);
void			ft_mlx_draw_unit(t_parsed *res, int i, int j);
void			ft_drawfloor(t_parsed *res);
int				ft_render(t_parsed *res);
void			ft_receiveinput1(t_parsed *res);
void			ft_receiveinput2(t_parsed *res);
void			ft_receiveinput3(t_parsed *res);
void			ft_receiveinput4(t_parsed *res);
void			ft_selectsprite(t_parsed *res, int i, int j);
void			ft_putspritepixel(t_parsed *res, int i, int j);
void			ft_initexit(t_parsed *res, int posx, int posy);
void			ft_putmoves(t_parsed *res);
void			ft_triggervictory(t_parsed *res);
void			ft_triggerloss(t_parsed *res);
void			ft_animatefire(t_parsed *res);
int				ft_mlx_terminate(int keycode, t_keys *keys);

#endif