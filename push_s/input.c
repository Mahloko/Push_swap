/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 17:50:11 by mmahloko          #+#    #+#             */
/*   Updated: 2018/09/01 12:23:11 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		isdoub(char *ndle, char **str)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (str[++i])
		if (ft_strcmp(str[i], ndle) == 0)
			count++;
	if (count >= 2)
		return (1);
	return (0);
}

static int		ft_notint(char *s)
{
	int		i;

	i = 0;
	while (s[i] == '0')
		i++;
	if (s[0] == '-')
		i++;
	if (ft_strlen(s + i) > 10)
		return (1);
	return (0);
}

static int		ft_overflow(char *str)
{
	char	*min;
	char	*max;
	int		len;

	min = "2147483648";
	max = "2147483647";
	len = ft_strlen(str);
	str = (len == 11 && *str == '-') ? str + 1 : str;
	while (*str && str[0] != '-')
	{
		if (len == 10)
		{
			if (ft_strncmp(str, max, 1) > 0)
				return (1);
			max++;
		}
		else if (len == 11)
		{
			if (ft_strncmp(str, min, 1) > 0)
				return (1);
			min++;
		}
		str++;
	}
	return (0);
}

static int		verify(char *s)
{
	int		i;
	int		j;
	int		k;
	char	**arr;

	arr = ft_strsplit(s, ' ');
	k = 1;
	i = -1;
	while (arr[++i] && k)
	{
		j = -1;
		if (arr[i][0] == '-')
			j++;
		while (arr[i][++j])
			if (!(arr[i][j] >= '0' && arr[i][j] <= '9') || isdoub(arr[i], arr))
				k = 0;
		if (ft_overflow(arr[i]))
			k = 0;
		if (ft_notint(arr[i]))
			k = 0;
	}
	ft_arraydel_s(&arr);
	return (k);
}

int				input(char **av, int ac, char **str)
{
	char	*temp;
	int		i;

	i = 1;
	temp = ft_strdup(av[i++]);
	while (i < ac)
	{
		*str = ft_strjoin(temp, " ");
		ft_strdel(&temp);
		temp = ft_strjoin(*str, av[i++]);
		ft_strdel(str);
		*str = temp;
	}
	if (ac == 2)
		*str = temp;
	if (!verify(temp))
		return (0);
	return (1);
}
