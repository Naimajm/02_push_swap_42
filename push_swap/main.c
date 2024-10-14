/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:24:53 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/13 20:43:06 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	// DECLARACION + INICIALIZACION LISTAS VINCULADAS 'STACKS' 
	t_stack	*stack_a; 	// ptr a nodo
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	// VALIDACION INPUT + CAPTURA ARGUMENTOS (1 ARG STRING O 2º ARGUMENTO SIN NUMERO)
	if (argc == 1 || (argc == 2 && argv[1][0] == 0)) // ./a.out ""
	{ 
		printf("1 \n");
		return (1);
	}
	else if (argc == 2)  // INPUTS ARGUMENTOS POR STRING
	{
		argv = ft_split(argv[1], ' '); // DIVISION ARGUMENTO EN NUMEROS
		printf("%s \n", argv[0]);
	}
	// CREACION STACK
	stack_init(&stack_a, argv + 1, argc == 2); 

	// VERIFICACION STACK A -> YA ORDENADO

	// ALGORTIMO ORDENACION -> ORDENAR PARA 2, 3 O RESTO ELEMENTOS (push_swap())

	// LIBERAR MEMORIA STACK


	return (0);
}