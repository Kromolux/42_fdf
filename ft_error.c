/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:23:15 by rkaufman          #+#    #+#             */
/*   Updated: 2022/03/01 07:42:42 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_error_arguments(void)
{
	ft_printf("Error! Program needs 2 arguments.\n./fdf <file_to_open>.fdf\n");
	return (1);
}

int	ft_error_malloc(char *function, char *variable, size_t size)
{
	ft_printf("Error! Not enough memory for allocating space for [%s] [%i]"
		"bytes by function: %s\n", variable, size, function);
	return (1);
}

int	ft_error_file(char *function, char *file)
{
	ft_printf("Error! Can not open file [%s] by function: %s.\n", file,
		function);
	return (1);
}

int	ft_error_file_result(char *function, char *file, int fd)
{
	ft_printf("Error! Empty file or read failed [%s] by function: %s\n",
		file, function);
	close(fd);
	return (1);
}
