/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:30:20 by dcavalei          #+#    #+#             */
/*   Updated: 2021/05/11 15:08:21 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define DEFAULT_SIZE 1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int					get_next_line(int fd, char **line);
void				free_machine_thx_norminette(char **ptr_1, char **ptr_2);
void				output_and_shift(char **buffer, char **line);
void				realloc_temp(char **temp, int *len, int next_ammount);
char				*new_temp(int fd);
char				*ft_strchr(const char *str, int c);
char				*ft_strdup(char *str);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_substr(char const *src, unsigned int start, size_t len);
size_t				ft_strlen(const char *str);

#endif
