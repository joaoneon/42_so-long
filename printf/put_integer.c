/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_integer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-a <jpedro-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:45:20 by jpedro-a          #+#    #+#             */
/*   Updated: 2023/06/20 15:08:57 by jpedro-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	flagchecker(char *str, int index);

int	put_integer(int nbr, char *str, int index, int check)
{
	int	counter;

	counter = 0;
	if (check == 1 && nbr >= 0)
		counter += flagchecker(str, index);
	check = 0;
	if (nbr == -2147483648)
	{
		counter += put_string("-2");
		counter += put_integer(147483648, str, index, 0);
	}
	else if (nbr < 0)
	{
		counter += put_char('-');
		nbr *= -1;
		counter += put_integer(nbr, str, index, 0);
	}
	else if (nbr > 9)
	{
		counter += put_integer(nbr / 10, str, index, 0);
		counter += put_integer(nbr % 10, str, index, 0);
	}
	else
		counter += put_char(nbr + '0');
	return (counter);
}

static int	flagchecker(char *str, int index)
{
	int	counter;

	counter = 0;
	if (str[index - 1] == ' ' || str[index - 1] == '+')
		counter += put_char(str[index - 1]);
	return (counter);
}
