## Weighted Survey Program

### Introduction

This project was created for the [Computer Science 311 course](https://study.com/academy/course/computer-science-311-artificial-intelligence.html) on [Study.com](https://study.com).

This program surveys you on three multiple choice questions about your political beliefs, with each question having four answers. These answers have no weights by default in favor of any political party. After answering those questions, you will be shown what the program predicted as your political affiliation. You will then be prompted for your affiliation with one of the four political parties. The program will adjust the weights of the answers based on your response. The hope is that the program can predict your political affiliation based on the answers you provide.

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

### Usage

After compiling and linking the C++ code into an executable, execute it in the terminal and follow the prompts. You will be prompted with three multiple choice political questions to gauge your political affiliation.

```
QUESTION: What should the government do to help the poor?

1. Make it easier to apply for assistance.
2. Allow parents to have school choice.
3. Create welfare for work programs.
4. The government should not interfere.

Enter an answer (1-4): 
```

Once you have completed all three questions, the program will show your political affiliation predictions. Since the weights are not changed until you submit your true political affiliation, all parties will have an equal chance. This changes with subsequent uses of the program.

```
PREDICTION: Here are your chances of being in each political party:

Blue Party: 25%
Green Party: 25%
Yellow Party: 25%
Red Party: 25%
```

You will finally be prompted with a question that asks for your political affiliation. This answer will adjust the weights of each of the answers that you selected before, making them weighted more heavily towards the party you selected. The answers you did not select will not be affected at all.

```
QUESTION: What political party do you affiliate with?

1. The Blue Party.
2. The Green Party.
3. The Yellow Party.
4. The Red Party.

Enter an answer (1-4): 
```

Re-running the program will produce more accurate predictions as the weights become better.