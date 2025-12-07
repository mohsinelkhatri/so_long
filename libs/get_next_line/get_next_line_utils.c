/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkhatr <melkhatr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:31:57 by melkhatr          #+#    #+#             */
/*   Updated: 2025/08/01 13:34:28 by melkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	size_t	i;
	char	*ptr;

	ptr = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < ft_strlen(str))
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char *buf, char *tmp)
{
	char	*s;
	size_t	i;
	size_t	k;

	if (buf == NULL)
		return (ft_strdup(tmp));
	s = malloc((ft_strlen(buf) + ft_strlen(tmp) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (i < ft_strlen(buf))
	{
		s[i] = buf[i];
		i++;
	}
	k = 0;
	while (k < ft_strlen(tmp))
	{
		s[i + k] = tmp[k];
		k++;
	}
	s[i + k] = '\0';
	free(buf);
	return (s);
}

ssize_t	ft_strchr(char *s)
{
	ssize_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_substr(char *s, ssize_t l, ssize_t len)
{
	char	*str;
	ssize_t	i;

	if (!s)
		return (NULL);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[l + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
