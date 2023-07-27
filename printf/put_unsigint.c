/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unsigint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-a <jpedro-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:46:05 by jpedro-a          #+#    #+#             */
/*   Updated: 2023/06/20 15:08:23 by jpedro-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_unsigint(unsigned int nbr)
{
	int	counter;

	counter = 0;
	if (nbr > 9)
	{
		counter += put_unsigint(nbr / 10);
		counter += put_unsigint(nbr % 10);
	}
	else
		counter += put_char(nbr + '0');
	return (counter);
}
