/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:11:52 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/24 10:04:21 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_append_node(t_stack **stack, int number)
{
    t_stack *node;
	t_stack	*last_node;
	
	if (stack == NULL) // VALIDACION INICIAL PARAMETROS
		return ;
	// RESERVA MEMORIA NODO
	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return ;

	// INICIALIZAR VALORES NUEVO NODO	
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

t_stack	*find_cheapest_node(t_stack *stack)
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

t_stack	*find_smallest_node(t_stack *stack)
{
	long	smallest_number;
	t_stack	*smallest_node;
	 
	if (stack == NULL) // VALIDACION INICIAL PARAMETROS
		return (NULL);
	
	smallest_number = LONG_MAX;
	while (stack)
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

t_stack	*ft_find_last_node(t_stack *node)
{	
	if (node == NULL) // VALIDACION INICIAL PARAMETROS
		return (NULL);
		
	// CICLO BUSQUEDA ULTIMO NODO CON stack->next NULO
	while (node->next)
		node = node->next;
	return (node); 
}

int	ft_stack_len(t_stack *stack)
{
	int	len;

	if (stack == NULL)
		return (0);
	len = 0;
	while (stack)
	{		
		len++;
		stack = stack->next;
	}
	return (len);	
}

/* int	main(void)
{
	t_stack *stack_a;
	t_stack	*stack_a_copy;

	// listado ptr string -> simulacion inputs string en 'argv' // argv[0] no cuenta
	char	*arg_num[6] = { arg_num[0]= "arg archivo", arg_num[1] = "42", arg_num[2] = "1337", arg_num[3] = "-21", arg_num[4] = "21" };  // 21
	
	stack_init(&stack_a, arg_num + 1, false);   // (arg_num + 1) apuntaria a 2º argumento
	printf("TESTEO INICIALIZAR STACK stack_init()-> ptr '%p' \n\n", stack_a);	
	stack_a_copy = stack_a; // COPIA PARA IMPRIMIR SIN MODIFICAR LA DIRECCION DEL PTR *STACK
	while (stack_a_copy)
	{
		printf( "arg numero-> %d, \t prev-> %p \t address-> %p \t next-> %p \n", stack_a_copy->value, stack_a_copy->prev, stack_a_copy, stack_a_copy->next );
		stack_a_copy = stack_a_copy->next;
	}
	// TESTEO FUNCIONES 'STACK_UTILS.C'
	printf("\nINICIALIZAR STACK stack_init()-> ptr '%p' \n\n", stack_a);
	
	printf("TESTEO ft_stack_len()-> int, return '%d' \n\n", ft_stack_len(stack_a));

	printf("TESTEO ft_find_last_node()-> ptr, return '%p' \n\n", ft_find_last_node(stack_a));

	ft_append_node(&stack_a, 99);
	stack_a_copy = stack_a;  // COPIA PARA IMPRIMIR SIN MODIFICAR LA DIRECCION DEL PTR *STACK
	while (stack_a_copy) 
	{
		printf( "arg numero-> %d, \t prev-> %p \t address-> %p \t next-> %p \n", stack_a_copy->value, stack_a_copy->prev, stack_a_copy, stack_a_copy->next );
		stack_a_copy = stack_a_copy->next;
	}
	printf("\nTESTEO ft_append_node()-> ptr, return '%p' \n\n", ft_find_last_node(stack_a));
	
	printf("TESTEO find_smallest_node()-> ptr, value-> '%i' ptr-> '%p' \n\n", find_smallest_node(stack_a)->value, find_smallest_node(stack_a));
	
	(stack_a)->next->cheapest_cost = true;
	printf("TESTEO find_cheapest_node()-> ptr, value-> '%i' cheapest_cost-> '%i' ptr-> '%p' \n\n", find_cheapest_node(stack_a)->value, (stack_a)->next->cheapest_cost,  find_cheapest_node(stack_a));

	ft_free_stack(&stack_a);
	return (0);
} */
