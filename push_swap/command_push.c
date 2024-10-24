/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:43:29 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/24 12:46:09 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static  void ft_push(t_stack **stack_dest, t_stack **stack_src);

void    pa(t_stack **stack_a, t_stack **stack_b, bool checker)
{
    ft_push(stack_a, stack_b);
    if (!checker)
        ft_putstr_fd("pa\n", 1);    
}

void    pb(t_stack **stack_b, t_stack **stack_a, bool checker)
{
    ft_push(stack_b, stack_a);
    if (!checker)
        ft_putstr_fd("pb\n", 1);    
}

/** 
* @brief Empujar un nodo hacia la parte superior desde src hasta destino.
Atención si la pila src está vacía (NULL). Planteamiento con stack dest 
vacio o con algun nodo existente.
* @param stack_dest: puntero a stack destino.
* @param stack_src: puntero a stack origen.
* @returns void.
*/
/* static  void ft_push(t_stack **stack_dest, t_stack **stack_src)
{
	t_stack *node_to_push;
	t_stack	*new_first_node;

	// VALIDACION INICIAL (stack src podria ser nulo)
	if ( *stack_src == NULL )
		return ;

	// stack src -> nodo temporal apunta al 1º nodo stack origen que
	// va a ser empujado a stack dest
	node_to_push = *stack_src; 
	new_first_node = (*stack_src)->next;
	//printf("node_to_push -> \t %p \n", node_to_push);
	//printf("new_first_node -> \t %p \n", new_first_node);

	// stack src -> apuntar puntero stack a nuevo 1º nodo
	*stack_src =  new_first_node;
	//printf("*stack_src -> %p \n", *stack_src);

	// SI YA NO HAY MAS NODOS¡¡ -> STACK VACIO  ¡¡¡
	if (*stack_src != NULL)
		new_first_node->prev = NULL; // stack src -> desconectar nuevo 1º nodo src y conectar a nulo
	
	node_to_push->prev = NULL;	

	// STACK DESTINO SIN NODOS EXISTENTES o CON NODOS EXISTENTE
	if ( *stack_dest == NULL )		
		node_to_push->next = NULL;	// stack dest -> conectar nuevo 1º nodo a nulo	
	else
	{
		// stack dest -> conectar nuevo 1º nodo a antiguo 1º nodo 
		node_to_push->next = *stack_dest;
		//printf("node_to_push->next-> %p \n", node_to_push->next);

		// stack dest -> desconectar antiguo 1º nodo->prev y conectar nuevo
		// 1º nodo
		node_to_push->next->prev = node_to_push;
		//printf("node_to_push->next->prev-> %p \n", (*stack_dest)->prev);		
	}
	// stack dest -> apuntar ptr stack dest a nuevo 1º nodo
	*stack_dest = node_to_push;
	//printf("*stack_dest-> %p \n", *stack_dest);	
} */

static void	ft_push(t_stack **dest, t_stack **src)
{
	t_stack	*node_to_push;

	if (NULL == *src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (NULL == *dest)
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		node_to_push->next->prev = node_to_push;
		*dest = node_to_push;
	}
}

/* static  void ft_push(t_stack **stack_dest, t_stack **stack_src)
{
	t_stack	*node_to_push;

	if (NULL == *stack_src)
		return ;
	node_to_push = *stack_src;
	*stack_src = (*stack_src)->next;
	if (*stack_src)
		(*stack_src)->prev = NULL;
	node_to_push->prev = NULL;
	if (NULL == *stack_dest)
	{
		*stack_dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *stack_dest;
		node_to_push->next->prev = node_to_push;
		*stack_dest = node_to_push;
	}
} */

/* int	main(void)
{
	t_stack *stack_a;
	t_stack *stack_b;

	// INICIALIZACION STACK_A + STACK B
	char	*arg_num_stack_a[4] = { arg_num_stack_a[0]= "0", arg_num_stack_a[1]= "4", arg_num_stack_a[2] = "5", arg_num_stack_a[3]= "6" };    
	stack_init(&stack_a, arg_num_stack_a + 1, false);

	//stack_b = NULL;  // OPCION STACK DESTINO SIN NODOS EXISTENTES
	char	*arg_num_stack_b[4] = { arg_num_stack_b[0]= "0", arg_num_stack_b[1]= "1", arg_num_stack_b[2] = "2", arg_num_stack_b[3]= "3" };
	stack_init(&stack_b, arg_num_stack_b + 1, false);	

	printf("stack_init() -> puntero (*stack_a) a 1º NODO-> %p \n", stack_a);
	printf("stack_init() -> puntero (*stack_a) a 1º NODO-> %p \n", stack_b);

	// PROCESO TRANSFORMACION
	printf("\nPROCESO TRANSFORMACION --------\n");
	pb(&stack_b, &stack_a , false);
	//ft_push(&stack_b, &stack_a);
	printf("------------ \n");

	// ESTADO FINAL STACKS
	printf("ESTADO FINAL STACKS \n");
	while (stack_a)
	{
		printf( "stack A -> numero-> %d, \t ptr previous -> %p \t address node -> %p \t ptr next -> %p \n", stack_a->value, stack_a->prev, stack_a, stack_a->next );
		stack_a = stack_a->next;
	}
	printf("------------ \n");
	while (stack_b)
	{
		printf( "stack B -> numero-> %d, \t ptr previous -> %p \t address node -> %p \t ptr next -> %p \n", stack_b->value, stack_b->prev, stack_b, stack_b->next );
		stack_b = stack_b->next;
	}

	printf("\nstack_init() -> return puntero stack a (*stack_a) -> %p \n", stack_a);
	printf("stack_init() -> return puntero stack b (*stack_b) -> %p \n", stack_b);
	return (0);
} */