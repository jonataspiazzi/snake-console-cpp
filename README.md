## snake-console-cpp
A simple snake game made in almost in standard c++ using only console visualization.

#
## Purpose and scope
This project was done as a warm up in c++ language before starting to code on Unreal Engine.

The Unreal guidelines as nomenclature and types was followed in this project and some of the modifications to make the code closer to Unreal can be spotted in `Global.h` file.  

#
## About the environment

This project was done in Visual Studio Code, because is a IDE supported by Unreal Engine, also was used `MSVC` compiler for the same reasons.


#
## Running

Make sure (if you using a integrated terminal) you have enough vertical and horizontal space on your terminal, or else something very messy will be outputted. (A side effect of using SetCursorPosition).

To build:
```
cl /std:c++17 *.cpp /Fe:snake.exe
```

Or if you don't like (as me) .obj files messing things up in your source dir:

```
cl /std:c++17 /Fo"./obj/" /EHsc *.cpp /Fe:"./bin/snake.exe"
```

Build and Run:

```
cl /std:c++17 /Fo"./obj/" /EHsc *.cpp /Fe:"./bin/snake.exe" && cls && bin\snake.exe
```