/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeston <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:16:02 by cmeston           #+#    #+#             */
/*   Updated: 2021/12/13 15:12:39 by cmeston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n / 10 != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned long int		nb;
	char					*str;
	int						i;

	str = malloc(sizeof(char) * ft_intlen(n) + 1);
	if (str == NULL)
		return (NULL);
	str[ft_intlen(n)] = '\0';
	i = ft_intlen(n) - 1;
	if (n == -2147483648)
		nb = 2147483648;
	else if (n < 0 && n > -2147483648)
		nb = n * -1;
	else
		nb = n;
	while (i > 0)
	{
		str[i--] = (nb % 10 + '0');
		nb = nb / 10;
	}
	if (n < 0)
		str[0] = '-';
	else
		str[0] = nb + 48;
	return (str);
}
