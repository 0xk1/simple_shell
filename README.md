# Shell Project

This is a shell project implemented in C. The shell is capable of executing commands and providing a command-line interface for the user.

## Table of Contents

- [Description](#description)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Description

The shell project aims to implement a basic shell program that provides a command-line interface for users to interact with the underlying operating system. It supports executing commands, handling built-in commands, managing environment variables, and more.

## Features

The shell program provides the following features:

- Command execution: Executes external commands by creating child processes.
- Built-in commands: Supports built-in commands like `env`, `exit`, `setenv`, `unset`, `cd`, etc.
- Environment variable manipulation: Allows manipulating environment variables using `setenv` and `unset` commands.
- Signal handling: Handles signals like `SIGINT` to provide the expected behavior.
- Command parsing: Parses user input to separate commands and arguments.
- Path resolution: Resolves the full path of a command using the `PATH` environment variable.

## Installation

To install and run the shell program, follow these steps:

1. Clone the repository:

   ```shell
   git clone git@github.com:0xk1/simple_shell.git
2. Compile the source code:
    ```shell
    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell
3. Run the shell:

## Contributing

Contributions to the shell project are welcome. If you encounter any issues or have suggestions for improvements, please create a new issue or submit a pull request.

When contributing to this repository, please first discuss the change you wish to make via issue or email with the project maintainers.

## Usage

Once the shell program is running, you can enter commands and interact with the shell. The shell will execute the commands and provide the output accordingly. You can use built-in commands like env, exit, setenv, unset, and cd as well.

## License

MIT License

simple_shell

Copyright (c) 2023 0xk1, ekarkat

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.