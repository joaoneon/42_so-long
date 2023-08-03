/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-a <jpedro-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:41:18 by jpedro-a          #+#    #+#             */
/*   Updated: 2023/06/05 16:40:01 by jpedro-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*nstr;
	char	*saved;
	char	*sv_1;

	if (s1 == NULL)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	sv_1 = s1;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	nstr = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (nstr == NULL)
		return (NULL);
	saved = nstr;
	while (s1_len-- > 0)
		*nstr++ = *s1++;
	while (s2_len-- > 0)
		*nstr++ = *s2++;
	*nstr = '\0';
	free(sv_1);
	return (saved);
}

int	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	character;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	character = (unsigned char)c;
	i = -1;
	while (s[++i] != '\0')
		if (s[i] == character)
			return (&str[i]);
	if (character == '\0')
		return (&str[i]);
	return (NULL);
}
