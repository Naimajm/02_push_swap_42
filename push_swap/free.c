/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:40:08 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/24 11:58:01 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack **stack)
{
	t_stack *tmp_node; // ptr a nodo temporal
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
	*stack= NULL; // redireccionar ptr stack a nulo
	exit(1);
}

void ft_print_error(int file_descriptor)
{
	ft_putstr_fd("Error\n", file_descriptor);
}


