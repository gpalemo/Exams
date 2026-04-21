/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 21:22:20 by cmauley           #+#    #+#             */
/*   Updated: 2026/01/07 21:23:02 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int ac, char *av[])
{
    /* vérifier le nombre d'arguments
     */
    if (ac == 4)
    {
        /* nous basculons ensuite sur l'opérateur (av[2][0])
         */
        switch(av[2][0])
        {
            /* si l'opérateur est +, nous faisons simplement une
             * addition et imprimons le résultat à l'écran
             */
            case '+':
                printf("%d", atoi(av[1]) + atoi(av[3]));
                break;
            /* si l'opérateur est -, nous faisons simplement une
             * soustraction et imprimons le résultat à l'écran
             */
            case '-':
                printf("%d", atoi(av[1]) - atoi(av[3]));
                break;
            /* si l'opérateur est *, nous faisons simplement une
             * multiplication et imprimons le résultat à l'écran
             */
            case '*':
                printf("%d", atoi(av[1]) * atoi(av[3]));
                break;
            /* si l'opérateur est /, nous faisons simplement une
             * division et imprimons le résultat à l'écran
             */            
            case '/':
                printf("%d", atoi(av[1]) / atoi(av[3]));
                break;
            /* si l'opérateur est %, nous faisons simplement un
             * modulo et imprimons le résultat à l'écran
             */
            case '%':
                printf("%d", atoi(av[1]) % atoi(av[3]));
                break;
        }
    }
    /* enfin, nous écrivons un retour à la ligne
     */
    printf("\n");
}