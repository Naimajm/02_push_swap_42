/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:38:00 by juagomez          #+#    #+#             */
/*   Updated: 2024/11/17 09:57:22 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_words_count(char const *str, char character);
static char	*ft_get_next_word(char *str, char separator);

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
	while (words_number-- >= 0)
	{
		if (index == 0)
		{
			vector_strings[index] = malloc(sizeof(char));
			if (vector_strings[index] == NULL)
				return (NULL);
			vector_strings[index++][0] = '\0';
			continue ;
		}
		vector_strings[index++] = ft_get_next_word(str, separator);
	}
	vector_strings[index] = NULL;
	return (vector_strings);
}

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

static char	*ft_get_next_word(char *str, char separator)
{
	static int	cursor = 0;
	char		*next_str;
	int			len;
	int			index_next_str;

	len = 0;
	index_next_str = 0;
	while (str[cursor] == separator)
		cursor++;
	while ((str[cursor + len] != separator) && str[cursor + len])
		len++;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (!next_str)
		return (NULL);
	while ((str[cursor] != separator) && str[cursor])
	{
		next_str[index_next_str] = str[cursor];
		index_next_str++;
		cursor++;
	}
	next_str[index_next_str] = '\0';
	return (next_str);
}
