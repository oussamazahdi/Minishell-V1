/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:17:50 by ozahdi            #+#    #+#             */
/*   Updated: 2024/08/06 10:52:13 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_syntax(int c)
{
	if (c == '<' || c == '>' || c == '|')
		return (1);
	return (0);
}
int ft_remove_spaces2(char *read)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (read[i])
	{
		while (read[i] && read[i] != ' ')
		{
			i++;
			j++;
		}
		if (read[i] && (read[i] == ' ' || read[i] == '\t'))
			j++;
		while (read[i] && (read[i] == ' ' || read[i] == '\t'))
			i++;
	}
	return (j);
}
char	*ft_remove_spaces(char *read)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = ft_remove_spaces2(read);
	tmp = malloc(j + 1);
	j = 0;
	while (read[i])
	{
		while (read[i] && (read[i] == ' ' || read[i] == '\t'))
			i++;
		while (read[i] && read[i] != ' ' && read[i] != '\t')
			tmp[j++] = read[i++];
		while (read[i] && (read[i] == ' ' || read[i] == '\t'))
			i++;
		if (read[i])
			tmp[j++] = ' ';
	}
	tmp[j] = '\0';
	return (tmp);
}

int	ft_strcomp(char *src, char *cmp)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!src || !cmp)
		return (0);
	while (src[i])
	{
		if (src[i] == cmp[j])
		{
			while (src[i] && cmp[j] && src[i] == cmp[j])
			{
				j++;
				i++;
			}
			if (!cmp[j])
				return (0);
			else
				j = 0;
		}
		else
			i++;
	}
	return (1);
}

