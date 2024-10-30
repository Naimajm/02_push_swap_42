/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:26:03 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/30 22:36:25 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	move_nodes(t_stack **stack_a, t_stack **stack_b);
static	void	rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node);
static	void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node);

/* void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*smallest_node;
	int	stack_len_a;

	stack_len_a = ft_stack_len(*stack_a);
	
	//printf("stack_len_a -> %i \n", stack_len_a);

	// INICIO CONFIGURACION STACK A Y B -----------------

	// CASO ESPECIAL 5 NODOS -> ALGORTIMO ORDENACION ESPECIFICO
	if (stack_len_a == 5)
		tiny_sort_five(stack_a, stack_b);
	else
	{
		// MOVER TODOS LOS NODOS EXCEPTO 3 AL STACK B
		while (stack_len_a > 3)
		{
			stack_len_a--;
			pb(stack_b, stack_a, true);			
		}
	}
	// ORDENACION 3 NODOS STACK A -----------------
	tiny_sort_three(stack_a);

	// INICIALIZAR ORDENACION -> ciclo mover nodos 'cheapest' desde b hasta stack a
	while (*stack_b != NULL)
	{
		init_nodes(*stack_a, *stack_b);  // actualizar valores nodos (current_position, cost, ..)
		move_nodes(stack_a, stack_b);		
	}
	// STACK B VACIO -> ACTUALIZAR POSICION STACK A
	set_current_position(*stack_a);

	// TRANSFORMACION 2º rotar hasta tener nodo mas pequeño arriba
	smallest_node = find_smallest_node(*stack_a);
	if (smallest_node->above_median == true)
		while (*stack_a != smallest_node)
			ra(stack_a, true);
	else
		while (*stack_a != smallest_node)
			rra(stack_a, true);
} */

/* 
	Ordenacion elementos a partir de mas de 3 argumentos
 */
void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	//t_stack	*first_node_stack_a;
	//t_stack	*first_node_stack_b;
	int	stack_a_len;
	t_stack	*smallest_node;

	stack_a_len = ft_stack_len(*stack_a);	
	//printf("push_swap() stack_len_a -> %i \n", stack_len_a);

	// 1º FASE INICIO CONFIGURACION STACK A Y B -----------------
	// ---------------------------------------------------------
	// CASO 2 NODOS
	if (stack_a_len == 2)
	{
		//printf("main() sa() -> \n");
		sa(stack_a, true); // ordenar stack a -> 2 elementos
	}
	// CASO 3 NODOS
	else if (stack_a_len == 3)
	{
		//printf("main() tiny_sort_three() -> \n");
		tiny_sort_three(stack_a); // ordenar stack a -> 3 elementos
	}	
	// CASO ESPECIAL 4 y 5 NODOS -> ALGORTIMO ORDENACION ESPECIFICO
	else if (stack_a_len > 3 && stack_a_len <= 5)
	{
		//printf("main() tiny_sort_five() -> \n");
		tiny_sort_five(stack_a, stack_b);
		tiny_sort_three(stack_a); // ORDENACION 3 NODOS STACK A -----------------
	}
	
	// CASO > 5 NODOS -> algoritmo ppal ordenacion ---------------
	// ALGORTIMO SORT_MAX() --------------------------------
	else
	{
		//printf("main() SORT_MAX() -> \n");

		sorting(stack_a, stack_b);	
		//printf("push_swap() ->tiny_sort_three \n");
		tiny_sort_three(stack_a);	
		
	}
	//tiny_sort_three(stack_a); 
		
	// 2º FASE -> MOVIMIENTO ORDENADO DESDE STACK A HASTA STACK B -----------------
	// ---------------------------------------------------------
	
	// 3º FASE -> MOVIMIENTO ORDENADO DESDE STACK B HASTA STACK A -----------------
	// ---------------------------------------------------------

	// ALGORTIMO SORT_STACK_A() --------------------------------

	// IMPRESION STACK 'A y B'
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

	// INICIALIZAR ORDENACION -> ciclo mover nodos 'cheapest' desde b hasta stack a
	//printf("main() MOVE MODES DE STACK B -> A \n");
	while (*stack_b != NULL)
	{
		init_nodes(*stack_a, *stack_b);  // actualizar valores nodos (current_position, cost, ..)
		move_nodes(stack_a, stack_b);		
	}
	// STACK B VACIO -> ACTUALIZAR POSICION STACK A
	set_current_position(*stack_a);

	/* while (stack_copy_a) 
	{
		printf( "push_swap() stack a -> arg numero-> %d, \t \t index-> %d \t address-> %p \t target_node-> %p \n", stack_copy_a->value, stack_copy_a->index, stack_copy_a, stack_copy_a->target_node );
		stack_copy_a = stack_copy_a->next;
	}
	stack_copy_b = *stack_b;
	while (stack_copy_b) 
	{
		printf( "push_swap() stack b -> arg numero-> %d, \t index-> %d \t address-> %p \t target_node-> %p \n", stack_copy_b->value, stack_copy_b->index, stack_copy_b, stack_copy_b->target_node );
		stack_copy_b = stack_copy_b->next;
	} */

	// TRANSFORMACION 2º rotar hasta tener nodo mas pequeño arriba
	//printf("TRANSFORMACION 2º \n");
	smallest_node = find_smallest_node(*stack_a);
	if (smallest_node->above_median == true)
		while (*stack_a != smallest_node)
			ra(stack_a, true);
	else
		while (*stack_a != smallest_node)
			rra(stack_a, true);
}

/*
 * Mueve el nodo de 'b' a 'a' con los metadatos disponibles en el nodo
 * 1) Hacer que emerjan los nodos objetivo
 * 2) push en A
*/
static void	move_nodes(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;
	t_stack	*target_node;

	cheapest_node = find_cheapest_node(*stack_b);
	target_node = cheapest_node->target_node;

	// ROTACION HASTA Q 1 NODO QUEDA COMO 1º NODO
	// CASO 1 -> NODO CHEAP + TARGE NODE ENCIMA MEDIANA -> ROTAR AMBOS (ra +rb)
	if (cheapest_node->above_median == true && target_node->above_median == true)
		rotate_both(stack_a, stack_b, cheapest_node);
	// CASO 2 -> NODO CHEAP + TARGE NODE DEBAJO MEDIANA -> ROTAR REVERSO AMBOS (rra + rrb)	
	else if (!(cheapest_node->above_median) && !(target_node->above_median))
		reverse_rotate_both(stack_a, stack_b, cheapest_node);

	// ROTACION INDIVIDUAL del OTRO NODO HASTA QUEDAR COMO 1º NODO
	finish_rotation(stack_b, cheapest_node, 'b');
	finish_rotation(stack_a, target_node, 'a');
	// PUSH DEL cheapest_node DEL STACK B AL STACK A
	pa(stack_a, stack_b, true);	
}

void	finish_rotation(t_stack **stack, t_stack *top_node, char stack_name)
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

/*
	Ejecuta 'rotacion rr' para cada nodo hasta q el 1º nodo sea el cheapest_node en el stack b
	y el target_node en el stack a	
*/
static	void	rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node)
{
	t_stack	*target_node;

	target_node = cheapest_node->target_node;

	// ROTAR ELEMENTOS HASTA Q CHEAPEST Y TARGET NODE ESTEN ARRIBA en los stack (ptr *stack)
	while ((*stack_a != target_node) && (*stack_b != cheapest_node))
		rr(stack_a, stack_b, true);
	// ACTUALIZAR POSICIONES DESPUES DE ROTACION
	set_current_position(*stack_a);
	set_current_position(*stack_b);	
}

/*
	Ejecuta 'reverse rotacion' 'rrr' para cada nodo hasta q el 1º nodo sea el cheapest_node en el stack b
	y el target_node en el stack a	
*/
static	void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node)
{
	// ROTAR ELEMENTOS HASTA Q CHEAPEST Y TARGET NODE ESTEN ARRIBA en los stack (ptr *stack)
	while (*stack_a != cheapest_node->target_node && *stack_b != cheapest_node)
		rrr(stack_a, stack_b, true);
	// ACTUALIZAR POSICIONES DESPUES DE ROTACION
	set_current_position(*stack_a);
	set_current_position(*stack_b);	
}



