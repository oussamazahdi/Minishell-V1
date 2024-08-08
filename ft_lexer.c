/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:31:56 by ozahdi            #+#    #+#             */
/*   Updated: 2024/08/08 13:31:46 by ozahdi           ###   ########.fr       */
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

int *ft_init(int *lexer, int size)
{
	int len;
	
	len = size - 1;
	while(len != -1)
		lexer[len--] = ARG;
	return lexer;
}

int *ft_token_p1(t_data **line, int size)
{
	t_data	*tmp;
	int i = 0;

	tmp = (*line);
	while (tmp->token)
	{
		if (tmp->token->content[0] == '|' && ft_strlen(tmp->token->content) == 1)
			tmp->lexer[i] = PIPE;
		else if (tmp->token->content[0] == '>' && ft_strlen(tmp->token->content) == 1)
			tmp->lexer[i] = OUTFILE;
		else if (tmp->token->content[0] == '<' && ft_strlen(tmp->token->content) == 1)
			tmp->lexer[i] = INFILE;
		else if (tmp->token->content[0] == '>' && ft_strlen(tmp->token->content) == 2)
			tmp->lexer[i] = APPEND;
		else if (tmp->token->content[0] == '<' && ft_strlen(tmp->token->content) == 1)
			tmp->lexer[i] = HEREDOC;
		tmp = tmp->token->next;
		i++;
	}
	return (tmp->lexer);
}

int *ft_lexer(t_data **line)
{
	int size;

	size = ft_token_size((*line)->token);
	(*line)->lexer = malloc(size * sizeof(int));
	(*line)->lexer = ft_init((*line)->lexer, size);
	(*line)->lexer = ft_token_p1(line, size);
	ft_print_lexer((*line)->lexer, size);
	// (*line)->lexer = ft_append_herdoc((*line)->lexer, size);
	// (*line)->lexer = ft_pipe((*line)->lexer, size);
	// (*line)->lexer = ft_builtin((*line)->lexer, size);
	return ((*line)->lexer);
}