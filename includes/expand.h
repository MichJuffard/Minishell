
#ifndef EXPAND_H
# define EXPAND_H

#include <stdint.h>
#include "stddef.h"
#include "env.h"

char **expand_cmd(char **cmd, t_env *env);
int8_t expand_quote(char **str, uint8_t *quote, t_vector *env);
void	remove_quote(char *s);
size_t	get_envline(char **env, char *var);
void    fill_quote(uint8_t quotes[2], char c);
uint8_t is_charset(char c);
int8_t	expand_ret(char **str, uint8_t ret, uint8_t *quote);

#endif
