# Push_Swap

###Final score: 86/100

## Task

 Sort a random list of integers for smallest numbers operations.

 This project work macOS only.
 
 ### Data

 You're starting with two empty stacks, a and b. You are given a random lists of integers via command line arguments.
 
 You must sort this list use next operations:
 
 1) SA - swap first element int stack a with second element in stack a.
 2) SB - swap first element int stack b with second element in stack b.
 3) SS - swap first and second elements in either stacks.
 4) RA - shift up all elements in stack a by 1.
 5) RB - shift up all elements in stack b by 1.
 6) RR - shift up all elements in either stacks by 1.
 7) RRA - shift down all elements in stack a by 1.
 8) RRB - shift down all elements in stack b by 1.
 9) RRR - shift down all elements in either stacks by 1.
 10) PA - take the first element from stack b, ant put int stack a.
 11) PB - take the first element from stack a, ant put int stack b.

 ## Instalation

 Clone repository and run following command:

```
 make
```
 After use the command, will be create file name "push_swap".

### Run programm

 After creating file, you can run the project following command:

```
 ./push_swap
```
 Program takes integers as a parameters

 To start program with Mandelbrot set use this parameters:
 ```
 ./push_swap 1 3 4 66 55 44 7 8 0 9 3
```
 Also you can copy push_swap binary file in directory name "push_swap_visualizer", and use next command for visualise:

 ```
python3 pyviz.py `ruby -e "puts (1..20).to_a.shuffle.join(' ')"`
```