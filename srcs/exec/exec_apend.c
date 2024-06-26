/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_apend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:35:32 by mjuffard          #+#    #+#             */
/*   Updated: 2024/05/02 04:26:02 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include "exec.h"
#include "ft_printf.h"
#include "expand.h"

int	exec_apend(t_tree *tree, t_fds *fds, t_param *param)
{
	int	fd;
	int	ret;

	tree->structur = expand_file((char *)tree->structur, param);
	if (!(char *)tree->structur)
		return (1);
	fd = open((char *)tree->structur, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1 || ft_vector_add(&fds->fd_out, &fd) == -1)
	{
		ft_dprintf(STDERR_FILENO, ERROR_MSG, (char *)tree->structur,
			strerror(errno));
		return (1);
	}
	ret = exec_args(tree->left, fds, tree->root, param);
	ft_vector_delete_elem(&fds->fd_out, fds->fd_out.nbr_elem - 1);
	if (close(fd) == -1)
	{
		ft_dprintf(STDERR_FILENO, ERROR_MSG, (char *)tree->structur,
			strerror(errno));
		return (1);
	}
	return (ret);
}
