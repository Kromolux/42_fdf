/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:21:52 by rkaufman          #+#    #+#             */
/*   Updated: 2022/02/23 13:37:31 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_someting(t_engine *engine);

int	main(int argc, char **argv)
{
	t_engine	fdf;

	if (argc != 2)
		return (-1);
	fdf.screen = ft_read_input_map(argv[1]);
	ft_engine_init(&fdf);
	fdf.file = (char *) malloc(ft_strlen(argv[1]) + 1);
	if (!fdf.file)
		return (-1);
	ft_copy(fdf.file, argv[1], 0);
	//ft_draw_map(&fdf);
	//read map
	//ft_draw_someting(&fdf);
	//ft_render_frame(&fdf);

	mlx_hook(fdf.window, 17, 0, &ft_engine_destroy, &fdf);
	mlx_key_hook(fdf.window, &ft_key, &fdf);
	mlx_do_key_autorepeaton(fdf.mlx);
	//mlx_loop_hook(fdf.mlx, &close, &fdf);
	mlx_loop_hook(fdf.mlx, &ft_render_frame, &fdf);
	mlx_loop(fdf.mlx);
	//ft_engine_destroy(&fdf);
}

//int offset = (y * line_length + x * (bits_per_pixel / 8));

void	ft_draw_someting(t_engine *engine)
{
	t_line	line;

	line.start.x = 0;
	line.start.y = 0;
	line.start.color = 0x00FF0000;
	line.end.x = 500;
	line.end.y = 500;
	line.end.color = 0x00FF0000;
	ft_draw_rectangle(engine, line);
	//line.start.color = 0x000000FF;
	//ft_draw_line(engine, line);
	
	line.start.x = 800;
	line.start.y = 450;
	line.start.color = 0x00FF0000;
	
	line.end.x = 400;
	line.end.y = 0;
	ft_draw_line(engine, line);
	line.end.x = 801;
	line.end.y = 0;
	ft_draw_line(engine, line);
	line.end.x = 1200;
	line.end.y = 0;
	ft_draw_line(engine, line);
	line.end.x = 1599;
	line.end.y = 0;
	ft_draw_line(engine, line);

	line.end.x = 1599;
	line.end.y = 225;
	ft_draw_line(engine, line);
	line.end.x = 1599;
	line.end.y = 451;
	ft_draw_line(engine, line);
	line.end.x = 1599;
	line.end.y = 675;
	ft_draw_line(engine, line);
	line.end.x = 1599;
	line.end.y = 899;
	ft_draw_line(engine, line);

	line.end.x = 1200;
	line.end.y = 899;
	ft_draw_line(engine, line);
	line.end.x = 801;
	line.end.y = 899;
	ft_draw_line(engine, line);
	line.end.x = 400;
	line.end.y = 899;
	ft_draw_line(engine, line);
	
	line.end.x = 0;
	line.end.y = 899;
	ft_draw_line(engine, line);
	
	line.end.x = 0;
	line.end.y = 675;
	ft_draw_line(engine, line);
	
	line.end.x = 0;
	line.end.y = 451;
	ft_draw_line(engine, line);
	
	line.end.x = 0;
	line.end.y = 225;
	ft_draw_line(engine, line);
	
	line.end.x = 0;
	line.end.y = 0;
	ft_draw_line(engine, line);
	
}
