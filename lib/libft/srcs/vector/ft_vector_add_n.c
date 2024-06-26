/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_add_n.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:16:23 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/18 00:31:27 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"
#include <stdlib.h>

int	ft_vector_add_n(t_vector *vector, void *elem, size_t n)
{
	while (vector->capacity < vector->nbr_elem + n)
	{
		if (ft_vector_resize(vector, vector->capacity * 2) == -1)
			return (-1);
	}
	ft_memcpy(vector->addr + vector->nbr_elem * vector->size, elem,
		vector->size * n);
	vector->nbr_elem += n;
	return (1);
}
