/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-a <jpedro-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:45:45 by jpedro-a          #+#    #+#             */
/*   Updated: 2023/06/20 15:07:49 by jpedro-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	variable_converter(char *str, int index, va_list list);

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		index;
	int		counter;

	if (str == 0)
		return (-1);
	va_start(list, str);
	index = -1;
	counter = 0;
	while (str[++index] != '\0')
	{
		if (str[index] == '%')
		{
			index++;
			while (str[index] != 'c' && str[index] != 's' && str[index] != 'p'
				&& str[index] != 'd' && str[index] != 'i' && str[index] != 'u'
				&& str[index] != 'x' && str[index] != 'X' && str[index] != '%')
				index++;
			counter += variable_converter((char *)str, index, list);
		}
		else
			counter += put_char(str[index]);
	}
	va_end(list);
	return (counter);
}

static int	variable_converter(char *str, int index, va_list list)
{
	int	counter;

	counter = 0;
	if (str[index] == 'c')
		counter += put_char(va_arg(list, int));
	else if (str[index] == 's')
		counter += put_string(va_arg(list, char *));
	else if (str[index] == 'p')
		counter += pointer_all(va_arg(list, unsigned long), LOW_BASE);
	else if (str[index] == 'd' || str[index] == 'i')
		counter += put_integer(va_arg(list, int), str, index, 1);
	else if (str[index] == 'u')
		counter += put_unsigint(va_arg(list, unsigned int));
	else if (str[index] == 'x' || str[index] == 'X')
		counter += put_hex(va_arg(list, int), str, index, 1);
	else if (str[index] == '%')
		counter += put_char('%');
	return (counter);
}
