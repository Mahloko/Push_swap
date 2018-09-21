/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 07:46:03 by mmahloko          #+#    #+#             */
/*   Updated: 2018/09/02 11:08:48 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		algo_push_min_rev(t_stack **a, t_stack **b, int pos)
{
	int		i;

	i = 0;
	while (!issorted_a(*a))
		if (i == pos)
		{
			push_b(a, b);
			ft_putendl("pb");
			return ;
		}
		else
		{
			rev_rotate(a);
			ft_putendl("rra");
			i++;
		}
}

void		algo_push_min(t_stack **a, t_stack **b, int pos)
{
	int		i;

	i = 0;
	while (!issorted_a(*a))
		if (i == pos)
		{
			push_b(a, b);
			ft_putendl("pb");
			return ;
		}
		else
		{
			rotate(a);
			ft_putendl("ra");
			i++;
		}
}

void		push_swap(t_stack **a, t_stack **b)
{
	if (issorted_a(*a) || *b)
		return ;
	else if (stack_size(*a) <= 5)
		sort_stack_a(a, b);
	else
		sort_stack(a, b);
	push_stack(a, b);
}
