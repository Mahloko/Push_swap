/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristics1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 11:32:07 by mmahloko          #+#    #+#             */
/*   Updated: 2018/09/02 11:07:05 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			find_min(t_stack *stack, int *i)
{
	int		min;
	int		count;

	if (!stack)
		return ;
	*i = 0;
	count = 0;
	min = stack->x;
	while ((stack = stack->next) && (++count))
		if (min > stack->x)
		{
			min = stack->x;
			*i = count;
		}
}

void			find_min_rev(t_stack *stack, int *i)
{
	int		min;
	int		count;

	if (!stack)
		return ;
	while (stack->next)
		stack = stack->next;
	*i = 1;
	count = 1;
	min = stack->x;
	while ((stack = stack->prev) && (++count))
		if (min > stack->x)
		{
			min = stack->x;
			*i = count;
		}
}

static void		sort_int_tab(int **tab, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size - 1)
		if ((*tab)[i] < (*tab)[i + 1])
			while ((i < size - 1) && ((*tab)[i] < (*tab)[i + 1]))
				i++;
		else
		{
			j = 0;
			while (i + j < size - 1 && ((*tab)[i + j] > (*tab)[i + j + 1]))
			{
				ft_swap(&(*tab)[i + j], &(*tab)[i + j + 1]);
				j++;
			}
			i = 0;
		}
}

void			median(t_stack *stack, int *q, int div)
{
	int		i;
	int		size;
	int		*tab;

	i = 0;
	size = stack_size(stack);
	tab = (int *)malloc(sizeof(int) * size);
	while (i < size)
	{
		tab[i++] = stack->x;
		stack = stack->next;
	}
	sort_int_tab(&tab, size);
	*q = tab[div];
	free(tab);
	tab = NULL;
}

void			sort_stack(t_stack **a, t_stack **b)
{
	int		nu;

	nu = 0;
	advanced_ai(a, b);
	sort_from_a(a, b, &nu);
	while (nu > 0)
	{
		push_a(a, b);
		ft_putendl("pa");
		if ((*a)->next)
			if ((*a)->x > (*a)->next->x)
			{
				swap(a);
				ft_putendl("sa");
			}
		nu--;
	}
	sort_from_b(a, b);
}
