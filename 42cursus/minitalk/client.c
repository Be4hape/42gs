/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:30:44 by si-park           #+#    #+#             */
/*   Updated: 2025/07/15 16:55:10 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int main(int argc, char *argv[])
{
    int i = 0;
    int j = 0;
    unsigned char bt = 0;
    unsigned char *string;
    
    if(argc == 3){
    //kill(server_pid, ...)
    pid_t server_pid = (pid_t)ft_atoi(argv[1]);
    
        if(argv[2]){
            *string = argv[2];
            while(string[i]){
                j = 0;
                while(j < 8){
                    bt = (string[i] >> j) & 1;
                    if(bt)
                        kill(bt, SIGUSR1);
                    else
                        kill(bt, SIGUSR2);
                    usleep(100);
                    j++;
                }i++;
            }
        }
    }
    
    //kill(server_pid, SIGUSR1);
    return 0;
}