/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:43:29 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/31 16:46:28 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_push(t_stack **stack_dest, t_stack **stack_src);

void	pa(t_stack **stack_a, t_stack **stack_b, bool print)
{
	ft_push(stack_a, stack_b);
	if (print)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **stack_b, t_stack **stack_a, bool print)
{
	ft_push(stack_b, stack_a);
	if (print)
		ft_putstr_fd("pb\n", 1);
}

static	void	ft_push(t_stack **stack_dest, t_stack **stack_src)
{
	t_stack	*node_to_push;
	t_stack	*new_first_node;

	if (*stack_src == NULL)
		return ;
	node_to_push = *stack_src;
	new_first_node = (*stack_src)->next;
	*stack_src = new_first_node;
	if (*stack_src != NULL)
		new_first_node->prev = NULL;
	node_to_push->prev = NULL;
	if (*stack_dest == NULL)
		node_to_push->next = NULL;
	else
	{
		node_to_push->next = *stack_dest;
		node_to_push->next->prev = node_to_push;
	}
	*stack_dest = node_to_push;
}

/* int	main(void)
{
	t_stack *stack_a;
	t_stack *stack_b;

	// INICIALIZACION STACK_A + STACK B
	char	*arg_num_stack_a[4] = { arg_num_stack_a[0]= "0",
	arg_num_stack_a[1]= "4", arg_num_stack_a[2] = "5", 
	arg_num_stack_a[3]= "6" };    
	stack_init(&stack_a, arg_num_stack_a + 1, false);

	//stack_b = NULL;  // OPCION STACK DESTINO SIN NODOS EXISTENTES
	char	*arg_num_stack_b[4] = { arg_num_stack_b[0]= "0", 
	arg_num_stack_b[1]= "1", arg_num_stack_b[2] = "2", 
	arg_num_stack_b[3]= "3" };
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
		printf( "stack A -> numero-> %d, \t ptr previous -> %p 
		\t address node -> %p \t ptr next -> %p \n", stack_a->value, 
		stack_a->prev, stack_a, stack_a->next );
		stack_a = stack_a->next;
	}
	printf("------------ \n");
	while (stack_b)
	{
		printf( "stack B -> numero-> %d, \t ptr previous -> %p
		\t address node -> %p \t ptr next -> %p \n", stack_b->value, 
		stack_b->prev, stack_b, stack_b->next );
		stack_b = stack_b->next;
	}
	printf("stack_init() -> puntero stack a (*stack_a) -> %p \n", stack_a);
	printf("stack_init() -> puntero stack b (*stack_b) -> %p \n", stack_b);
	return (0);
} */