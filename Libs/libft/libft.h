/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:59:01 by svillalv          #+#    #+#             */
/*   Updated: 2023/04/16 17:07:21 by svillalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define GREEN_C   "\033[1;32m"
# define BLUE_C    "\x1b[1;34m"
# define RESET_C   "\x1b[0m"
# define YELLOW_C  "\x1b[43m"
# define NEGRO_T   "\x1b[30m"
# define BLANCO_F  "\x1b[47m"

# include <signal.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>
# include <errno.h>
# include <unistd.h>
# include <sys/wait.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(void *s, int c, size_t n);
int		ft_memcmp(void *s1, void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_printf(char const *format, ...);
int		ft_check_format(const char c, va_list args);
int		ft_printchar(const char c);
int		ft_print_hex(unsigned int num, char c);
int		ft_print_ptr(unsigned long long ptr);
int		ft_printchar(const char c);
int		ft_printstr(char *str);
int		ft_printnbr(int n);
int		ft_printpercent(void);
int		ft_print_unsigned(unsigned int num);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
