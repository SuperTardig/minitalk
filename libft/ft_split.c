/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:38:09 by bperron           #+#    #+#             */
/*   Updated: 2022/04/06 11:10:22 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sep_count(const char *s, char c)
{
	int	i;
	int	sep;

	sep = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c
				|| s[i + 1] == '\0'))
				sep++;
		i++;
	}
	return (sep);
}

static int	new_split_len(const char *s, char c, int index)
{
	int	i;

	i = 0;
	while (index >= 0 && s[index] != c)
	{
		index--;
		i++;
	}
	return (i);
}

static char	*splitting(const char *s, char c, int index)
{
	char	*new_split;
	int		i;
	int		j;
	int		start;

	i = new_split_len(s, c, index);
	j = 0;
	start = index - i + 1;
	new_split = ft_calloc(i + 1, sizeof(char));
	if (new_split == NULL)
		return (NULL);
	while (j < i)
		new_split[j++] = s[start++];
	return (new_split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		nb_sep;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	nb_sep = sep_count(s, c);
	split = ft_calloc(nb_sep + 1, sizeof(char *));
	if (split == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c
				|| s[i + 1] == '\0'))
			split[j++] = splitting(s, c, i);
		i++;
	}
	return (split);
}
