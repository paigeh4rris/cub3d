/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeston <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:03:19 by cmeston           #+#    #+#             */
/*   Updated: 2021/12/13 15:20:45 by cmeston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	str = (char *) s;
	len = ft_strlen(str);
	while (i <= len)
	{
		if (*(str + i) == (unsigned char)c)
		{
			str = str + i;
			return (str);
		}
		i++;
	}
	return (NULL);
}
