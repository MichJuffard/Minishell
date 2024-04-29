/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:42:13 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/25 04:32:08 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "vector.h"
#include "libft.h"
#include "ft_printf.h"

void	close_vector_fd(t_vector *fd)
{
	size_t	i;

	i = 0;
	while (i < fd->nbr_elem)
	{
		if (-1 == close(*(int *)ft_vector_get(fd, i)))
			ft_dprintf(STDERR_FILENO, "Minichel: %s\n", strerror(errno));
		i++;
	}
}

int	is_build_in(char *str)
{
	if (NULL == str)
		return (0);
	return (!ft_strcmp(str, "cd")
		|| !ft_strcmp(str, "echo")
		|| !ft_strcmp(str, "param")
		|| !ft_strcmp(str, "exit")
		|| !ft_strcmp(str, "export")
		|| !ft_strcmp(str, "pwd")
		|| !ft_strcmp(str, "unset")
		|| !ft_strcmp(str, "return")
		|| !ft_strcmp(str, "ptree")
		|| !ft_strcmp(str, "env"));
}
