/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:30:36 by cmauley           #+#    #+#             */
/*   Updated: 2026/01/07 20:34:58 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// easy frr

#include <unistd.h>

void	rev_print(char *str)
{
	int i = 0;

	while (str[i])
	{
		i++;
	}
	while (i >= 0)
	{
		write (1, &str[i], 1);
		i--;
	}
}
int main(int ac, char **av)
{
	if (ac == 2)
		rev_print(av[1]);
	write (1, "\n", 1);
	return (0);
}
