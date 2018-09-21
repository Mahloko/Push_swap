/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_for_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 10:57:05 by mmahloko          #+#    #+#             */
/*   Updated: 2018/08/30 14:30:38 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		find_max(t_stack *stack, t_point *p)
{
	int		max;
	int		count;

	count = 0;
	max = stack->x;
	while ((stack = stack->next) && (++count))
		if (max < stack->x && p->n2 != count && p->n3 != count)
		{
			max = stack->x;
			p->n1 = count;
		}
}

static void		find_max_rev(t_stack *stack, t_point *q)
{
	int		max;
	int		count;

	while (stack->next)
		stack = stack->next;
	count = 1;
	max = stack->x;
	while ((stack = stack->prev) && (++count))
		if (max < stack->x && q->n2 != count && q->n3 != count)
		{
			max = stack->x;
			q->n1 = count;
		}
}

static void		find_3_max(t_stack *stack, t_point *p)
{
	int		max;
	int		count;
	t_stack	*tmp;

	count = 0;
	tmp = stack;
	max = stack->next->x;
	while ((stack = stack->next) && (++count))
		if (max < stack->x && count != p->n1 && count != p->n3)
		{
			max = stack->x;
			p->n2 = count;
		}
	count = -1;
	max = tmp->next->next->x;
	while (tmp && (++count + 1))
		if (max < tmp->x && count != p->n2 && count != p->n1)
		{
			max = tmp->x;
			p->n3 = count--;
		}
		else
			tmp = tmp->next;
}

static void		find_3_max_rev(t_stack *stack, t_point *q)
{
	int		max;
	int		count;
	t_stack	*tmp;

	count = 1;
	tmp = stack;
	max = stack->prev->x;
	while ((stack = stack->prev) && (++count))
		if (max < stack->x && count != q->n1 && count != q->n3)
		{
			max = stack->x;
			q->n2 = count;
		}
	count = 0;
	max = tmp->prev->prev->x;
	while (tmp && (++count))
		if (max < tmp->x && count != q->n2 && count != q->n1)
		{
			max = tmp->x;
			q->n3 = count--;
		}
		else
			tmp = tmp->prev;
}

int				q_find_max(t_stack *stack, t_point *p, t_point *q)
{
	int		s;
	int		r;

	p->n1 = 0;
	p->n2 = 1;
	p->n3 = 2;
	q->n1 = 1;
	q->n3 = 3;
	q->n2 = 2;
	find_max(stack, p);
	find_3_max(stack, p);
	find_max_rev(stack, q);
	while (stack->next)
		stack = stack->next;
	find_3_max_rev(stack, q);
	r = q->n1 + q->n2 + q->n3;
	s = p->n1 + p->n2 + p->n3;
	if (r <= s)
		return (1);
	return (0);
}
