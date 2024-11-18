/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:32:35 by juagomez          #+#    #+#             */
/*   Updated: 2024/11/17 21:24:05 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_swap(t_stack **stack);

void	sa(t_stack **stack_a, bool print)
{
	ft_swap(stack_a);
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **stack_b, bool print)
{
	ft_swap(stack_b);
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **stack_a, t_stack **stack_b, bool print)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	if (print)
		ft_putstr_fd("ss\n", 1);
}

static	void	ft_swap(t_stack **stack)
{
	t_stack	*new_first_node;
	t_stack	*new_second_node;
	int		stack_len;

	if (stack == NULL || *stack == NULL)
		return ;
	stack_len = get_stack_len(*stack);
	if (stack_len < 2)
		return ;
	new_first_node = (*stack)->next;
	new_second_node = *stack;
	if (new_first_node->next != NULL)
		new_first_node->next->prev = new_second_node;
	*stack = new_first_node;
	new_second_node->next = new_first_node->next;
	new_first_node->prev = NULL;
	new_first_node->next = new_second_node;
	new_second_node->prev = new_first_node;
}

/* int	main(void)
{
	t_stack *stack_a;
	//t_stack *stack_b;
    t_stack *stack_a_copy;

	// INICIALIZACION STACK_A -> OPCION MAS DE 2 NODOS
	//char	*arg_num_stack_a[4] = { arg_num_stack_a[0]= "3", 
	arg_num_stack_a[1]= "4", arg_num_stack_a[2] = "5", 
	arg_num_stack_a[3]= "6"};

    // INICIALIZACION STACK_A -> 2 NODOS
    char	*arg_num_stack_a[2] = { arg_num_stack_a[0]= "4", 
	arg_num_stack_a[1]= "5" };

	stack_init(&stack_a, arg_num_stack_a, false);
	printf("stack_init() -> puntero (*stack_a) a 1º NODO-> %p \n", stack_a);

    // INICIALIZACION STACK_A -> 2 NODOS
	//char	*arg_num_stack_b[4] = { arg_num_stack_b[0]= "0", 
	arg_num_stack_b[1]= "4", arg_num_stack_b[2] = "5" };    

    //stack_init(&stack_b, arg_num_stack_b + 1, false);
	//printf("stack_init() -> puntero (*stack_b) a 1º NODO-> %p \n", stack_b);

	// PROCESO TRANSFORMACION
	printf("\nPROCESO TRANSFORMACION --------\n");
    ft_swap(&stack_a);
    stack_a_copy = stack_a;
    while (stack_a_copy)
	{
		printf( "stack-> num-> %d, \t prev-> %p \t address-> %p 
		\t next-> %p \n", stack_a_copy->value, stack_a_copy->prev, 
		stack_a_copy, stack_a_copy->next );
		stack_a_copy = stack_a_copy->next;
	}	

    sa(&stack_a, false);
    stack_a_copy = stack_a;
    while (stack_a_copy)
	{
		printf( "stack-> num-> %d, \t prev-> %p \t address-> %p 
		\t next-> %p \n",  stack_a_copy->value, stack_a_copy->prev, 
		stack_a_copy, stack_a_copy->next );
		stack_a_copy = stack_a_copy->next;
	}
    //sb(&stack_b, false);    
	printf("------------ \n");
    
	// ESTADO FINAL STACKS
	printf("ESTADO FINAL STACKS \n");
    printf("\nstack_init() -> return puntero stack a (*stack_a) -> %p \n", 
	stack_a);
	while (stack_a)
	{
		printf( "stack-> num-> %d, \t prev-> %p \t address-> %p 
		\t next-> %p \n", stack_a->value, stack_a->prev, 
		stack_a, stack_a->next );
		stack_a = stack_a->next;
	}	

    ft_free_stack(&stack_a);
	//ft_free_stack(&stack_b);
	return (0);
} */