/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:56:44 by anramire          #+#    #+#             */
/*   Updated: 2022/04/28 21:33:25 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*aux;
	t_list	*ptr;	

	aux = lst;
	new_list = NULL;
	while (aux != NULL)
	{
		ptr = ft_lstnew(f(aux->content));
		if (!ptr)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, ptr);
		aux = aux->next;
	}
	return (new_list);
}
