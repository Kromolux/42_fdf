/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:21:52 by rkaufman          #+#    #+#             */
/*   Updated: 2022/03/08 10:42:36 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_engine	fdf;

	fdf.screen = NULL;
	if (argc != 2)
		return (ft_error_arguments());
	fdf.screen = ft_read_input_map(argv[1]);
	ft_engine_init(&fdf);
	fdf.file = (char *) malloc(ft_strlen(argv[1]) + 1);
	if (!fdf.file)
		return (ft_error_malloc("main", "fdf.file", ft_strlen(argv[1]) + 1));
	ft_copy(fdf.file, argv[1], 0);
	mlx_hook(fdf.window, 17, 0, &ft_engine_destroy, &fdf);
	mlx_hook(fdf.window, 2, 0, &ft_key, &fdf);
	mlx_loop_hook(fdf.mlx, &ft_render_frame, &fdf);
	mlx_do_key_autorepeaton(fdf.mlx);
	mlx_loop(fdf.mlx);
}
