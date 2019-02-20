/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:59:01 by kibotrel          #+#    #+#             */
/*   Updated: 2019/01/23 19:34:53 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

/*
**	Libc Functions
*/

# define LLMAX 9223372036854775807ull

size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
											size_t len);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_atoi(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

/*
**	Complementary Functions
*/

void				ft_putnbr(int nb);
void				ft_strclr(char *s);
void				ft_putchar(char c);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_putstr(char const *s);
void				*ft_memalloc(size_t size);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_itoa(int n);
char				*ft_strnew(size_t size);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);

/*
**	Bonus Functions
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

/*
**	Extra Functions
*/

# define BUFF_SIZE 4096

typedef struct		s_gnlist
{
	struct s_gnlist	*next;
	struct s_gnlist	*prev;
	int				fd;
	char			*save;
}					t_gnlist;

typedef struct		s_chain
{
	void			*data;
	struct s_chain	*next;
}					t_chain;

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}					t_btree;

unsigned int		ft_numlen(int nb);
t_btree				*ft_btree_create_node(void *item);
t_chain				*ft_create_elem(void *data);
t_chain				*ft_list_last(t_chain *begin_list);
t_chain				*ft_list_at(t_chain *begin_list, unsigned int nbr);
void				ft_list_reverse(t_chain **begin_list);
void				ft_sort_int_tab(int *tab, unsigned int size);
void				ft_foreach(int *tab, int length, void (*f)(int));
void				ft_list_push_back(t_chain **begin_list, void *data);
void				ft_list_push_front(t_chain **begin_list, void *data);
void				ft_list_foreach(t_chain *begin_list, void (*f)(void *));
void				ft_btree_apply_infix(t_btree *src, void (applyf)(void *));
void				ft_btree_apply_suffix(t_btree *src, void (*applyf)(void *));
void				ft_btree_apply_prefix(t_btree *src, void (*applyf)(void *));
void				ft_list_remove_if(t_chain **begin_list, void *data_ref,
										int (*cmp)());
void				*ft_btree_search_item(t_btree *root, void *dataref,
										int (*cmpf)(void *, void *));
void				ft_foreach_if(t_chain *begin_list, void (*f)(void *),
										void *data_ref, int (*cmp)());
char				*ft_strrev(char *str);
char				*ft_itoa_base(int value, int base);
int					ft_isspace(int c);
int					ft_is_prime(int nb);
int					ft_is_negative(int n);
int					ft_fibonacci(int index);
int					ft_find_next_prime(int nb);
int					ft_power(int nb, int power);
int					ft_match(char *s1, char *s2);
int					ft_nmatch(char *s1, char *s2);
int					ft_str_is_lowercase(char *str);
int					ft_str_is_uppercase(char *str);
int					ft_list_size(t_chain *begin_list);
int					ft_word_count(char const *s, char c);
int					ft_count_if(char **tab, int (*f)(char*));
int					ft_get_next_line(const int fd, char **line);
int					ft_word_length(char const *s, int i, char c);
int					ft_is_sort(int *tab, int length, int (*f)(int, int));

#endif
