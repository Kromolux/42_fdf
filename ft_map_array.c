/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:06:57 by rkaufman          #+#    #+#             */
/*   Updated: 2022/02/24 18:09:23 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_create_map_array(char *input, t_map *screen)
{
	char	**string_array;
	int	i;
	int	i_row;
	int	i_column;

	if (!input)
		return ;
	ft_printf("input=\n%s\n", input);
	screen->rows = ft_count_of_in_str(input, '\n');
	screen->columns = ft_count_of_columns(input, '\n');
	screen->resolution.width = WIDTH;
	screen->resolution.height = HEIGHT;
	screen->pivot.row = (int) screen->rows / 2;
	screen->pivot.column = (int) screen->columns / 2;
	screen->pivot.column_half = 0;
	screen->pivot.row_half = 0;
	if ((screen->columns % 2) == 0)
		screen->pivot.column_half = 1;
	if ((screen->rows % 2) == 0)
		screen->pivot.row_half = 1;
	//screen->pivot.column_half = (screen->columns % 2) * 1;
	screen->movement.x = 0;
	screen->movement.y = 0;
	screen->movement.z = 0;
	screen->angle.x = -35;
	screen->angle.y = 35;
	screen->angle.z = -35;
	screen->zoom = screen->resolution.width / (screen->rows + screen->columns);//50;
	screen->zoom = screen->zoom;
	screen->zoom_z = 5;
	screen->offset.x = (int) (screen->resolution.width / 2); //- (screen->pivot.column * screen->zoom + screen->pivot.column_half * 0.5 * screen->zoom);
	screen->offset.y = (int) (screen->resolution.height / 2); //- (screen->pivot.row * screen->zoom + screen->pivot.row_half * 0.5 * screen->zoom);
	ft_replace_in_string(input, '\n', ' ');
	ft_printf("input=\n%s\n", input);
	string_array = ft_split(input, ' ');
	ft_printf("%ix%i\n", (int) (screen->resolution.width), (screen->resolution.height));
	ft_printf("rows=%i columns=%i\n", screen->rows, screen->columns);
	ft_printf("pivot_row=%i pivot_column=%i\n", screen->pivot.row, screen->pivot.column);
	ft_printf("offset_x=%i offset_y=%i zoom=%i\n", screen->offset.x, screen->offset.y, screen->zoom);
	free(input);
	i = 0;
	/*
	while (string_array[i])
	{
		printf("[%2li]=[%3s] ", i, string_array[i]);
		i++;
	}
	*/
	screen->map = (t_3d_point **) malloc(sizeof(t_3d_point *) * screen->rows);
	screen->proj = (t_3d_point **) malloc(sizeof(t_3d_point *) * screen->rows);
	if (!screen->map || ! screen->proj)
		return ;
	i_row = 0;
	while (i_row < screen->rows)
	{
		screen->map[i_row] = (t_3d_point *) malloc(sizeof(t_3d_point) * screen->columns);
		screen->proj[i_row] = (t_3d_point *) malloc(sizeof(t_3d_point) * screen->columns);
		if (!screen->map[i_row] || !screen->proj)
			return ;
		i_row++;
	}
	i = 0;
	i_row = 0;
	ft_printf("\n");
	while (i_row < screen->rows)
	{
		i_column = 0;
		while (i_column < screen->columns)
		{
			screen->map[i_row][i_column].x = i_column - screen->pivot.column;
			screen->map[i_row][i_column].y = i_row - screen->pivot.row;
			screen->map[i_row][i_column].z = ft_string_to_int(string_array[i]);
			screen->map[i_row][i_column].color = 0x00FFFFFF;
			//ft_printf("[%lu][%lu]=[%i] [%lu]\n", i_row, i_column, ft_atoi(string_array[i]), i);
			i_column++;
			i++;
		}
		i_row++;
	}
	ft_free_char_array(string_array);
}

void	ft_draw_map(t_engine *engine)
{
	t_line	line;
	int		i_row;
	int		i_column;

	i_row = 0;
	i_column = 0;
	line.start.color = 0x00FFFFFF;
	//printf("drawing map\n");
	while (i_row < engine->screen->rows - 1)
	{
		i_column = 0;
		while (i_column < engine->screen->columns - 1)
		{
			ft_get_point(engine, i_row, i_column, &line.start);
			ft_get_point(engine, i_row, i_column + 1, &line.end);
			ft_draw_line(engine, line);
			ft_get_point(engine, i_row + 1, i_column, &line.end);
			ft_draw_line(engine, line);
			i_column++;
		}
		i_row++;
	}
	i_column = 0 ;
	while (i_column < engine->screen->columns - 1)
	{
		ft_get_point(engine, engine->screen->rows - 1, i_column, &line.start);
		ft_get_point(engine, engine->screen->rows - 1, i_column + 1, &line.end);
		ft_draw_line(engine, line);
		i_column++;
	}
	i_row = 0;
	while (i_row < engine->screen->rows - 1)
	{
		ft_get_point(engine, i_row, engine->screen->columns - 1, &line.start);
		ft_get_point(engine, i_row + 1, engine->screen->columns - 1, &line.end);
		ft_draw_line(engine, line);
		i_row++;
	}
}

void	ft_free_map(t_map *screen)
{
	int	i_row;

	i_row = 0;
	while (i_row < screen->rows)
	{
		free(screen->map[i_row]);
		free(screen->proj[i_row]);
		i_row++;
	}
	free(screen->map);
	free(screen->proj);
	free(screen);
}

void	ft_apply_rotation(t_engine *engine)
{
	int		i_row;
	int		i_column;
	/*
	int		tmp_x;
	int		tmp_y;
	int		tmp_z;
	float	cos_x;
	float	cos_y;
	float	cos_z;
	float	sin_x;
	float	sin_y;
	float	sin_z;

	cos_x = cos(engine->screen->angle.x * M_PI / 180);
	cos_y = cos(engine->screen->angle.y * M_PI / 180);
	cos_z = cos(engine->screen->angle.z * M_PI / 180);
	sin_x = sin(engine->screen->angle.x * M_PI / 180);
	sin_y = sin(engine->screen->angle.y * M_PI / 180);
	sin_z = sin(engine->screen->angle.z * M_PI / 180);

	(void) cos_z;
	(void) sin_z;
	(void) cos_y;
	(void) sin_y;
	(void) cos_x;
	(void) sin_x;
	*/
	i_row = 0;
	while (i_row < engine->screen->rows)
	{
		i_column = 0;
		while (i_column < engine->screen->columns)
		{
			engine->screen->proj[i_row][i_column].x = engine->screen->map[i_row][i_column].x * engine->screen->zoom;
			engine->screen->proj[i_row][i_column].y = engine->screen->map[i_row][i_column].y * engine->screen->zoom;
			engine->screen->proj[i_row][i_column].z = engine->screen->map[i_row][i_column].z * engine->screen->zoom_z;
			ft_rotate_x(engine, i_row, i_column);
			ft_rotate_y(engine, i_row, i_column);
			ft_rotate_z(engine, i_row, i_column);
			/*
			tmp_x = engine->screen->map[i_row][i_column].x * engine->screen->zoom;
			tmp_y = engine->screen->map[i_row][i_column].y * engine->screen->zoom;
			tmp_z = engine->screen->map[i_row][i_column].z * 20;
			engine->screen->projection[i_row][i_column].x = tmp_x * cos_z + tmp_y * -sin_z + tmp_x * cos_y + tmp_z * sin_y;
			engine->screen->projection[i_row][i_column].y = tmp_y * cos_x + tmp_z * sin_x + tmp_x * sin_z + tmp_y * cos_z;
			engine->screen->projection[i_row][i_column].z = -tmp_y * sin_x + tmp_z * cos_x + tmp_x * -sin_y +  tmp_z * cos_y;
			*/
			i_column++;
		}
		i_row++;
	}
}

void	ft_rotate_x(t_engine *engine, int i_row, int i_column)
{
	int	tmp_y;
	int	tmp_z;
	
	float	cos_x;
	float	sin_x;

	cos_x = cos(engine->screen->angle.x * M_PI / 180);
	sin_x = sin(engine->screen->angle.x * M_PI / 180);

	tmp_y = engine->screen->proj[i_row][i_column].y;
	tmp_z = engine->screen->proj[i_row][i_column].z;

	engine->screen->proj[i_row][i_column].y = tmp_y * cos_x + tmp_z * sin_x;
	engine->screen->proj[i_row][i_column].z = tmp_y * - sin_x + tmp_z * cos_x;
}

void	ft_rotate_y(t_engine *engine, int i_row, int i_column)
{
	int	tmp_x;
	int	tmp_z;
	
	float	cos_y;
	float	sin_y;

	cos_y = cos(engine->screen->angle.y * M_PI / 180);
	sin_y = sin(engine->screen->angle.y * M_PI / 180);

	tmp_x = engine->screen->proj[i_row][i_column].x;
	tmp_z = engine->screen->proj[i_row][i_column].z;

	engine->screen->proj[i_row][i_column].x = tmp_x * cos_y + tmp_z * - sin_y;
	engine->screen->proj[i_row][i_column].z = tmp_x * sin_y +  tmp_z * cos_y;
}

void	ft_rotate_z(t_engine *engine, int i_row, int i_column)
{
	int	tmp_x;
	int	tmp_y;
	

	float	cos_z;
	float	sin_z;
	
	cos_z = cos(engine->screen->angle.z * M_PI / 180);
	sin_z = sin(engine->screen->angle.z * M_PI / 180);

	tmp_x = engine->screen->proj[i_row][i_column].x;
	tmp_y = engine->screen->proj[i_row][i_column].y;

	engine->screen->proj[i_row][i_column].x = tmp_x * cos_z + tmp_y * sin_z;
	engine->screen->proj[i_row][i_column].y = tmp_x * - sin_z + tmp_y * cos_z;

}

void	ft_get_point(t_engine *engine, int row, int column, t_3d_point *point)
{

	//printf("angle_x=%i cos_x=%f sin_x=%f\n", engine->screen->angle.x, cos_x, sin_x);
	point->x = engine->screen->offset.x + engine->screen->proj[row][column].x + engine->screen->movement.x;
	point->y = engine->screen->offset.y + engine->screen->proj[row][column].y + engine->screen->movement.y;
	//point->y = engine->screen->offset.y + row * engine->screen->zoom * cos(engine->screen->angle.x * M_PI / 180);
	//point->y = (int) (engine->screen->resolution.height / 2) - (row * engine->screen->zoom + engine->screen->pivot.row_half * 0.5 * engine->screen->zoom)
	//	+ row * engine->screen->zoom * cos(engine->screen->angle.x * M_PI / 180);
	//printf("cos(%i)=%.2f\n", engine->screen->angle.x, cos(engine->screen->angle.x * M_PI / 180));
	//point->x = (engine->screen->offset.x + column * engine->screen->angle.x) - (row * engine->screen->angle.x);
	//point->y = (engine->screen->offset.y + row * engine->screen->angle.y) + (column * engine->screen->angle.y) - engine->screen->map[row][column] * engine->screen->angle.z;
}
