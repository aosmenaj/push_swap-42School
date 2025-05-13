# 🔄 Push_Swap - 42 School Project

## 📖 Description

**Push_Swap** is a sorting algorithm project from the [42 School](https://42.fr) curriculum.  
The goal is to sort a stack of integers using a limited set of operations, following strict performance constraints.  
You must write a program that outputs the smallest possible list of operations to sort data on a stack, using only allowed moves.

The list of instructions we had is as follows:

sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.

sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.

ss : sa and sb at the same time.

pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.

ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.

rrr : rra and rrb at the same time.

The challenge focuses on **algorithmic efficiency**, **data structure design**, and **optimal operation planning**.

---

## 📦 Project Overview

The program takes a list of integers as arguments:

```bash
./push_swap 3 2 1
