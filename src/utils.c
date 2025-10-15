/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:42:16 by alda-sil          #+#    #+#             */
/*   Updated: 2025/10/14 21:48:53 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_list	*ft_lstnew(void *content)
{
	t_list			*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	lst->content = content;
	lst->next = (NULL);
	return (lst);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current_lst;

	current_lst = lst;
	while (current_lst)
	{
		if (current_lst->next == NULL)
			break ;
		current_lst = current_lst->next;
	}
	return (current_lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}
