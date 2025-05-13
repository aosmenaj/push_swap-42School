/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pute_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:48:27 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/02/22 11:54:04 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pute_node(t_node **stack_a, char **argv, int argc)
{
	int	n;
	int	i;
	int	error;
	int	pos;

	i = 1;
	while (argc > i)
	{
		pos = 0;
		while (pos != -1)
		{
			n = myatoi(argv[i], &error, &pos);
			if (error || repeat_contr(*stack_a, n))
				ft_exit(stack_a);
			fill_node(stack_a, n);
		}
		i++;
	}
	return ;
}
