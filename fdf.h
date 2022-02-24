/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:31:38 by rkaufman          #+#    #+#             */
/*   Updated: 2022/02/24 17:08:32 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft_tools/libft_tools.h"
# include "libft_printf/libft_printf.h"
# include <stdio.h>
# include <fcntl.h>
//open()
# include <stdlib.h>
# include <unistd.h>
//write()
//close()
# include <math.h>
# include <X11/keysym.h>
# include "mlx_linux/mlx.h"
# define WIDTH 1600
# define HEIGHT 900
# define TITLE "<FdF> - <42 Wolfsburg Project> - <made by Rene Kaufmann> - <2022/02/23>"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16384
# endif
# ifndef XK_Plus
# define XK_Plus 0xffab
# endif
# ifndef XK_Minus
# define XK_Minus 0xffad
# endif

typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_engine {
	void			*mlx;
	void			*window;
	t_data			img0;
	t_data			img1;
	t_data			*img;
	char			*file;
	struct s_map 	*screen;
}				t_engine;

typedef struct	s_point {
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct	s_resolution {
	int			width;
	int			height;
}				t_resolution;

typedef struct	s_3d_point {
	int			x;
	int			y;
	int			z;
	int			color;
}				t_3d_point;

typedef struct	s_pivot {
	int			column;
	int			row;
	int			column_half;
	int			row_half;
}				t_pivot;

typedef struct	s_line {
	t_3d_point		start;
	t_3d_point		end;
	int				dx;
	int				dy;
	int				x_next;
	int				y_next;
	int				p_start;
	int				p_less;
	int				p_greater;
}				t_line;

typedef struct	s_map {
	struct s_3d_point	**map;
	struct s_3d_point	**proj;
	int					rows;
	int					columns;
	int					zoom;
	int					zoom_z;
	struct s_resolution resolution;
	struct s_pivot		pivot;
	struct s_point		offset;
	struct s_point		factor;
	struct s_point		angle;
	struct s_point		movement;
}				t_map;

//ft_engine.c
void			ft_engine_init(t_engine *engine);
int				ft_engine_destroy(t_engine *engine);

//ft_string.c
size_t			ft_count_of_columns(char *s, char c);
char			*ft_get_screen_resolution_str(t_engine *engine);

//ft_file.c
t_map			*ft_read_input_map(char *file);

//ft_map_array.c
void			ft_create_map_array(char *input, t_map *screen);
void			ft_draw_map(t_engine *engine);
void			ft_free_map(t_map *screen);
void			ft_get_point(t_engine *engine, int row, int column, t_3d_point *point);
void			ft_apply_rotation(t_engine *engine);
void			ft_rotate_x(t_engine *engine, int i_row, int i_column);
void			ft_rotate_y(t_engine *engine, int i_row, int i_column);
void			ft_rotate_z(t_engine *engine, int i_row, int i_column);

//ft_lines.c
void			ft_draw_rectangle(t_engine *engine, t_line rectangle);
void			ft_draw_line(t_engine *engine, t_line line);
void			ft_line_preparations(t_line *line);
void			ft_draw_line_edge_case(t_engine *engine, t_line line);
void			ft_draw_line_algorythm(t_engine *engine, t_line line);
int				ft_at_least_one_point_on_screen(t_engine *engine, t_line *line);

//ft_pixel.c
void			ft_put_pixel(t_data *data, int x, int y, int color);

//ft_math.c
unsigned int	ft_abs(int number);

//ft_key.c
int				ft_key(int keycode, t_engine *engine);
void			ft_key_projection_change(int keycode, t_engine *engine);
void			ft_key_screen_movement(int keycode, t_engine *engine);
void			ft_key_rotation(int key, t_engine *engine);
void			ft_key_zoom(int keycode, t_engine *engine);
void			ft_key_center_view(int keycode, t_engine *engine);

//ft_grafic.c
int				ft_render_frame(t_engine *engine);
void			ft_clear_image(t_engine *engine);

//ft_display_info.c
void			ft_display_info(t_engine *engine);

#endif