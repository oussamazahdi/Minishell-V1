/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:04:16 by ozahdi            #+#    #+#             */
/*   Updated: 2024/08/06 11:22:10 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdup(char *s)
{
	int		i;
	int		size;
	char	*ptr;

	i = 0;
	size = ft_strlen(s);
	ptr = malloc(size + 1);
	if (!ptr)
		return (0);
	while (s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return ((char *)ptr);
}

int	ft_strlen(char *s)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*ptr;
	int		size;
	int		l;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || !len)
		return (ft_strdup(""));
	l = len;
	size = ft_strlen(s + start);
	if (size <= len)
		l = size;
	ptr = (char *)malloc(l * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	while (i < l)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char *ft_chifr(char *read)
{
	int i;
	
	i = 0;
	while (read[i])
	{
		while (read[i] != '"' && read[i] != 39)
			i++;
		if (read[i] == '"')
		{
			while (read[++i] != '"')
			{
				if (read[i] == '\\')
				{
					read[i++] *= -1;
					read[i++] *= -1;
				}
				if (read[i] > 0)
					read[i] *= -1;
			}
			i++;
		}
		if (read[i] == 39)
		{
			while (read[++i] != 39)
			{
				if (read[i] == '\\')
				{
					read[i++] *= -1;
					read[i++] *= -1;
				}
				if (read[i] > 0)
					read[i] *= -1;
			}
			i++;
		}
	}
	return (read);
}
