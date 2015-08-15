


#!/bin/bash 
cd include &&
indent -kr -i8 *.h
cd ../src && 
indent -kr -i8 *.c 
gcc *.c -lm -g -o mem
mv mem ../bin/

