/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myatoi_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:17:46 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/02/23 17:19:15 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	myisdigit(int ch)
{
	if ('0' <= ch && ch <= '9')
		return (1);
	return (0);
}

static int	check_limits(long long val, int sign, int *error)
{
	if (-2147483648 <= val * sign && val * sign <= 2147483647)
	{
		*error = 0;
		return (1);
	}
	*error = 1;
	return (0);
}

static	void	skip_init_spaces(char const *s, int *pos)
{
	while (' ' == s[*pos] || '\t' == s[*pos])
		++*pos;
}

static	int	set_sign(char c, int *pos)
{
	if ('-' == c)
	{
		++*pos;
		return (-1);
	}
	return (1);
}

int	myatoi_bonus(char const *s, int *err, int *pos)
{
	int			sign;
	long long	ret;

	skip_init_spaces(s, pos);
	sign = set_sign(s[*pos], pos);
	ret = 0;
	while (s[*pos] && myisdigit(s[*pos]) && ret <= 2147483647)
	{
		ret *= 10;
		ret += s[*pos] - '0';
		++*pos;
	}
	skip_init_spaces(s, pos);
	if (!check_limits(ret, sign, err))
		*err = 1;
	if (s[*pos] == '\0')
		*pos = -1;
	return ((int)ret * sign);
}
