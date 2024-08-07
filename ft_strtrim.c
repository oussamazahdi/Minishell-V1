/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:30:00 by ozahdi            #+#    #+#             */
/*   Updated: 2024/08/06 12:09:40 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strtrim(char *s1, char *set)
{
	int	s;
	int	f;
	int	vlen;

	if (!s1 || !set)
		return (0);
	if (!(*s1))
		return (ft_strdup(""));
	s = 0;
	f = ft_strlen(s1);
	f--;
	while (ft_strchr(set, s1[s]) && s1[s])
		s++;
	while (ft_strchr(set, s1[f]) && s1[f])
		f--;
	vlen = f - s + 1;
	return (ft_substr(s1, s, vlen));
}
