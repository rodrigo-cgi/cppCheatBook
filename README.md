# cppCheatBook
As I often forget the syntax of pretty much everything in cpp, I decided to make a compilation of fundamental sytanx and standard library functions.
By doing this, I hope to finally memorize everything and never need to consult this repo :)


## G++ basic Compilation:

g++ -Wall -Wextra -pedantic -std=c++14 -O2 -o hello hello.cpp

### where:
-Wall: This enables all the warnings about constructions that some users consider questionable, and that are easy to avoid (or modify to prevent the warning), even in conjunction with macros. This also enables some language-specific warnings described in C ++
-Wextra: This enables some extra warning flags that are not enabled by -Wall
-std = Cpp version
-O2: Optimize even more. GCC performs nearly all supported optimizations that do not involve a space-speed tradeoff. As compared to -O, this option increases both compilation time and the performance of the generated code.
-o: output file name, if not set, it will generate a.out

## StyleGuide

I'm following style guide of coreCPP for c++ in this repo. 
https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#S-functions
Naming conventions:
https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#S-naming

Worth checking google's version as well
https://google.github.io/styleguide/cppguide.html


## Debugging in VS Code

It's required to install gdb on your system. 
For ubuntu or windown's unbuntu WSL. 
sudo apt get install gdb

Then, restart VS code. 
Install the extension C.C++ from msfot

Click Debug ->
Start Debugging ->
Choose the c++ configuration
Choose g++ build and debug active file. 

A few files will be created inside .vscode folder, on the root of your project. 
You can change configurations on launch.json
If you need to compile multiple fles, add them on the definition of the tasks, at tasks.json.
Example of tasks.json
```
        {
            "tasks": [
                {
                    "type": "shell",
                    "label": "cpp build active file",
                    "command": "/usr/bin/g++",
                    "args": [
                        "-ggdb",  // stronger option for VS gdb debug
                        "${file}",
                        "-o",
                        "${fileDirname}/${fileBasenameNoExtension}"
                    ],
                    "options": {
                        "cwd": "/usr/bin"
                    }
                }
            ],
            "version": "2.0.0"
        }
```
example of  launch.json
```
    "version": "0.2.0",
    "configurations": [
        {
            "name": "cpp build and debug active file",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}/${fileBasenameNoExtension}",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "cpp build active file",
            "miDebuggerPath": "/usr/bin/gdb"
        }
    ]

```

## Visual Studio code nuget

Enforces Profiles from c++ core guidelines

https://marketplace.visualstudio.com/items?itemName=jmrog.vscode-nuget-package-manager