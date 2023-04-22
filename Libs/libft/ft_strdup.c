/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:20:36 by svillalv          #+#    #+#             */
/*   Updated: 2022/05/22 20:51:45 by svillalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*d;
	char	*temp;

	d = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!d)
	{
		errno = ENOMEM;
		return (0);
	}
	temp = d;
	while (*s1)
	{
		*temp++ = *s1++;
	}
	*temp = '\0';
	return (d);
}
