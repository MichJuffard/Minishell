
#include <stdlib.h>
#include "vector.h"
#include "expand.h"
#include "libft.h"

static int ft_vector_add_negative(t_vector *v, char *c);
static int ft_vector_add_n_negative(t_vector *v, char *c);
static int8_t	is_inquote(char *s, t_vector *new, size_t *i, t_vector *env);
static int		get_value(char *s, size_t *i, char **env, t_vector *vector);

int8_t expand_quote(char **str, uint8_t *quote, t_vector *env)
{
	size_t	i;
	t_vector	new;
	char 		*s;

	s = *str;
	if (-1 == ft_vector_init(&new, sizeof(char)))
		return -1;
	i = 0;
	while (s[i])
	{
		fill_quote(quote, s[i]);
		if (quote[1])
		{
			if (is_inquote(s, &new, &i, env))
				return (-1);
		}
		else if (-1 == ft_vector_add(&new, &s[i]))
			return (-1);
		i++;
	}
	if (-1 == ft_vector_add(&new, &s[i]))
		return (-1);
	free(*str);
	*str = ft_vector_get(&new, 0);
	return (0);
}

static int8_t is_inquote(char *s, t_vector *new, size_t *i, t_vector *env)
{
	if (s[*i] != '$' || (s[*i] == '$' && !is_charset(s[*i + 1])))
	{
		if (-1 == ft_vector_add_negative(new, &s[*i]))
			return (-1);
	}
	else
	{
		++*i;
		get_value(s, i, ft_vector_get(env, 0), new);
	}
	return (0);
}

static int get_value(char *s, size_t *i, char **env, t_vector *vector)
{
	char *value;
	size_t	backup;

	backup = *i;
	value = env[get_envline(env, s + *i)];
	while (s[*i] && is_charset(s[*i]))
		(*i)++;
	--*i;
	if (value == NULL)
		return 0;
	value += (*i - backup + 2);
	return ft_vector_add_n_negative(vector, value);
}

static int ft_vector_add_n_negative(t_vector *v, char *c)
{
	size_t	i;
	int		return_value;
	char	*strdup;

	strdup = malloc(sizeof(char) * (ft_strlen(c) + 1));
	if (NULL == strdup)
		return (-1);
	strdup[0] = c[0];
	i = 1;
	while (c[i])
	{
		strdup[i] = -c[i];
		i++;
	}
	strdup[i] = '\0';
	return_value = ft_vector_add_n(v, strdup, ft_strlen(strdup));
	free(strdup);
	return (return_value);
}
static int ft_vector_add_negative(t_vector *v, char *c)
{
	char	dupchar;
	int		return_value;

	dupchar = c[0];
	if (c[0] == '\'')
		dupchar = -(*c);
	return_value = ft_vector_add(v, &dupchar);
	return (return_value);
}