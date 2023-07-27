/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-a <jpedro-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:47:11 by jpedro-a          #+#    #+#             */
/*   Updated: 2023/06/20 15:09:08 by jpedro-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hexhigh(unsigned int nbr, char *str, int index);

int	put_hex(unsigned int nbr, char *str, int index, int check)
{
	int	counter;

	counter = 0;
	if (str[index - 1] == '#' && check == 1 && nbr != 0)
	{
		if (str[index] == 'x')
			counter += put_string("0x");
		else
			counter += put_string("0X");
	}
	check = 0;
	if (str[index] == 'x')
	{
		if (nbr > 15)
		{
			counter += put_hex(nbr / 16, str, index, 0);
			counter += put_hex(nbr % 16, str, index, 0);
		}
		else
			counter += put_char(LOW_BASE[nbr]);
	}
	if (str[index] == 'X')
		counter += put_hexhigh(nbr, str, index);
	return (counter);
}

int	put_hexhigh(unsigned int nbr, char *str, int index)
{
	int	counter;

	counter = 0;
	if (nbr > 15)
	{
		counter += put_hex(nbr / 16, str, index, 0);
		counter += put_hex(nbr % 16, str, index, 0);
	}
	else
		counter += put_char(HIGH_BASE[nbr]);
	return (counter);
}
