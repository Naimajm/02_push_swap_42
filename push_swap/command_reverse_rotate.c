/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_reverse_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:05:06 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/31 12:37:00 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_reverse_rotate(t_stack **stack);

void    rra(t_stack **stack_a, bool print)
{
    ft_reverse_rotate(stack_a);
    if (print)
        ft_putstr_fd("rra\n", 1);
}

void    rrb(t_stack **stack_b, bool print)
{
    ft_reverse_rotate(stack_b);
    if (print)
        ft_putstr_fd("rrb\n", 1);
}

void    rrr(t_stack **stack_a, t_stack **stack_b, bool print)
{
    ft_reverse_rotate(stack_a);
    ft_reverse_rotate(stack_b);
    if (print)
        ft_putstr_fd("rrr\n", 1);
}
/** 
* @brief Empujar el ultimo nodo inferior a la parte superior del stack.
Atención si la pila src está vacía (NULL).
* @param stack t_stack **: dirección de un puntero al primer nodo del stack.
* @returns void.
*/
static void ft_reverse_rotate(t_stack **stack)
{
    t_stack *last_node;
    int stack_len;
    
    if (stack == NULL || *stack == NULL) // VALIDACION INICIAL ARGUMENTOS
        return ;

    stack_len = get_stack_len(*stack);    
    if (stack_len < 2)
        return ;

    last_node = find_last_node(*stack);
    //printf("last_node -> \t %p \n", last_node);

    last_node->prev->next = NULL; // desconectar -> conectar nuevo ultimo nodo a '\0'    
    last_node->prev = NULL; // desconectar -> conectar nuevo primer nodo a nulo

    last_node->next = *stack; // conectar antiguo ultimo nodo a antiguo 1º nodo    
    *stack = last_node;  // NUEVO PUNTERO STACK  a nuevo 1º nodo
    last_node->next->prev = last_node; // conectar antiguo 1º nodo a nuevo 1º nodo        
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
    //ft_reverse_rotate(&stack_a);
    rra(&stack_a, false);
    
    printf("------------ \n");
    printf("\nESTADO FINAL STACKS --------\n");
    while (stack_a)
    {
        printf("STACK A -> value -> %d \t prev -> %p \t address -> %p \t next -> %p \n", stack_a->value, stack_a->prev, stack_a, stack_a->next);
        stack_a = stack_a->next;
    }
    return (0);
} */