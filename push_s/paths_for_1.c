/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_for_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 10:50:43 by mmahloko          #+#    #+#             */
/*   Updated: 2018/09/02 11:07:42 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	verify(t_stack *stack, int q)
{
	while (stack)
	{
		if (stack->x <= q)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static void	c_divide_stack(t_stack **a, t_stack **b, int *q)
{
	t_stack	*tmp;

	while (verify(*a, q[1]))
	{
		tmp = *a;
		while (tmp->next)
			tmp = tmp->next;
		if (tmp->x <= q[1])
		{
			rev_rotate(a);
			push_b(a, b);
			ft_putendl("rra\npb");
			if ((*b)->x <= q[0])
			{
				rotate(b);
				ft_putendl("rb");
			}
		}
		else
		{
			tmp = tmp->prev;
			rev_rotate(a);
			ft_putendl("rra");
		}
	}
}

static void	div_stack(t_stack **a, t_stack **b, int *q)
{
	while (verify(*a, q[1]))
		if ((*a)->x <= q[1])
		{
			push_b(a, b);
			ft_putendl("pb");
			if ((*b)->x <= q[0])
			{
				rotate(b);
				ft_putendl("rb");
			}
		}
		else
		{
			rotate(a);
			ft_putendl("ra");
		}
}

void		divide_stack(t_stack **a, t_stack **b, int *tab)
{
	t_point	les_q;
	t_point	les_p;

	while (verify(*a, tab[1]))
		if (q_find_min(*a, &les_p, &les_q))
			c_divide_stack(a, b, tab);
		else
			div_stack(a, b, tab);
}
