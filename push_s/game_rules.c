/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 07:45:05 by mmahloko          #+#    #+#             */
/*   Updated: 2018/08/25 10:22:07 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	int		hold;
	t_stack	*tmp;

	if (!*stack || !(tmp = (*stack)->next))
		return ;
	hold = tmp->x;
	tmp->x = (*stack)->x;
	(*stack)->x = hold;
}

void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = tmp->next;
	if (*b)
		(*b)->prev = NULL;
	tmp->next = *a;
	if (*a)
		(*a)->prev = tmp;
	*a = tmp;
}

void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = tmp->next;
	if (*a)
		(*a)->prev = NULL;
	tmp->next = *b;
	if (*b)
		(*b)->prev = tmp;
	*b = tmp;
}

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*cursor;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	cursor = *stack;
	*stack = cursor->next;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = tmp;
	(*stack)->prev = NULL;
	tmp->prev = cursor;
	tmp->next = NULL;
}

void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*cursor;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	cursor = *stack;
	while (cursor->next->next)
		cursor = cursor->next;
	tmp = cursor->next;
	tmp->next = *stack;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	cursor->next = NULL;
	*stack = tmp;
}
