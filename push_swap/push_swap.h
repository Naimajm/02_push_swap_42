/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:24:48 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/23 11:29:13 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"

#include <unistd.h> // write
#include <stdlib.h> // malloc free
# include <stdbool.h> // booleanos
# include <limits.h> // VALORES INT_MIN INT_MAX

#include <stdio.h>  // printf

// ESTRUCTURA DATOS -> LISTA VINCULADA -> STACKS / PILAS
typedef struct s_stack
{
	int	value;
	int	current_position;
	int	push_price;
	bool	above_median;
	bool	cheapest_cost;

	struct	s_stack	*target_node;
	struct	s_stack	*prev;
	struct	s_stack	*next;	
}					t_stack;

// FUNCIONES INICIALIZACION PILA (STACK)  ---------------------------
// ---------------------------------------------------------------

/// ?? split archivo
char	**ft_split_1(char *str, char separator);

// ARCHIVO 'stack_init.c' -----------------------------

/** 
* @brief Crea la pila con los valores de la línea de comando.
Las verificaciones están integrados en la creación misma:
	-Valores duplicados.
	-Sobre / Desbordamiento insuficiente.
	-Errores de sintaxis.
* @param t_stack **stack: puntero a la lista vinculada creada.
* @param char **argv: puntero a lista de argumentos strings.
* @param bool flag_argc_2: si es verdadera, tengo el argv en el HEAP
para liberar.
* @returns void
*/
void	stack_init(t_stack **stack, char **argv, bool flag_argc_2);

/*
 * Comprobar si una pila determinada está ordenada
*/
bool	stack_is_sorted(t_stack *stack);

// ARCHIVO 'free.c' -----------------------------

void ft_free_all(t_stack **stack, char **argv, bool flag_argc_2);

// liberar la matriz 2D creado con la función ft_split() -> ATENCIÓN Tienes que empezar desde -1
void ft_free_matrix(char **argv);

// LIBERAR MEMORIA STACK
void	ft_free_stack(t_stack **stack);

// IMPRESION MENSAJE 'Error' en fd = 2
void ft_print_error(void);

// ARCHIVO 'stack_utils.c' -----------------------------

/*
 * Encuentra el nodo con push_price mas barato (cheapest == true)
*/
t_stack	*find_cheapest_node(t_stack *stack);

/*
 * Encuentra el nodo de valor más pequeño
*/
t_stack	*find_smallest_node(t_stack *stack);

void    ft_append_node(t_stack **stack, int number);

// ENCONTRAR ULTIMO NODO DE ESTRUCTURA
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

// FUNCIONES ALGORITMO ORDENACION  ---------------------
// ---------------------------------------------------------------

// ARCHIVO 'sort_min.c' --------------------------

/*
	Algoritmo ordenamiento 5 argumentos
*/
void	tiny_sort_five(t_stack **stack_a, t_stack **stack_b);

/*
 * Cuando tengo 3 nodos, es fácil de ordenar
 * ~Si el 1* es el más grande, ra (de mayor a inferior)
 * ~Si el 2* es el más grande, rra (de mayor a abajo)
 * ~ Ahora tengo con fuerza el más grande en la parte inferior.
 * entonces solo reviso 1° y 2°
*/
void tiny_sort_three(t_stack **stack);

// ARCHIVO 'push_swap_init.c' --------------------------

/*
 * Todos los valores necesarios para realizar el push a stack a.
 * -Posiciones relativas de stack a y stack b
 * -Nodo objetivo del nodo b.
 * -push_price por cada configuración
 * -cheapest segun la configuración actual
*/
void	init_nodes(t_stack *stack_a, t_stack *stack_b);

/*
 * Marcar el nodo más barato en la actuales configuraciones de stacks
*/
void	set_cheapest_node(t_stack *stack_b);

/*
 * Establecer los precios para impulsar el nodo de b -> a
 * El precio verifica las posiciones relativas en la pila para cada nodo, 
 * fijando el precio respectivo.
*/
void	set_push_price(t_stack *stack_a, t_stack *stack_b);

/*
	ASIGNAR CURRENT POSITION + ABOVE_MEDIAN PARA NODO.
	Establecer la posición actual de cada nodo en la configuración de estado actual	
*/
void	set_current_position(t_stack *stack);

// ARCHIVO 'push_swap_command.c' --------------------------

/*
 * ~Empuja todos los nodos en B 
 * ~ Para cada configuración, elija el "nodo_más barato"
 * ~ Empuja todo hacia atrás en A en orden
*/
void	push_swap(t_stack **stack_a, t_stack **stack_b);

/*
 * Concluir la rotación de las pilas. Rotar de forma individual cada stack hasta posicionar al 1º nodo
*/
void	finish_rotation(t_stack **stack, t_stack *top_node, char stack_name);

#endif
