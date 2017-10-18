arch 1- Binary search tree project

This directory contains:

- code that implements a binary search tree that store the names of all
the employees in the company.
-a demo program to test it.

The demo program creates a BST and add,remove and prints the names of the employees; with many options such as write it in a text file and read it in the same program without loosing the BST structure.

This demo contains the following files: bnlist.h header file of BST structure, functions.c: implementation of the BST project1.c: the user interface and demostration program that uses BST.


To compile:

 $ make

To test it, try:
 $ make demo

To delete binaries:
 $ make clean

NOTES
- it may contains little bugs on printing from the text file in the terminal.
- the delete options does not work properly and may cause changes in the BST structure.(runing the program without deleting employees it does not affect the others methods)