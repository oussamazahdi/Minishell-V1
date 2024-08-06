/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:52:55 by ozahdi            #+#    #+#             */
/*   Updated: 2024/08/06 10:53:09 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	chech_quotes(char *read)
{
	int		i;
	int		k;
	int		s;

	i = 0;
	s = 0;
	k = 0;
	while (read[i])
	{
		if (read[i] && read[i] == '\\')
			i += 2;
		if (read[i] && read[i] == '"')
			k++;
		if (read[i] && read[i] == '\'')
			s++;
		i++;
	}
	if (k % 2 != 0 || s % 2 != 0)
	{
		printf(BOLD RED "Quotes Error!\n" RESET);
		return (0);
	}
	return (1);
}
