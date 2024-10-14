/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:43:29 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/14 21:19:25 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static  void ft_push(t_stack **stack_dest, t_stack **stack_src);

// OPERACIONES PERMITIDAS PARA ALGORITMO ORDENACION

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
Atención si la pila src está vacía (NULL).
* @param stack_dest: puntero a stack destino.
* @param stack_src: puntero a stack origen.
* @returns void.
*/
static  void ft_push(t_stack **stack_dest, t_stack **stack_src)
{
    t_stack *node_tmp; // puntero temporal

	//printf("ft_push() -> stack_src -> %p \n", stack_src);
	//printf("ft_push() -> stack_dest -> %p \n", stack_dest);
	//printf("ft_push() -> *stack_src -> %p \n", *stack_src);
	
    // VALIDACION INICIAL
	if (*stack_src == NULL)
		return ;
		
	node_tmp = (*stack_src)->next; // apunta al 2º elemento del stack origen
	//printf("ft_push() -> node_tmp -> %p \n", node_tmp);

	// Asigna el 1º elemento del stack origen como el nuevo 1º elemento del stack destino.
	(*stack_src)->next = *stack_dest; // engancha nuevo 1º elem (src) a antiguo 1º elem de dest
	//printf("ft_push() -> (*stack_src)->next -> %p \n", (*stack_src)->next);

	*stack_dest = *stack_src; // puntero stack dest apunta a nuevo 1º elemento
	//printf("ft_push() -> *stack_dest  -> %p \n", *stack_dest );

	// Apunta el puntero del stack origen al nuevo 1º elem (antiguo 2º elem), guardado en el puntero temporal node_tmp
	*stack_src = node_tmp;	
	//printf("ft_push() -> *stack_src  -> %p \n", *stack_src );
}

/* int	main(void)
{
	t_stack *stack_a;
	t_stack *stack_b;
	//stack_b = NULL;

	// INICIALIZACION STACK_A
	char	*arg_num_stack_a[4] = { arg_num_stack_a[0]= "0", arg_num_stack_a[1]= "4", arg_num_stack_a[2] = "5", arg_num_stack_a[3]= "6" };    
	stack_init(&stack_a, arg_num_stack_a + 1, false);

	char	*arg_num_stack_b[4] = { arg_num_stack_b[0]= "0", arg_num_stack_b[1]= "1", arg_num_stack_b[2] = "2", arg_num_stack_b[3]= "3" };
	stack_init(&stack_b, arg_num_stack_b + 1, false);

	// ESTADO INICIAL STACKS
	printf("ESTADO INICIAL STACKS \n");
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
	// REINICIALIZACION punteros !!	
	stack_init(&stack_a, arg_num_stack_a + 1, false);
	//stack_b = NULL;
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

	printf("\ntack_init() -> return puntero stack a (*stack_a) -> %p \n", stack_a);
	printf("stack_init() -> return puntero stack b (*stack_b) -> %p \n", stack_b);
	return (0);
} */