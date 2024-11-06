/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:40:32 by yohatana          #+#    #+#             */
/*   Updated: 2024/11/03 22:14:53 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// return 1 is error
int	sort_exec(t_stack *stack_a, t_stack *stack_b)
{
	// printf("---sort_exec---\n");
	int			*stack;
	int			len;

	stack = (int *)ft_calloc(sizeof(int), DEFAULT_LIMIT);
	if (!stack)
	{
		free(stack_b);
		error_stack(stack_a);
	}
	stack_b->stack = stack;
	stack_b->min_index = 0;
	stack_b->max_index = 0;
	if (stack_a->len == 2)
		sa(stack_a);
	else if (stack_a->len == 3)
		sort_3(stack_a);
	else if (stack_a->len < 6)
		small_sort(stack_a, stack_b);
	else
		large_sort(stack_a, stack_b);
	return (0);
}

void	sort_3(t_stack *stack_a)
{
	int	max;

	// printf("---few_sort---\n");
	max = get_max(stack_a);
	if (max == stack_a->stack[0])
		ra(stack_a);
	else if (max == stack_a->stack[1])
		rra(stack_a);
	if (stack_a->stack[0] > stack_a->stack[1])
	{
		sa(stack_a);
	}

	// for (int i =0; i < stack_a->len; i++)
	// {
	// 	printf("stack_a[i] %d\n", stack_a->stack[i]);
	// }
}

void	small_sort(t_stack *stack_a, t_stack *stack_b)
{
	// printf("---small_sort\n");
	int	*stack;
	int	min_index;

	if (stack_a->len == 4)
	{
		// printf("----- init ------\n");
		// for (int i =0; i < stack_a->len; i++)
		// {
		// 	printf("1 stack_a[i] %d\n", stack_a->stack[i]);
		// }
		// printf("-----------\n");
		// printf("get_min_index(stack_a) > (stack_a->len / 2) %d\n", get_min_index(stack_a) > (stack_a->len / 2));
		// このへんがおかしい
		if ((stack_a->len / 2) > get_min_index(stack_a))
		{
			while (get_min_index(stack_a) != 0)
			{
				ra(stack_a);
				for (int i =0; i < stack_a->len; i++)
				{
					// printf("2 stack_a[i] %d\n", stack_a->stack[i]);
				}
			}
		}
		else
		{
			while (get_min_index(stack_a) != 0)
			{
				rra(stack_a);
				for (int i =0; i < stack_a->len; i++)
				{
					// printf("2 stack_a[i] %d\n", stack_a->stack[i]);
				}
			}
		}

		// printf("---- top min number ----\n");
		// for (int i =0; i < stack_a->len; i++)
		// {
		// 	printf("2 stack_a[i] %d\n", stack_a->stack[i]);
		// }
		// printf("-----------\n");
		pb(stack_a, stack_b);

		// for (int i =0; i < stack_a->len; i++)
		// {
		// 	printf("stack_a[i] %d\n", stack_a->stack[i]);
		// }
		// for (int i =0; i < stack_b->len; i++)
		// {
		// 	printf("stack_b[i] %d\n", stack_b->stack[i]);
		// }
// printf("-----------\n");
		sort_3(stack_a);
		// for (int i =0; i < stack_b->len; i++)
		// {
		// 	printf("stack_b[i] %d\n", stack_b->stack[i]);
		// }
		// printf("-----------\n");
		pa(stack_a, stack_b);
		// for (int i =0; i < stack_a->len; i++)
		// {
		// 	printf("stack_a[i] %d\n", stack_a->stack[i]);
		// }
		// for (int i =0; i < stack_b->len; i++)
		// {
		// 	printf("stack_b[i] %d\n", stack_b->stack[i]);
		// }
	}
	else if (stack_a->len == 5)
	{
		// min & min+ -> stack_b
		if ((stack_a->len / 2) > get_min_index(stack_a))
		{
			while (get_min_index(stack_a) != 0)
				ra(stack_a);
		}
		else
		{
			while (get_min_index(stack_a) != 0)
				rra(stack_a);
		}
		pb(stack_a, stack_b);
		if ((stack_a->len / 2) > get_min_index(stack_a))
		{
			while (get_min_index(stack_a) != 0)
				ra(stack_a);
		}
		else
		{
			while (get_min_index(stack_a) != 0)
				rra(stack_a);
		}
		pb(stack_a, stack_b);
		sort_3(stack_a);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}

void	large_sort(t_stack *stack_a, t_stack *stack_b)
{
	// printf("---large_sort\n");
	radix_sort(stack_a, stack_b);
}

