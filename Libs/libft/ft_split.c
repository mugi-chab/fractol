/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:35:25 by svillalv          #+#    #+#             */
/*   Updated: 2022/05/22 20:51:38 by svillalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_pointtostring(char *memory, unsigned int len, int words)
{
	char	**arr;
	size_t	i;
	size_t	w;

	arr = (char **) malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (0);
	i = 0;
	w = 0;
	if (memory[i] != '\0')
		arr[w++] = ft_strdup(&memory[i]);
	i++;
	while (i < len)
	{
		if (memory[i] != '\0' && memory[i - 1] == '\0')
			arr[w++] = ft_strdup(&memory[i]);
		i++;
	}
	arr[w] = 0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	len;
	size_t	i;
	int		words;
	char	*memory;
	char	**arr;

	if (!s)
		return (0);
	len = ft_strlen(s);
	memory = ft_strdup(s);
	if (!memory)
		return (0);
	i = 0;
	words = 0;
	while (i < len)
	{
		if (memory[i] == c)
			memory[i] = '\0';
		else if (i == 0 || memory[i - 1] == '\0')
			words++;
		i++;
	}
	arr = ft_pointtostring(memory, len, words);
	free(memory);
	return (arr);
}
