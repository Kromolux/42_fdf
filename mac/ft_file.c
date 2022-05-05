/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:23:46 by rkaufman          #+#    #+#             */
/*   Updated: 2022/03/08 06:44:47 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_init_struct_t_map(t_map *var);

t_map	*ft_read_input_map(char *file)
{
	t_map	*output;
	int		fd;
	char	*read_file_result;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(ft_error_file("ft_read_input_map", file));
	read_file_result = ft_read_file(fd);
	if (!read_file_result)
		exit(ft_error_file_result("ft_read_file", file, fd));
	close(fd);
	output = (t_map *) malloc(sizeof(t_map));
	ft_init_struct_t_map(output);
	if (!output)
	{
		free(read_file_result);
		exit(ft_error_malloc("ft_read_input_map", "output", sizeof(t_map)));
	}
	ft_create_map_array(read_file_result, output);
	return (output);
}

static void	ft_init_struct_t_map(t_map *var)
{
	var->map = NULL;
	var->proj = NULL;
	var->paralel = 0;
	var->colored = 0;
	var->rows = 0;
	var->columns = 0;
	var->zoom = 0;
	var->zoom_z = 1;
	var->resolution.width = WIDTH;
	var->resolution.height = HEIGHT;
	var->pivot.column = 0;
	var->pivot.row = 0;
	var->offset.x = 0;
	var->offset.y = 0;
	var->offset.z = 0;
	var->factor.x = 0;
	var->factor.y = 0;
	var->factor.z = 0;
	var->angle.x = 0;
	var->angle.y = 0;
	var->angle.z = 0;
	var->movement.x = 0;
	var->movement.y = 0;
	var->movement.z = 0;
}
