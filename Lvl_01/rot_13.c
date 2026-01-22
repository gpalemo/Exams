/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:36:35 by cmauley           #+#    #+#             */
/*   Updated: 2026/01/07 20:39:56 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char *av[])
{
    if (ac == 2)
    {
        int i;
        
        i = 0;
        /* boucler sur toute la chaîne
         */
        while (av[1][i])
        {
            /* vérifier si le caractère est entre A a - M m
             * si c'est le cas, nous pouvons ajouter 13 pour obtenir
             * le caractère 13 places plus loin
             */
            if ((av[1][i] >= 'A' && av[1][i] <= 'M') || (av[1][i] >= 'a' && av[1][i] <= 'm'))
                av[1][i] += 13;
            /* vérifier si le caractère est entre N n - Z z
             * si c'est le cas, nous pouvons soustraire 13 pour obtenir
             * le caractère 13 places plus loin
             */
            else if ((av[1][i] >= 'N' && av[1][i] <= 'Z') || (av[1][i] >= 'n' && av[1][i] <= 'z'))
                av[1][i] -= 13;
            /* enfin, nous pouvons écrire le caractère et incrémenter le
             * compteur
             */
            write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}