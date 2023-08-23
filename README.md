# Simple Shell
The simple shell project

# Synopsis
This repository holds all the code necessary for our custom simple shell to run. Our shell currently handles the executions of executables found in the environmental variable PATH, with or without their full paths. Sample commands that our shell supports include ls (/bin/ls), pwd, echo, which, whereis, etc. We've also created the following builtins.

# Resources
Read or watch:
 - <a href="https://intranet.alxswe.com/rltoken/f0YU9TAhniMXWlSXtb64Yw">Unix shell</a>
 - <a href="https://intranet.alxswe.com/rltoken/7LJOp2qP7qHUcsOK2-F3qA">Thompson shell</a>
 - <a href="https://intranet.alxswe.com/rltoken/wTSu31ZP1f7fFTJFgRQC7w">Ken Thompson</a>

**man or help:**
 - sh (Run sh as well)
 - Learning Objectives

# General
Who designed and implemented the original Unix operating system </br>
Who wrote the first version of the UNIX shell </br>
Who invented the B programming language (the direct predecessor to the C programming language) </br>
Who is Ken Thompson </br>
How does a shell work </br>
What is a pid and a ppid </br>
How to manipulate the environment of the current process </br>
What is the difference between a function and a system call </br>
How to create processes </br>
What are the three prototypes of main </br>
How does the shell use the PATH to find the programs </br>
How to execute another program with the execve system call </br>
How to suspend the execution of a process until one of its children terminates </br>
What is EOF / “end-of-file”? </br>

# Builtins
exit exits shell (Usage: exit [status])</br>
env prints environmental variables (Usage: env)</br>
setenv creates or modifies an environmental variable (Usage: setenv name value)</br>
unsetenv removes an envrionmental variable (Usage: unsetenv name value)</br>
cd changes directories (Usage: cd [-][~][path])</br>
Functions and system calls used</br>
read, signal, malloc, free, getcwd, chdir, access, execve, wait, write, exit

# Compilation
Use this command to compile the shell</br>
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

# Authors
Adjumany Yann & Perpetua Otieno
