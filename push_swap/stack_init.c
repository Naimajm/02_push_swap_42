/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 12:15:28 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/17 10:00:39 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_duplicate_numbers(t_stack *stack_a, int number);
static int	ft_error_syntax(char *str_numbers);
static long ft_atol(const char *str);


/*
 *  atol, i need it to check eventual overflows
 *  converting every string into a long value
*/
/* static long	ft_atol_oceano(const char *str)
{
	long	num;
	int		isneg;
	int		i;

	num = 0;
	isneg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * isneg);
} */


void	stack_init(t_stack **stack, char **argv, bool flag_argc_2)
{
	long number;
	int	index;

	index = 0;
	// para cada argumento string -> validar, convertir a numero y añadir a nodo
	while (argv[index])
	{	
		// VALIDACION ERRORES SINTACTICOS -> NUMEROS VALIDOS
		if(ft_error_syntax(argv[index]))
			ft_free_all(stack, argv, flag_argc_2);

		// CONVERSION ARGUMENTO STR A NUMERO
		number = ft_atol(argv[index]);

		// VALIDACION NUMEROS ENTEROS MAXIMOS Y MINIMOS -> NUMEROS NO VALIDOS
		if(number > INT_MAX || number < INT_MIN)
			ft_free_all(stack, argv, flag_argc_2);

		// VALIDACION NUMBER CON NUMEROS EN LOS NODOS YA CREADOS
		if(ft_check_duplicate_numbers(*stack, (int)number))
			ft_free_all(stack, argv, flag_argc_2);

		// AÑADIR VALOR EN NUEVO NODO
		ft_append_node(stack, (int)number);		
		index++;
	}
	if (flag_argc_2)
		ft_free_matrix(argv);	
}

bool	stack_is_sorted(t_stack *stack)
{
	// VALIDACION INICIAL
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

/** 
* @brief Checkea string por error de repeticion de numeros en el stack.
* @param str: puntero a estructura lista vinculada.
* @param int: numero entero a comparar con valores de los nodos.
* @returns 0 -> no duplicidad numero ; valor 1 -> duplicidad numero.
*/
static int	ft_check_duplicate_numbers(t_stack *stack, int number)
{
	// VALIDACION INICIAL ARGUMENTOS
	if (stack == NULL)
		return (0);
	// CICLO VALORES EN NODOS Y COMPARACION CON NUMBER
	while (stack)
	{
		if (stack->value == number)
			return (1);
		stack = stack->next;
	}
	return (0);	
}

/** 
* @brief Checkea string por error sintaticos para la conversion de 
numeros validos.
* @param str: puntero al string con valores numericos o de signo -,+.
* @returns 0 -> no errores sintacticos ; valor 1 -> error.
*/
static int	ft_error_syntax(char *str_numbers)
{
	int index;

	index = 0;
	// VALIDACION 1º CHAR-> char fuera de signo (+ -) y serie numerica (0-9) 
	if(!(str_numbers[index] == '+' || str_numbers[index] == '-' 
		|| ft_isdigit(str_numbers[index])))
		return (1);
	//VALIDACION 1º CHAR COMO SIGNO y siguiente caracter NO ES NUMERO
	if ((str_numbers[index] == '+' || str_numbers[index] == '-') && !ft_isdigit(str_numbers[index + 1]))
		return (1);
	// validacion valor numerico a partir del 2º character
	while (str_numbers[index])
	{
		if (!ft_isdigit(str_numbers[index]))
			return (1);
		index++;
	}
	return (0);	
}

/** 
* @brief Convierte una representación de cadena de un número 'LONG'
en su valor entero correspondiente.
* @param str: puntero a la cadena que se va a converti.
* @returns long -> valor long obtenido de la cadena de entrada
o valor 0 como error.
*/
static long ft_atol(const char *str)
{
	return ((long)(ft_atoi(str)));
}

/* int main(void)
{
	// TESTEO FUNCION ft_atol()
	printf("TESTEO FUNCION ft_atol() -> str '%s' \n", " -945asd");
	printf("ft_atol -> return %ld \n\n", ft_atol(" -945asd"));

	// TESTEO FUNCION ft_error_syntax()
	printf("TESTEO FUNCION ft_error_syntax() -> str '%s' \n", " -a945");
	printf("ft_error_syntax -> return %d \n", ft_error_syntax(" -a945"));

	printf("TESTEO FUNCION ft_error_syntax() -> str '%s' \n", "-945");
	printf("ft_error_syntax -> return %d \n\n", ft_error_syntax("-945"));

	// TESTEO INICIALIZAR STACK
	t_stack *stack_a;
	stack_a = NULL;
	printf("TESTEO INICIALIZAR STACK stack_init() -> str '%p' \n", stack_a);
	printf("stack_init() -> return puntero stack a -> %p \n", stack_a);

	// listado ptr string -> simulacion inputs string en 'argv'
	char	*arg_num[5] = { arg_num[0]= '\0', arg_num[1] = "42", arg_num[2] = "1337", arg_num[3] = "-21", arg_num[4] = NULL };
	stack_init(&stack_a, arg_num + 1, false);
	while (stack_a)
	{
		printf( "arg numero-> %d, \t ptr previous -> %p \t address node -> %p \t ptr next -> %p \n", stack_a->value, stack_a->prev, stack_a, stack_a->next );
		stack_a = stack_a->next;
	}
	return (0);
} */