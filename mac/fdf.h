/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:31:38 by rkaufman          #+#    #+#             */
/*   Updated: 2022/03/08 19:08:09 by rkaufman         ###   ########.fr       */
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
# include "minilibx_opengl_20191021/mlx.h"
# define WIDTH 1600
# define HEIGHT 900
# define TITLE "<FdF> - <42 Wolfsburg Project> - <made by Rene Kaufmann>"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16384
# endif
# define XK_ESC 0x35
# define XK_X 0x07
# define XK_C 0x08
# define XK_PLUS 69
# define XK_PLUS2 30
# define XK_MINUS 78
# define XK_MINUS2 44
# define XK_LEFT 123
# define XK_RIGHT 124
# define XK_UP 126
# define XK_DOWN 125
# define XK_A 0
# define XK_D 2
# define XK_S 1
# define XK_W 13
# define XK_Q 12
# define XK_E 14
# define XK_I 34
# define XK_P 35
# define XK_F 3
# define XK_V 9
# define XK_HOME 115

typedef struct s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_engine {
	void			*mlx;
	void			*window;
	t_data			img0;
	t_data			img1;
	t_data			*img;
	char			*file;
	struct s_map	*screen;
}				t_engine;

typedef struct s_point {
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct s_resolution {
	int			width;
	int			height;
}				t_resolution;

typedef struct s_3d_point {
	int			x;
	int			y;
	int			z;
	int			color;
}				t_3d_point;

typedef struct s_pivot {
	int			column;
	int			row;
}				t_pivot;

typedef struct s_sin_cos {
	float		cos_x;
	float		cos_y;
	float		cos_z;
	float		sin_x;
	float		sin_y;
	float		sin_z;
}				t_sin_cos;

typedef struct s_line {
	t_3d_point		start;
	t_3d_point		pos;
	t_3d_point		end;
	int				dx;
	int				dy;
	int				main_x;
	int				x_next;
	int				y_next;
	int				p_start;
	int				p_less;
	int				p_greater;
}				t_line;

typedef struct s_map {
	struct s_3d_point	**map;
	struct s_3d_point	**proj;
	int					paralel;
	int					colored;
	int					rows;
	int					columns;
	int					zoom;
	int					zoom_z;
	struct s_resolution	resolution;
	struct s_pivot		pivot;
	struct s_point		offset;
	struct s_point		factor;
	struct s_point		angle;
	struct s_point		movement;
}				t_map;

typedef struct s_algo {
	int			*primary;
	int			*secondary;
	int			*primary_next;
	int			*secondary_next;
	int			*primary_end;
}				t_algo;

//ft_error.c
int				ft_error_arguments(void);
int				ft_error_malloc(char *function, char *variable, size_t size);
int				ft_error_file(char *function, char *file);
int				ft_error_file_result(char *function, char *file, int fd);
int				ft_error_number(char *function, char *value, size_t row,
					size_t column);
void			ft_error_split(t_map *screen, char *input);

//ft_error_map.c
void			ft_error_input(t_map *screen, char **string_array);
void			ft_error_map(t_map *screen, char **string_array);
void			ft_error_proj(t_map *screen, char **string_array);
void			ft_error_map_row(t_map *screen, char **string_array,
					int i_row);
void			ft_error_proj_row(t_map *screen, char **string_array,
					int i_row);

//ft_memory_map.c
void			ft_allocate_mem_map(t_map *screen, char **string_array);
void			ft_free_map(t_map *screen);

//ft_engine.c
void			ft_engine_init(t_engine *engine);
int				ft_engine_destroy(t_engine *engine);

//ft_string.c
size_t			ft_count_of_columns(char *s, char c);
void			ft_check_input_exit_on_error(t_map *screen, char **input);
int				ft_valid_number(char *argv);

//ft_file.c
t_map			*ft_read_input_map(char *file);

//ft_map_array.c
void			ft_create_map_array(char *input, t_map *screen);
void			ft_get_point(t_engine *engine, int row, int column,
					t_3d_point *point);

//ft_geometry.c
void			ft_draw_rectangle(t_engine *engine, t_line rectangle);

//ft_lines0.c
void			ft_draw_rectangle(t_engine *engine, t_line rectangle);
void			ft_draw_line(t_engine *engine, t_line line);
void			ft_line_preparations(t_line *line);
void			ft_draw_line_edge_case(t_engine *engine, t_line line);
int				ft_at_least_one_point_on_screen(t_engine *engine, t_line *line);

//ft_lines1.c
void			ft_draw_line_algorythm(t_engine *engine, t_line line);

//ft_pixel.c
void			ft_put_pixel(t_data *data, int x, int y, int color);
void			ft_get_point(t_engine *engine, int row, int column,
					t_3d_point *point);

//ft_color.c
int				ft_get_color(t_line *line);
double			ft_get_percentage(int start, int end, int pos);
int				ft_get_rgb(int start, int end, double percentage);

//ft_math.c
unsigned int	ft_abs(int number);
void			ft_apply_rotation(t_engine *engine);

//ft_rotations.c
void			ft_rotate_x(t_engine *engine, int i_row, int i_column,
					t_sin_cos *calcs);
void			ft_rotate_y(t_engine *engine, int i_row, int i_column,
					t_sin_cos *calcs);
void			ft_rotate_z(t_engine *engine, int i_row, int i_column,
					t_sin_cos *calcs);

//ft_key0.c
int				ft_key(int keycode, t_engine *engine);
void			ft_key_projection_change(int keycode, t_engine *engine);
void			ft_key_screen_movement(int keycode, t_engine *engine);
void			ft_key_rotation(int key, t_engine *engine);
void			ft_key_zoom(int keycode, t_engine *engine);

//ft_key1.c
void			ft_key_center_view(int keycode, t_engine *engine);

//ft_grafic.c
int				ft_render_frame(t_engine *engine);
void			ft_clear_image(t_engine *engine);
void			ft_draw_map(t_engine *engine);

//ft_display_info.c
void			ft_display_info(t_engine *engine);

#endif