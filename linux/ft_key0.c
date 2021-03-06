/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:57:03 by rkaufman          #+#    #+#             */
/*   Updated: 2022/03/08 19:16:28 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_key(int keycode, t_engine *engine)
{
	if (keycode == XK_Escape)
		ft_engine_destroy(engine);
	else if (keycode == XK_Left || keycode == XK_Right
		|| keycode == XK_Up || keycode == XK_Down)
		ft_key_screen_movement(keycode, engine);
	else if (keycode == XK_a || keycode == XK_d
		|| keycode == XK_s || keycode == XK_w
		|| keycode == XK_q || keycode == XK_e)
		ft_key_rotation(keycode, engine);
	else if (keycode == XK_i || keycode == XK_p)
		ft_key_projection_change(keycode, engine);
	else if (keycode == XK_PLUS || keycode == XK_MINUS
		|| keycode == XK_f || keycode == XK_v
		|| keycode == XK_plus || keycode == XK_minus)
		ft_key_zoom(keycode, engine);
	else if (keycode == XK_Home)
		ft_key_center_view(keycode, engine);
	return (0);
}

void	ft_key_center_view(int keycode, t_engine *engine)
{
	if (keycode == XK_Home)
	{
		engine->screen->movement.x = 0;
		engine->screen->movement.y = 0;
		engine->screen->movement.z = 0;
	}
}

void	ft_key_projection_change(int keycode, t_engine *engine)
{
	if (keycode == XK_i)
	{
		engine->screen->angle.x = -35;
		engine->screen->angle.y = 35;
		engine->screen->angle.z = -35;
		engine->screen->paralel = 0;
	}
	else if (keycode == XK_p)
	{
		engine->screen->angle.x = 0;
		engine->screen->angle.y = 0;
		engine->screen->angle.z = 0;
		engine->screen->paralel = 1;
	}
}

void	ft_key_screen_movement(int keycode, t_engine *engine)
{
	if (keycode == XK_Left)
		engine->screen->movement.x -= 1 * (engine->screen->zoom / 2);
	else if (keycode == XK_Right)
		engine->screen->movement.x += 1 * (engine->screen->zoom / 2);
	else if (keycode == XK_Up)
		engine->screen->movement.y -= 1 * (engine->screen->zoom / 2);
	else if (keycode == XK_Down)
		engine->screen->movement.y += 1 * (engine->screen->zoom / 2);
}

void	ft_key_rotation(int keycode, t_engine *engine)
{
	if (keycode == XK_a)
		engine->screen->angle.y++;
	else if (keycode == XK_d)
		engine->screen->angle.y--;
	else if (keycode == XK_s)
		engine->screen->angle.x++;
	else if (keycode == XK_w)
		engine->screen->angle.x--;
	else if (keycode == XK_q)
		engine->screen->angle.z++;
	else if (keycode == XK_e)
		engine->screen->angle.z--;
}
