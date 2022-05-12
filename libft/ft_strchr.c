/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:46:57 by anfreire          #+#    #+#             */
/*   Updated: 2022/02/15 13:46:59 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	c1;

	c1 = (char)c;
	while (*s != '\0')
	{
		if (*s == c1)
			return ((char *)s);
		s++;
	}
	if (*s == c1)
		return ((char *)s);
	return (NULL);
}
