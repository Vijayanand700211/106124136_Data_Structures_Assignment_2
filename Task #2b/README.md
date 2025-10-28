# Astroworld Communication Problem

Subtask 1 code is in `subtask1.c`  
Subtask 2 code is in `subtask2.c`

## Description
In Subtask 1, the family tree is constructed from the given level order traversal.  
Then, the minimum number of phones `m` required is found such that every member can communicate with at least one phone either directly or through parent/child connection.

In Subtask 2, continuing from Subtask 1, the first `m` prime numbers are generated using the Sieve of Eratosthenes.  
For every pair of phones, the XOR of their prime values is calculated, and the number of pairs lying outside the range `[l, r]` is counted.

## To Compile and Run
Open terminal and run:
```bash
cd code
```
```bash
gcc subtask1.c -o sub1
./sub1
```
```bash
gcc subtask2.c -o sub2
./sub2
```