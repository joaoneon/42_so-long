/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pointerall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-a <jpedro-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:45:23 by jpedro-a          #+#    #+#             */
/*   Updated: 2023/06/20 15:08:17 by jpedro-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_pointer(unsigned long nbr, char *base);

int	pointer_all(unsigned long nbr, char *base)
{
	int	counter;

	if (nbr == 0)
		return (put_string("(nil)"));
	counter = 0;
	counter += put_string("0x");
	counter += put_pointer(nbr, base);
	return (counter);
}

int	put_pointer(unsigned long nbr, char *base)
{
	int	counter;

	counter = 0;
	if (nbr > 15)
		counter += put_pointer(nbr / 16, base);
	counter += put_char(base[nbr % 16]);
	return (counter);
}
