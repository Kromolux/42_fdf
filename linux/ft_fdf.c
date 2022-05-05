/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:21:52 by rkaufman          #+#    #+#             */
/*   Updated: 2022/03/08 14:56:30 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_init_fdf(t_engine *engine);

int	main(int argc, char **argv)
{
	t_engine	fdf;

	ft_init_fdf(&fdf);
	if (argc != 2)
		return (ft_error_arguments());
	fdf.screen = ft_read_input_map(argv[1]);
	ft_engine_init(&fdf);
	fdf.file = (char *) malloc(ft_strlen(argv[1]) + 1);
	if (!fdf.file)
		return (ft_error_malloc("main", "fdf.file", ft_strlen(argv[1]) + 1));
	ft_copy(fdf.file, argv[1], 0);
	mlx_hook(fdf.window, 17, 0, &ft_engine_destroy, &fdf);
	mlx_hook(fdf.window, 2, (1L << 0), &ft_key, &fdf);
	mlx_loop_hook(fdf.mlx, &ft_render_frame, &fdf);
	mlx_do_key_autorepeaton(fdf.mlx);
	mlx_loop(fdf.mlx);
}

static void	ft_init_fdf(t_engine *engine)
{
	engine->mlx = NULL;
	engine->window = NULL;
	engine->img0.img = NULL;
	engine->img0.addr = NULL;
	engine->img0.bits_per_pixel = 0;
	engine->img0.line_length = 0;
	engine->img0.endian = 0;
	engine->img1.img = NULL;
	engine->img1.addr = NULL;
	engine->img1.bits_per_pixel = 0;
	engine->img1.line_length = 0;
	engine->img1.endian = 0;
	engine->img = NULL;
	engine->file = NULL;
	engine->screen = NULL;
}
