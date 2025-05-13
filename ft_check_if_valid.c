/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_if_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:03:48 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/02/22 11:10:14 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	myisdigit(int ch)
{
	if ('0' <= ch && ch <= '9')
		return (1);
	return (0);
}

static int	ft_is_good(char c)
{
	if (c != ' ' && c != '\t' && c != '-' && !myisdigit(c))
		return (0);
	return (1);
}

static int	ft_check_str(char *str)
{
	int	i;
	int	d_met;

	i = 0;
	d_met = 0;
	while (str[i])
	{
		if (!ft_is_good(str[i]))
			return (0);
		if (myisdigit(str[i]))
		{
			d_met = 1;
			if (str[i + 1] != ' ' && str[i + 1] != '\t'
				&& str[i + 1] != '\0' && !myisdigit(str[i + 1]))
				return (0);
		}
		if (str[i] == '-')
			if (!myisdigit(str[i + 1]))
				return (0);
		i++;
	}
	if (!d_met)
		return (0);
	return (1);
}

int	ft_check_if_valid(char **argv, int argc)
{
	int	i;

	i = 1;
	while (argc > i)
	{
		if (!ft_check_str(argv[i]))
			return (0);
		++i;
	}
	return (1);
}
