/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:45:40 by mechane           #+#    #+#             */
/*   Updated: 2023/02/12 14:33:25 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t	ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (0);
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	return (1);
}

int	ft_strncmp(const char *s11, const char *s22, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s2 = (unsigned char *)s22;
	s1 = (unsigned char *)s11;
	if (n == 0)
		return (-1);
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0' && n - 1 > 0)
	{
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}

int	ft_atoi(const char *str)
{
	long long		res;
	int				sign;
	int				i;

	i = 0;
	res = 0;
	sign = 1;
	if (str[0] == '\0')
		return (0);
	while (((((str[i] >= 9) && (str[i] <= 13))
				|| (str[i] == ' ')) && (str[i] != '\0')))
				i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return ((sign * res));
}
