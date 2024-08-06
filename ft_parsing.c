/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:28:57 by ozahdi            #+#    #+#             */
/*   Updated: 2024/08/06 10:44:16 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_standar_syntax(char *read)
{
	char	*tmp;

	tmp = ft_remove_spaces(read);
	if (!ft_strcomp(tmp, "<< |") || !ft_strcomp(tmp, "<<|") || \
		!ft_strcomp(tmp, "< |") || !ft_strcomp(tmp, "<|") || \
		!ft_strcomp(tmp, ">> |") || !ft_strcomp(tmp, ">>|") || \
		!ft_strcomp(tmp, "> |") || !ft_strcomp(tmp, ">|") || \
		!ft_strcomp(tmp, "||") || !ft_strcomp(tmp, "| |") || \
		!ft_strcomp(tmp, "< <") || !ft_strcomp(tmp, "> >") || \
		!ft_strcomp(tmp, "<< <<") || !ft_strcomp(tmp, ">> >>") || \
		!ft_strcomp(tmp, "< >") || !ft_strcomp(tmp, "&") || \
		!ft_strcomp(tmp, "&&") || !ft_strcomp(tmp, "& &") || \
		!ft_strcomp(tmp, "(") || !ft_strcomp(tmp, "()") || \
		!ft_strcomp(tmp, "; |") || !ft_strcomp(tmp, ";|") || \
		!ft_strcomp(tmp, "> <") || !ft_strcomp(tmp, "( )"))
		return (0);
	else
		return (1);
}

static int	ft_multi_syntax(char *read)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (read[i])
	{
		while (ft_is_syntax(read[i]))
		{
			k++;
			i++;
		}
		if (k > 2)
			return (0);
		else
			k = 0;
		i++;
	}
	return (1);
}

static int	ft_check_syntax(char *read)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(read);
	if (len && (read[0] == '|' || ft_is_syntax(read[len - 1]) || \
		!ft_multi_syntax(read) || !ft_standar_syntax(read)))
	{
		printf(BOLD RED"Syntax error!\n"RESET);
		return (0);
	}
	return (1);
}

static int	check_spaces(char *read)
{
	int		i;

	i = -1;
	while (read[++i])
		if (read[i] != ' ')
			return (1);
	return (0);
}

int	ft_parsing(char *read)
{
	if (!read || !ft_strlen(read) || !check_spaces(read) || \
		!ft_check_syntax(read) || !chech_quotes(read))
		return (0);
	return (1);
}