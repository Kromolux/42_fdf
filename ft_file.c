/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:23:46 by rkaufman          #+#    #+#             */
/*   Updated: 2022/02/24 16:12:26 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*ft_read_input_map(char *file)
{
	t_map	*output;
	int		fd;
	char	*read_file_result;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	read_file_result = ft_read_file(fd);
	if (!read_file_result)
		return (NULL);
	close(fd);
	output = (t_map *) malloc(sizeof(t_map));
	if (!output)
		return (NULL);
	ft_create_map_array(read_file_result, output);
	return (output);
}
