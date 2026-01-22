/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 21:16:48 by cmauley           #+#    #+#             */
/*   Updated: 2026/01/07 21:17:35 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char *av[])
{
    int i;
    
    if (ac == 2)
    {
        i = 0;
        /* boucler sur toute la chaîne
         */
        while (av[1][i])
        {
            /* si nous rencontrons une lettre majuscule,
             * nous devons la rendre minuscule et écrire un _ avant elle
             */
            if (av[1][i] >= 'A' && av[1][i] <= 'Z')
            {
                /* ici, nous changeons la lettre majuscule en sa
                 * lettre minuscule correspondante
                 */
                av[1][i] += 32;
                /* nous écrivons un _ à l'écran
                 */
                write(1, "_", 1);
            }
            /* puis nous pouvons écrire le caractère actuel, modifié ou non
             */
            write(1, &av[1][i], 1);
            i++;
        }
    }
    /* enfin nous pouvons écrire le retour à la ligne
     */
    write(1, "\n", 1);
}