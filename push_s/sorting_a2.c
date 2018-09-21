/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_a2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 15:05:59 by mmahloko          #+#    #+#             */
/*   Updated: 2018/08/30 18:55:39 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			issorted_a(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->x < stack->next->x)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}

static void	c_acending_order(t_stack **stack, int a, int b, int c)
{
	if (a < b && a > c && b > c)
	{
		rotate(stack);
		swap(stack);
		rev_rotate(stack);
		swap(stack);
		ft_putendl("ra\nsa\nrra\nsa");
	}
	else if (a > b && a > c && b > c)
	{
		swap(stack);
		rotate(stack);
		swap(stack);
		rev_rotate(stack);
		swap(stack);
		ft_putendl("sa\nra\nsa\nrra\nsa");
	}
	else if (a > b && a > c && b < c)
	{
		swap(stack);
		rotate(stack);
		swap(stack);
		rev_rotate(stack);
		ft_putendl("sa\nra\nsa\nrra");
	}
}

void		acending_order(t_stack **stack)
{
	int		*a;
	int		*b;
	int		*c;

	if (!*stack || stack_size(*stack) < 3)
		return ;
	a = &(*stack)->x;
	b = &(*stack)->next->x;
	c = &(*stack)->next->next->x;
	if (issorted_a(*stack))
		return ;
	else if (*a > *b && *a < *c && *b < *c)
	{
		swap(stack);
		ft_putendl("sa");
	}
	else if (*a < *b && *a < *c && *b > *c)
	{
		rotate(stack);
		swap(stack);
		rev_rotate(stack);
		ft_putendl("ra\nsa\nrra");
	}
	else
		c_acending_order(stack, *a, *b, *c);
}
