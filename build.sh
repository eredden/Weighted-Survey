# This script can be executed through Bash and Powershell.

rm -r build
mkdir build
cd build
cmake -G "MinGW Makefiles" ..
make 