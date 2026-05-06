/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeston <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:54:46 by cmeston           #+#    #+#             */
/*   Updated: 2022/05/24 15:43:14 by cmeston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_tokeep(char const *s1, const char *set)
{
	size_t	i;
	int		tokeep;

	i = 0;
	tokeep = ft_strlen(s1);
	while (ft_strchr(set, s1[i]) && s1[i])
	{
		tokeep--;
		i++;
	}
	i = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i]) && i)
	{
		if (tokeep == 0)
			return (0);
		tokeep--;
		i--;
	}
	if (tokeep < 0)
		tokeep = 0;
	return (tokeep);
}

static char	*ft_dotrim(char const *s1, char const *set, int len, char *s1trim)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ft_strchr(set, s1[i]))
		i++;
	len = len + i;
	while (i < len)
	{
		s1trim[j] = (char)s1[i];
		j++;
		i++;
	}
	s1trim[j] = '\0';
	return (s1trim);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s1trim;
	int		len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_tokeep(s1, set);
	s1trim = malloc(sizeof(char) * (len + 1));
	if (s1trim == NULL)
		return (NULL);
	if (len > 0)
		ft_dotrim(s1, set, len, s1trim);
	else
		s1trim[0] = '\0';
	return (s1trim);
}
