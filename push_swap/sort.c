/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:28:06 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/28 14:30:18 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_highest_node(t_stack *stack);

void	tiny_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_stack_len(*stack_a) > 3)
	{
		init_nodes(*stack_a, *stack_b);			
		finish_rotation(stack_a, find_smallest_node(*stack_a), 'a');
		pb(stack_b, stack_a, true);	// push to stack b	
	}
}

void	tiny_sort_three(t_stack **stack)
{
    t_stack *highest_node; 

    highest_node = find_highest_node(*stack);
	// COLOCAR ABAJO EL VALOR MAS ALTO
	if (*stack == highest_node)  // 1º nodo numero + alto
		ra(stack, true);
	else if ((*stack)->next == highest_node) // 2º nodo numero + alto
		rra(stack, true);
		
	// ORDENAR 2 ELEMENTOS (una vez el valor mayor se coloca abajo)
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, true);    
}

/** 
* @brief Encuentra el nodo con atributo 'value' mas grande.
* @param stack t_stack *: puntero al primer nodo del stack.
* @returns t_stack * -> puntero a nodo encontrado .
*/
static t_stack	*find_highest_node(t_stack *stack)
{
	int	highest_number;
	t_stack	*highest_node;
	
	if (stack == NULL) //VALIDACION INICIAL ARGUMENTOS
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

/* int	main(void)
{
	t_stack	*stack;

	// INICIALIZACION STACK
	char	*arg_num_stack[4] = { arg_num_stack[0] = "0", arg_num_stack[1] = "4", arg_num_stack[2] = "2", arg_num_stack[3] = "1" };
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
		printf( "stack -> numero-> %d, \t ptr previous-> %p \t address-> %p \t ptr next-> %p \n", stack->value, stack->prev, stack, stack->next );
		stack = stack->next;
	}
	printf("stack_init() -> puntero (*stack_a) a 1º NODO-> %p \n", stack);
	return (0);
} */
