# Basic Linux/UNIX Shell

This repository contains the implementation of a basic Linux/UNIX shell program developed as part of the Operating Systems course at the Indraprastha Institute of Information Technology, Delhi.

## Description

This project aimed to design a shell program capable of handling both internal and external commands. The shell program allows users to interact with the operating system by executing commands and performing various operations.

Key features of the shell program:

- **Internal commands:**
  - `cd`: Change the current working directory.
    - `cd ~`: Move to the default working directory.
    - `cd /`: Move into the system's root directory.
    - `cd [directory]`: Move to the specified directory.
  - `echo`: Print a string or empty space to the console.
    - `echo *`: List all files and directories (similar to the `ls` command).
    - `echo --help`: Display a help message and exit.
    - `echo [string]`: Print the specified string.
  - `exit`: Terminate the shell program.
  - `pwd`: Show the current working directory.
  - `ls`: List all files and directories.
    - `ls -a`: Show hidden files.
    - `ls -n`: List files and directories (including details).

- **External commands:**
  - The shell program can execute external commands by forking a new process and using the `exec` family of system calls.
  - The shell program supports two options for each external command, enhancing the user experience.

- **Graceful error handling:**
  - The shell program has been designed to gracefully handle various corner cases and errors.
  - It provides informative error messages when a command or operation fails.

I gained practical experience in shell programming and system calls by implementing this shell program. It helped me understand the inner workings of a shell and how it interacts with the underlying operating system.

## Usage

To use the shell program, follow these steps:

1. Clone this repository to your local machine using the following command:
   ```
   git clone https://github.com/kanishk393/Basic-linux-unix-shell.git
   ```

2. Change into the cloned directory:
   ```
   cd basic-linux-unix-shell
   ```

3. Compile the shell program using the provided Makefile:
   ```
   make
   ```

4. Run the compiled shell program:
 
5. The shell program will start, and you can enter commands like in a regular shell. Press Enter to execute a command.

6. Enjoy using the basic Linux/UNIX shell program!

## Acknowledgments

I want to thank the faculty and staff at the Indraprastha Institute of Information Technology, Delhi, for allowing me to work on this project and gain valuable experience in shell programming and system calls.

Thanks to the course instructor and classmates for their support and collaboration throughout the development process.
