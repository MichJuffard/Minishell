/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:46:40 by lrio              #+#    #+#             */
/*   Updated: 2024/02/29 03:25:19 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token.h"
#include "lexer.h"

//todo: si type == CHAR verifier quil ny a pas de &a
//todo: fix &
//todo: check type[last]
int	lexer(char *str)
{
	t_vector		vector;
	size_t 			i;
	size_t 			parent[2];
	t_token_type	type;

	if (-1 == vector_init(&vector, sizeof(t_token)))
		return (0);
	if (-1 == get_tokens(str, &vector))
		return (0);
	i = 0;
	ft_memset(parent, 0, sizeof(size_t) * 2);
	while (i < vector.nbr_elem)
	{
		type = ((t_token *)vector.addr)[i].type;
		if ((type == PARENTESE_OP && lex_parenthese_op(&vector, parent, i)) || \
			(type == PARENTESE_CL && lex_parenthese_cl(&vector, parent, i)) || \
			(type == LOGICAL_OP && lex_operator(&vector, i)) || \
			(type == RED_OUT && lex_redirect_out(&vector, i)) || \
			(type == RED_IN && lex_redirect_in(&vector, i)) || \
			(type == PIPE && lex_pipe(&vector, i)))
			return (free_token(&vector), 1);

		i++;
	}
	if (parent[0] != parent[1])
		return (free_token(&vector), 1);

	free_token(&vector);
	return (0);
}
