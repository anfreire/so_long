/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:36:14 by anfreire          #+#    #+#             */
/*   Updated: 2022/05/11 14:12:05 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_nbr_cntr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
	{
		i++;
		i++;
		nb = 147483648;
	}
	if (nb < 0)
	{
		i++;
		nb *= -1;
	}
	while (nb > 9)
	{
		i++;
		nb /= 10;
	}
	i++;
	return (i);
}

int	ft_putnbr(int nb)
{
	int	i;

	i = ft_nbr_cntr(nb);
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + 48);
	}
	return (i);
}

int	ft_num_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_print_unsigned_hex(unsigned int n, const char format)
{
	int		i;
	char	*num;

	if (format == 0)
	{
		i = 0;
		if (n == 0)
			i += write(1, "0", 1);
		else
		{
			num = ft_uitoa(n);
			i += ft_putstr(num);
			free(num);
		}
		return (i);
	}
	else
		if (n == 0)
			return (write(1, "0", 1));
	else
		ft_put_hex((unsigned long long)n, format);
	return (ft_hex_len((unsigned long long)n));
}
