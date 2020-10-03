/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 20:16:11 by mgiraldo          #+#    #+#             */
/*   Updated: 2020/06/23 19:53:47 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>

/*
** References for 42 libft of C Standard Library
** https://en.wikipedia.org/wiki/C_standard_library
*/

/*
** 42 libft | string.h | Three subsections
** (1) string mainpulation (2) string examination (3) memory manipulation
*/

/*
**  String manipulation | Funtion sorted by return type
*/

char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strnew(size_t size);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strtrim_blank(char const *s);
char				**ft_split(char const *s, char c);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_strdel(char **as);
void				ft_strclr(char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
char				*ft_strrealloc(char **ptr, size_t size);

/*
**  String examination | Funtion sorted by return type
*/

int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
								size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
size_t				ft_strlen(const char *s);
size_t				ft_strnlen(const char *s, size_t maxlen);
int					ft_wordcount(char const *s, char c);
int					ft_wordcountx(char const *s, char *c);
char				*ft_strappend_xo(char **dst, char *s2);
char				*ft_strappend_xx(char **dst, char **s2);
char				*ft_strappend_ox(char *s2, char **dst);
char				*ft_strappend_xo_chr(char **dst, char c2);
/*
**  Memory manipulation | Function sorted by return type
*/

int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c_in, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_mempalloc(size_t size);
void				*ft_mempcpy(void *dest, const void *src, size_t n);
void				*ft_memcpy_rev(void *dest, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_calloc(size_t count, size_t size);
void				*ft_realloc(void *ptr, size_t size);

/*
** 42 libft | stdlib.h | Function sorted by return type
** https://en.wikipedia.org/wiki/C_string_handling#Numeric_conversions
** Math conversion
*/

int					ft_numlen(long long int n);
int					ft_numlen_base(long long int n, size_t base);
int					ft_numlen_base_unsigned(unsigned long long int n,
															size_t base);
int					ft_numlen_float(long double n);
int					ft_atoi(const char *str);
int					ft_atoi_base(const char *s, int base);
int					ft_isalnum_base(char c, int base);
char				*ft_itoa(long long int n);
char				*ft_itoa_base(long long int n, int b);
char				*ft_itoa_unsigned(unsigned long long int n);
char				*ft_itoa_base_unsigned(unsigned long long int n, int b);
char				*ft_dtoa(long double d, size_t p, size_t base);
long double			ft_dtoa_round(long double nbr, int precision);
int					ft_round_half_to_even(long double nbr, int precision);
long double			ft_ldmod(long double x, long double y);

/*
** 42 libft | stdio.h | Function sorted by return type
** https://en.wikipedia.org/wiki/C_file_input/output
*/

int					ft_putchar(int c);
int					ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** 42 libft | ctype.h | Function sorted by return type
** https://en.wikipedia.org/wiki/C_character_classification
*/

int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isblank(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_isxdigit(int c);
int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);

/*
** 42 LIBFT MATH.H
** https://en.wikipedia.org/wiki/C_mathematical_functions#Overview_of_functions
*/

/*
**	t_signbit is used by ft_signbit
*/

typedef	union		u_nbrx
{
	double			d;
	uint64_t		i;
}					t_signbit;

int					ft_abs(int n);
long double			ft_abs_ld(long double n);
long double			ft_pow(long double n, int pow);
long double			ft_sqrt(long double n);
int					ft_signbit(double x);
int					ft_isinf(long double nbr);

/*
** Libft project bonus part | linked list
*/

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
				void (*del)(void *));

#endif
