/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:27:14 by si-park           #+#    #+#             */
/*   Updated: 2025/02/22 18:22:51 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include <stdio.h>

char *get_next_line(int fd)
{
	int linecount = -1;
	char buf[1];
	char *format;
	ssize_t reread;
	
	while((reread = read(fd, buf, 1)) > 0)
	{
		linecount++;
		//read는 반복 호출 시 자동으로 다음 위치에서 읽는다. 따라서 1씩 증가시켜도 됨
		if(reread == '\n')
		{
			//줄내림을 만나면, 함수는 return 값을 반환하며 종료되어야 한다.
			format = (char *)malloc(sizeof(char) * linecount);
			
			while(linecount-- > 0)
			{
				format[] = buf[0]
			}
		}


	}

	if(reread == -1)
		perror("파일 읽기 실패");

	close(fd);

	return 0;
}

int main(){
	int fd;
	char *format;

	fd = open("example.txt", O_RDONLY);
	
	format = get_next_line(fd);
	printf("%s", format);
	return 0;
}