/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:28:06 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/16 14:30:41 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_highest_node(t_stack *stack);


void tiny_sort(t_stack **stack)
{
	t_stack	*first_node;
    t_stack *highest_node; // nodo con numero mas alto

	first_node = *stack;
    highest_node = find_highest_node(*stack);
	if (first_node == highest_node)  // 1º nodo numero + alto
		ra(stack, false);
	else if (first_node->next == highest_node) // 2º nodo numero + alto
		rra(stack, false);
	// ordenar 2 elementos (una vez el valor mayor se coloca abajo)
	if (first_node->value > first_node->next->value)
		sa(stack, false);    
}

static t_stack	*find_highest_node(t_stack *stack)
{
	int	highest_number;
	t_stack	*highest_node;

	//VALIDACION INICIAL ARGUMENTOS
	if (stack == NULL)
		return (NULL);

	highest_number = INT_MIN;
	while (stack != NULL)
	{
		if (stack->value > highest_number)
		{
			highest_number = stack->value; // cambio a num temporal + alto 
			highest_node = stack;  // capturamos nodo del num temporal + alto
		}
		stack = stack->next;
	}
	return (highest_node);
} 

int	main(void)
{
	t_stack	*stack;

	// INICIALIZACION STACK
	char	*arg_num_stack[4] = { arg_num_stack[0] = "0", arg_num_stack[1] = "4", arg_num_stack[2] = "2", arg_num_stack[3] = "1" };
	stack_init(&stack, arg_num_stack + 1, false);
	printf("stack_init() -> puntero (*stack_a) a 1º NODO-> %p \n", stack);

	// PROCESO TRANSFORMACION
	printf("\nPROCESO TRANSFORMACION --------\n");
	tiny_sort(&stack);
	printf("------------ \n");

	// ESTADO FINAL STACKS
	printf("ESTADO FINAL STACKS \n");
	while (stack)
	{
		printf( "stack -> numero-> %d, \t ptr previous-> %p \t address-> %p \t ptr next-> %p \n", stack->value, stack->prev, stack, stack->next );
		stack = stack->next;
	}
	printf("stack_init() -> puntero (*stack_a) a 1º NODO-> %p \n", stack);
	return (0);
}
