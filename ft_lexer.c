/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:31:56 by ozahdi            #+#    #+#             */
/*   Updated: 2024/08/09 12:17:28 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_print_lexer(int *lexer, int size)
{
	int i = 0;
	while (size)
	{
		printf("lexer[%d]	: %d\n", i, lexer[i]);
		i++;
		size--;
	}
}

int ft_token_size(t_list *token)
{
	t_list	*tmp;
	int		i;

	if (!token)
		return 0;
	tmp = token;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void ft_fill_lexer(t_data **line, int size)
{
	t_list	*tmp;
	int		i;
	int		x;

	tmp = (*line)->token;
	x = size;
	i = 0;
	while (x && tmp)
	{
		(*line)->lexer[i] = tmp->type;
		x--;
		i++;
		tmp = tmp->next;
	}
}

int *ft_lexer(t_data **line)
{
	int size;

	size = ft_token_size((*line)->token);
	(*line)->lexer = malloc(size * sizeof(int));
	ft_fill_lexer(line, size);
	// ft_print_lexer((*line)->lexer, size);
	return ((*line)->lexer);
}