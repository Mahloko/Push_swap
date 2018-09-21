/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 08:25:44 by mmahloko          #+#    #+#             */
/*   Updated: 2018/08/30 18:48:48 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_generate(t_stack **a, char *s)
{
	t_stack	*node;
	t_stack	*tmp;

	if (!(node = (t_stack *)malloc(sizeof(t_stack))))
		return ;
	node->x = ft_atoi(s);
	node->next = NULL;
	node->prev = NULL;
	if (!*a)
	{
		*a = node;
		return ;
	}
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	node->prev = tmp;
}

void			create_stack(t_stack **a, char **data)
{
	int	i;

	i = -1;
	while (data[++i])
		ft_generate(a, data[i]);
}

int				stack_size(t_stack *stack)
{
	int		size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void			push_stack(t_stack **a, t_stack **b)
{
	if (!*b && !*a)
		return ;
	while (*b)
	{
		push_a(a, b);
		ft_putendl("pa");
		if ((*a)->x > (*a)->next->x)
		{
			swap(a);
			ft_putendl("sa");
		}
	}
}

void			clear_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack)
		return ;
	while (*stack)
	{
		tmp = *stack;
		*stack = tmp->next;
		if (tmp)
		{
			tmp->next = NULL;
			tmp->prev = NULL;
			free(tmp);
		}
	}
}
