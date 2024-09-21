# 42_philosophers

The Philosophers Project is a well-known concurrency and synchronization problem, used to teach about resource-sharing issues in computer science.
Problem Overview:

    The Setup: Imagine five philosophers seated around a circular table. In front of each philosopher, there is a single plate of spaghetti and a fork. Philosophers alternate between sleeping, thinking and eating.
    Rules for Eating:
        A philosopher can only eat if they have two forks—one in each hand.
        Since there are only five forks and each philosopher needs two to eat, they must coordinate with each other to avoid conflicts.

Objectives:

    Avoid Deadlock: Ensure that the philosophers don't get stuck waiting for each other indefinitely.
    Avoid Starvation: Every philosopher should eventually be able to eat, even if it’s not their turn yet.
    Handle Concurrency Properly: Implement the solution with careful management of threads or processes, ensuring they can operate concurrently without issues.

Technical Requirements:

    Implement the logic in C.
    Use threads or processes for each philosopher.
    Use synchronization primitives like mutexes or semaphores to manage access to shared resources (the forks).

Learning Outcomes:

Students learn how to:

    Handle concurrent processes/threads.
    Implement proper synchronization mechanisms.
    Understand and avoid common concurrency problems like deadlocks and starvation.

This project is a classic introduction to the complexities of concurrency and is foundational in building a deeper understanding of operating system concepts.

---

## How to run

1. Clone repository
    ```bash
    git clone git@github.com:teresa-chow/42-libft.git
    ```

2. Go inside project directory and run `make`
    ```bash
    cd libft
    make
    ```
3. To use the library in your code, `#include` the following header
    ```c
    #include "get_next_line.h"
    ```

</br>
