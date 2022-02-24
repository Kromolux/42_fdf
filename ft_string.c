/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:53:48 by rkaufman          #+#    #+#             */
/*   Updated: 2022/02/24 18:05:57 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	ft_count_of_columns(char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			i++;
		else if (s[i] == c)
			return (count);
		else
		{
			while (s[i] && s[i] != c && s[i] != ' ')
				i++;
			count++;
		}
	}
	return (0);
}

char	*ft_get_screen_resolution_str(t_engine *engine)
{
	//char	*w;
	//char	*h;
	char	*output;
	//int		i;
	output = ft_sprintf("%ix%i", engine->screen->resolution.width, engine->screen->resolution.height);
	/*
	w = ft_int_to_string(engine->screen->resolution.width);
	h = ft_int_to_string(engine->screen->resolution.height);
	output = (char *) malloc(ft_strlen(w) + ft_strlen(h) + 2);
	i = ft_copy(output, w, 0);
	i += ft_copy(&output[i], "x", 0);
	ft_copy(&output[i], h, 0);
	free(w);
	free(h);
	*/
	return (output);
}
