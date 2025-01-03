# Syhmac's C program for generating random matrices
## About project
This program is creating 2 files with matrices of a user defined size,
filled with random integers from 0 to 100. I'm creating this program as a plugin
to mu other project, where I'm multiplying matrices. This program is a part of
it and helps with testing the multiplication program.

## Inputs
Program will open in a terminal and ask you for the size of the first matrix.
Then it will ask you for the size of the second matrix. Both matrices will be
saved in the same directory as the program.

The size of the matrix is defined by 2 integers separated by a single whitespace.

## Output
Program will create 2 files with matrices. The files will be named `matrix_1.txt` and `matrix_2.txt`.
Files will have the following format:
```
4 3
6 2 3
2 3 4
9 8 7
1 9 2
```
Where the first line defines the size of the matrix, and following lines include the matrix.

## Building
Build using CMake 3.29 or newer using `CMakeList.txt`