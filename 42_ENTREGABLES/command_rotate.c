/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:03:11 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/31 17:01:54 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_rotate(t_stack **stack);

void	ra(t_stack **stack_a, bool print)
{
	ft_rotate(stack_a);
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **stack_b, bool print)
{
	ft_rotate(stack_b);
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b, bool print)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	if (print)
		ft_putstr_fd("rr\n", 1);
}

static	void	ft_rotate(t_stack **stack)
{
	t_stack	*node_to_rotate;
	t_stack	*last_node;
	int		stack_len;

	if (stack == NULL || *stack == NULL)
		return ;
	stack_len = get_stack_len(*stack);
	if (stack_len < 2)
		return ;
	node_to_rotate = *stack;
	last_node = find_last_node(*stack);
	last_node->next = node_to_rotate;
	*stack = node_to_rotate->next;
	(*stack)->prev = NULL;
	node_to_rotate->prev = last_node;
	node_to_rotate->next = NULL;
}

/* 
int main(void)
{
    t_stack *stack_a;
    t_stack *initial_stack;

    char    *arg_num_stack_a[4] = { arg_num_stack_a[0] = "4", 
	arg_num_stack_a[1] = "3", arg_num_stack_a[2] = "2", 
	arg_num_stack_a[3] = "1" };

    stack_init(&stack_a, arg_num_stack_a);
    initial_stack = stack_a;

    // ESTADO INICIAL STACKS
    printf("\nESTADO INICIAL STACKS --------\n");
    printf("stack_init() -> puntero (*stack_a) a 1º NODO-> %p \n", stack_a);

    while (initial_stack)
    {
        printf("STACK A -> value -> %d \t prev -> %p \t address -> %p 
		\t next -> %p \n", initial_stack->value, initial_stack->prev, 
		initial_stack, initial_stack->next);
        initial_stack = initial_stack->next;
    }

    // TRANSFORMACION
    printf("\nPROCESO TRANSFORMACION --------\n");
    ra(&stack_a, false);
    printf("------------ \n");

    printf("\nESTADO FINAL STACKS --------\n");
    while (stack_a)
    {
        printf("STACK A -> value -> %d \t prev -> %p \t address -> %p 
		\t next -> %p \n", stack_a->value, stack_a->prev, 
		stack_a, stack_a->next);
        stack_a = stack_a->next;
    }
    return (0);
} */