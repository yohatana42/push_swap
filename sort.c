/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 21:20:20 by yohatana          #+#    #+#             */
/*   Updated: 2024/11/06 14:56:14 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack *stack)
{
	int	max;
	int	max_bits;

	max_bits = 0;
	max = get_max(stack);
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bits;
	int	bit_pos;
	int	index;

	max_bits = get_max_bits(stack_a);
	printf("max_bits %d nbr %d\n", max_bits , get_max(stack_a));
	bit_pos = 0;
	index = 0;
	printf("stack_a->len: %zu\n", stack_a->len);

	while (bit_pos++ < max_bits)
	{
		// このワイルはちゃんと動いてる
		printf("bit_pos: %d max_bits: %d\n", bit_pos, max_bits);
		for (int i =0; i < stack_a->len; i++)
		{
			printf("i: %d stack_a->stack[i]: %d\n", i, stack_a->stack[i]);
		}
		index = 0;
		// while (index++ < stack_a->len - 1)
		while (index < stack_a->len)
		{
			printf ("index :%d\n", index);
			// ビットシフトして1になるかどうか
			if (((stack_a->stack[index] >> index) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			index++;
		}
		printf("stack_b->len: %zu\n", stack_b->len);
		while (stack_b->len > 0)
			pa(stack_a, stack_b);
	}
}
