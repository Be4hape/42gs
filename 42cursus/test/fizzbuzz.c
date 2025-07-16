#include <unistd.h>

//write 함수만 사용가능, 숫자를 표기해야함.
//
void num(int i){
    if(i > 9)
        num(i / 10);
    write(1, &"0123456789"[i%10], 1);
}



int main(void){
    int i = 1;
    while(i <= 100){
        if (i % 3 == 0 && i % 5 == 0){
            //fizzbuzz
            write(1, "fizzbuzz", 8);
        }
        else if(i % 3 == 0){
            //fizz
            write(1, "fizz", 4);
        }
        else if(i % 5 == 0){
            //buzz
            write(1, "buzz", 4);
        }
        else{
            //just print number;
            num(i);
        }
        i++;
        write(1, "\n", 1);
    }
}