/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:26:03 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/16 23:07:22 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	move_nodes(t_stack **stack_a, t_stack **stack_b);
static	void	rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node);
static	void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node);

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*smallest_node;
	int	stack_len_a;

	stack_len_a = ft_stack_len(*stack_a);

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
			pb(stack_b, stack_a, false);			
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
			ra(stack_a, false);
	else
		while (*stack_a != smallest_node)
			rra(stack_a, false);
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
	pa(stack_a, stack_b, false);	
}

void	finish_rotation(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median == true)
				ra(stack, false);
			else
				rra(stack, false);			
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median == true)
				rb(stack, false);
			else
				rrb(stack, false);
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
		rr(stack_a, stack_b, false);
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
	t_stack	*target_node;

	target_node = cheapest_node->target_node;

	// ROTAR ELEMENTOS HASTA Q CHEAPEST Y TARGET NODE ESTEN ARRIBA en los stack (ptr *stack)
	while (*stack_a != target_node && *stack_b != cheapest_node)
		rrr(stack_a, stack_b, false);
	// ACTUALIZAR POSICIONES DESPUES DE ROTACION
	set_current_position(*stack_a);
	set_current_position(*stack_b);	
}



