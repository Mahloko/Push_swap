/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 17:51:18 by mmahloko          #+#    #+#             */
/*   Updated: 2018/09/02 12:40:19 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_stack	*a;
	t_stack *b;
	char	*str;
	char	**arr;

	a = NULL;
	b = NULL;
	arr = NULL;
	if (ac > 1)
	{
		if (input(av, ac, &str))
		{
			arr = ft_strsplit(str, ' ');
			create_stack(&a, arr);
			ft_strdel(&str);
			ft_arraydel_s(&arr);
		}
		else
			ft_putendl_fd("Error", 2);
		if (a)
			push_swap(&a, &b);
		clear_stack(&a);
		clear_stack(&b);
	}
	return (0);
}
