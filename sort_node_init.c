/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_node_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:06:25 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/31 13:08:08 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	set_cheapest_node(t_stack *stack_b);
static void	set_cost_move(t_stack *stack_a, t_stack *stack_b);
static void	set_target_node(t_stack *stack_a, t_stack *stack_b);

void	init_atributtes_nodes(t_stack *stack_a, t_stack *stack_b)
{
	//printf("init_nodes() \n");

	//printf("set_current_position() \n");
	set_current_position(stack_a);
	set_current_position(stack_b);
	
	//printf("set_target_node() \n");
	set_target_node(stack_a, stack_b);

	//printf("set_push_price() \n");
	set_cost_move(stack_a, stack_b);

	//printf("set_cheapest_node() \n");
	set_cheapest_node(stack_b);	

	//printf("fin  init_nodes() \n");
}

void	set_current_position(t_stack *stack)
{
	int	index_position;		// CONTADOR PARA MARCAR POSICION
	int	central_line;

	index_position = 0;
	// VALIDACION INICIAL
	if (stack == NULL)
		return ;
	central_line = get_stack_len(stack) / 2;

	while (stack != NULL)
	{
		stack->current_position = index_position;
		if (index_position <= central_line)
			stack->above_median = true;
		else
			stack->above_median = false;
		index_position++;
		stack = stack->next;
	}
}

/*
	ASIGNAR TARGET NODE A NODO STACK B.
	Encuentra nodo objetivo de 1 nodo. Es el nodo mas pequeño de los mas grandes a su valor.
	Si no hay (el nodo es el numero mas alto) -> nodo objetivo es el mas pequeño (1º nodo)
	Ese nodo será el siguiente donde colocar el nodo de stack b.
	Con esta función cada nodo en b obtiene su nodo objetivo en a.
*/
static void	set_target_node(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_node_a;  // nodo actual stack a
	t_stack	*targe_node;  // puntero al nodo objetivo a del nodo de stack b
	long	best_match_index;

	while (stack_b)
	{
		best_match_index = LONG_MAX;  // flag dinamico
		current_node_a = stack_a;

		// BUSQUEDA NODO OBJETIVO
		while (current_node_a)
		{
			if (current_node_a->value > stack_b->value && current_node_a->value < best_match_index)
			{
				best_match_index = current_node_a->value; 	// cambio a valor actual
				targe_node = current_node_a;				// capturamos nodo objetivo temporal
			}
			current_node_a = current_node_a->next;
		}
		// REGISTRO NODO OBJETIVO EN NODOS DE STACK B
		if (best_match_index == LONG_MAX) // no habia num mayor en stack a del numero de stack b			
			stack_b->target_node = find_smallest_node(stack_a); // encontrar el numero mas pequeño como target_node
		else  // nodo objetivo encontrado
			stack_b->target_node = targe_node;
		stack_b = stack_b->next;
	}	
} 

/*
 * Establecer los precios para impulsar el nodo de b -> a
 * El precio verifica las posiciones relativas en la pila para cada nodo, 
 * fijando el precio respectivo.
*/
static void	set_cost_move(t_stack *stack_a, t_stack *stack_b)
{
	int	stack_len_a;
	int	stack_len_b;

	stack_len_a = get_stack_len(stack_a);
	stack_len_b = get_stack_len(stack_b);
	while (stack_b)
	{
		stack_b->cost = stack_b->current_position;
		if (!(stack_b->above_median))
			stack_b->cost = stack_len_b - (stack_b->current_position);
		if (stack_b->target_node->above_median)
			stack_b->cost += stack_b->target_node->current_position;
		else
			stack_b->cost += stack_len_a - (stack_b->target_node->current_position);
		stack_b = stack_b->next;
	}
}

/*
 * Marcar el nodo más barato en la actuales configuraciones de stacks
*/
static	void	set_cheapest_node(t_stack *stack_b)
{
	long	best_match_value;
	t_stack	*best_match_node;

	// VALIDACION INICIAL
	if (stack_b == NULL)
		return ;
	best_match_value = LONG_MAX;
	while (stack_b != NULL)
	{
		if (stack_b->cost < best_match_value)
		{
			best_match_value = stack_b->cost;
			best_match_node = stack_b;
		}
		stack_b = stack_b->next;
	}
	best_match_node->cheapest_cost = true; // asignacion a nodo mas barato segun configuracion
}




