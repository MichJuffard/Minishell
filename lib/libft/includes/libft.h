/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 23:49:35 by lrio              #+#    #+#             */
/*   Updated: 2024/04/24 23:19:22 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void	*ft_null_alloc(size_t nmemb, size_t size);
size_t	ft_strclen(const char *str, int c);
size_t	ft_count_word(const char *str, char c);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
int		ft_putfloat_fd(double num, int fd);
int		ft_putnbr_fd(long n, int fd);
int		ft_strcmp(const char *s1, char *s2);
int		ft_putstr_fd(char *s, int fd);
int		ft_putchar_fd(char c, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_memcmp(const void *p1, const void *p2, size_t n);
long	ft_atol(const char *str);
int		ft_atoi(const char *str);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isalpha(int c);
int		fp_isdigit(int c);
int		ft_isspace(char c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
char	*ft_strcdup(const char *src, int c);
void	*ft_memset(void	*dest, int c, size_t n);
void	*ft_bzero(void	*dest, size_t n);
void	*ft_memcpy(void	*dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
void	*ft_memchr(const void *b, int c, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup(const char *src);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char *str, char *charset);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strstrfjoin(char *str1, char *str2, char *str3);
char	*ft_strfjoin(char *s1, char const *s2);
char	*ft_itoa(long n);
char	*ft_itoa_base(size_t n, char *base);
char	*ft_strndup(const char *src, size_t n);
void	ft_free_tab(char **tab);
size_t	ft_tablen(char **tab);
char	**ft_tabdup(char **tab);

#endif
