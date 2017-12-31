#include <stdio.h>
#include <string.h>

int main(){
    char buffer[0x20] = {0};
    scanf("%s", buffer);
    printf("Strlen: %lu\n", strlen(buffer));
}
