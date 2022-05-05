/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:55:51 by rkaufman          #+#    #+#             */
/*   Updated: 2022/02/24 16:58:48 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tools.h"

void	*ft_calloc(size_t size)
{
	void	*output;
	size_t	i;

	output = malloc(size);
	if (!output)
		return (NULL);
	i = 0;
	while (i < size)
	{
		((char *)output)[i] = '\0';
		i++;
	}
	return (output);
}
