#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd)
{
    char *line = NULL;
    char buffer;
    int len = 0;
    int bytes_read;

    while ((bytes_read = read(fd, &buffer, 1)) > 0) // 한 글자씩 읽기
    {
        // 메모리 확장
        char *new_line = (char *)malloc(len + 2); // +1 for new char, +1 for '\0'
        if (!new_line)
            return NULL; // 메모리 할당 실패 시 NULL 반환

        // 기존 문자열 복사 후 새 글자 추가
        for (int i = 0; i < len; i++) 
        {
            if (line) 
                new_line[i] = line[i];
            else 
                new_line[i] = '\0';
        }

        new_line[len] = buffer;
        new_line[len + 1] = '\0';


        // 기존 메모리 해제 후 새 메모리 적용
        free(line);
        line = new_line;
        len++;

        // 줄바꿈 문자 만나면 반환
        if (buffer == '\n')
            break;
    }

    return (bytes_read == 0 && len == 0) ? NULL : line; // EOF 시 NULL 반환
}
