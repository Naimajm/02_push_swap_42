/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:26:03 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/31 14:29:11 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	// INICIO CONFIGURACION STACK A Y B -----------------
	int	stack_a_len;
	
	stack_a_len = get_stack_len(*stack_a);	

	// CASO 2 NODOS
	if (stack_a_len == 2)
		sa(stack_a, true); // ordenar stack a -> 2 elementos

	// CASO 3 NODOS
	else if (stack_a_len == 3)
		sort_three(stack_a); // ORDENACION 3 NODOS STACK A 
		
	// MOVIMIENTO ORDENADO DESDE STACK A HASTA STACK B -----------------
	// CASO ESPECIAL 4 y 5 NODOS
	else if (stack_a_len > 3 && stack_a_len <= 5)
	{
		//printf("push_swap() sort_small_stack() -> \n");
		sort_small_stack(stack_a, stack_b);
		sort_three(stack_a); 
	}	
	// CASO > 5 NODOS -> algoritmo ppal ordenacion ---------------
	else
	{
		//printf("push_swap() sort_big_stack() -> \n");
		sort_big_stack(stack_a, stack_b);	
		sort_three(stack_a);			
	}	
	
	// MOVIMIENTO ORDENADO DESDE STACK B HASTA STACK A -----------------
	sort_to_stack_a(stack_a, stack_b);	

	// STACK B VACIO -> ACTUALIZAR POSICION STACK A
	set_current_position(*stack_a);

	// ROTACION FINAL STACK A
	rotate_stack_a(stack_a);
	
	// IMPRESION STACK 'A y B' ESTADO FINAL
	/* t_stack *stack_copy_a;
	stack_copy_a = *stack_a;
	while (stack_copy_a) 
	{
		printf( "push_swap() stack a -> arg numero-> %d, \t \t index-> %d \t address-> %p \t target_node-> %p \n", stack_copy_a->value, stack_copy_a->index, stack_copy_a, stack_copy_a->target_node );
		stack_copy_a = stack_copy_a->next;
	}
	t_stack *stack_copy_b;
	stack_copy_b = *stack_b;
	while (stack_copy_b) 
	{
		printf( "push_swap() stack b -> arg numero-> %d, \t index-> %d \t address-> %p \t target_node-> %p \n", stack_copy_b->value, stack_copy_b->index, stack_copy_b, stack_copy_b->target_node );
		stack_copy_b = stack_copy_b->next;
	} */
}

void	rotate_stack_a(t_stack **stack_a)
{
	t_stack	*smallest_node;

	if (stack_a == NULL) //VALIDACION INICIAL ARGUMENTOS
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
	if (stack_a == NULL || stack_b == NULL) //VALIDACION INICIAL ARGUMENTOS
		return ;
	while (*stack_b != NULL)
	{
		// actualizar valores nodos (current_position, cost, ..)
		init_atributtes_nodes(*stack_a, *stack_b);  
		// mover nodo de mejor coste a stack a
		move_nodes_to_stack_a(stack_a, stack_b);
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp_node; // ptr a nodo temporal
	t_stack	*current_node;
	
	if (stack == NULL) // VALIDACION INICIAL ARGUMENTOS 
		return ;
	current_node = *stack;
	while (current_node)
	{
		tmp_node = current_node->next;
		free(current_node);
		current_node = tmp_node;
	}
	*stack = NULL; // redireccionar ptr stack a nulo	
}
