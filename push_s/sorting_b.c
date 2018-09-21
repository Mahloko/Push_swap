/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 13:18:21 by mmahloko          #+#    #+#             */
/*   Updated: 2018/08/30 18:09:37 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			issorted_b(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->x > stack->next->x)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}

static void	c_decending(t_stack **stack, int a, int b, int c)
{
	if (a > b && a < c && b < c)
	{
		rotate(stack);
		swap(stack);
		rev_rotate(stack);
		swap(stack);
		ft_putendl("rb\nsb\nrrb\nsb");
	}
	else if (a < b && a < c && b > c)
	{
		swap(stack);
		rotate(stack);
		swap(stack);
		rev_rotate(stack);
		ft_putendl("sb\nrb\nsb\nrrb");
	}
	else if (a < b && a < c && b < c)
	{
		swap(stack);
		rotate(stack);
		swap(stack);
		rev_rotate(stack);
		swap(stack);
		ft_putendl("sb\nrb\nsb\nrrb\nsb");
	}
}

void		decending_order(t_stack **stack)
{
	int		*a;
	int		*b;
	int		*c;

	a = &(*stack)->x;
	b = &(*stack)->next->x;
	c = &(*stack)->next->next->x;
	if (issorted_b(*stack))
		return ;
	else if (*a > *b && *a > *c && *b < *c)
	{
		rotate(stack);
		swap(stack);
		rev_rotate(stack);
		ft_putendl("rb\nsb\nrrb");
	}
	else if (*a < *b && *a > *c && *b > *c)
	{
		swap(stack);
		ft_putendl("sb");
	}
	else
		c_decending(stack, *a, *b, *c);
}

void		sort_stack_b(t_stack **b)
{
	if (!*b || issorted_b(*b))
		return ;
	else if (stack_size(*b) == 2)
	{
		swap(b);
		ft_putendl("sb");
	}
	else
		decending_order(b);
}
