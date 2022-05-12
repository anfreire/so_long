/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:41:45 by anfreire          #+#    #+#             */
/*   Updated: 2022/02/14 17:52:25 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*c;

	i = 0;
	c = s;
	if (n == 0)
		return ;
	while (i < n)
	{
		c[i] = 0;
		i++;
	}
}

/*int main()
{
    char str[] = "+-123teste58";
    bzero(str, 5);
	//ft_bzero(str, 5);
    printf("%s" , str);
    return 0;
}*/