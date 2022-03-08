/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 06:21:37 by rkaufman          #+#    #+#             */
/*   Updated: 2022/03/01 09:01:27 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_alloc_map(t_map *screen, char **string_array);
static void	ft_alloc_proj(t_map *screen, char **string_array);

void	ft_allocate_mem_map(t_map *screen, char **string_array)
{
	screen->map = (t_3d_point **) malloc(sizeof(t_3d_point *) * screen->rows);
	if (!screen->map)
		ft_error_map(screen, string_array);
	screen->proj = (t_3d_point **) malloc(sizeof(t_3d_point *) * screen->rows);
	if (!screen->proj)
		ft_error_proj(screen, string_array);
	ft_alloc_map(screen, string_array);
	ft_alloc_proj(screen, string_array);
}

static void	ft_alloc_map(t_map *screen, char **string_array)
{
	int	i_row;

	i_row = 0;
	while (i_row < screen->rows)
	{
		screen->map[i_row] = (t_3d_point *) malloc(sizeof(t_3d_point)
				* screen->columns);
		if (!screen->map[i_row])
			ft_error_map_row(screen, string_array, i_row);
		i_row++;
	}
}

static void	ft_alloc_proj(t_map *screen, char **string_array)
{
	int	i_row;

	i_row = 0;
	while (i_row < screen->rows)
	{
		screen->proj[i_row] = (t_3d_point *) malloc(sizeof(t_3d_point)
				* screen->columns);
		if (!screen->proj[i_row])
			ft_error_proj_row(screen, string_array, i_row);
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
