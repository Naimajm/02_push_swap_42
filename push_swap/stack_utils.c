/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:11:52 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/17 00:23:53 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_cheapest_node(t_stack *stack)
{
	// VALIDACION INICIAL
	if (stack == NULL)
		return (NULL);
	while (stack != NULL)
	{
		if (stack->cheapest_cost == true)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}


t_stack	*find_smallest_node(t_stack *stack)
{
	int	smallest_number;
	t_stack	*smallest_node;

	// VALIDACION INICIAL 
	if (stack == NULL)
		return (NULL);
	
	smallest_number = INT_MIN;
	while (stack != NULL)
	{
		if (stack->value < smallest_number)
		{ 
			smallest_number = stack->value; // cambio a num temporal + pequeño
			smallest_node = stack; // capturamos nodo del num temporal + pequeño
		}
		stack = stack->next;
	}
	return (smallest_node);
}

void    ft_append_node(t_stack **stack, int number)
{
    t_stack *node;
	t_stack	*last_node;

	// VALIDACION INICIAL PARAMETROS (stack no inicializado)
	if (stack == NULL)
		return ;
	// RESERVA MEMORIA NODO
	node = malloc(sizeof(t_stack));
	//node = ft_calloc(1, sizeof(t_stack));
	if (node == NULL)
		return ;

	// INICIALIZAR VALORES NODO	
	node->next = NULL;
	node->value = number;	

	// CASO PUNTERO STACK VACIO -> NUEVO 1º NODO
	if (*stack == NULL)
	{	
		*stack = node; // establece nuevo nodo como primer nodo
		node->prev = NULL; // primer nodo
	}
	else
	{
		last_node = ft_find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}    
}

t_stack	*ft_find_last_node(t_stack *stack)
{
	// VALIDACION INICIAL
	if (stack == NULL)
		return (NULL);
	// CICLO BUSQUEDA ULTIMO NODO CON stack->next NULO
	while (stack->next)
		stack = stack->next;
	return (stack); 
}

int	ft_stack_len(t_stack *stack)
{
	int	len;

	if (stack == NULL)
		return (0);

	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);	
}
