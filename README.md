# Project: Simple Shell

A simple shell program.

# Introduction

This repository contains the files for Simple Shell Project. The objective of this project is to make our shell program.

# Concepts

    Who designed and implemented the original Unix operating system
    Who wrote the first version of the UNIX shell
    Who invented the B programming language (the direct predecessor to the C programming language)
    Who is Ken Thompson
    How does a shell work
    What is a pid and a ppid
    How to manipulate the environment of the current process
    What is the difference between a function and a system call
    How to create processes
    What are the three prototypes of main
    How does the shell use the PATH to find the programs
    How to execute another program with the execve system call
    How to suspend the execution of a process until one of its children terminates
    What is EOF / “end-of-file”?

# Requirements

    Allowed editors: vi, vim, emacs
    All your files will be compiled on Ubuntu 14.04 LTS
    Your C programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
    All your files should end with a new line
    A README.md file, at the root of the folder of the project is mandatory
    Your code should use the Betty style
    Your shell should not have any memory leaks
    No more than 5 functions per file
    All your header files should be include guarded
    Use system calls only when you need to
    
    List of allowed functions and system calls:

*  access (man 2 access)
*  chdir (man 2 chdir)
*  close (man 2 close)
*  closedir (man 3 closedir)
*  execve (man 2 execve)
*  exit (man 3 exit)
*  _exit (man 2 _exit)
*  fflush (man 3 fflush)
*  fork (man 2 fork)
*  free (man 3 free)
*  getcwd (man 3 getcwd)
*  getline (man 3 getline)
*  isatty (man 3 isatty)
*  kill (man 2 kill)
*  malloc (man 3 malloc)
*  open (man 2 open)
*  opendir (man 3 opendir)
*  perror (man 3 perror)
*  read (man 2 read)
*  readdir (man 3 readdir)
*  signal (man 2 signal)
*  stat (__xstat) (man 2 stat)
*  lstat (__lxstat) (man 2 lstat)
*  fstat (__fxstat) (man 2 fstat)
*  strtok (man 3 strtok)
*  wait (man 2 wait)
*  waitpid (man 2 waitpid)
*  wait3 (man 2 wait3)
*  wait4 (man 2 wait4)
*  write (man 2 write)

# Instructions to run the code

1. Clone this repository

2. Create the main.c file by copying this template:

   int main(void)
   {
	prompt();
	return (0);
   }


3. Compile the code with this command:

   gcc -Wall -Werror -Wextra -pedantic *.c -o shell

4. Execute the code by entering ./shell in the terminal

5. After executing the program the output should look something like this

   ($) 

# Repository content

* [**AUTHORS**](./AUTHORS): Contains the authors of the project
* [** **](./): Contains the  the project
* [**env_handler.c**](./env_handler.c): C File that contains the functions use to work with env built-in
* [**exit_handler.c**](./exit_handler.c): C File that contains the functions use to work with exit built-in
* [**failed_case.c**](./failed_case.c): C File that contains the functions use to handle failed or error cases
* [**man_1_simple_shell**](./man_1_simple_shell): Contains the manual for the simple shell program
* [**path_handler.c**](./path_handler.c): C File that contains the functions use to work with PATH environment variable
* [**prompt.c**](./prompt.c): C File that contains the prompt function use for the simple shell project
* [**README.md**](./README.md): Contains the info for the simple shell project
* [**shell.h**](./shell.h): Contains the prototypes and the structure use in shell program
* [**signal_handler.c**](./signal_handler.c): C File that contains the functions that handle SIGINT signal
* [**split_in_array.c**](./split_in_array.c): C File that contains the functions to work with strtok and manage the resulting process with an array of strings used with prompt function in prompt.c
* [**split_in_list.c**](./split_in_list.c): C File that contains the functions to work with strtok and manage the resulting process with a singly linked list used with functions in path_handler.c
* [**str_manipulator.c **](./str_manipulator.c): C File that contains the functions used in the simple shell program to manage strings
* [**str_str.c**](./str_str.c): C File that contains the functions used in the simple shell program to manage strings

# By:

* juankarlos999
* SneyderHOL
