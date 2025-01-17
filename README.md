## AI Survey Program

### Introduction

This project was created for the [Computer Science 311 course](https://study.com/academy/course/computer-science-311-artificial-intelligence.html) on [Study.com](https://study.com). I did this to expand my knowledge of the C++ programming language as well as to pursue a college degree from Western Governor's University.

This program surveys you on three multiple choice questions about your political beliefs, with each question having four answers. These answers have no weights by default in favor of any political party. After answering those questions, you will be shown what the program predicted as your political affiliation. You will then be prompted for your affiliation with one of the four political parties. The program will adjust the weights of the answers based on your response. The hope is that the program can evenually predict your political affiliation based on the answers you provide.

### Setup

You must have CMake installed on your system to build the executable for this program. You can execute `build.sh` in the root directory of this project to build an executable, or you may use the commands listed below.
```bash
# This script can be executed through Bash or Powershell.

rm -r build
mkdir build
cd build

# You may need to adjust the build system generator
# based on what you have installed on your machine.
cmake -G "MinGW Makefiles" ..
make 
```

```bash
# Running the executable built by CMake.

./main.exe
```