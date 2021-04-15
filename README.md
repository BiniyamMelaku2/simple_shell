# simple_shell
 Writing a simple UNIX command interpreter.

# simple_shell project repository

# Pre-requisites

### Authorized functions and macros:
- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- _exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)

### GCC command to compile:

gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
`
### Memory leak check

 valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./hsh

This wil compile all the '.c' files and change the output's name to 'hsh'.

### Template to test output:
===========================
$ ./hsh

($) 

hsh main.c shell.c

$ exit
$

### Project Requirements
=========================
- [0] README, man, AUTHORS    File: README.md, man_1_simple_shell, AUTHORS
- [1] passes the Betty checks
- [2] display prompt, REPL, Cntl + D, Perrors: "./shell: No such file or directory"    
    work with  "/bin/ls", 
- [3] cmd + args;    ls -l , echo "..." , cd /home, 
- [4] Handle the PATH    ls -l /tmp
- [5] exit, only exit no args
- [6] env : print current env
- [7] Test suite: reg cases, 0-20,edge cases, 
- [8] _getline make your own 
- [9]  ..do not use strtok
- [10] exit 98, echo $?
- [11] Ctrl + C, should not quit
- [12] setenv, unsetenv, implement, 
- [13] cd [] cd $HOME, update env var PWD, cd -, 
- [14] Handle the commands separator ;,,  ls /var ; ls /var  ,   
- [15] Handle the && and || shell logical operators,  ls /var && ls /var,    ls /var && ls /var && ls /var && ls /hbtn && ls /hbtn
- [16] alias [name[='value'] ...]  ,   implement alias, 
- [17] Handle variables replacement  echo $PATH
     Handle the $? variable  echo $?
     Handle the $$ variable   echo $$
- [18] Handle comments (#)    echo $$ # ls -la
- [19] Usage: help [BUILTIN]  implement help builtin
- [20] Implement the history built-in, without any argument
- [21] File as input  :   simple_shell [filename]

README.md: this.

### Contact Info:

Git: [Biniyam Melaku](https://github.com/biniyammelaku2), 
