/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 16:20:17 by mmahloko          #+#    #+#             */
/*   Updated: 2018/09/01 16:27:31 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					rev_stack_size(t_stack *stack)
{
	int		size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->prev;
	}
	return (size);
}

static void			algor_push_min_rev(t_stack **a, t_stack **b, t_point p)
{
	int		c;

	c = 0;
	while (c != 3)
		if ((*a)->x == p.n1 || (*a)->x == p.n2 || (*a)->x == p.n3)
		{
			push_b(a, b);
			ft_putendl("pb");
			sort_stack_b(b);
			c++;
		}
		else
		{
			rev_rotate(a);
			ft_putendl("rra");
		}
}

static void			algor_push_min(t_stack **a, t_stack **b, t_point p)
{
	int		c;

	c = 0;
	while (c != 3)
		if ((*a)->x == p.n1 || (*a)->x == p.n2 || (*a)->x == p.n3)
		{
			push_b(a, b);
			ft_putendl("pb");
			sort_stack_b(b);
			c++;
		}
		else
		{
			rotate(a);
			ft_putendl("ra");
		}
}

static void			minimum(t_point *m, t_point p, t_stack *stack)
{
	int		i;
	t_stack	*t;
	t_stack	*t1;

	i = -1;
	t = stack;
	t1 = stack;
	while (++i < p.n1)
		stack = stack->next;
	m->n1 = stack->x;
	i = -1;
	while (++i < p.n2)
		t = t->next;
	m->n2 = t->x;
	i = -1;
	while (++i < p.n3)
		t1 = t1->next;
	m->n3 = t1->x;
}

void				sort_from_a(t_stack **a, t_stack **b, int *nu)
{
	t_point	p;
	t_point	m;
	t_point	q;
	int		i;

	while (!issorted_a(*a))
	{
		i = q_find_min(*a, &p, &q);
		minimum(&m, p, *a);
		if (i)
			algor_push_min_rev(a, b, m);
		else
			algor_push_min(a, b, m);
		*nu += 3;
		sort_stack_b(b);
		sort_stack_a(a, b);
	}
	sort_stack_b(b);
}
