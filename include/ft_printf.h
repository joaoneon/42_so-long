/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-a <jpedro-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:47:20 by jpedro-a          #+#    #+#             */
/*   Updated: 2023/06/19 18:06:34 by jpedro-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define LOW_BASE "0123456789abcdef"
# define HIGH_BASE "0123456789ABCDEF"

int	ft_printf(const char *str, ...);
int	put_char(char c);
int	put_string(char *str);
int	pointer_all(unsigned long nbr, char *base);
int	put_integer(int nbr, char *str, int index, int check);
int	put_unsigint(unsigned int nbr);
int	put_hex(unsigned int nbr, char *str, int index, int check);

#endif