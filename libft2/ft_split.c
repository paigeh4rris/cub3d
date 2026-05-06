/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeston <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:53:26 by cmeston           #+#    #+#             */
/*   Updated: 2022/05/31 10:47:46 by cmeston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_nbmots(const char *s, char c)
{
	int	i;
	int	mots;

	i = 0;
	mots = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			mots++;
		while (s[i] != c && s[i])
			i++;
	}
	return (mots);
}

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char	**ft_nbchar(const char *s, char c, char **tab)
{
	int	i;
	int	j;
	int	nbchar;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < ft_nbmots(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] == '\0')
			return (tab);
		nbchar = 0;
		while (s[i] && s[i++] != c)
			nbchar++;
		tab[j] = malloc(sizeof(char) * nbchar + 1);
		if (tab[j] == NULL)
		{
			ft_free(tab);
			return (NULL);
		}
		j++;
	}
	return (tab);
}

static char	**ft_copytab(char const *s, char **tab, char c, int mots)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (j < mots)
	{
		while (s[i] == c && s[i])
			i++;
		k = 0;
		while (s[i] != c && s[i])
		{
			tab[j][k] = s[i];
			i++;
			k++;
		}
		tab[j][k] = '\0';
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split_chine(char const *s, char c)
{
	char	**tab;

	if (s == NULL)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_nbmots(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	ft_nbchar(s, c, tab);
	tab = ft_copytab(s, tab, c, ft_nbmots(s, c));
	return (tab);
}
