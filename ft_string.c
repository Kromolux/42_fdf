/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:53:48 by rkaufman          #+#    #+#             */
/*   Updated: 2022/03/01 09:01:07 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_check_number(int i, char c1, char c2);

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

void	ft_check_input_exit_on_error(t_map *screen, char **input)
{
	size_t	i_row;

	i_row = 0;
	while (input[i_row])
	{
		if (!ft_valid_number(input[i_row]))
		{
			ft_printf("Error! Invalid number [%s] in .fdf file input[%i] by"
				" function ft_check_input_exit_on_error\n", input[i_row], i_row);
			free(screen);
			ft_free_char_array(input);
			exit(1);
		}
		i_row++;
	}
}

int	ft_valid_number(char *argv)
{
	int		i;
	int		i_arg;

	i = 0;
	i_arg = 0;
	while (argv[i])
	{
		if (argv[i] == ' ')
		{
			while (argv[i] == ' ')
				i++;
			i_arg = 0;
		}
		if (argv[i] < '0' || argv[i] > '9')
		{
			if (argv[i] == ',' && !ft_check_hex(&argv[i]))
			{
				if (!ft_check_number(i_arg, argv[i], argv[i + 1]))
					return (0);
			}
		}
		i_arg++;
		i++;
	}
	return (1);
}

static int	ft_check_number(int i, char c1, char c2)
{
	if (i > 0 || (c1 != '+' && c1 != '-') || c2 < '0' || c2 > '9')
		return (0);
	return (1);
}
