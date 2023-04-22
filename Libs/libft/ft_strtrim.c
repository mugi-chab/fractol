/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:53:13 by svillalv          #+#    #+#             */
/*   Updated: 2022/05/22 20:52:07 by svillalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinstr(char s, char const *set)
{
	while (*set)
	{
		if (*set == s)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (ft_isinstr(s1[start], set))
		start++;
	len = 0;
	i = 0;
	while (s1[start + i])
	{
		if (!ft_isinstr(s1[start + i], set))
			len = i + 1;
		i++;
	}
	return (ft_substr(s1, start, len));
}
