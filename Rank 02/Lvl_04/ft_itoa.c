/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:25:36 by cmauley           #+#    #+#             */
/*   Updated: 2026/01/20 15:08:29 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	count_len(int nbr)	// Fonction pour compter le nombre de chiffres d'un nombre
{
	int i = 0;	// Compteur initialisé à 0

	if (nbr >= 0)	// Si le nombre est positif ou zéro
		i++;	// Ajoute 1 pour la place du dernier chiffre
	while (nbr != 0)	// Boucle tant qu'il y a des chiffres à traiter
	{
		nbr = nbr / 10;	// Divise par 10 pour retirer un chiffre
		i++;	// Incrémente le compteur
	}
	return (i);	// Retourne le nombre total de chiffres
}
char	*itoa(int nbr)	// Fonction pour convertir un entier en string
{
	int i;	// Index pour remplir la string
	int len;	// Longueur totale de la string à allouer
	long num;	// Copie du nombre en long pour gérer les négatifs
	char *result;	// Pointeur vers la string résultante

	num = nbr;	// Copie le nombre dans num
	len = count_len(nbr);	// Calcule la longueur totale nécessaire
	result = malloc(len + 1);	// Alloue de la mémoire (+1 pour '\0')
	if (!result)	// Si l'allocation a échoué
		return (NULL);	// Retourne NULL
	result[len] = '\0';	// Place le terminateur de string à la fin
	i = len - 1;	// Commence à remplir par la fin
	if (num < 0)	// Si le nombre est négatif
	{
		result[0] = '-';	// Place le signe négatif en première position
		num = -num;	// Rend num positif pour le traitement
	}
	while (num > 9)	// Boucle tant qu'il y a plus d'un chiffre
	{
		result[i] = num % 10 + '0';	// Extrait le dernier chiffre et le convertit en char
		num = num / 10;	// Retire ce chiffre du nombre
		i--;	// Recule dans la string pour le chiffre suivant
	}
	result[i] = num + '0';	// Place le dernier chiffre
	return (result);	// Retourne la string générée
}