/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:06:25 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/24 13:43:56 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_node(t_stack *stack_a, t_stack *stack_b);

/* void	init_nodes(t_stack *stack_a, t_stack *stack_b)
{
	//printf("init_nodes() \n");

	//printf("set_current_position() \n");
	set_current_position(stack_a);
	set_current_position(stack_b);
	
	//printf("set_target_node() \n");
	set_target_node(stack_a, stack_b);

	//printf("set_push_price() \n");
	set_push_price(stack_a, stack_b);

	//printf("set_cheapest_node() \n");
	set_cheapest_node(stack_b);	

	//printf("fin  init_nodes() \n");
} */

void	init_nodes(t_stack *a, t_stack *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_push_price(a, b);
	set_cheapest_node(b);
}

/* void	set_cheapest_node(t_stack *stack_b)
{
	long	best_match_value;
	t_stack	*best_match_node;

	// VALIDACION INICIAL
	if (stack_b == NULL)
		return ;
	best_match_value = LONG_MAX;
	while (stack_b != NULL)
	{
		if (stack_b->push_price < best_match_value)
		{
			best_match_value = stack_b->push_price;
			best_match_node = stack_b;
		}
		stack_b = stack_b->next;
	}
	best_match_node->cheapest_cost = true; // asignacion a nodo mas barato segun configuracion
} */

void	set_cheapest_node(t_stack *b)
{
	long			best_match_value;
	t_stack	*best_match_node;

	if (NULL == b)
		return ;
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->push_price < best_match_value)
		{
			best_match_value = b->push_price;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest_cost = true;
}

/* void	set_push_price(t_stack *stack_a, t_stack *stack_b)
{
	int	stack_len_a;
	int	stack_len_b;
	t_stack	*target_node_a;

	stack_len_a = ft_stack_len(stack_a);
	stack_len_b = ft_stack_len(stack_b);	

	while (stack_b != NULL)
	{
		target_node_a = stack_b->target_node;
		
		stack_b->push_price = stack_b->current_position;
		if (stack_b->above_median == false)  // nodo stack b por debajo linea central
			stack_b->push_price = stack_len_b - (stack_b->current_position);
		if (target_node_a->above_median == true) // nodo objetivo stack a por encima linea central
			stack_b->push_price = stack_b->push_price + target_node_a->current_position;
		
		else
			stack_b->push_price = stack_b->push_price - (stack_len_a - target_node_a->current_position);
		stack_b = stack_b->next;
	}	
} */

void	set_push_price(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_stack_len(a);
	len_b = ft_stack_len(b);
	while (b)
	{
		b->push_price = b->current_position;
		if (!(b->above_median))
			b->push_price = len_b - (b->current_position);
		if (b->target_node->above_median)
			b->push_price += b->target_node->current_position;
		else
			b->push_price += len_a - (b->target_node->current_position);
		b = b->next;
	}
}

/* void	set_push_price(t_stack *stack_a, t_stack *stack_b)
{
	int	stack_len_a;
	int	stack_len_b;

	stack_len_a = ft_stack_len(stack_a);
	stack_len_b = ft_stack_len(stack_b);
	while (stack_b)
	{
		stack_b->push_price = stack_b->current_position;
		if (!(stack_b->above_median))
			stack_b->push_price = stack_len_b - (stack_b->current_position);
		if (stack_b->target_node->above_median)
			stack_b->push_price += stack_b->target_node->current_position;
		else
			stack_b->push_price += stack_len_a - (stack_b->target_node->current_position);
		stack_b = stack_b->next;
	}
} */

/* void	set_current_position(t_stack *stack)
{
	int	index_position;		// CONTADOR PARA MARCAR POSICION
	int	central_line;

	index_position = 0;
	// VALIDACION INICIAL
	if (stack == NULL)
		return ;
	central_line = ft_stack_len(stack) / 2;

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
} */

void	set_current_position(t_stack *stack)
{
	int	i;
	int	centerline;

	i = 0;
	if (NULL == stack)
		return ;
	centerline = ft_stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= centerline)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

/*
	ASIGNAR TARGET NODE A NODO STACK B.
	Encuentra nodo objetivo de 1 nodo. Es el nodo mas pequeño de los mas grandes a su valor.
	Si no hay (el nodo es el numero mas alto) -> nodo objetivo es el mas pequeño (1º nodo)
	Ese nodo será el siguiente donde colocar el nodo de stack b.
	Con esta función cada nodo en b obtiene su nodo objetivo en a.
*/
/* static void	set_target_node(t_stack *stack_a, t_stack *stack_b)
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
}  */

static void	set_target_node(t_stack *a,
							t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match_index)
			b->target_node = find_smallest_node(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}