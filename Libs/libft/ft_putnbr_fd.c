/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: svillalv <svillalv@student.42malaga.com    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2022/05/22 23:34:17 by svillalv          #+#    #+#             */
/*   Updated: 2022/05/22 23:34:17 by svillalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	i;

	i = (long)n;
	if (i < 0)
	{
		ft_putchar_fd('-', fd);
		i *= -1;
	}
	if (i >= 10)
	{
		ft_putnbr_fd(i / 10, fd);
		i %= 10;
	}
	if (i < 10)
		ft_putchar_fd(i + '0', fd);
	return ;
}
