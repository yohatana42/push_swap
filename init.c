/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:38:29 by yohatana          #+#    #+#             */
/*   Updated: 2024/11/03 21:48:37 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack_a(int argc, char **argv, t_stack *stack_a)
{
	int	i;
	int	*stack;

	i = 1;
	stack = (int *)ft_calloc(sizeof(int), DEFAULT_LIMIT);
	if (!stack)
		error_stack(stack_a);
	while (i < argc)
	{
		stack[i - 1] = ft_atoi_ps(argv[i]);
		i++;
	}
	stack_a->stack = stack;
	stack_a->len = argc - 1;
	stack_a->min_index = 0;
	stack_a->max_index = 0;
	return (stack_a);
}

int	same_nbr_check(t_stack *stack_a)
{
	// printf("----same_nbr_check\n");
	int		nbr_1;
	int		nbr_2;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < stack_a->len)
	{
		j = i + 1;
		nbr_1 = stack_a->stack[i];
		while (j < stack_a->len)
		{
			nbr_2 = stack_a->stack[j];
			if (nbr_1 == nbr_2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	sort_check(t_stack *stack)
{
	// printf("----sort_check()\n");
	int		min;
	int		max;
	int		i;

	i = 0;
	if (stack->len == 1)
		return (0);
	while (i < stack->len - 1)
	{
		min = stack->stack[i];
		max = stack->stack[i + 1];
		if (min > max)
			return (1);
		i++;
	}
	return (0);
}
