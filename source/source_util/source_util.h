/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source_util.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:27:24 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/12 12:00:13 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  SOURCE_UTIL_H
# define SOURCE_UTIL_H
# include <stdarg.h>
# include <stdlib.h>

typedef unsigned long long	u64;
typedef unsigned int		u32;

typedef struct s_strjoin_e
{
	va_list	arg;
	char	*out;
	char	*tmp;
	int		i;
	int		j;
}	t_sje;

/// ASCII_TO_INT_C ///
int		ascii_2_int(char *str);

/// STRJOIN_E_C ///
int		ft_strlen(char *s);
void	*malloc_strlen_n(unsigned int c, va_list arg);
char	*strjoin_e(unsigned int c, ...);



#endif
