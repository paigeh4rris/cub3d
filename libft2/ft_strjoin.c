/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeston <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:01:22 by cmeston           #+#    #+#             */
/*   Updated: 2022/05/31 12:07:19 by cmeston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	cat = malloc(sizeof(char) * len);
	if (cat == NULL)
		return (NULL);
	ft_strlcpy(cat, s1, ft_strlen(s1));
	ft_strlcpy((cat + ft_strlen(s1)), s2, ft_strlen(s2));
	return (cat);
}
