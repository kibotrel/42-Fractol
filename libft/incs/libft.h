/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:59:01 by kibotrel          #+#    #+#             */
/*   Updated: 2019/05/01 12:06:21 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

/*
**	Useful Structures
*/

typedef struct		s_gnlist
{
	struct s_gnlist	*next;
	struct s_gnlist	*prev;
	int				fd;
	char			*save;
}					t_gnlist;

/*
**	Useful Macros
*/

# define LLMAX 		9223372036854775807ull
# define BUFF_SIZE	4096

/*
**	Display functions
*/

void				ft_putnbr(int nb);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_print_error(char *desc, int error);

/*
**	Control functions
*/
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_str_is_lowercase(char *str);
int					ft_str_is_uppercase(char *str);
int					ft_charcount(char const *s, char c);
int					ft_wordcount(char const *s, char c);
int					ft_charrcount(char const *s, char c);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_wordlength(char const *s, int i, char c);
int					ft_isvalidname(char *filename, char *reference);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
size_t				ft_strlen(const char *s);
unsigned int		ft_numlen(long nb, int base);

/*
**	String manipulation functions
*/

char				*ft_strrev(char *str);
char				*ft_strdup(const char *s1);
char				*ft_strtrim(char const *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strcat(char *s1, const char *s2);
char				**ft_strsplit(char const *s, char c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strsub(char const *s, unsigned int start, size_t len);

/*
**	Conversion functions
*/

int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
char				*ft_strupcase(char *str);
char				*ft_strlowcase(char *str);
char				*ft_itoa_base(int value, int base);

/*
**	Memory manipulation functions
*/

char				*ft_strnew(size_t size);
void				*ft_memalloc(size_t size);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

/*
**	File manipulation functions
*/

int					ft_get_next_line(const int fd, char **line);

#endif
