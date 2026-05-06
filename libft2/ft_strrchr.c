/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrcchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeston <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:18:23 by cmeston           #+#    #+#             */
/*   Updated: 2021/12/08 18:56:30 by cmeston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *) s;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (*(str + i) == (unsigned char)c)
		{
			str = str + i;
			return (str);
		}
		i--;
	}
	return (NULL);
}
