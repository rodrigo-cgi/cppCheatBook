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

Worth checking google's version as well
https://google.github.io/styleguide/cppguide.html
