# simple_shell

## Introduction
**simple_shell** is a basic Unix-like shell implementation written in C. It provides a command-line interface for executing system commands and built-in functions, supporting both interactive and non-interactive modes.

## Features
- Interactive and non-interactive shell modes
- Dynamic command line reading
- Input tokenization
- Command path resolution
- Process creation and execution
- Environment variable handling
- Customizable prompt
- Error messages for unknown commands
- Graceful handling of EOF (Ctrl+D)
- Built-in command execution without forking when unnecessary

## Built-in Commands
### exit
Terminates the shell.

### env
Prints all current environment variables.

### help
Displays information about built-in commands and usage.

## Usage
### Interactive Mode
Launch the shell and interact directly:
```bash
$ ./simple_shell
simple_shell$ ls
simple_shell$ pwd
simple_shell$ exit
```

### Non-Interactive Mode
Pipe commands or use input redirection:
```bash
$ echo "ls" | ./simple_shell
$ cat commands.txt | ./simple_shell
```

### Command Execution
**simple_shell** supports single-word commands with or without arguments. Commands are executed by searching the directories listed in the PATH environment variable.

### Built-in Commands Usage
#### exit
Terminates the shell session:
```bash
simple_shell$ exit
```

#### env
Displays the current environment variables:
```bash
simple_shell$ env
```

#### help
Provides help information for built-in commands:
```bash
simple_shell$ help
```

## Token Delimiters
The shell recognizes the following token delimiters:
- Space
- Tab (`\t`)
- Carriage return (`\r`)
- Newline (`\n`)
- Bell (`\a`)

## Prerequisites
- GNU Compiler Collection (GCC)
- UNIX-like operating system (Linux, macOS)
- Standard C libraries
- Basic understanding of Unix command-line interface

## Compilation
Compile the shell using:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell
```

## Limitations
- Limited built-in command support
- Basic path resolution mechanism
- No advanced shell features like pipes or redirections
- Basic error handling
- No support for scripting or complex command chaining
- Limited customization options

## File Structure
- **shell.h**: Header file with function declarations
- **main.c**: Entry point and mode selection
- **exec.c**: Implementation of command execution
- **builtins.c**: Implementation of built-in commands
- **utils.c**: Utility functions for command parsing and error handling

## Error Handling
Handles various error scenarios including:
- Unknown commands
- Memory allocation failures
- Process creation errors
- Command execution errors
- Invalid input handling
- Proper error messages for debugging

## Examples
### Run the shell interactively:
```bash
$ ./simple_shell
```

### Execute a command with arguments:
```bash
simple_shell$ ls -l /home/user
```

### Use the built-in `env` command:
```bash
simple_shell$ env
```

### Exit the shell using the `exit` command:
```bash
simple_shell$ exit
```

## See Also
- `sh(1)`, `bash(1)`

## Author
Written Arnaud
And Also By Bryan.

