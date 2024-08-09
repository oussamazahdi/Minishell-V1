/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:31:56 by ozahdi            #+#    #+#             */
/*   Updated: 2024/08/09 11:20:57 by ozahdi           ###   ########.fr       */
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
	t_list	*tmp;
	int i = 0;

	tmp = (*line)->token;
	while (tmp)
	{
		if (tmp->content[0] == '|' && ft_strlen(tmp->content) == 1)
			(*line)->lexer[i++] = PIPE;
		else if (tmp->content[0] == '>' && ft_strlen(tmp->content) == 1)
		{
			(*line)->lexer[i++] = OUTFILE;
			tmp = tmp->next;
			(*line)->lexer[i] = OUTFILE;
		}
		else if (tmp->content[0] == '<' && ft_strlen(tmp->content) == 1)
		{
			(*line)->lexer[i++] = INFILE;
			tmp = tmp->next;
			(*line)->lexer[i] = INFILE;
		}
		else if (tmp->content[0] == '>' && ft_strlen(tmp->content) == 2)
		{
			(*line)->lexer[i++] = APPEND;
			tmp = tmp->next;
			(*line)->lexer[i] = APPEND;
		}
		else if (tmp->content[0] == '<' && ft_strlen(tmp->content) == 2)
		{
			(*line)->lexer[i++] = HEREDOC;
			tmp = tmp->next;
			(*line)->lexer[i] = HEREDOC;
		}
		tmp = tmp->next;
		i++;
	}
	return ((*line)->lexer);
}

void ft_pars_token(t_list *token)
{
	t_list *tmp;

	tmp = token;
	while (tmp)
	{
		if (tmp->content[0] == '|')
			tmp->type = PIPE;
		else if (tmp->content[0] == '>' && ft_strlen(tmp->content) == 1)
		{
			tmp = tmp->next;
			tmp->type = OUTFILE;
		}
		else if (tmp->content[0] == '<' && ft_strlen(tmp->content) == 1)
		{
			tmp = tmp->next;
			tmp->type = INFILE;
		}
		else if (tmp->content[0] == '<' && ft_strlen(tmp->content) == 2)
		{
			tmp = tmp->next;
			tmp->type = HEREDOC;
		}
		else if (tmp->content[0] == '>' && ft_strlen(tmp->content) == 2)
		{
			tmp = tmp->next;
			tmp->type = APPEND;
		}
		tmp = tmp->next;
	}
	tmp = token;
	
		
}

int *ft_lexer(t_data **line)
{
	int size;

	size = ft_token_size((*line)->token);
	(*line)->lexer = malloc(size * sizeof(int));
	(*line)->lexer = ft_init((*line)->lexer, size);
	ft_pars_token((*line)->token);
	(*line)->lexer = ft_token_p1(line, size);
	// ft_print_lexer((*line)->lexer, size);
	// (*line)->lexer = ft_append_herdoc((*line)->lexer, size);
	// (*line)->lexer = ft_pipe((*line)->lexer, size);
	// (*line)->lexer = ft_builtin((*line)->lexer, size);
	return ((*line)->lexer);
}