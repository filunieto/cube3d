/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:05:04 by anramire          #+#    #+#             */
/*   Updated: 2022/04/28 21:32:33 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*aux;
	t_list	*ptr;

	aux = lst;
	ptr = NULL;
	while (aux != NULL)
	{
		ptr = aux;
		aux = aux->next;
	}
	return (ptr);
}
