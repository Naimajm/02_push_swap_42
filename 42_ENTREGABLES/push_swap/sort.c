/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:28:06 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/31 19:08:52 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_nodes_to_stack_b(t_stack **stack_a, t_stack **stack_b);
static void	ft_get_index(t_stack *stack);

void	sort_three(t_stack **stack)
{
	t_stack	*highest_node;

	highest_node = find_highest_node(*stack);
	if (*stack == highest_node)
		ra(stack, true);
	else if ((*stack)->next == highest_node)
		rra(stack, true);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, true);
}

void	sort_small_stack(t_stack **stack_a, t_stack **stack_b)
{
	while (get_stack_len(*stack_a) > 3)
		pb(stack_b, stack_a, true);
	if (!is_stack_sorted(*stack_b))
		sb(stack_b, true);
}

void	sort_big_stack(t_stack **stack_a, t_stack **stack_b)
{
	ft_get_index(*stack_a);
	move_nodes_to_stack_b(stack_a, stack_b);
}

static void	move_nodes_to_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	int	pushed_number;
	int	stack_len;
	int	index;

	stack_len = get_stack_len(*stack_a);
	pushed_number = 0;
	index = 0;
	while (index < stack_len && (stack_len - pushed_number) >= 3)
	{
		if ((*stack_a)->index <= (stack_len / 2 + 1))
		{
			pb(stack_b, stack_a, true);
			pushed_number++;
		}
		else
			ra(stack_a, true);
		index++;
	}
	while ((stack_len - pushed_number) > 3)
	{
		pb(stack_b, stack_a, true);
		pushed_number++;
	}
}

static void	ft_get_index(t_stack *stack)
{
	t_stack	*current_node_a;
	t_stack	*bigger_node;
	int		highest_number;
	int		current_index;

	current_index = get_stack_len(stack);
	while (current_index)
	{
		current_node_a = stack;
		bigger_node = NULL;
		highest_number = INT_MIN;
		while (current_node_a)
		{
			if (current_node_a->value >= highest_number
				&& current_node_a->index == 0)
			{
				highest_number = current_node_a->value;
				bigger_node = current_node_a;
			}
			current_node_a = current_node_a->next;
		}
		if (bigger_node)
			bigger_node->index = current_index;
		current_index--;
	}
}

/* int	main(void)
{
	t_stack	*stack;

	// INICIALIZACION STACK
	char	*arg_num_stack[4] = { arg_num_stack[0] = "0", arg_num_stack[1] = "4",
	arg_num_stack[2] = "2", arg_num_stack[3] = "1" };
	stack_init(&stack, arg_num_stack + 1, false);
	printf("stack_init() -> puntero (*stack_a) a 1º NODO-> %p \n", stack);

	// PROCESO TRANSFORMACION
	printf("\nPROCESO TRANSFORMACION --------\n");
	tiny_sort_three(&stack);
	printf("------------ \n");

	// ESTADO FINAL STACKS
	printf("ESTADO FINAL STACKS \n");
	while (stack)
	{
		printf( "stack -> numero-> %d, \t ptr previous-> %p \t address-> %p 
		\t ptr next-> %p \n", stack->value, stack->prev, stack, stack->next );
		stack = stack->next;
	}
	printf("stack_init() -> puntero (*stack_a) a 1º NODO-> %p \n", stack);
	return (0);
} */

/* int	main(void)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = NULL;
	stack_b = NULL;

	char    *arg_num_stack_a[8] = { arg_num_stack_a[0] = "23", 
	arg_num_stack_a[1] = "6", arg_num_stack_a[2] = "-42", 
	arg_num_stack_a[3] = "4", arg_num_stack_a[4] = "14", 
	arg_num_stack_a[5] = "45", arg_num_stack_a[6] = "145" };

	stack_init(&stack_a, arg_num_stack_a);

	// IMPRESION STACK 'INICIAL'
	t_stack *stack_copy_a;
	stack_copy_a = stack_a;
	while (stack_copy_a) 
	{
		printf( "main() stack a INICIAL -> arg numero-> %d, \t prev-> %p 
		\t address-> %p \t next-> %p \n", stack_copy_a->value, 
		stack_copy_a->prev, stack_copy_a, 
		stack_copy_a->next );
		stack_copy_a = stack_copy_a->next;
	}
	ft_get_index(stack_a, ft_stack_len(stack_a));
	nb_partition(&stack_a, &stack_b);

	// IMPRESION STACK 'FINAL'
	//stack_copy_a = stack_a;
	while (stack_a) 
	{
		printf( "main() stack a -> arg numero-> %d, index-> %d, \t prev-> %p 
		\t address-> %p \t next-> %p \n", stack_a->value, stack_a->index, 
		stack_a->prev, stack_a, 
		stack_a->next );
		stack_a = stack_a->next;
	}
	//t_stack *stack_copy_b = stack_b;
	while (stack_b) 
	{
		printf( "main() stack b -> arg numero-> %d, index-> %d, \t prev-> %p 
		\t address-> %p \t next-> %p \n", stack_b->value, stack_b->index, 
		stack_b->prev, stack_b, 
		stack_b->next );
		stack_b = stack_b->next;
	}
	return (0);
} */
