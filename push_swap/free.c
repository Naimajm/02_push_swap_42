/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:40:08 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/16 23:00:48 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_free_all(t_stack **stack, char **argv, bool flag_argc_2)
{
	// LIBERAR MEMORIA STACK
	ft_free_stack(stack);

	// LIBERAR MEMORIA ARGUMENTOS SI NUM ARG = 2
	if (flag_argc_2)
		ft_free_matrix(argv);

	// impresion error en fd = 2 -> gestion errores
	ft_putstr_fd("Error\n", 2);
	
	exit(1);
}

void ft_free_matrix(char **argv)
{
	int	index;

	index = -1; // ultimo elemento
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[index])		
	{
		free(argv[index]);
		index++;
	}
	free(argv - 1);	
}

void	ft_free_stack(t_stack **stack)
{
	t_stack *tmp_node; // ptr a nodo temporal
	t_stack	*current_node;

	// VALIDACION ARGUMENTOS
	if (stack == NULL)
		return ;
	current_node = *stack;
	while (current_node)
	{
		tmp_node = current_node->next;
		free(current_node);
		current_node = tmp_node;
	}
	*stack= NULL; // redireccionar ptr stack a nulo
}


