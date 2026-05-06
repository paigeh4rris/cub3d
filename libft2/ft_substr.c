/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeston <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:19:46 by cmeston           #+#    #+#             */
/*   Updated: 2021/12/13 14:37:16 by cmeston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new_s;
	int				i;
	unsigned long	j;

	if (s == NULL)
		return (NULL);
	new_s = malloc(sizeof(char) * (len + 1));
	if (new_s == NULL)
		return (NULL);
	i = start;
	j = 0;
	if (start <= ft_strlen(s))
	{
		while (j < len && s[i] != '\0')
		{
			new_s[j] = s[i];
			j++;
			i++;
		}
	}
	new_s[j] = '\0';
	return (new_s);
}
