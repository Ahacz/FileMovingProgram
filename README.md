# FileMovingProgram
Program that simply moves files, made for BCF

This small program utilises <filesystem> library added to std C++ 17, previously existing in boost library. 
The program itself may accept arguments from command prompt, or in case of lacking arguments asks for file paths by itself. 
First argument should be a path to a file, while the second should be a valid directory. 
Any errors encountered include message given by the operating system itself. The program checks if the operation of moving is done right. 
In case of something going awry, the program attempts to revert changes done. Each operation considering files is done in a try catch block in order to make it as safe as possible.

Technologies used: C++17 filesystem, exception handling. 
