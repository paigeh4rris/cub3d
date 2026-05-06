/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeston <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:11:54 by cmeston           #+#    #+#             */
/*   Updated: 2021/12/07 13:38:43 by cmeston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*scopy;
	int		l;

	l = ft_strlen(s);
	scopy = malloc(sizeof(char) * l + 2);
	if (scopy == NULL)
		return (NULL);
	ft_strlcpy(scopy, s, l + 2);
	return (scopy);
}
