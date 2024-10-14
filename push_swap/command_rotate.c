/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:03:11 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/14 22:15:08 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_rotate(t_stack **stack);

void    ra(t_stack **stack_a, bool checker)
{
    ft_rotate(stack_a);
    if (!checker)
        ft_putstr_fd("ra\n", 1);
}

void    rb(t_stack **stack_b, bool checker)
{
    ft_rotate(stack_b);
    if (!checker)
        ft_putstr_fd("rb\n", 1);
}

void    rr(t_stack **stack_a, t_stack **stack_b, bool checker)
{
    ft_rotate(stack_a);
    ft_rotate(stack_b);
    if (!checker)
        ft_putstr_fd("rr\n", 1);
}

/** 
* @brief Empujar el nodo superior en la parte inferior del stack.
Atención si la pila src está vacía (NULL).
* @param stack : stack.
* @returns void.
*/
static void ft_rotate(t_stack **stack)
{
    t_stack *last_node;
    int stack_len;

    // VALIDACION INICIAL (no stack o no puntero stack)
    if (stack == NULL || *stack == NULL)
        return ;

    stack_len = ft_stack_len(*stack);
    // VERIFICACION  TAMAÑO STACK MAYOR Q 1
    if (stack_len < 2)
        return ;
    last_node = ft_find_last_node(*stack);

    // TRANSFORMACION
    last_node->next = *stack; // conexion ultimo nodo next a 1º nodo
    *stack = (*stack)->next; // ptr stack a 2º nodo
    (*stack)->prev = NULL; // NUEVO 1º nodo -> prev a '0'
    last_node->next->prev = last_node;  // conexion del nuevo ultimo nodo al antiguo ultimo nodo
    last_node->next->next = NULL; // conexion nuevo ultimo nodo a nulo
}

/* int main(void)
{
    t_stack *stack_a;
    t_stack *initial_stack;

    char    *arg_num_stack_a[4] = { arg_num_stack_a[0] = "4", arg_num_stack_a[1] = "3", arg_num_stack_a[2] = "2", arg_num_stack_a[3] = "1" };

    stack_init(&stack_a, arg_num_stack_a, false);
    initial_stack = stack_a;

    // ESTADO INICIAL STACKS
    printf("\nESTADO INICIAL STACKS --------\n");
    printf("stack_init() -> puntero (*stack_a) a 1º NODO-> %p \n", stack_a);

    while (initial_stack)
    {
        printf("STACK A -> value -> %d \t prev -> %p \t address -> %p \t next -> %p \n", initial_stack->value, initial_stack->prev, initial_stack, initial_stack->next);
        initial_stack = initial_stack->next;
    }

    // TRANSFORMACION
    printf("\nPROCESO TRANSFORMACION --------\n");
    ra(&stack_a, false);
    printf("------------ \n");

    printf("\nESTADO FINAL STACKS --------\n");
    while (stack_a)
    {
        printf("STACK A -> value -> %d \t prev -> %p \t address -> %p \t next -> %p \n", stack_a->value, stack_a->prev, stack_a, stack_a->next);
        stack_a = stack_a->next;
    }
    return (0);
} */