/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:24:48 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/16 14:14:00 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"

#include <unistd.h> // write
#include <stdlib.h> // malloc free

#include <stdio.h>  // printf

# include <stdbool.h> // booleanos
# include <limits.h> // VALORES INT_MIN INT_MAX

// ESTRUCTURA DATOS -> LISTA VINCULADA -> STACKS / PILAS
typedef struct s_stack
{
	int	value;
	int	current_position;
	int	final_index; // indice

	struct	s_stack	*target_node;
	struct	s_stack	*prev;
	struct	s_stack	*next;	
}					t_stack;

// FUNCIONES CONTRUCCION PILA (STACK)  ---------------------------
// ---------------------------------------------------------------

// ARCHIVO 'stack_init.c' -----------------------------
void	stack_init(t_stack **stack, char **argv, bool flag_argc_2);

// ARCHIVO 'error.c' -----------------------------
void ft_free_all(t_stack **stack, char **argv, bool flag_argc_2);
void ft_free_matrix(char **argv);

// ARCHIVO 'stack_utils.c' -----------------------------
void    ft_append_node(t_stack **stack, int number);
t_stack	*ft_find_last_node(t_stack *stack);

/** 
* @brief  Cuenta el número de elementos en una pila (stack).
Cuenta el número de nodos de un stack.
* @param stack: puntero al primer nodo del stack.
* @returns int -> Número de nodos del stack.
*/
int	ft_stack_len(t_stack *stack);

// FUNCIONES FUNCIONES PERMITIDAS ORDENACION NODOS  ---------------------------
// ---------------------------------------------------------------

// ARCHIVO 'command_push.c' -----------------------------

/** 
* @brief push to stack a: Toma el primer elemento del stack b y lo pone 
el primero en el stack a. No hace nada si b está vacío.
* @param stack_a: puntero a stack destino.
* @param stack_b: puntero a stack origen.
* @returns void.
*/
void    pa(t_stack **stack_a, t_stack **stack_b, bool checker);

/** 
* @brief push to stack b: Toma el primer elemento del stack a y lo pone
el primero en el stack b. No hace nada si a está vacío.
* @param stack_b: puntero a stack destino.
* @param stack_a: puntero a stack origen.
** @returns void.
*/
void    pb(t_stack **stack_b, t_stack **stack_a, bool checker);

// ARCHIVO 'command_rotate.c' --------------------------

/** 
* @brief Empujar el 1º nodo superior en la parte inferior del stack a.
Atención si la pila vacía (NULL) o tamaño nodos igual a 1.
* @param stack : dirección de un puntero al primer nodo del stack a.
* @param checker : bool -> imprimir operacion si checker = 0.
* @returns void. Retorna 0 si tamaño stack menor de 2.
*/
void    ra(t_stack **stack_a, bool checker);

/** 
* @brief Empujar el 1º nodo superior en la parte inferior del stack b.
Atención si la pila vacía (NULL) o tamaño nodos igual a 1.
* @param stack : dirección de un puntero al primer nodo del stack b.
* @param checker : bool -> imprimir operacion si checker = 0.
* @returns void. Retorna 0 si tamaño stack menor de 2.
*/
void    rb(t_stack **stack_b, bool checker);

/** 
* @brief Empujar el 1º nodo superior en la parte inferior del stack a y stack b.
Atención si la pila vacía (NULL) o tamaño nodos igual a 1.
* @param stack_a : dirección de un puntero al primer nodo del stack a.
* @param stack_b : dirección de un puntero al primer nodo del stack b.
* @param checker : bool -> imprimir operacion si checker = 0.
* @returns void. Retorna 0 si tamaño stack menor de 2.
*/
void    rr(t_stack **stack_a, t_stack **stack_b, bool checker);

// ARCHIVO 'command_reverse_rotate.c' --------------------------

void    rra(t_stack **stack_a, bool checker);
void    rrb(t_stack **stack_b, bool checker);
void    rrr(t_stack **stack_a, t_stack **stack_b, bool checker);

// ARCHIVO 'command_swap.c' --------------------------

void    sa(t_stack **stack_a, bool checker);
void    sb(t_stack **stack_b, bool checker);
void    ss(t_stack **stack_a, t_stack **stack_b, bool checker);

// FUNCIONES FUNCIONES PERMITIDAS ORDENACION NODOS  ---------------------
// ---------------------------------------------------------------

// ARCHIVO 'sort_min.c' --------------------------

/*
 * Cuando tengo 3 nodos, es fácil de ordenar
 * ~Si el 1* es el más grande, ra (de mayor a inferior)
 * ~Si el 2* es el más grande, rra (de mayor a abajo)
 * ~ Ahora tengo con fuerza el más grande en la parte inferior.
 * entonces solo reviso 1° y 2°
*/
void tiny_sort(t_stack **stack);

#endif

