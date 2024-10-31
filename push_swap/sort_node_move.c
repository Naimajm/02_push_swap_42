/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_node_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:26:03 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/31 12:24:15 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	finish_rotation(t_stack **stack, t_stack *top_node, char stack_name);
static	void	rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node);
static	void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node);
static	t_stack	*find_cheapest_node(t_stack *stack);

void	move_nodes_to_stack_a(t_stack **stack_a, t_stack **stack_b)
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

/*
 * Concluir la rotación de las pilas. Rotar de forma individual cada stack hasta posicionar al 1º nodo
*/
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

/** 
* @brief Encuentra el nodo con atributo 'push_price' 
mas barato (cheapest == true).
* @param stack t_stack *: puntero al primer nodo del stack.
* @returns t_stack * -> puntero a nodo encontrado .
*/
static	t_stack	*find_cheapest_node(t_stack *stack)
{	
	if (stack == NULL) // VALIDACION INICIAL PARAMETROS
		return (NULL);
	while (stack)
	{
		if (stack->cheapest_cost == true)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

