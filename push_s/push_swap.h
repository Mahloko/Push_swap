/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 18:43:38 by mmahloko          #+#    #+#             */
/*   Updated: 2018/09/01 16:27:34 by mmahloko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct		s_stack
{
	int				x;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct		s_point
{
	int				n1;
	int				n2;
	int				n3;
}					t_point;

void				swap(t_stack **stack);
void				rotate(t_stack **stack);
void				sort_stack_b(t_stack **b);
int					stack_size(t_stack *stack);
int					issorted_a(t_stack *stack);
int					issorted_b(t_stack *stack);
void				print_stack(t_stack *stack);
void				rev_rotate(t_stack **stack);
void				clear_stack(t_stack **stack);
int					rev_stack_size(t_stack *stack);
void				acending_order(t_stack **stack);
void				print_stack_rev(t_stack *stack);
void				decending_order(t_stack **stack);
void				push_a(t_stack **a, t_stack **b);
void				push_b(t_stack **a, t_stack **b);
void				find_min(t_stack *stack, int *i);
void				push_swap(t_stack **a, t_stack **b);
void				find_min_rev(t_stack *stack, int *i);
int					input(char **av, int ac, char **str);
void				push_stack(t_stack **a, t_stack **b);
void				sort_stack(t_stack **a, t_stack **b);
void				create_stack(t_stack **a, char **data);
void				sort_from_b(t_stack **a, t_stack **b);
void				advanced_ai(t_stack **a, t_stack **b);
void				sort_stack_a(t_stack **a, t_stack **b);
void				divide_stack(t_stack **a, t_stack **b, int *tab);
void				median(t_stack *stack, int	*q, int div);
void				sort_from_a(t_stack **a, t_stack **b, int *nu);
void				algo_push_min(t_stack **a, t_stack **b, int pos);
int					q_find_max(t_stack *stack, t_point *p, t_point *q);
int					q_find_min(t_stack *stack, t_point *p, t_point *q);
void				algo_push_min_rev(t_stack **a, t_stack **b, int	pos);

#endif
