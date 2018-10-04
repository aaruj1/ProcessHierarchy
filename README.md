# ProcessHierarchy
ProcessHierarchy implementation in C 

This code generate a process hierarchy of H height and C child at each parent node. It uses fork() system call in a for loop to create C children at a given node and uses recursion to create child from hight 1 to H levels. The recursion uses execv() system call. The wait() system call has been used to force the parent to wait until all the children are created. A sleep(1) system call has been used before the return command to print the terminating process in sequential order.

Below are the steps to run the ProcessHierarchy.c :

Step 1: Use the makefile to compile the code
$make all
Step 2: Run the code with 2 command line-argument H and C value.
$./ProcessHierarchy H C

If any problem contact me at : aaruj1@binghamton.edu
