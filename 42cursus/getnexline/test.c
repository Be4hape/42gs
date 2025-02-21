#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int fd;
    char buffer[100];
    ssize_t bytes_read;

    fd = open("example.txt", O_RDONLY);

    if(fd == -1){
        perror("open file fail\n");
        return 1;
    }
    bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if(bytes_read == -1){
        perror("file read fail\n");
        return 1;
    }
    
    buffer[bytes_read] = '\0';
    printf("읽은 데이터 : \n%s\n", buffer);

    close(fd);
    return 0;
}