/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefernan <hefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 00:14:32 by hefernan          #+#    #+#             */
/*   Updated: 2022/03/04 12:36:21 by hefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[start] && len)
	{
		str[i] = s[start];
		start++;
		i++;
		len--;
	}
	str[i] = '\0';
	return (str);
}

static	int			ft_countwords(char const *s, char c)
{
	unsigned int	i;
	int				count;

	i = 0;
	count = 0;
	if (!s || !c)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (count);
}

static char			**ft_tab(char *s, char c, char **tab, int words)
{
	int				k;
	int				f;
	unsigned int	i;
	unsigned int	j;

	k = 0;
	i = 0;
	f = 0;
	while (k < words)
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		tab[k] = ft_substr(s, j, i - j);
		if (!tab)
		{
			while (f < k)
				free(tab[f++]);
			return (NULL);
		}
		k++;
	}
	tab[k] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		words;

	tab = NULL;
	if (!s)
		return (NULL);
	words = ft_countwords((char *)s, c);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	tab = ft_tab((char *)s, c, tab, words);
	if (!tab)
	{
		free(tab);
		tab = NULL;
	}
	return (tab);
}