/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeston <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:32:28 by cmeston           #+#    #+#             */
/*   Updated: 2021/12/08 15:45:52 by cmeston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*m;

	m = malloc(nmemb * size);
	if (m == 0)
		return (NULL);
	ft_bzero(m, nmemb * size);
	return (m);
}
