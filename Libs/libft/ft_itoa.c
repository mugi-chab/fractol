/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:15:01 by svillalv          #+#    #+#             */
/*   Updated: 2022/05/22 20:51:25 by svillalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countnumber(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		n *= -1;
		len++;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	long	num;
	char	*conver;

	len = ft_countnumber(n);
	num = (long)n;
	conver = malloc(sizeof(char) * (len + 1));
	if (!conver)
		return (0);
	if (n < 0)
	{
		conver[0] = '-';
		num *= -1;
	}
	if (num == 0)
		conver[0] = '0';
	conver[len] = '\0';
	while (num > 0)
	{
		len--;
		conver[len] = num % 10 + '0';
		num /= 10;
	}
	return (conver);
}
