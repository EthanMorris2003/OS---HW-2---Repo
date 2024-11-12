# OS-HW-2-Repo
Operating Systems Homework #2 Repo 

# Banker's Algorithm for Deadlock Avoidance

This C++ program implements the Banker's Algorithm for deadlock avoidance. 

## Program Overview

The program takes input from a file named `input.txt` and calculates whether the system is in a safe state based on the Banker's Algorithm.

## How to Run the Program

1. **Compile the Program**

   Use the following command to compile the code:

   ```bash
    g++ bankers_algoritm.cpp

   If the system is in a safe state, the program will print the safe sequence. If not, it will indicate that the system is not in a safe state.

Example output:

Following is the SAFE Sequence:
P0 -> P1 -> P3 -> P2 -> P4

If the system is not in a safe state, the output will display:
The given sequence is not safe.