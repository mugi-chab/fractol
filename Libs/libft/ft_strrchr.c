/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:55:13 by svillalv          #+#    #+#             */
/*   Updated: 2022/04/30 21:08:01 by svillalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			ptr = (char *)&s[i];
		i++;
	}
	if (s[i] == (char) c)
	{
		ptr = (char *)&s[i];
		return (ptr);
	}	
	return (ptr);
}
