/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:28:06 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/21 12:43:15 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_highest_node(t_stack *stack);

/* void	tiny_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_len_a;
	t_stack	*smallest_node;

	stack_len_a = ft_stack_len(*stack_a);
	smallest_node = find_smallest_node(*stack_a);

	printf("tiny_sort_five()-> smallest_node -> %p", smallest_node);

	while (stack_len_a > 3)
	{
		init_nodes(*stack_a, *stack_b);

		// IMPRESION STACK
		t_stack *stack_copy_a = *stack_a;
		while (stack_copy_a)  
		{
			printf( "tiny_sort_five() -> arg numero-> %d, \t prev-> %p \t address-> %p \t next-> %p \n", stack_copy_a->value, stack_copy_a->prev, stack_copy_a, stack_copy_a->next );
			stack_copy_a = stack_copy_a->next;
		}
		
		finish_rotation(stack_a, smallest_node, 'a');
		pb(stack_b, stack_a, false);	// push to stack b	
	}
} */
void	tiny_sort_five(t_stack **a, t_stack **b)
{
	while (ft_stack_len(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, find_smallest_node(*a), 'a');
		pb(b, a, false);
	}
}

/*
 * Cuando tengo 3 nodos, es fácil de ordenar
 * ~Si el 1* es el más grande, ra (de mayor a inferior)
 * ~Si el 2* es el más grande, rra (de mayor a abajo)
 * ~ Ahora tengo con fuerza el más grande en la parte inferior.
 * entonces solo reviso 1° y 2°
*/
/* void	tiny_sort_three(t_stack **stack)
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
} */

void	tiny_sort_three(t_stack **a)
{
	t_stack	*highest_node;

	highest_node = find_highest_node(*a);
	if (*a == highest_node)
		ra(a, false);
	else if ((*a)->next == highest_node)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
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
