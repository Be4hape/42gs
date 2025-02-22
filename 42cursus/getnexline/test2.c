#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int fd;
    char buffer[1];
    ssize_t bytes_read;

    fd = open("example.txt", O_RDONLY);
    if(fd == -1){
        perror("파일 열기 실패");
        return -1;  
    }

    while((bytes_read = read(fd, buffer, 1)) > 0){
        if(buffer[0] == '\n'){
            printf("[줄바꿈 문자 발견]\n");
        }
        else{
            printf("%c", buffer[0]);
        }
    }

    if(bytes_read == -1){
        perror("파일 읽기 실패");
    }

    close(fd);
    return 0;
}