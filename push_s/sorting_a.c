/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 07:57:20 by mmahloko          #+#    #+#             */
/*   Updated: 2018/08/30 18:53:54 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		c_sort_three(t_stack **stack, int a, int b, int c)
{
	if (a > b && a > c && b > c)
	{
		rotate(stack);
		swap(stack);
		ft_putendl("ra\nsa");
	}
	else if (c < b && c > a && b > a)
	{
		swap(stack);
		rotate(stack);
		ft_putendl("sa\nra");
	}
	else if (a < b && a > c && b > c)
	{
		rev_rotate(stack);
		ft_putendl("rra");
	}
	else if (a > b && a > c && b < c)
	{
		rotate(stack);
		ft_putendl("ra");
	}
}

static void		sort_three(t_stack **stack)
{
	t_stack	*fst;
	t_stack	*sec;
	t_stack	*lst;

	if (issorted_a(*stack) || stack_size(*stack) != 3)
		return ;
	fst = *stack;
	sec = fst->next;
	lst = sec->next;
	if (fst->x > sec->x && fst->x < lst->x && sec->x < lst->x)
	{
		swap(stack);
		ft_putendl("sa");
	}
	else
		c_sort_three(stack, fst->x, sec->x, lst->x);
}

static void		sort_four(t_stack **a, t_stack **b)
{
	int		m;
	int		rev_m;

	find_min(*a, &m);
	find_min_rev(*a, &rev_m);
	if (m <= rev_m)
		algo_push_min(a, b, m);
	else
		algo_push_min_rev(a, b, rev_m);
	sort_three(a);
}

static void		sort_five(t_stack **a, t_stack **b)
{
	int		m;
	int		rev_m;

	find_min(*a, &m);
	find_min_rev(*a, &rev_m);
	if (m <= rev_m)
		algo_push_min(a, b, m);
	else
		algo_push_min_rev(a, b, rev_m);
	sort_four(a, b);
}

void			sort_stack_a(t_stack **a, t_stack **b)
{
	if (!*a || issorted_a(*a))
		return ;
	else if (stack_size(*a) == 2)
	{
		swap(a);
		ft_putendl("sa");
	}
	else if (stack_size(*a) == 3)
		sort_three(a);
	else if (stack_size(*a) == 4)
		sort_four(a, b);
	else if (stack_size(*a) == 5)
		sort_five(a, b);
	else
		acending_order(a);
}
