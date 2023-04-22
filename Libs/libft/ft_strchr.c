/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 13:25:03 by svillalv          #+#    #+#             */
/*   Updated: 2022/07/07 14:50:21 by svillalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		ptr = (char *)&s[i];
		if (s[i] == (char)c)
			return (ptr);
		i++;
	}
	ptr = (char *)&s[i];
	if (s[i] == (char)c)
		return (ptr);
	return (0);
}
