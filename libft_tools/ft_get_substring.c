/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_substring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:44:09 by rkaufman          #+#    #+#             */
/*   Updated: 2022/02/24 13:44:30 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tools.h"

char	*ft_get_substring(char const *s, size_t start, size_t len)
{
	char	*substring;
	size_t	s_len;
	size_t	bytes;

	if (!s)
		return (NULL);
	s_len = 0;
	while (s[s_len])
		s_len++;
	if (start > s_len)
		bytes = 0;
	else
		bytes = s_len - start;
	substring = (char *) malloc(bytes + 1);
	if (!substring)
		return (NULL);
	if (start <= s_len)
		ft_copy(substring, (char *) &s[start], len + 1);
	else
		substring[0] = '\0';
	return (substring);
}
