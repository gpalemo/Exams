/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:09:15 by cmauley           #+#    #+#             */
/*   Updated: 2026/01/21 16:33:46 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_space(char c)	// Fonction pour vérifier si un caractère est un espace ou une tabulation
{
	return (c == ' ' || c == '\t');	// Retourne 1 si c'est un espace/tab, 0 sinon
}

void	rostring(char *s)	// Fonction principale pour réorganiser la string
{
	int i;	// Index pour parcourir la string
	int start;	// Index du début du premier mot
	int end;	// Index de la fin du premier mot

	i = 0;	// Initialise l'index à 0

	// 1️⃣ skip espaces au début
	while (s[i] && is_space(s[i]))	// Boucle tant que le caractère est un espace/tab
		i++;	// Avance jusqu'au premier caractère non-espace

	start = i;	// Marque le début du premier mot

	// 2️⃣ fin du premier mot
	while (s[i] && !is_space(s[i]))	// Boucle tant que le caractère n'est pas un espace
		i++;	// Avance jusqu'à trouver un espace

	end = i;	// Marque la fin du premier mot

	// 3️⃣ afficher les mots suivants
	while (s[i])	// Boucle tant qu'il y a des caractères
	{
		while (s[i] && is_space(s[i]))	// Saute les espaces entre les mots
			i++;	// Avance jusqu'au prochain mot
		if (s[i])	// Si on a trouvé un caractère non-espace
		{
			while (s[i] && !is_space(s[i]))	// Affiche le mot entier
				write(1, &s[i++], 1);	// Écrit chaque caractère du mot
			write(1, " ", 1);	// Ajoute un espace après le mot
		}
	}

	// 4️⃣ afficher le premier mot
	while (start < end)	// Boucle du début à la fin du premier mot
		write(1, &s[start++], 1);	// Écrit chaque caractère du premier mot
}

int	main(int ac, char **av)	// Fonction principale
{
	if (ac == 2)	// Vérifie qu'il y a exactement 2 arguments (programme + 1 string)
		rostring(av[1]);	// Appelle rostring avec la string passée en argument
	write(1, "\n", 1);	// Écrit une newline à la fin
	return (0);	// Retourne 0 (succès)
}
