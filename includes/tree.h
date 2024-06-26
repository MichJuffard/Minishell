/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:43:43 by lrio              #+#    #+#             */
/*   Updated: 2024/04/24 22:01:20 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

# include "vector.h"
# include "env.h"

# define PTREE_INDENT 6

typedef enum e_node
{
	O_OR,		// ||
	O_AND,		// &&
	O_PIPE,		// |
	HERE_DOC,	// <<
	APPEND,		// >>
	OUTPUT,		// >
	INPUT,		// <
	CMD,
}	t_node;

typedef struct s_tree
{
	struct s_tree	*left;
	struct s_tree	*right;
	struct s_tree	*root;
	enum e_node		type;
	void			*structur;
}	t_tree;

typedef struct s_cmd
{
	char	*path;
	char	**arg;
}	t_cmd;

void	print_tree(t_tree *root);
void	ft_clean_tree(t_tree *tree);
t_tree	*ft_new_tree(void *content, t_node node, t_tree *root);

#endif