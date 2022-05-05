/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 06:51:18 by rkaufman          #+#    #+#             */
/*   Updated: 2022/03/08 19:06:54 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_key_zoom(int keycode, t_engine *engine)
{
	if (keycode == XK_PLUS || keycode == XK_PLUS2)
	{
		if (engine->screen->zoom >= 20)
			engine->screen->zoom += 5;
		else
			engine->screen->zoom += 1;
	}
	else if (keycode == XK_MINUS || keycode == XK_MINUS2)
	{
		if (engine->screen->zoom >= 25)
			engine->screen->zoom -= 5;
		else if (engine->screen->zoom > 1)
			engine->screen->zoom -= 1;
	}
	else if (keycode == XK_F)
		engine->screen->zoom_z += 1;
	else if (keycode == XK_V)
		engine->screen->zoom_z -= 1;
}
