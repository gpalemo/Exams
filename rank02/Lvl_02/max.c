/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 21:09:47 by cmauley           #+#    #+#             */
/*   Updated: 2026/01/07 21:10:18 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max(int *tab, unsigned int len)
{
	int		result;
	int		i;

	result = 0;
	i = 0;
	while (i <= len)
	{
		if (tab[i] > result)
			result = tab[i];
		i++;
	}
	return (result);
}