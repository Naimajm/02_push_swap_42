/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:32:35 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/17 14:13:40 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_swap(t_stack **stack);

void    sa(t_stack **stack_a, bool checker)
{
    ft_swap(stack_a);
    if (!checker)
        ft_putstr_fd("sa\n", 1);
}

void    sb(t_stack **stack_b, bool checker)
{
    ft_swap(stack_b);
    if (!checker)
        ft_putstr_fd("sb\n", 1);
}

void    ss(t_stack **stack_a, t_stack **stack_b, bool checker)
{
    ft_swap(stack_a);
    ft_swap(stack_b);
    if (!checker)
        ft_putstr_fd("ss\n", 1);
}

static void ft_swap(t_stack **stack)
{
    t_stack *new_first_node;
    t_stack *new_second_node;   
    int stack_len; 
    
    stack_len = ft_stack_len(*stack);
    // VALIDACION INICIAL (stack no inicializado o ptr sin direccion)
    if (*stack == NULL || stack == NULL || stack_len < 2)
        return ;
    
    // COPIAR 1º NODO A NUEVO 2º NODO y 2º NODO COMO NUEVO 1º NODO
    new_first_node = (*stack)->next;
    new_second_node = *stack;
    //printf("new_first_node -> %p \n", new_first_node);    
    //printf("new_second_node -> %p \n", new_second_node);

    // validar -> si hay mas nodo despues del segundo -> enlazar con el nuevo 2ºnodo    
    if (new_first_node->next != NULL)
    {
        new_first_node->next->prev = new_second_node; // CONECTAR RESTO LISTA A NUEVO 2º NODO (si existen mas nodos)
        //printf("new_first_node->next->prev-> %p \n", new_first_node->next->prev);
    }
    // CAMBIAR PUNTERO STACK A NUEVO 1º NODO
    *stack = new_first_node;
    //printf("*stack-> %p \n", *stack);

    // desconectar 2º nodo->prev y conectar a nulo o  siguiente nodo como nuevo 1º nodo
    new_second_node->next = new_first_node->next;
    //printf("new_second_node->next-> %p \n", new_second_node->next);

    // desconectar nuevo 1º nodo->prev
    new_first_node->prev = NULL;
    //printf("new_first_node->prev-> %p \n", new_first_node->prev);    

    // conectar nuevo 1º nodo->next a nuevo 2º nodo
    new_first_node->next = new_second_node;
    //printf("new_first_node->next -> %p \n", new_first_node->next);

    // conectar nuevo 2º nodo->prev a nuevo 1º nodo
    new_second_node->prev = new_first_node;    
    //printf("new_second_node->prev-> %p \n", new_second_node->prev);
}

/* int	main(void)
{
	t_stack *stack_a;
	//t_stack *stack_b;
    t_stack *stack_a_copy;

	// INICIALIZACION STACK_A -> OPCION MAS DE 2 NODOS
	//char	*arg_num_stack_a[4] = { arg_num_stack_a[0]= "3", arg_num_stack_a[1]= "4", arg_num_stack_a[2] = "5", arg_num_stack_a[3]= "6"};

    // INICIALIZACION STACK_A -> 2 NODOS
    char	*arg_num_stack_a[2] = { arg_num_stack_a[0]= "4", arg_num_stack_a[1]= "5" };

	stack_init(&stack_a, arg_num_stack_a, false);
	printf("stack_init() -> puntero (*stack_a) a 1º NODO-> %p \n", stack_a);

    // INICIALIZACION STACK_A -> 2 NODOS
	//char	*arg_num_stack_b[4] = { arg_num_stack_b[0]= "0", arg_num_stack_b[1]= "4", arg_num_stack_b[2] = "5" };    

    //stack_init(&stack_b, arg_num_stack_b + 1, false);
	//printf("stack_init() -> puntero (*stack_b) a 1º NODO-> %p \n", stack_b);

	// PROCESO TRANSFORMACION
	printf("\nPROCESO TRANSFORMACION --------\n");
    ft_swap(&stack_a);
    stack_a_copy = stack_a;
    while (stack_a_copy)
	{
		printf( "stack-> num-> %d, \t prev-> %p \t address-> %p \t next-> %p \n", stack_a_copy->value, stack_a_copy->prev, stack_a_copy, stack_a_copy->next );
		stack_a_copy = stack_a_copy->next;
	}	

    sa(&stack_a, false);
    stack_a_copy = stack_a;
    while (stack_a_copy)
	{
		printf( "stack-> num-> %d, \t prev-> %p \t address-> %p \t next-> %p \n",  stack_a_copy->value, stack_a_copy->prev, stack_a_copy, stack_a_copy->next );
		stack_a_copy = stack_a_copy->next;
	}
    //sb(&stack_b, false);    
	printf("------------ \n");
    
	// ESTADO FINAL STACKS
	printf("ESTADO FINAL STACKS \n");
    printf("\nstack_init() -> return puntero stack a (*stack_a) -> %p \n", stack_a);
	while (stack_a)
	{
		printf( "stack-> num-> %d, \t prev-> %p \t address-> %p \t next-> %p \n", stack_a->value, stack_a->prev, stack_a, stack_a->next );
		stack_a = stack_a->next;
	}	

    ft_free_stack(&stack_a);
	//ft_free_stack(&stack_b);
	return (0);
} */