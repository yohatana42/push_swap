/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:28:20 by yohatana          #+#    #+#             */
/*   Updated: 2024/11/03 22:33:13 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		error();
	else
	{
		stack_a = (t_stack *)ft_calloc(sizeof(t_stack), 1);
		if (!stack_a)
			error();
		create_stack_a(argc, argv, stack_a);
		// validation check まとめる
		stack_b = (t_stack *)ft_calloc(sizeof(t_stack), 1);
		if (!stack_b)
			error_stack(stack_a);
		if (same_nbr_check(stack_a) == 1)
			error_stack(stack_a);
		if (sort_check(stack_a) == 1)
		{
			// printf("sort untill \n");
			sort_exec(stack_a, stack_b);
		}
		printf("sort done\n");
		for (int i = 0; i < stack_a->len; i++)
		{
			printf("i %d stack_a->stack[i] %d\n", i, stack_a->stack[i]);
		}
		free_all(stack_a);
		free_all(stack_b);
	}
	return (SUCCESS);
}

void	free_all(t_stack *stack)
{
	if (stack != NULL)
	{
		// printf("stack is not null\n");
		if (stack->stack != NULL)
		{
			// printf("stack->stack is not null\n");
			free(stack->stack);
		}

		free(stack);
	}
}

int	error(void)
{
	ft_printf("Error\n");
	exit(ERROR);
}

int	error_stack(t_stack *stack)
{
	free_all(stack);
	ft_printf("Error\n");
	exit(ERROR);
}
