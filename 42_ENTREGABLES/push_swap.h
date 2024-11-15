/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:24:48 by juagomez          #+#    #+#             */
/*   Updated: 2024/11/15 00:04:58 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <stddef.h>

// #include <stdio.h>

# include "./libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;

	int				current_position;
	bool			above_median;

	struct s_stack	*target_node;
	int				cost;
	bool			cheapest_cost;	
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

char	**split_push_swap(char *str, char separator);

void	init_stack(t_stack **stack, char **argv);
bool	is_stack_sorted(t_stack *stack);
void	free_stack(t_stack **stack);
void	append_node(t_stack **stack, int number);
t_stack	*find_highest_node(t_stack *stack);
t_stack	*find_smallest_node(t_stack *stack);
t_stack	*find_last_node(t_stack *stack);
int		get_stack_len(t_stack *stack);

void	pa(t_stack **stack_a, t_stack **stack_b, bool print);
void	pb(t_stack **stack_b, t_stack **stack_a, bool print);

void	ra(t_stack **stack_a, bool print);
void	rb(t_stack **stack_b, bool print);
void	rr(t_stack **stack_a, t_stack **stack_b, bool print);

void	rra(t_stack **stack_a, bool print);
void	rrb(t_stack **stack_b, bool print);
void	rrr(t_stack **stack_a, t_stack **stack_b, bool print);

void	sa(t_stack **stack_a, bool print);
void	sb(t_stack **stack_b, bool print);
void	ss(t_stack **stack_a, t_stack **stack_b, bool print);

void	push_swap(t_stack **stack_a, t_stack **stack_b);

void	sort_three(t_stack **stack);
void	sort_small_stack(t_stack **stack_a, t_stack **stack_b);
void	sort_big_stack(t_stack **stack_a, t_stack **stack_b);

void	rotate_stack_a(t_stack **stack_a);

void	sort_to_stack_a(t_stack **stack_a, t_stack **stack_b);
void	init_atributtes_nodes(t_stack *stack_a, t_stack *stack_b);
void	set_current_position(t_stack *stack);
void	move_nodes_to_stack_a(t_stack **stack_a, t_stack **stack_b);

#endif
