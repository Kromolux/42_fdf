/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:19:38 by rkaufman          #+#    #+#             */
/*   Updated: 2022/02/23 13:32:45 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_engine_init(t_engine *engine)
{
	engine->mlx = mlx_init();
	engine->window = mlx_new_window(engine->mlx, WIDTH, HEIGHT, TITLE);
	engine->img0.img = mlx_new_image(engine->mlx, WIDTH, HEIGHT);
	engine->img0.addr = mlx_get_data_addr(engine->img0.img,
								&engine->img0.bits_per_pixel,
								&engine->img0.line_length,
								&engine->img0.endian);
	engine->img1.img = mlx_new_image(engine->mlx, WIDTH, HEIGHT);
	engine->img1.addr = mlx_get_data_addr(engine->img1.img,
								&engine->img1.bits_per_pixel,
								&engine->img1.line_length,
								&engine->img1.endian);
	engine->img = &engine->img0;
}

int	ft_engine_destroy(t_engine *engine)
{
	mlx_destroy_image(engine->mlx, engine->img0.img);
	mlx_destroy_image(engine->mlx, engine->img1.img);
	mlx_destroy_window(engine->mlx, engine->window);
	mlx_destroy_display(engine->mlx);
	free(engine->mlx);
	ft_free_map(engine->screen);
	free(engine->file);
	exit(1);
}
