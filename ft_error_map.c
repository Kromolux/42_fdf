/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 06:06:56 by rkaufman          #+#    #+#             */
/*   Updated: 2022/03/01 07:53:53 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error_split(t_map *screen, char *input)
{
	ft_error_malloc("ft_split", "string_array", 0);
	free(input);
	free(screen);
	exit(1);
}

void	ft_error_map(t_map *screen, char **string_array)
{
	ft_error_malloc("ft_create_map_array", "screen->map",
		sizeof(t_3d_point *) * screen->rows);
	ft_free_char_array(string_array);
	free(screen);
	exit(1);
}

void	ft_error_proj(t_map *screen, char **string_array)
{
	ft_error_malloc("ft_create_map_array", "screen->proj",
		sizeof(t_3d_point *) * screen->rows);
	ft_free_char_array(string_array);
	free(screen->map);
	free(screen);
	exit(1);
}

void	ft_error_map_row(t_map *screen, char **string_array, int i_row)
{
	ft_error_malloc("ft_create_map_array", "screen->map[i_row]",
		sizeof(t_3d_point *) * screen->columns);
	ft_free_char_array(string_array);
	while (i_row > 0)
	{
		i_row--;
		free(screen->map[i_row]);
	}
	free(screen->map);
	free(screen);
	exit(1);
}

void	ft_error_proj_row(t_map *screen, char **string_array, int i_row)
{
	ft_error_malloc("ft_create_map_array", "screen->proj[i_row]",
		sizeof(t_3d_point *) * screen->columns);
	ft_free_char_array(string_array);
	while (i_row > 0)
	{
		i_row--;
		free(screen->proj[i_row]);
	}
	i_row = 0;
	while (i_row < screen->rows)
	{
		free(screen->map[i_row]);
		i_row++;
	}
	free(screen->map);
	free(screen);
	exit(1);
}
