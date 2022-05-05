/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:23:22 by rkaufman          #+#    #+#             */
/*   Updated: 2022/03/02 19:02:13 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_get_calculations(t_engine *engine, t_sin_cos *calculations);
static void	ft_apply_zoom(t_map *screen, int i_row, int i_column);
static void	ft_apply_projection(t_map *screen, int i_row, int i_column);

unsigned int	ft_abs(int number)
{
	if (number < 0)
		return ((unsigned int)(number * -1));
	else
		return (number);
}

void	ft_apply_rotation(t_engine *engine)
{
	int			i_row;
	int			i_column;
	t_sin_cos	calcs;

	ft_get_calculations(engine, &calcs);
	i_row = 0;
	while (i_row < engine->screen->rows)
	{
		i_column = 0;
		while (i_column < engine->screen->columns)
		{
			engine->screen->proj[i_row][i_column].color
				= engine->screen->map[i_row][i_column].color;
			ft_apply_zoom(engine->screen, i_row, i_column);
			if (engine->screen->paralel == 1)
				ft_apply_projection(engine->screen, i_row, i_column);
			ft_rotate_x(engine, i_row, i_column, &calcs);
			ft_rotate_y(engine, i_row, i_column, &calcs);
			ft_rotate_z(engine, i_row, i_column, &calcs);
			i_column++;
		}
		i_row++;
	}
}

static void	ft_apply_zoom(t_map *screen, int i_row, int i_column)
{
	screen->proj[i_row][i_column].x = screen->map[i_row][i_column].x
		* screen->zoom;
	screen->proj[i_row][i_column].y = screen->map[i_row][i_column].y
		* screen->zoom;
	screen->proj[i_row][i_column].z = screen->map[i_row][i_column].z
		* screen->zoom_z;
}

static void	ft_get_calculations(t_engine *engine, t_sin_cos *calculations)
{
	calculations->cos_x = cos(engine->screen->angle.x * M_PI / 180);
	calculations->cos_y = cos(engine->screen->angle.y * M_PI / 180);
	calculations->cos_z = cos(engine->screen->angle.z * M_PI / 180);
	calculations->sin_x = sin(engine->screen->angle.x * M_PI / 180);
	calculations->sin_y = sin(engine->screen->angle.y * M_PI / 180);
	calculations->sin_z = sin(engine->screen->angle.z * M_PI / 180);
}

static void	ft_apply_projection(t_map *screen, int i_row, int i_column)
{
	if (screen->zoom_z > 0)
	{
		screen->proj[i_row][i_column].x -= screen->proj[i_row][i_column].z
			* screen->zoom_z;
		screen->proj[i_row][i_column].y -= screen->proj[i_row][i_column].z
			* screen->zoom_z;
	}
	else
	{
		screen->proj[i_row][i_column].x += screen->proj[i_row][i_column].z
			* screen->zoom_z;
		screen->proj[i_row][i_column].y += screen->proj[i_row][i_column].z
			* screen->zoom_z;
	}
}
