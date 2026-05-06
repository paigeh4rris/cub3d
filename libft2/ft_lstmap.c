/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeston <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:30:50 by cmeston           #+#    #+#             */
/*   Updated: 2021/12/14 15:43:31 by cmeston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*lstcopy;
// 	t_list	*eltcopy;

// 	if (lst == NULL || f == NULL)
// 		return (NULL);
// 	eltcopy = ft_lstnew((f)(lst->content));
// 	if (eltcopy == NULL)
// 		return (NULL);
// 	lstcopy = eltcopy;
// 	lst = lst->next;
// 	while (lst)
// 	{
// 		eltcopy = ft_lstnew(f(lst->content));
// 		if (eltcopy == NULL)
// 		{
// 			ft_lstclear(&lst, del);
// 			ft_lstclear(&lstcopy, del);
// 			break ;
// 		}
// 		lst = lst->next;
// 		ft_lstadd_back(&lstcopy, eltcopy);
// 	}
// 	return (lstcopy);
// }
