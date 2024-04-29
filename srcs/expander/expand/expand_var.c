
#include <stdlib.h>
#include "expand_utils.h"
#include "libft.h"
#include "ft_printf.h"

static int8_t free_and_return(t_vector *v);
int8_t expand_var(char **str, t_vector *env)
{
	char		*s;
	t_vector	new;
	size_t		i;

	if (ft_vector_init(&new, sizeof(char)) == -1)
		return (-1);
	s = *str;
	i = 0;
	while (s[i])
	{
		if (s[i] == '$' && (ft_isalpha(s[i + 1]) || s[i + 1] == '_'))
		{
			if (add_var(s, &i, env, &new) == -1)
				return (free_and_return(&new));
			continue ;
		}
		if (ft_vector_add(&new, &s[i]) == -1)
			return (free_and_return(&new));
		if (s[i])
			i++;
	}
	if (ft_vector_add(&new, &s[i]) == -1)
		return (free_and_return(&new));
	free(s);
	*str = ft_vector_get(&new, 0);
	return (0);
}

static int8_t	free_and_return(t_vector *v)
{
	ft_vector_free(v, NULL);
	return (-1);
}
