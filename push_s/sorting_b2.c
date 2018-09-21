/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_b2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 16:30:44 by mmahloko          #+#    #+#             */
/*   Updated: 2018/09/02 11:04:07 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*medi_of_stacks(t_stack *a)
{
	int		*tab;
	int		i;
	int		num;

	i = 0;
	num = 24;
	tab = (int *)malloc(sizeof(int) * 2);
	while (i < 2)
	{
		median(a, &tab[i++], num);
		num += 25;
	}
	return (tab);
}

static void	stack_of_hun(t_stack **a, t_stack **b, int size)
{
	int		*tab;

	tab = (int *)malloc(sizeof(int) * 2);
	median(*a, &tab[0], (size / 4) - 1);
	median(*a, &tab[1], (size / 2) - 1);
	divide_stack(a, b, tab);
	free(tab);
	tab = NULL;
}

void		advanced_ai(t_stack **a, t_stack **b)
{
	int		i;
	int		*tab;
	int		nu_stacks;

	i = 0;
	nu_stacks = stack_size(*a) / 100;
	if (stack_size(*a) <= 100)
		stack_of_hun(a, b, stack_size(*a));
	else if (stack_size(*a) > 100)
	{
		while (++i <= 6)
		{
			tab = medi_of_stacks(*a);
			divide_stack(a, b, tab);
			free(tab);
			tab = NULL;
		}
	}
}
