/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeston <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:15:15 by cmeston           #+#    #+#             */
/*   Updated: 2021/12/08 19:02:34 by cmeston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char	*bigg, const char *little, size_t len)
{
	unsigned long	i;
	char			*big;

	big = (char *) bigg;
	i = 0;
	if (ft_strlen(little) == 0)
		return (big);
	if (len > 0)
	{
		while (big[i] != '\0' && i <= len - ft_strlen(little))
		{
			if (big[i] == little[0]
				&& ft_strncmp(little, &big[i], ft_strlen(little)) == 0)
				return (&big[i]);
			i++;
		}
	}
	return (NULL);
}
