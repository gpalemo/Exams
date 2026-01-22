/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 21:12:17 by cmauley           #+#    #+#             */
/*   Updated: 2026/01/07 21:15:25 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

int main(int ac, char *av[])
{
    int i;
    
    if (ac == 2)
    {
        i = 0;
        while (av[1][i])
        {
            if (av[1][i] >= 'A' && av[1][i] <= 'Z')
            /* nous soustrayons le code ASCII de la lettre du code ASCII
             * de la dernière lettre majuscule, puis ajoutons le code ASCII
             * de la première lettre majuscule
             * 90 - 65(A) = 35, 35 + 65 = 90(Z)
             * 90 - 66(B) = 34, 34 + 65 = 89(Y)
             */ 
                av[1][i] = 'Z' - av[1][i] + 65;
            else if (av[1][i] >= 'a' && av[1][i] <= 'z')
            /* nous soustrayons le code ASCII de la lettre du code ASCII
             * de la dernière lettre minuscule, puis ajoutons le code ASCII
             * de la première lettre minuscule
             * 'z' - 'a' = 35, 35 + 'a' = 'z'
             * 'z' - 'b' = 34, 34 + 'a' = 'y'
             */ 
                av[1][i] = 'z' - av[1][i] + 'a';
            /* enfin, nous pouvons écrire le caractère actuel à l'écran
             */
            write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}