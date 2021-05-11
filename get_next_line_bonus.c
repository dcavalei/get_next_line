/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:19:43 by dcavalei          #+#    #+#             */
/*   Updated: 2021/04/06 10:47:20 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	get_next_line(int fd, char **line)
{
	static char	*buffer[1024];
	char		*temp;
	char		*new;
	int			ret;

	ret = 1;
	if (read(fd, 0, 0) < 0 || !line)
		return (-1);
	if (!buffer[fd])
		buffer[fd] = ft_substr("", 0, 0);
	if (check_newline(buffer[fd]))
		output_and_shift(&buffer[fd], line);
	else
	{
		temp = new_temp(fd);
		new = ft_strjoin(buffer[fd], temp);
		free_machine_thx_norminette(&temp, &buffer[fd]);
		buffer[fd] = new;
		if (!check_newline(buffer[fd]))
			ret = 0;
		output_and_shift(&buffer[fd], line);
	}
	if (ret == 0)
		free_machine_thx_norminette(&buffer[fd], NULL);
	return (ret);
}

char	*new_temp(int fd)
{
	char	*temp;
	int		len;
	int		i;
	int		r;
	int		total;

	len = DEFAULT_SIZE;
	while (len <= BUFFER_SIZE)
		len += DEFAULT_SIZE;
	temp = malloc(sizeof(char) * len);
	i = 0;
	while (i < len)
		temp[i++] = '\0';
	total = 0;
	while ((r = read(fd, temp + total, BUFFER_SIZE)) != 0)
	{
		total += r;
		i = 0;
		if (len < total + r + 1)
			realloc_temp(&temp, &len, total + r);
		while (temp[i])
			if (temp[i++] == '\n')
				return (temp);
	}
	return (temp);
}

void	output_and_shift(char **buffer, char **line)
{
	int		i;
	char	*temp;

	i = 0;
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	*line = ft_substr(*buffer, 0, i);
	if ((*buffer)[i] == '\n')
		i++;
	temp = ft_strdup((*buffer) + i);
	free(*buffer);
	*buffer = temp;
}

void	realloc_temp(char **temp, int *len, int next_ammount)
{
	char	*ptr;
	int		i;

	while (*len <= next_ammount)
		*len += DEFAULT_SIZE;
	ptr = malloc(sizeof(char) * (*len));
	if (!ptr)
		return ;
	i = 0;
	while (i < (*len))
		ptr[i++] = '\0';
	i = 0;
	while ((*temp)[i])
	{
		ptr[i] = (*temp)[i];
		i++;
	}
	free(*temp);
	(*temp) = ptr;
}

void	free_machine_thx_norminette(char **ptr_1, char **ptr_2)
{
	if (ptr_1)
	{
		free(*ptr_1);
		*ptr_1 = NULL;
	}
	if (ptr_2)
	{
		free(*ptr_2);
		ptr_2 = NULL;
	}
}
