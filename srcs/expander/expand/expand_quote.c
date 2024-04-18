/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:12:19 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/17 20:12:24 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	remove_quote(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 127)
			s[i] = '\0';
		if ((s[i] == '\'' || s[i] == '"') || (s[i] == '$'
			&& (s[i + 1] == '\'' || s[i + 1] == '"')))
		{
			ft_memmove(s + i, s + i + 1, ft_strlen(s + i + 1) + 1);
			continue ;
		}
		if (s[i] < 0)
			s[i] = -s[i];
		i++;
	}
}
