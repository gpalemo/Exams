/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:19:10 by cmauley           #+#    #+#             */
/*   Updated: 2026/01/07 20:26:42 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char *av[])
{
    int i;
    int j;
    
      /* vérifier le nombre d'arguments
     */
    if (ac == 2)
    {
        i = 0;
/* boucler sur toute la chaîne
         */
        while (av[1][i])
        {
            /* si le caractère est une lettre majuscule
             */
            if (av[1][i] >= 'A' && av[1][i] <= 'Z')
            {
                j = 0;
                /* boucler tant que j est plus petit que l'index alphabétique
                 * du caractère actuel
                 * - 64 permet d'obtenir l'index alphabétique
                 * A en ASCII => 65, donc 65 - 64 = 1
                 * Z en ASCII => 90, donc 90 - 64 = 26
                 */
                while (j < av[1][i] - 64)
                {
                    write(1, &av[1][i], 1);
                    j++;
                }
            }
            else if (av[1][i] >= 'a' && av[1][i] <= 'z')
            {
                j = 0;
                j = 0;
                /* boucler tant que j est plus petit que l'index alphabétique
                 * du caractère actuel
                 * - 96 permet d'obtenir l'index alphabétique
                 * a en ASCII => 97, donc 97 - 96 = 1
                 * z en ASCII => 122, donc 122 - 96 = 26
                 */
                while (j < av[1][i] - 96)
                {
                    write(1, &av[1][i], 1);
                    j++;
                }
            }
            else
                /* si le caractère actuel n'est pas une lettre
                 * écrit simplement le caractère
                 */
                write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}