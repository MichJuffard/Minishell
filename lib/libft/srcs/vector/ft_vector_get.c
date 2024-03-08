/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:15:57 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/05 23:46:37 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*ft_vector_get(t_vector *vector, size_t n)
{
	if (n > vector->nbr_elem)
		return (NULL);
	return (vector->addr + ((n) * vector->size));
}
