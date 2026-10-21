/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirsner <ekirsner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:56:21 by ekirsner          #+#    #+#             */
/*   Updated: 2024/06/07 15:56:21 by ekirsner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *s, char c)
{
	int	i;
	int	word;

	word = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			word++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (word);
}

static char	*next_word(const char *s, char c, int *start)
{
	int	i;
	int	len;

	while (s[*start] && s[*start] == c)
		(*start)++;
	i = *start;
	len = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	*start = i;
	return (ft_substr(s, *start - len, len));
}

char	**ft_split(const char *s, char c)
{
	int		wc;
	char	**tab;
	int		i;
	int		start;

	wc = count_word(s, c);
	tab = (char **)malloc((wc + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	i = 0;
	start = 0;
	while (i < wc)
	{
		tab[i] = next_word(s, c, &start);
		if (tab[i] == NULL)
		{
			while (i-- > 0)
				free(tab[i]);
			free(tab);
			return (NULL);
		}
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

/*
int main()
{
	const char *s = "bonjour,les,amis";
	char **str;
	str = ft_split(s, ',');
	printf("%s", str[0]);
	printf("%s", str[1]);
	printf("%s", str[2]);
	return (0);
}
*/