# push\_swap

## Introduction

**push\_swap** is a sorting algorithm project where you must sort a stack of numbers using a limited set of operations. The goal is to sort the numbers with the **fewest moves possible**, using only two stacks (`a` and `b`) and a defined list of operations.

---

## Goal

* Take a list of integers as input.
* Sort them in ascending order using only allowed operations.
* Display the list of operations used to achieve the sorting.
* Optimize the number of moves to make your solution as efficient as possible.

---

## Allowed Operations

* `sa` / `sb`: Swap the first two elements of stack a or b.
* `ss`: `sa` and `sb` at the same time.
* `pa` / `pb`: Push the top element from stack b to a, or a to b.
* `ra` / `rb`: Rotate stack a or b (first element becomes last).
* `rr`: `ra` and `rb` at the same time.
* `rra` / `rrb`: Reverse rotate stack a or b (last becomes first).
* `rrr`: `rra` and `rrb` at the same time.

---

## How It Works

1. You start with all numbers in **stack a**.
2. You use the operations to move elements between stacks and sort them.
3. Your program outputs the sequence of operations it used.

---

## Example

Input:

```bash
$ ./push_swap 3 2 1
```

Output:

```
sa
rra
```

(Explanation: swap the first two, then reverse rotate to bring the smallest to the top.)

---

## Key Concepts

* Stack manipulation
* Sorting algorithms 
* Optimization and algorithm efficiency
* Input validation and memory management in C

---

## Conclusion

**push\_swap** helps you think algorithmically and write efficient C code. You’ll learn how to build and manipulate stacks, create optimized sorting logic, and handle complex constraints in a clean way.

