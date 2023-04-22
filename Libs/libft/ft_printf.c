/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:56:12 by svillalv          #+#    #+#             */
/*   Updated: 2022/09/21 13:03:51 by svillalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_format(const char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = count + ft_printchar(va_arg(args, int));
	else if (c == 's')
		count = count + ft_printstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count = count + ft_printnbr(va_arg(args, int));
	else if (c == 'u')
		count = count + ft_print_unsigned(va_arg(args, unsigned int));
	else if (c == 'p')
		count = count + ft_print_ptr(va_arg(args, unsigned long long));
	else if (c == 'x' || c == 'X')
		count = count + ft_print_hex(va_arg(args, unsigned int), c);
	else if (c == '%')
		count = count + ft_printpercent();
	return (count);
}

int	ft_printf(char const *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, format);
	if (!format)
		return (0);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] != '%')
			count = count + ft_printchar(format[i]);
		else
		{
			i++;
			count = count + ft_check_format(format[i], args);
		}
		i++;
	}
	va_end(args);
	return (count);
}
