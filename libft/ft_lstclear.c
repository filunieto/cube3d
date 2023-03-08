/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:47:09 by anramire          #+#    #+#             */
/*   Updated: 2022/04/28 21:31:09 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;
	t_list	*ptr;

	aux = *lst;
	while (aux != NULL)
	{
		del(aux->content);
		ptr = aux;
		aux = aux->next;
		free(ptr);
	}
	*lst = aux;
}
