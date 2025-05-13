/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:01:10 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/02/22 11:18:36 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct node
{
	int				content;
	int				index;
	int				push_cost;
	int				above_median;
	int				cheapest;
	struct node		*target;
	struct node		*next;
	struct node		*previous;
}	t_node;

void	fill_node(t_node **stack, int n);
void	pute_node(t_node **stack_a, char **argv, int argc);
int		repeat_contr(t_node *a, long long n);
void	fill_node(t_node **stack, int n);
t_node	*find_last_node(t_node *stack);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pb(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_b, t_node **stack_a);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
int		not_sorted(t_node **stack_a);
int		check_how_many(t_node **stack);
void	check_sort_type(t_node **stack_a, t_node **stack_b, int i);
void	sort_three(t_node **stack);
void	ft_exit(t_node **stack_a);
void	full_sort(t_node **stack_a, t_node **stack_b, int i);
void	ft_free_stack(t_node **stack);
t_node	*ft_find_max_nb(t_node **stack);
t_node	*ft_find_cheapest_a(t_node **stack_a, t_node **stack_b, int i);
void	ft_push_in_b(t_node **stack_a, t_node **stack_b, int i,
			t_node	*cheapest);
int		ft_back_to_a(t_node **stack_a, t_node **stack_b, int i);
void	ft_push_in_a(t_node **stack_a, t_node **stack_b, int i,
			t_node	*cheapest);
void	ft_last_check(t_node **stack_a, int i);
void	ft_find_target_in_b(t_node **stack_a, t_node **stack_b);
void	ft_find_target_in_a(t_node **stack_a, t_node **stack_b);
t_node	*ft_find_cheapest_b(t_node **stack_b, int i);
int		ft_check_if_valid(char **argv, int argc);
int		myatoi(char const *s, int *err, int *pos);

#endif