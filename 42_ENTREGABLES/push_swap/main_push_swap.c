/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:26:03 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/31 19:18:08 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_a_len;

	stack_a_len = get_stack_len(*stack_a);
	if (stack_a_len == 2)
		sa(stack_a, true);
	else if (stack_a_len == 3)
		sort_three(stack_a);
	else if (stack_a_len > 3 && stack_a_len <= 5)
	{
		sort_small_stack(stack_a, stack_b);
		sort_three(stack_a);
	}
	else
	{
		sort_big_stack(stack_a, stack_b);
		sort_three(stack_a);
	}
	sort_to_stack_a(stack_a, stack_b);
	set_current_position(*stack_a);
	rotate_stack_a(stack_a);
}

void	rotate_stack_a(t_stack **stack_a)
{
	t_stack	*smallest_node;

	if (stack_a == NULL)
		return ;
	smallest_node = find_smallest_node(*stack_a);
	if (smallest_node->above_median == true)
		while (*stack_a != smallest_node)
			ra(stack_a, true);
	else
		while (*stack_a != smallest_node)
			rra(stack_a, true);
}

void	sort_to_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || stack_b == NULL)
		return ;
	while (*stack_b != NULL)
	{
		init_atributtes_nodes(*stack_a, *stack_b);
		move_nodes_to_stack_a(stack_a, stack_b);
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp_node;
	t_stack	*current_node;

	if (stack == NULL)
		return ;
	current_node = *stack;
	while (current_node)
	{
		tmp_node = current_node->next;
		free(current_node);
		current_node = tmp_node;
	}
	*stack = NULL;
}
