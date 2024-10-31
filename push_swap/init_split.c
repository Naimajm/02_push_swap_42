/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:38:00 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/31 21:25:52 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_words_count(char const *str, char character);
static char	*ft_get_next_word(char *str, char separator);

/** 
* @brief Divide una cadena en una matriz de subcadenas según un carácter 
delimitador. Se guarda en lista de vectores con espacio +2 para el placeholder
"\0" y el terminador nulo.
* @param str char *: puntero a la cadena que se va a dividir.
* @param character char: carácter delimitador utilizado para dividir la cadena.
* @returns char ** -> Una matriz de cadenas asignada dinámicamente que 
representa las subcadenas divididas. El último elemento de la matriz se 
establece en NULL. NULL si falla la asignación de memoria o si 'str' es NULL.
*/
char	**split_push_swap(char *str, char separator)
{
	char	**vector_strings;
	int		words_number;	
	int		index;

	index = 0;
	words_number = ft_words_count(str, separator);
	if (!words_number)
		exit(1);
	vector_strings = malloc(sizeof(char *) * (size_t)(words_number + 2));
	if (!vector_strings)
		return (NULL);
	while (words_number >= 0)
	{
		words_number--;
		if (index == 0)
		{
			vector_strings[index] = malloc(sizeof(char));
			if (vector_strings[index] == NULL)
				return (NULL);
			vector_strings[index][0] = '\0';
			index++;
			continue ;
		}
		vector_strings[index] = ft_get_next_word(str, separator);
		index++;		
	}
	vector_strings[index] = NULL;
	return (vector_strings);
}

/** 
* @brief Cuenta las palabras recibidas de argv y separadas por 
un caracter definido.
* @param str char *: puntero a la cadena que se va a dividir.
* @param character char: carácter delimitador utilizado para dividir la cadena.
* @returns int -> numeros de palabras divididas por un separador.
*/
static int	ft_words_count(char const *str, char character)
{
	int	index;
	int	count;
	int	word_flag;

	index = 0;
	count = 0;
	word_flag = 0;
	while (str[index] != '\0')
	{
		if (str[index] != character && word_flag == 0)
		{
			word_flag = 1;
			count++;
		}
		else if (str[index] == character)
			word_flag = 0;
		index++;
	}
	return (count);
}

/** 
* @brief Accede al siguiente string desde la variable estatica 'cursor'
* @param str char *: puntero a la cadena que se va a dividir.
* @param separator char: carácter delimitador utilizado para dividir la cadena.
* @returns char	* -> Retorna la siguiente palabra.
*/
static char	*ft_get_next_word(char *str, char separator)
{
	static int	cursor = 0; // variable estatica indice del final de la palabra retornada
	char		*next_str; // buffer string donde copiar la palabra
	int			len; // longitud de la palabra
	int			index_next_str; // iterador de next_str

	len = 0;
	index_next_str = 0;
	// AVANZA HASTA EL 1º CARACTER NO SEPARADOR
	while (str[cursor] == separator)
		cursor++;
	// CALCULO LONGITUD DE LA PALABRA
	while ((str[cursor + len] != separator) && str[cursor + len])
		len++;
	// RESERVA ESPACIO BUFFER STRING + TERMINADOR NULO
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (!next_str)
		return (NULL);
	// COPIA CARACTERES de la palabra EN BUFFER 'next_str'
	while ((str[cursor] != separator) && str[cursor])
	{
		next_str[index_next_str] = str[cursor];
		index_next_str++;
		cursor++;
	}
	next_str[index_next_str] = '\0';
	return (next_str);
}
