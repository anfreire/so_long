/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:57:58 by anfreire          #+#    #+#             */
/*   Updated: 2022/05/11 14:12:28 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_aux_printf(const char *fmt, va_list args, int i);

int	ft_printf(const char *fmt, ...)
{	
	int		i;
	va_list	args;

	i = 0;
	va_start(args, fmt);
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			fmt++;
			i = ft_aux_printf(fmt, args, i);
		}
		else
			i += ft_putchar(*fmt);
		fmt++;
	}
	va_end(args);
	return (i);
}

static int	ft_aux_printf(const char *fmt, va_list args, int i)
{
	if (*fmt == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (*fmt == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (*fmt == 'p')
		i += ft_print_ptr(va_arg(args, unsigned long long));
	else if (*fmt == 'd' || *fmt == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (*fmt == 'u')
		i += ft_print_unsigned_hex(va_arg(args, unsigned int), 0);
	else if (*fmt == 'x' || *fmt == 'X')
		i += ft_print_unsigned_hex(va_arg(args, unsigned int), *fmt);
	else if (*fmt == '%')
		i += ft_putchar('%');
	return (i);
}
