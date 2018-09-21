/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:20:34 by mmahloko          #+#    #+#             */
/*   Updated: 2018/09/01 10:50:55 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int		verify(char *str)
{
	if (ft_strcmp("sa", str) == 0 || ft_strcmp("sb", str) == 0)
		return (1);
	else if (ft_strcmp("pa", str) == 0 || ft_strcmp("pb", str) == 0)
		return (1);
	else if (ft_strcmp("ra", str) == 0 || ft_strcmp("rb", str) == 0)
		return (1);
	else if (ft_strcmp("rra", str) == 0 || ft_strcmp("rrb", str) == 0)
		return (1);
	else if (ft_strcmp("rrr", str) == 0 || ft_strcmp("ss", str) == 0)
		return (1);
	else if (ft_strcmp("rr", str) == 0)
		return (1);
	ft_putendl_fd("Error", 2);
	return (0);
}

static char		**reading_fd(t_stack *a, char *line)
{
	char	**cmd;

	if (first_read(a, &line))
		return (NULL);
	cmd = (char **)malloc(sizeof(char *) * 2);
	cmd[0] = ft_strdup(line);
	ft_strdel(&line);
	cmd[1] = NULL;
	if (verify(cmd[0]))
		while (get_next_line(0, &line) == 1)
		{
			if (verify(line))
				cmd = ft_array_join_s(cmd, line);
			else
			{
				ft_strdel(&line);
				ft_arraydel_s(&cmd);
				break ;
			}
			ft_strdel(&line);
		}
	else
		ft_arraydel_s(&cmd);
	return (cmd);
}

static void		s_cases(t_stack **a, t_stack **b, char *str)
{
	if (ft_strcmp("rrr", str) == 0)
	{
		rev_rotate(a);
		rev_rotate(b);
	}
	else if (ft_strcmp("ss", str) == 0)
	{
		swap(a);
		swap(b);
	}
	else if (ft_strcmp("rr", str) == 0)
	{
		rotate(a);
		rotate(b);
	}
}

static void		check_sort(t_stack **a, t_stack **b, char *str)
{
	if (ft_strcmp("sa", str) == 0)
		swap(a);
	else if (ft_strcmp("sb", str) == 0)
		swap(b);
	else if (ft_strcmp("pa", str) == 0)
		push_a(a, b);
	else if (ft_strcmp("pb", str) == 0)
		push_b(a, b);
	else if (ft_strcmp("ra", str) == 0)
		rotate(a);
	else if (ft_strcmp("rb", str) == 0)
		rotate(b);
	else if (ft_strcmp("rra", str) == 0)
		rev_rotate(a);
	else if (ft_strcmp("rrb", str) == 0)
		rev_rotate(b);
	else
		s_cases(a, b, str);
}

void			checker(t_stack **a, t_stack **b)
{
	char	**cmd;
	char	*line;
	int		i;

	i = -1;
	line = NULL;
	cmd = reading_fd(*a, line);
	if (cmd)
	{
		while (cmd[++i])
			check_sort(a, b, cmd[i]);
		if (issorted_a(*a) && !*b)
			ft_putendl("OK");
		else
			ft_putendl("KO");
		ft_arraydel_s(&cmd);
	}
}
