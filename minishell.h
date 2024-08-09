/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:03:09 by ozahdi            #+#    #+#             */
/*   Updated: 2024/08/09 11:06:26 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <libc.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define WHITE   "\x1b[37m"
# define ORANGE  "\x1b[38;5;214m"
# define RESET   "\x1b[0m"
# define BOLD     "\x1b[1m"

typedef enum    e_lexeme
{
    INFILE = 1,
    OUTFILE,
    HEREDOC,
    APPEND,
    PIPE,
    BUILTIN,
    CMD,
    ARG
} 	e_lexeme;

typedef struct s_list
{
	char			*content;
	int				type;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	char		*prompt;
	char		*home;
	t_list		*env;
	t_list		*token;
	int			*lexer;
	// t_exec		*exec;
	int			has_cmd;
	int			has_builtin;
	int			process_count;
	int			builtin_check;
	// t_args		*args;
	int			exit_status;
	int			*fd_heredoc;
}			t_data;


//ft_fill_token.c
int ft_fill_token(t_data **line, char *read);
//ft_parsing.c : 1 & 2
int	ft_parsing(char *read);
int	chech_quotes(char *read);
//ft_split.c
char	**ft_split(char *s, char c);
//ft_strtrim.c
char	*ft_strtrim(char *s1, char *set);
//tools.c : 1, 2 & 3
char	*ft_strdup(char *s);
int	ft_strlen(char *s);
char	*ft_substr(char *s, int start, int len);
char *ft_chifr(char *read);
int	ft_is_syntax(int c);
int ft_remove_spaces2(char *read);
char	*ft_remove_spaces(char *read);
int	ft_strcomp(char *src, char *cmp);
t_list	*ft_lstnew(char *content);
t_list	*ft_lstadd_back(t_list *lst, char *ptr);
char	*ft_addspace(char *read);
int	ft_compare(char *s1, char *s2);

//lexer.c
int *ft_lexer(t_data **line);



void ft_print_lexer(int *lexer, int size);
void ft_print_token(t_list *token);

#endif