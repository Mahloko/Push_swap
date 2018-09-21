/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristics2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 13:35:59 by mmahloko          #+#    #+#             */
/*   Updated: 2018/09/01 11:27:09 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		algo_push_max_rev(t_stack **a, t_stack **b, t_point p)
{
	int		c;

	c = 0;
	while (c != 3)
		if ((*b)->x == p.n1 || (*b)->x == p.n2 || (*b)->x == p.n3)
		{
			push_a(a, b);
			ft_putendl("pa");
			sort_stack_a(a, b);
			c++;
		}
		else
		{
			rev_rotate(b);
			ft_putendl("rrb");
		}
}

static void		algo_push_max(t_stack **a, t_stack **b, t_point p)
{
	int		c;

	c = 0;
	while (c != 3)
		if ((*b)->x == p.n1 || (*b)->x == p.n2 || (*b)->x == p.n3)
		{
			push_a(a, b);
			ft_putendl("pa");
			sort_stack_a(a, b);
			c++;
		}
		else
		{
			rotate(b);
			ft_putendl("rb");
		}
}

static void		maximum(t_point *m, t_point p, t_stack *stack)
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

void			sort_from_b(t_stack **a, t_stack **b)
{
	t_point	p;
	t_point	q;
	t_point m;
	int		i;

	while (!issorted_b(*b) && stack_size(*b) > 3)
	{
		sort_stack_b(b);
		i = q_find_max(*b, &p, &q);
		maximum(&m, p, *b);
		if (i)
			algo_push_max_rev(a, b, m);
		else
			algo_push_max(a, b, m);
		sort_stack_a(a, b);
	}
	sort_stack_b(b);
	sort_stack_a(a, b);
}
