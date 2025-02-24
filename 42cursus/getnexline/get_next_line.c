/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:27:14 by si-park           #+#    #+#             */
/*   Updated: 2025/02/24 19:53:47 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// record를 동적할당하고, 문자열을 합치는 함수 추가.


// 개행을 기준으로 한 줄을 나누는 함수 추가.


// record관리 방법을 수정.


char *get_next_line(int fd)
{
    int reread;
    //버퍼사이즈만큼의 공간, record는 개행을 기준으로 나눈 문자열을 저장하기 위함.
    char buf[BUFFER_SIZE + 1];
    char *record = NULL;
    
    //파일 디스크립터는 012를 제외한 3부터의 정수.
    //read를 통해 파일을 읽고, 반환값을 저장해야함. 반환값이 0이면 파일이 끝났다는 것.
    //파일이 닫힐 때 까지 계속 while을 돌린다.
    //reread = read(fd, buf, BUFFER_SIZE);
    while((reread = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        // read가 BUFFER_SIZE만큼 읽은 데이터를 record에 저장한다.
        // 만약 기존에 record의 값이 존재한다면 데이터를 이어붙인다. static variable
        
        //만약 줄내림을 발견한다면, 그 줄내림을 기준으로 앞의 문자열을 반환해야한다.
        //잘라내고 나머지 데이터는 record에 다시 저장한다. 


        if(reread == 0){
            //파일이 끝났을 때, EOF
            //record에 남아있는 데이터를 반환하고, NULL로 초기화해야한다.
        }

        if(reread == -1){
            //fd가 유효하지 않거나, 허용되지 않은 파일을 읽으려고 할 때, 
            //record를 free()하고 null을 반환해야함
        }
    }
}

