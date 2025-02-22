/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:27:14 by si-park           #+#    #+#             */
/*   Updated: 2025/02/22 15:48:36 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char *get_next_line(int fd)
{    
	//fd는 파일 디스크립터, 012는 정해져있는 입출력에러가 있음. 3부터 지정될 것.
    //파일 디스크립터가 들어온다는 것은 open함수를 거쳐 디스크립터의 형태로 들어온다는 것
    //read(int fd, void *buf, ssize_t nbytes);
    int temp = 40;
    int reread;
    char *buf;    
    ssize_t nbyte = 40;

    //nbyte를 몇개 씩 읽을 것인가?
    //일정 버퍼만큼을 읽고, 만약 read의 반환값이 -1이라면 파일이 끝난 것.
    //그만큼을 버퍼의 전체 크기로 설정.
    
    reread = read(fd, buf,temp);

    if(reread == -1)
    {
        malloc(sizeof(int) * )
    }

}

int main()
{
    
    return 0;
}
