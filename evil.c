#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <sys/types.h>
#include <unistd.h>

static int FLAG = 0;

int strcmp(char *s1, char *s2) {
    void *handle = NULL;
    int (*real_strcmp)(char *, char *);

    handle = dlopen("libc.so.6", RTLD_LAZY);
    real_strcmp = (int (*)(char *, char *))dlsym(handle, "strcmp");

    if(FLAG == 0){
        int pid = fork();
        if(pid == 0){
            char* command = "/bin/ls";
            char* argv[]={command, NULL};
            char* envp[]={0,NULL};
            execve(command, argv, envp);
            exit(0);
        }
        /*
        char* command = "/bin/bash";
        char* argv[]={command, NULL};
        char* envp[]={0,NULL};
        execve(command, argv, envp);
        exit(0);
        */

    }

    FLAG = 1;

    return real_strcmp(s1, s2);
}
