/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:07:23 by cmauley           #+#    #+#             */
/*   Updated: 2026/01/21 17:20:17 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>


// You have to use the ft_list.h file, which will contain: ft_list.h

typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

#include "ft_list.h"
#include "stdlib.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *tmp;

	if ((*begin_list == NULL) || (begin_list == NULL))
		return ;
	if (cmp((*begin_list)->data, data_ref) == 0)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	else
		ft_list_remove_if(&((*begin_list)->next), data_ref, cmp);
}