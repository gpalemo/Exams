/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:44:03 by cmauley           #+#    #+#             */
/*   Updated: 2026/01/21 17:45:16 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}
int	count_words(char *str)
{
	int count = 0;

	while (*str)
	{
		while (*str && ft_isspace(*str))
			str++;
		if (*str)
		{
			count++;
			while (*str && !ft_isspace(*str))
				str++;
		}
	}
	return (count);
}
char	*copy_word(char *str)
{
	int		i = 0;
	char	*word;

	while (str[i] && !ft_isspace(str[i]))
		i++;

	word = malloc(sizeof(*word) * (i + 1));
	if (!word)
		return (NULL);

	i = 0;
	while (str[i] && !ft_isspace(str[i]))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}
char	**ft_split(char *str)
{
	char	**result;
	int		i = 0;

	result = malloc(sizeof(*result) * (count_words(str) + 1));
	if (!result)
		return (NULL);

	while (*str)
	{
		while (*str && ft_isspace(*str))
			str++;
		if (*str)
		{
			result[i] = copy_word(str);
			i++;
			while (*str && !ft_isspace(*str))
				str++;
		}
	}
	result[i] = NULL;
	return (result);
}
