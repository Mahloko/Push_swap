/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 18:44:30 by mmahloko          #+#    #+#             */
/*   Updated: 2018/09/02 11:24:40 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int				first_read(t_stack *a, char **line)
{
	if (get_next_line(0, line) != 1)
	{
		if (issorted_a(a))
			ft_putendl("OK");
		else
			ft_putendl("KO");
		return (1);
	}
	return (0);
}

int				main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
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
			ft_arraydel_s(&arr);
			ft_strdel(&str);
		}
		else
			ft_putendl_fd("Error", 2);
		if (a)
			checker(&a, &b);
		clear_stack(&a);
		clear_stack(&b);
	}
	return (0);
}
