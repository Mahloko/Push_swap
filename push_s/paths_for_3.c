/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_for_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 10:49:50 by mmahloko          #+#    #+#             */
/*   Updated: 2018/09/01 11:30:05 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		qfind_min(t_stack *stack, t_point *p)
{
	int		min;
	int		count;

	if (!stack)
		return ;
	count = 0;
	min = stack->x;
	while ((stack = stack->next) && (++count))
		if (min > stack->x && p->n2 != count && p->n3 != count)
		{
			min = stack->x;
			p->n1 = count;
		}
}

static void		qfind_min_rev(t_stack *stack, t_point *q)
{
	int		min;
	int		count;

	if (!stack)
		return ;
	while (stack->next)
		stack = stack->next;
	count = 1;
	min = stack->x;
	while ((stack = stack->prev) && (++count))
		if (min > stack->x && !(q->n2 == count || q->n3 == count))
		{
			min = stack->x;
			q->n1 = count;
		}
}

static void		find_3_min(t_stack *stack, t_point *p)
{
	int		min;
	int		count;
	t_stack	*tmp;

	count = 0;
	tmp = stack;
	min = stack->next->x;
	while ((stack = stack->next) && (++count))
		if (min > stack->x && count != p->n1 && count != p->n3)
		{
			min = stack->x;
			p->n2 = count;
		}
	count = -1;
	min = tmp->next->next->x;
	while (tmp && (++count + 1))
		if (min > tmp->x && count != p->n2 && count != p->n1)
		{
			min = tmp->x;
			p->n3 = count--;
		}
		else
			tmp = tmp->next;
}

static void		find_3_min_rev(t_stack *stack, t_point *q)
{
	int		min;
	int		count;
	t_stack	*tmp;

	count = 1;
	tmp = stack;
	min = stack->prev->x;
	while ((stack = stack->prev) && (++count))
		if (min > stack->x && count != q->n1 && count != q->n3)
		{
			min = stack->x;
			q->n2 = count;
		}
	count = 0;
	min = tmp->prev->prev->x;
	while (tmp && (++count))
		if (min > tmp->x && count != q->n2 && count != q->n1)
		{
			min = tmp->x;
			q->n3 = count--;
		}
		else
			tmp = tmp->prev;
}

int				q_find_min(t_stack *stack, t_point *p, t_point *q)
{
	int		s;
	int		r;

	p->n1 = 0;
	p->n2 = 1;
	p->n3 = 2;
	q->n1 = 1;
	q->n3 = 3;
	q->n2 = 2;
	qfind_min(stack, p);
	qfind_min_rev(stack, q);
	if (!stack->next->next)
		return (0);
	find_3_min(stack, p);
	while (stack->next)
		stack = stack->next;
	find_3_min_rev(stack, q);
	r = q->n1 + q->n2 + q->n3;
	s = p->n1 + p->n2 + p->n3;
	if (r <= s)
		return (1);
	return (0);
}
