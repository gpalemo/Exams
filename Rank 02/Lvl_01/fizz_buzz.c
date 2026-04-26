/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizz_buzz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:36:15 by cmauley           #+#    #+#             */
/*   Updated: 2026/01/07 18:50:39 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* nous avons besoin d'une fonction putnbr simple pour cela
* puisque nous travaillerons avec et imprimerons des nombres
 */
void ft_putnbr(int i)
{
/* si le nombre est supérieur à 9, nous appelons la fonction à nouveau
 * avec le nombre divisé par 10 pour supprimer un chiffre
 * de la fin (123 => 12)
 */
    if (i > 9)
        ft_putnbr(i / 10);
/* ensuite nous pouvons imprimer le caractère à l'index i % 10 (123 => 3)
 * dans une chaîne contenant tous les chiffres de 0 à 9
 */
    write(1, &"0123456789"[i % 10], 1);
/* Je vais expliquer ce que j'ai écrit ci-dessus :
 * en C, les chaînes n'existent pas, quand nous stockons une chaîne
 * nous stockons un tableau de caractères terminé par un caractère NUL
 * donc ce que j'ai fait ci-dessus, c'est écrire une chaîne, puis j'ai fait
 * la même chose que vous feriez pour sélectionner un élément de tableau avec
 * les crochets pour sélectionner un index spécifique
 * le deuxième argument de la fonction write est un char *
 * c'est pourquoi j'ai ajouté le caractère & devant la chaîne
 * De cette façon, je donne à write() un pointeur vers le
 * caractère spécifique que je veux écrire
 */
}

int main(void)
{
    int i;
    
    i = 1;
    while (i <= 100)
    {
        if (i % 3 == 0 && i % 5 == 0)
            write(1, "fizzbuzz", 8);
        else if  (i % 3 == 0)
            write(1, "fizz", 4);
        else if (i % 5 == 0)
            write(1, "buzz", 4);
        else
            ft_putnbr(i);
        i++;
        write(1, "\n", 1);
    }
}