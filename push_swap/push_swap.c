/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:01:04 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/02/21 19:53:00 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		i;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (1);
	if (!ft_check_if_valid(argv, argc))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	pute_node(&stack_a, argv, argc);
	i = check_how_many(&stack_a);
	if (not_sorted(&stack_a))
		check_sort_type(&stack_a, &stack_b, i);
	else
		ft_free_stack(&stack_a);
	return (0);
}
