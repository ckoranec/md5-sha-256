/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 15:20:40 by jkertgat          #+#    #+#             */
/*   Updated: 2018/06/05 16:10:03 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_longint(long long n);
int					ft_intlen(int n);
char				*ft_itoa_base(long long nbr, unsigned int base);
int					ft_num_len(int n);
int					ft_wordcnt(const char *t, char c);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);
char				*ft_strchr(const char *s, int c);
char				*ft_strnew(size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
size_t				ft_strlen(const char *s);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_strrev(char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
void				ft_bzero(void *s, size_t n);
void				ft_putnbr(int n);
char				*ft_strcat(char *s1, const char *s2);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memalloc(size_t size);
int					ft_strncmp(char const *s1, char const *s2, size_t n);
void				*ft_memalloc(size_t size);
char				ft_isspace(unsigned char c);
char				*ft_strdup(char *src);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_strdel(char **as);
char				*ft_strmap(char const *s, char (*f)(char));
int					ft_strequ(char const *s1, char const *s2);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
char				*ft_strrchr(const char *s, int c);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				ft_putendl(char const *s);
char				*ft_itoa(int n);
void				ft_putendl_fd(char const *s, int fd);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_strclr(char *s);
void				*ft_memmove(void *dst, const void *src, size_t len);
char				*ft_strtrim(char const *s);
t_list				*ft_lstnew(void const *content, size_t content_size);
char				**ft_strsplit(char const *s, char c);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_memdel(void **ap);
void				ft_putnbr_fd(int nb, int fd);
void				ft_lstadd(t_list **alst, t_list *new);
char				*ft_strnstr(const char *big, const char *lit, size_t len);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
int					ft_atoi(const char *str);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t				ft_strlcat(char *dst, const char *src, size_t size);

#endif
