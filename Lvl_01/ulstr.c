/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 21:00:50 by cmauley           #+#    #+#             */
/*   Updated: 2026/01/07 21:01:17 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* Fonction qui inverse la casse des lettres dans une chaîne :
 * majuscules deviennent minuscules et vice versa,
 * puis affiche la chaîne modifiée.
 */
void	ulstr(char *str)
{
	int	i;

	i = 0;
	/* Boucle sur chaque caractère de la chaîne jusqu'à la fin */
	while (str[i] != '\0')
	{
		/* Si le caractère est une majuscule, le convertir en minuscule */
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
			write(1, &str[i], 1);
		}
		/* Si le caractère est une minuscule, le convertir en majuscule */
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
			write(1, &str[i], 1);
		}
		/* Sinon, afficher le caractère tel quel (non alphabétique) */
		else
			write(1, &str[i], 1);
		i++;
	}
}

/* Fonction principale : prend un argument de ligne de commande,
 * applique ulstr dessus, puis affiche un saut de ligne.
 */
int	main(int argc, char **argv)
{
	if (argc == 2)
		ulstr(argv[1]);
	write(1, "\n", 1);
	return (0);
}