/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:24:48 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/30 17:42:33 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* C LIBRARIES */

#include <unistd.h> // write
#include <stdlib.h> // malloc free
# include <stdbool.h> // booleanos
# include <limits.h> // VALORES INT_MIN INT_MAX
#include <stddef.h> // size_t NULL

#include <stdio.h>  // printf

/* OWN LIBRARIES */

#include "../libft/libft.h"

// ESTRUCTURA DATOS -> LISTA VINCULADA -> STACKS / PILAS
/* La estructura `s_stack` es una representación rica en información de un
nodo en una pila doblemente enlazada, diseñada para soportar algoritmos de 
ordenación complejos. Contiene campos para valores, índices, costos, posiciones, 
punteros a nodos adyacentes y objetivos, así como marcadores booleanos para facilitar la implementación de estrategias de ordenación eficientes. */
typedef struct s_stack
{
	int	value; //  valor del nodo en la pila
	int	current_position; // pos -> posición actual del nodo en la pila
	int index; // index índice del nodo (valor en una lista si todos los numeros estuvieran ordenados)


	int	cost;  // cost  costo asociado con mover este nodo a su posición correcta en la pila ordenada. Este costo puede ser calculado en función de las operaciones necesarias para mover el nodo

	int	target_position; // posición nodo objetivo del nodo en la pila ordenada
	
	int	a_cost; // costo de mover el nodo en stack a
	int	b_cost; // costo de mover el nodo en stack b
	bool	above_median;  // above -> indicar si el nodo está por encima de otro nodo en algún contexto específico del algoritmo
	bool	cheapest_cost; // best option mejor candidato para alguna operación específica en el algoritmo

	struct	s_stack	*target_node; // puntero a nodo objetivo en la pila ordenada
	struct	s_stack	*prev;
	struct	s_stack	*next;	
}					t_stack;

// FUNCIONES INICIALIZACION PILA (STACK)  ---------------------------
// ---------------------------------------------------------------

/** 
* @brief Divide una cadena en una matriz de subcadenas 
según un carácter delimitador.
* @param str: puntero a la cadena que se va a dividir.
* @param separator: carácter delimitador utilizado para dividir la cadena.
* @returns char ** -> Una matriz de cadenas asignada dinámicamente que 
representa las subcadenas divididas. 
El último elemento de la matriz se establece en NULL.
NULL si falla la asignación de memoria o si 'str' es NULL.
*/
char	**split(char *str, char separator);

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
void	stack_init(t_stack **stack, char **argv);

/** 
* @brief  Comprobar si una pila determinada está ordenada.
* @param stack t_stack *: puntero a estructura lista vinculada.
* @returns bool -> true -> stack numeros ordeandos ; false -> no ordenado.
*/
bool	stack_is_sorted(t_stack *stack);

// ARCHIVO 'free.c' -----------------------------

/** 
* @brief Libera reserva de memoria del stack utilizado. 
Borra cada nodo de forma individual y establece puntero stack en nulo.
* @param stack t_stack **: puntero a lista de nodos stack.
* @returns void .
*/
void	ft_free_stack(t_stack **stack);

// ARCHIVO 'stack_utils.c' -----------------------------

/** 
* @brief Agrega nuevo nodo al final del stack. 
Incorpora numero en el atributo 'value'.
* @param stack t_stack **: puntero a lista de nodos stack.
* @param number int: valor numerico a incluir en stack->value.
* @returns void .
*/
void    ft_append_node(t_stack **stack, int number);

/** 
* @brief Encuentra el nodo con atributo 'push_price' 
mas barato (cheapest == true).
* @param stack t_stack *: puntero al primer nodo del stack.
* @returns t_stack * -> puntero a nodo encontrado .
*/
t_stack	*find_cheapest_node(t_stack *stack);

/** 
* @brief Encuentra el nodo con atributo 'value' mas pequeño.
* @param stack t_stack *: puntero al primer nodo del stack.
* @returns t_stack * -> puntero a nodo encontrado .
*/
t_stack	*find_smallest_node(t_stack *stack);

/** 
* @brief  Retorna puntero al ultimo nodo del stack.
* @param stack t_stack *: puntero al primer nodo del stack.
* @returns t_stack * -> puntero ultimo nodo.
*/
t_stack	*ft_find_last_node(t_stack *stack);

/** 
* @brief  Cuenta el número de nodos en una pila (stack).
* @param stack t_stack *: puntero al primer nodo del stack.
* @returns int -> Número de nodos del stack.
*/
int	ft_stack_len(t_stack *stack);

// FUNCIONES FUNCIONES PERMITIDAS ORDENACION NODOS  ---------------------------
// ---------------------------------------------------------------

// ARCHIVO 'command_push.c' -----------------------------

/** 
* @brief push to stack a: Toma el primer elemento del stack b y lo pone 
el primero en el stack a. No hace nada si b está vacío.
* @param stack_a t_stack **: rección de un puntero al primer nodo del stack a.
* @param stack_b t_stack **: dirección de un puntero al primer nodo del stack b.
* @param print bool: imprimir operacion si print = true.
* @returns void.
*/
void    pa(t_stack **stack_a, t_stack **stack_b, bool print);

/** 
* @brief push to stack b: Toma el primer elemento del stack a y lo pone
el primero en el stack b. No hace nada si a está vacío.
* @param stack_b t_stack **: dirección de un puntero al primer nodo del stack b.
* @param stack_a t_stack **: rección de un puntero al primer nodo del stack a.
* @param print bool: imprimir operacion si print = true.
** @returns void.
*/
void    pb(t_stack **stack_b, t_stack **stack_a, bool print);

// ARCHIVO 'command_rotate.c' --------------------------

/** 
* @brief Empujar el 1º nodo superior en la parte inferior del stack a.
Atención si la pila vacía (NULL) o tamaño nodos igual a 1.
* @param stack t_stack **: dirección de un puntero al primer nodo del stack a.
* @param print bool: imprimir operacion si print = true.
* @returns void. Retorna 0 si tamaño stack menor de 2.
*/
void    ra(t_stack **stack_a, bool print);

/** 
* @brief Empujar el 1º nodo superior en la parte inferior del stack b.
Atención si la pila vacía (NULL) o tamaño nodos igual a 1.
* @param stack t_stack **: dirección de un puntero al primer nodo del stack b.
* @param print bool: imprimir operacion si print = true.
* @returns void. Retorna 0 si tamaño stack menor de 2.
*/
void    rb(t_stack **stack_b, bool print);

/** 
* @brief Empujar el 1º nodo superior en la parte inferior del stack a y stack b.
Atención si la pila vacía (NULL) o tamaño nodos igual a 1.
* @param stack_a t_stack **: dirección de un puntero al primer nodo del stack a.
* @param stack_b t_stack **: dirección de un puntero al primer nodo del stack b.
* @param print bool: imprimir operacion si print = true.
* @returns void. Retorna 0 si tamaño stack menor de 2.
*/
void    rr(t_stack **stack_a, t_stack **stack_b, bool print);

// ARCHIVO 'command_reverse_rotate.c' --------------------------

/** 
* @brief Empujar el ultimo nodo a la parte superior del stack a.
Atención si la pila vacía (NULL) o tamaño nodos igual a 1.
* @param stack_b t_stack **: dirección de un puntero al primer nodo del stack b.
* @param print bool: imprimir operacion si print = true.
* @returns void. Retorna 0 si tamaño stack menor de 2.
*/
void    rra(t_stack **stack_a, bool print);

/** 
* @brief Empujar el ultimo nodo a la parte superior del stack b.
Atención si la pila vacía (NULL) o tamaño nodos igual a 1.
* @param stack_b t_stack **: dirección de un puntero al primer nodo del stack b.
* @param print bool: imprimir operacion si print = true.
* @returns void. Retorna 0 si tamaño stack menor de 2.
*/
void    rrb(t_stack **stack_b, bool print);

/** 
* @brief Empujar el ultimo nodo a la parte superior del stack a y stack b.
Atención si la pila vacía (NULL) o tamaño nodos igual a 1.
* @param stack_a t_stack **: dirección de un puntero al primer nodo del stack a.
* @param stack_b t_stack **: dirección de un puntero al primer nodo del stack b.
* @param print bool: imprimir operacion si print = true.
* @returns void. Retorna 0 si tamaño stack menor de 2.
*/
void    rrr(t_stack **stack_a, t_stack **stack_b, bool print);

// ARCHIVO 'command_swap.c' --------------------------

/** 
* @brief Intercambia el 1º nodo de posición con el 2º nodo del stack a.
Atención si la pila src está vacía (NULL). Planteamiento con stack dest 
vacio o con algun nodo existente.
* @param stack_a t_stack **: dirección de un puntero al primer nodo del stack a.
* @param print bool: imprimir operacion si print = true.
*/
void    sa(t_stack **stack_a, bool print);

/** 
* @brief Intercambia el 1º nodo de posición con el 2º nodo del stack b.
Atención si la pila src está vacía (NULL). Planteamiento con stack dest 
vacio o con algun nodo existente.
* @param stack_b t_stack **: dirección de un puntero al primer nodo del stack b.
* @param print bool: imprimir operacion si print = true.
*/
void    sb(t_stack **stack_b, bool print);

/** 
* @brief Intercambia el 1º nodo de posición con el 2º nodo del stack a y b.
Atención si la pila src está vacía (NULL). Planteamiento con stack dest 
vacio o con algun nodo existente.
* @param stack_a t_stack **: dirección de un puntero al primer nodo del stack a.
* @param stack_b t_stack **: dirección de un puntero al primer nodo del stack b.
* @param print bool: imprimir operacion si print = true.
*/
void    ss(t_stack **stack_a, t_stack **stack_b, bool print);

// FUNCIONES ALGORITMO ORDENACION  ---------------------
// ---------------------------------------------------------------


// ARCHIVO 'sort.c' --------------------------

/** 
 * @brief Ordena stack con 5 nodos. 
* @param stack_a t_stack **: dirección de un puntero al primer nodo del stack a.
* @param stack_b t_stack **: dirección de un puntero al primer nodo del stack b.
* @returns void.
*/
void	tiny_sort_five(t_stack **stack_a, t_stack **stack_b);

/** 
 * @brief Ordena stack con 3 nodos. Coloca abajo el nodo con valor mas alto:
 * -Si el 1* es el más grande, ra (de mayor a inferior).
 * -Si el 2* es el más grande, rra (de mayor a abajo).
 * Posteriormente ordena los 2 elementos restantes.
* @param stack t_stack **: puntero a lista de nodos stack.
* @returns void.
*/
void tiny_sort_three(t_stack **stack);

/** 
* @brief Encuentra el nodo con atributo 'value' mas grande.
* @param stack t_stack *: puntero al primer nodo del stack.
* @returns t_stack * -> puntero a nodo encontrado .
*/
t_stack	*find_highest_node(t_stack *stack);

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

// ARCHIVO 'sorting.c' --------------------------

void	sorting(t_stack **stack_a, t_stack **stack_b);
void ft_get_index(t_stack *stack);

//void	ft_get_index(t_stack *stack_a, int stack_len_max);

// ARCHIVO 'utils.c' --------------------------



#endif
