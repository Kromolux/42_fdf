/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:57:03 by rkaufman          #+#    #+#             */
/*   Updated: 2022/03/08 15:46:49 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_key(int keycode, t_engine *engine)
{
	if (keycode == XK_ESC)
		ft_engine_destroy(engine);
	else if (keycode == XK_LEFT || keycode == XK_RIGHT
		|| keycode == XK_UP || keycode == XK_DOWN)
		ft_key_screen_movement(keycode, engine);
	else if (keycode == XK_A || keycode == XK_D
		|| keycode == XK_S || keycode == XK_W
		|| keycode == XK_Q || keycode == XK_E)
		ft_key_rotation(keycode, engine);
	else if (keycode == XK_I || keycode == XK_P)
		ft_key_projection_change(keycode, engine);
	else if (keycode == XK_PLUS || keycode == XK_MINUS
		|| keycode == XK_F || keycode == XK_V)
		ft_key_zoom(keycode, engine);
	else if (keycode == XK_HOME)
		ft_key_center_view(keycode, engine);
	return (0);
}

void	ft_key_center_view(int keycode, t_engine *engine)
{
	if (keycode == XK_HOME)
	{
		engine->screen->movement.x = 0;
		engine->screen->movement.y = 0;
		engine->screen->movement.z = 0;
	}
}

void	ft_key_projection_change(int keycode, t_engine *engine)
{
	if (keycode == XK_I)
	{
		engine->screen->angle.x = -35;
		engine->screen->angle.y = 35;
		engine->screen->angle.z = -35;
		engine->screen->paralel = 0;
	}
	else if (keycode == XK_P)
	{
		engine->screen->angle.x = 0;
		engine->screen->angle.y = 0;
		engine->screen->angle.z = 0;
		engine->screen->paralel = 1;
	}
}

void	ft_key_screen_movement(int keycode, t_engine *engine)
{
	if (keycode == XK_LEFT)
		engine->screen->movement.x -= 1 * (engine->screen->zoom / 2);
	else if (keycode == XK_RIGHT)
		engine->screen->movement.x += 1 * (engine->screen->zoom / 2);
	else if (keycode == XK_UP)
		engine->screen->movement.y -= 1 * (engine->screen->zoom / 2);
	else if (keycode == XK_DOWN)
		engine->screen->movement.y += 1 * (engine->screen->zoom / 2);
}

void	ft_key_rotation(int keycode, t_engine *engine)
{
	if (keycode == XK_A)
		engine->screen->angle.y++;
	else if (keycode == XK_D)
		engine->screen->angle.y--;
	else if (keycode == XK_S)
		engine->screen->angle.x++;
	else if (keycode == XK_W)
		engine->screen->angle.x--;
	else if (keycode == XK_Q)
		engine->screen->angle.z++;
	else if (keycode == XK_E)
		engine->screen->angle.z--;
}
