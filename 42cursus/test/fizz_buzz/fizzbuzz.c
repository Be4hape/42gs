#include <unistd.h>

char Write(char a){
    if(a == 'a'){
        write(1, "fizz", 4);
    }
    else if(a == 'b'){
        write(1, "buzz", 4);
    }
    else{
        write(1, "fizzbuzz", 8);
    }
}


int main(){
    unsigned int i = 1;

    while(i <= 100){
        if(i % 3 == 0){
            Write('a');
        }
        else if(i % 5 == 0){
            Write('b');
        }
        else if(i % 3 == 0 && i % 5 == 0){
            Write('c');
        }
        write(1, &(i + 47), 1);        
        write(1, "\n", 1);
        i++;
    }

    return 0;
}