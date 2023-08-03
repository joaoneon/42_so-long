/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-a <jpedro-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:57:40 by jpedro-a          #+#    #+#             */
/*   Updated: 2023/08/02 17:58:25 by jpedro-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	is_negative(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

static size_t	count_digits(size_t n)
{
	unsigned int	digits;

	if (n == 0)
		return (1);
	digits = 0;
	while (n > 0)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char			*result;
	unsigned int	negative;
	long int		number;
	unsigned int	digits;

	negative = is_negative(n);
	number = n;
	if (negative == 1)
		number *= -1;
	digits = count_digits(number);
	result = (char *)malloc(digits + negative + 1);
	if (result == NULL)
		return (NULL);
	if (negative == 1)
		result[0] = '-';
	result[digits + negative] = '\0';
	while (digits > 0)
	{
		result[(digits - 1) + negative] = (number % 10) + '0';
		number /= 10;
		digits--;
	}
	return (result);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	i = nmemb * size;
	if (i != 0 && i / size != nmemb)
		return (NULL);
	ptr = (void *)malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}

void	*ft_memset(void *s, int c, size_t x)
{
	size_t	i;

	i = 0;
	while (i < x)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}
