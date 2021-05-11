/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:04:14 by dcavalei          #+#    #+#             */
/*   Updated: 2021/04/05 17:59:25 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	check_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	i_src;
	size_t	i_dest;

	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr || !s1 || !s2)
		return (NULL);
	i_dest = 0;
	i_src = 0;
	while (s1[i_src])
		ptr[i_dest++] = s1[i_src++];
	i_src = 0;
	while (s2[i_src])
		ptr[i_dest++] = s2[i_src++];
	ptr[i_dest] = '\0';
	return (ptr);
}

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	current;
	size_t	real_size;

	real_size = ft_strlen(src);
	if (real_size < len)
		len = real_size;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr || !src)
		return (NULL);
	current = 0;
	if (start < ft_strlen(src))
	{
		while (src[start + current] && current < len)
		{
			ptr[current] = src[start + current];
			current++;
		}
	}
	ptr[current] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!ptr)
		return (NULL);
	while (src[i])
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
