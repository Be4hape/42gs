/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:30:37 by si-park           #+#    #+#             */
/*   Updated: 2025/07/15 17:32:21 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void handler(int sig){
    static unsigned char c = 0;
    static int i = 0;
    
    
}


int main(){
    char *string;
    unsigned int i = 0;

    printf("pid : %d, waiting\n", getpid());

    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    
    while(1)
        pause();

    return 0;
}