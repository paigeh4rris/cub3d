/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeston <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:59:17 by cmeston           #+#    #+#             */
/*   Updated: 2021/12/14 16:22:02 by cmeston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*scopy;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	scopy = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (scopy == NULL)
		return (NULL);
	ft_strlcpy(scopy, (char *)s, (ft_strlen(s) + 1));
	i = 0;
	while (scopy[i] != '\0')
	{
		scopy[i] = f(i, scopy[i]);
		i++;
	}
	return (scopy);
}
