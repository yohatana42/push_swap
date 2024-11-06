/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:29:28 by yohatana          #+#    #+#             */
/*   Updated: 2024/10/31 21:55:30 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "printf/libftprintf.h"

# define SUCCESS 0
# define ERROR -1
# define DEFAULT_LIMIT 1000

typedef struct s_stack
{
	int		*stack;
	size_t	len;
	int		max_index;
	int		min_index;
}		t_stack;

// enum
typedef struct s_command
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}		t_command;

// init
t_stack	*create_stack_a(int argc, char **argv, t_stack *stack_a);
int		same_nbr_check(t_stack *stack_a);
int		sort_check(t_stack *stack);

// push_swap
int		sort_exec(t_stack *stack_a, t_stack *stack_b);
void	sort_3(t_stack *stack_a);
void	large_sort(t_stack *stack_a, t_stack *stack_b);
void	small_sort(t_stack *stack_a, t_stack *stack_b);

// get_num
int		get_max_index(t_stack *stack);
int		get_min_index(t_stack *stack);
int		get_max(t_stack *stack);
int		get_min(t_stack *stack);

// main
int		error(void);
int		error_stack(t_stack *stack);
void	free_all(t_stack *stack);

// ft_atoi_ps
int		ft_atoi_ps(const char *str);

//stack_move_a
int	sa(t_stack *stack_a);
int	pa(t_stack *stack_a, t_stack *stack_b);
int	ra(t_stack *stack_a);
int	rra(t_stack *stack_a);

//stack_move_b
int	sb(t_stack *stack_b);
int	pb(t_stack *stack_a, t_stack *stack_b);
int	rb(t_stack *stack_b);
int	rrb(t_stack *stack_b);

//stack_move_both
int	ss(t_stack *stack_a, t_stack *stack_b);
int	rr(t_stack *stack_a, t_stack *stack_b);
int	rrr(t_stack *stack_a, t_stack *stack_b);

// command
void	rotate(t_stack *stack);
void	swap(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	push(t_stack *stack_1, t_stack *stack_2);

// sort
void	radix_sort(t_stack *stack_a, t_stack *stack_b);

#endif
