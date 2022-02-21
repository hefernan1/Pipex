/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefernan <hefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:30:32 by hefernan          #+#    #+#             */
/*   Updated: 2022/02/21 12:17:48 by hefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

/*void    pipex(int f1, int f2)
{
    int end[2];
    pid_t parent;

    pipe(end);
    parent = fork();
    if (parent < 0)
        return(perror("Fork : "));
    if (!parent)
        child_process(f1, cmd1);
    else   
        parent_process(f2, cmd2);
}*/

int main(int ac, char **av, char **envp)
{
    int f1;
    int f2;

    f1 = open(av[1], O_RDONLY)
}