/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_node_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:06:25 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/31 18:58:08 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_cheapest_node(t_stack *stack_b);
static void	set_cost_move(t_stack *stack_a, t_stack *stack_b);
static void	set_target_node(t_stack *stack_a, t_stack *stack_b);

void	init_atributtes_nodes(t_stack *stack_a, t_stack *stack_b)
{
	set_current_position(stack_a);
	set_current_position(stack_b);
	set_target_node(stack_a, stack_b);
	set_cost_move(stack_a, stack_b);
	set_cheapest_node(stack_b);
}

void	set_current_position(t_stack *stack)
{
	int	index_position;
	int	central_line;

	index_position = 0;
	if (stack == NULL)
		return ;
	central_line = get_stack_len(stack) / 2;
	while (stack != NULL)
	{
		stack->current_position = index_position;
		if (index_position <= central_line)
			stack->above_median = true;
		else
			stack->above_median = false;
		index_position++;
		stack = stack->next;
	}
}

static void	set_target_node(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_node_a;
	t_stack	*target_node;
	long	best_match_index;

	while (stack_b)
	{
		best_match_index = LONG_MAX;
		current_node_a = stack_a;
		while (current_node_a)
		{
			if (current_node_a->value > stack_b->value
				&& current_node_a->value < best_match_index)
			{
				best_match_index = current_node_a->value;
				target_node = current_node_a;
			}
			current_node_a = current_node_a->next;
		}
		if (best_match_index == LONG_MAX)
			stack_b->target_node = find_smallest_node(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

static void	set_cost_move(t_stack *stack_a, t_stack *stack_b)
{
	int	stack_len_a;
	int	stack_len_b;

	stack_len_a = get_stack_len(stack_a);
	stack_len_b = get_stack_len(stack_b);
	while (stack_b)
	{
		stack_b->cost = stack_b->current_position;
		if (!(stack_b->above_median))
			stack_b->cost = stack_len_b - (stack_b->current_position);
		if (stack_b->target_node->above_median)
			stack_b->cost += stack_b->target_node->current_position;
		else
			stack_b->cost += stack_len_a
				- (stack_b->target_node->current_position);
		stack_b = stack_b->next;
	}
}

static	void	set_cheapest_node(t_stack *stack_b)
{
	long	best_match_value;
	t_stack	*best_match_node;

	if (stack_b == NULL)
		return ;
	best_match_value = LONG_MAX;
	while (stack_b != NULL)
	{
		if (stack_b->cost < best_match_value)
		{
			best_match_value = stack_b->cost;
			best_match_node = stack_b;
		}
		stack_b = stack_b->next;
	}
	best_match_node->cheapest_cost = true;
}
