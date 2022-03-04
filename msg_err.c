/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefernan <hefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:47:53 by hefernan          #+#    #+#             */
/*   Updated: 2022/03/04 12:04:01 by hefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int     aff_msg(char *str)
{
    write(2, str, ft_strlen(str));
    return 1;
}

void    error_msg(char *str)
{
    perror(str);
    exit (1);
}