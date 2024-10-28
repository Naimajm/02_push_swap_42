/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:26:03 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/28 14:40:17 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	move_nodes(t_stack **stack_a, t_stack **stack_b);
static	void	rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node);
static	void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node);

/* void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*smallest_node;
	int	stack_len_a;

	stack_len_a = ft_stack_len(*stack_a);
	
	//printf("stack_len_a -> %i \n", stack_len_a);

	// INICIO CONFIGURACION STACK A Y B -----------------

	// CASO ESPECIAL 5 NODOS -> ALGORTIMO ORDENACION ESPECIFICO
	if (stack_len_a == 5)
		tiny_sort_five(stack_a, stack_b);
	else
	{
		// MOVER TODOS LOS NODOS EXCEPTO 3 AL STACK B
		while (stack_len_a > 3)
		{
			stack_len_a--;
			pb(stack_b, stack_a, true);			
		}
	}

	// ORDENACION 3 NODOS STACK A -----------------
	tiny_sort_three(stack_a);

	// INICIALIZAR ORDENACION -> ciclo mover nodos 'cheapest' desde b hasta stack a
	while (*stack_b != NULL)
	{
		init_nodes(*stack_a, *stack_b);  // actualizar valores nodos (current_position, cost, ..)
		move_nodes(stack_a, stack_b);		
	}
	// STACK B VACIO -> ACTUALIZAR POSICION STACK A
	set_current_position(*stack_a);

	// TRANSFORMACION 2º rotar hasta tener nodo mas pequeño arriba
	smallest_node = find_smallest_node(*stack_a);
	if (smallest_node->above_median == true)
		while (*stack_a != smallest_node)
			ra(stack_a, true);
	else
		while (*stack_a != smallest_node)
			rra(stack_a, true);
} */

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	int				len_a;

	//printf("push_swap() \n");
	
	len_a = ft_stack_len(*a);
	//printf("ft_stack_len() -> %i \n", len_a);

	if (len_a == 5)
	{
		//printf("push_swap() tiny_sort_five() \n");
		tiny_sort_five(a, b);
	}
	else
	{
		//printf("push_swap() pb() \n");
		while (len_a-- > 3)
			pb(b, a, true);
	}
	//printf("push_swap() tiny_sort_three() \n");
	// IMPRESION STACK A	
	/* t_stack *stack_copy_a;
	stack_copy_a = *a;
	while (stack_copy_a)  
	{
		//printf( "push_swap() stack -> arg numero-> %d, \t prev-> %p \t address-> %p \t next-> %p \n", stack_copy_a->value, stack_copy_a->prev, stack_copy_a, stack_copy_a->next );
		stack_copy_a = stack_copy_a->next;
	}
 */
	tiny_sort_three(a);

	//printf("push_swap() inicio ciclo init node() \n");

	// IMPRESION STACK B	
	/* t_stack *stack_copy_b;
	stack_copy_b = *b;
	while (stack_copy_b)  
	{
		printf( "main() stack -> arg numero-> %d, \t prev-> %p \t address-> %p \t next-> %p \n", stack_copy_b->value, stack_copy_b->prev, stack_copy_b, stack_copy_b->next );
		stack_copy_b = stack_copy_b->next;
	} */

	while (*b)
	{
		init_nodes(*a, *b);

		//printf("push_swap() init_nodes() -> %p a, %p b \n", *a, *b);

		move_nodes(a, b);
	}
	set_current_position(*a);
	smallest = find_smallest_node(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, true);
	else
		while (*a != smallest)
			rra(a, true);
}



/*
 * Mueve el nodo de 'b' a 'a' con los metadatos disponibles en el nodo
 * 1) Hacer que emerjan los nodos objetivo
 * 2) push en A
*/
/* static void	move_nodes(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;
	t_stack	*target_node;

	cheapest_node = find_cheapest_node(*stack_b);
	target_node = cheapest_node->target_node;

	// ROTACION HASTA Q 1 NODO QUEDA COMO 1º NODO
	// CASO 1 -> NODO CHEAP + TARGE NODE ENCIMA MEDIANA -> ROTAR AMBOS (ra +rb)
	if (cheapest_node->above_median == true && target_node->above_median == true)
		rotate_both(stack_a, stack_b, cheapest_node);
	// CASO 2 -> NODO CHEAP + TARGE NODE DEBAJO MEDIANA -> ROTAR REVERSO AMBOS (rra + rrb)	
	else if (!(cheapest_node->above_median) && !(target_node->above_median))
		reverse_rotate_both(stack_a, stack_b, cheapest_node);

	// ROTACION INDIVIDUAL del OTRO NODO HASTA QUEDAR COMO 1º NODO
	finish_rotation(stack_b, cheapest_node, 'b');
	finish_rotation(stack_a, target_node, 'a');
	// PUSH DEL cheapest_node DEL STACK B AL STACK A
	pa(stack_a, stack_b, true);	
} */

static void	move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = find_cheapest_node(*b);
	//printf("move_nodes() -> cheapest_node, %p \n", cheapest_node);
	
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	pa(a, b, true);
}



/* void	finish_rotation(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median == true)
				ra(stack, true);
			else
				rra(stack, true);			
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median == true)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
} */

void	finish_rotation(t_stack **stack,
							t_stack *top_node,
							char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, true);
			else
				rrb(stack, true);
		}	
	}
}

/*
	Ejecuta 'rotacion rr' para cada nodo hasta q el 1º nodo sea el cheapest_node en el stack b
	y el target_node en el stack a	
*/
/* static	void	rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node)
{
	t_stack	*target_node;

	target_node = cheapest_node->target_node;

	// ROTAR ELEMENTOS HASTA Q CHEAPEST Y TARGET NODE ESTEN ARRIBA en los stack (ptr *stack)
	while ((*stack_a != target_node) && (*stack_b != cheapest_node))
		rr(stack_a, stack_b, true);
	// ACTUALIZAR POSICIONES DESPUES DE ROTACION
	set_current_position(*stack_a);
	set_current_position(*stack_b);	
} */

static void	rotate_both(t_stack **a,
						t_stack **b,
						t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node
		&& *b != cheapest_node)
		rr(a, b, true);
	set_current_position(*a);
	set_current_position(*b);
}

/*
	Ejecuta 'reverse rotacion' 'rrr' para cada nodo hasta q el 1º nodo sea el cheapest_node en el stack b
	y el target_node en el stack a	
*/
/* static	void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node)
{
	t_stack	*target_node;

	target_node = cheapest_node->target_node;

	// ROTAR ELEMENTOS HASTA Q CHEAPEST Y TARGET NODE ESTEN ARRIBA en los stack (ptr *stack)
	while (*stack_a != target_node && *stack_b != cheapest_node)
		rrr(stack_a, stack_b, true);
	// ACTUALIZAR POSICIONES DESPUES DE ROTACION
	set_current_position(*stack_a);
	set_current_position(*stack_b);	
} */

static void	reverse_rotate_both(t_stack **a,
								t_stack **b,
								t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node
		&& *b != cheapest_node)
		rrr(a, b, true);
	set_current_position(*a);
	set_current_position(*b);
}



