/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_node_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:26:03 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/31 19:04:36 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		finish_rotation(t_stack **stack, t_stack *top_node,
					char stack_name);
static void		rotate_both(t_stack **stack_a, t_stack **stack_b,
					t_stack *cheapest_node);
static void		reverse_rotate_both(t_stack **stack_a, t_stack **stack_b,
					t_stack *cheapest_node);
static t_stack	*find_cheapest_node(t_stack *stack);

void	move_nodes_to_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;
	t_stack	*target_node;

	cheapest_node = find_cheapest_node(*stack_b);
	target_node = cheapest_node->target_node;
	if (cheapest_node->above_median == true
		&& target_node->above_median == true)
		rotate_both(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->above_median) && !(target_node->above_median))
		reverse_rotate_both(stack_a, stack_b, cheapest_node);
	finish_rotation(stack_b, cheapest_node, 'b');
	finish_rotation(stack_a, target_node, 'a');
	pa(stack_a, stack_b, true);
}

static void	finish_rotation(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median == true)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median == true)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}

static	void	rotate_both(t_stack **stack_a, t_stack **stack_b,
	t_stack *cheapest_node)
{
	t_stack	*target_node;

	target_node = cheapest_node->target_node;
	while ((*stack_a != target_node) && (*stack_b != cheapest_node))
		rr(stack_a, stack_b, true);
	set_current_position(*stack_a);
	set_current_position(*stack_b);
}

static	void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b,
	t_stack *cheapest_node)
{
	while (*stack_a != cheapest_node->target_node && *stack_b != cheapest_node)
		rrr(stack_a, stack_b, true);
	set_current_position(*stack_a);
	set_current_position(*stack_b);
}

static	t_stack	*find_cheapest_node(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest_cost == true)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
