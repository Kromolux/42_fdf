/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:06:57 by rkaufman          #+#    #+#             */
/*   Updated: 2022/03/08 06:43:08 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_assign_struct_values(t_map *screen, char *input);
static void	ft_assign_map_values(t_map *screen, char **string_array);

void	ft_create_map_array(char *input, t_map *screen)
{
	char	**string_array;
	int		size;

	ft_assign_struct_values(screen, input);
	ft_replace_in_string(input, '\n', ' ');
	string_array = ft_split(input, ' ');
	if (!string_array)
		ft_error_split(screen, input);
	free(input);
	size = 0;
	while (string_array[size])
		size++;
	if (size != screen->rows * screen->columns)
		ft_error_input(screen, string_array);
	ft_check_input_exit_on_error(screen, string_array);
	ft_allocate_mem_map(screen, string_array);
	ft_assign_map_values(screen, string_array);
}

static void	ft_assign_struct_values(t_map *screen, char *input)
{
	screen->rows = ft_count_of_in_str(input, '\n');
	screen->columns = ft_count_of_columns(input, '\n');
	if (ft_char_in_str(input, ','))
		screen->colored = 1;
	screen->pivot.row = (int) screen->rows / 2;
	screen->pivot.column = (int) screen->columns / 2;
	screen->angle.x = -35;
	screen->angle.y = 35;
	screen->angle.z = -35;
	screen->zoom = (int) screen->resolution.width
		/ (screen->rows + screen->columns);
	screen->zoom_z = 1;
	screen->offset.x = (int)(screen->resolution.width / 2);
	screen->offset.y = (int)(screen->resolution.height / 2);
}

static void	ft_assign_map_values(t_map *screen, char **string_array)
{
	int	i;
	int	i_row;
	int	i_column;

	i = 0;
	i_row = 0;
	while (i_row < screen->rows)
	{
		i_column = 0;
		while (i_column < screen->columns)
		{
			screen->map[i_row][i_column].x = i_column - screen->pivot.column;
			screen->map[i_row][i_column].y = i_row - screen->pivot.row;
			screen->map[i_row][i_column].z = ft_string_to_int(string_array[i]);
			if (screen->colored == 0 || !ft_char_in_str(string_array[i], ','))
				screen->map[i_row][i_column].color = 0x00FFFFFF;
			else
				screen->map[i_row][i_column].color
					= ft_string_to_hex(string_array[i]);
			i_column++;
			i++;
		}
		i_row++;
	}
	ft_free_char_array(string_array);
}
