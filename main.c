#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char password[] = "password";

int main(){
    char buffer[0x20] = {0};
    int size = scanf("%s", buffer);
    buffer[size] = '\x00';
    if(strcmp(buffer, password) == 0){
        printf("Ok!Give you a present!\n");
        system("/bin/bash");
        return 0;
    }else{
        printf("Go away, hacker!\n");
        return 1;
    }
}
