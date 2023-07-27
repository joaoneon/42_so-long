/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-a <jpedro-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:45:32 by jpedro-a          #+#    #+#             */
/*   Updated: 2023/06/20 15:08:20 by jpedro-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_string(char *str)
{
	int	i;

	i = 0;
	if (str == 0)
		return (put_string("(null)"));
	while (str[i] != '\0')
	{
		put_char(str[i]);
		i++;
	}
	return (i);
}
