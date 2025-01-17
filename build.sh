# This script can be executed through Bash or Powershell.

rm -r build
mkdir build
cd build

# You may need to adjust the build system generator
# based on what you have installed on your machine.
cmake -G "MinGW Makefiles" ..
make 