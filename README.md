# 42_philosophers

The Philosophers Project is a well-known concurrency and synchronization problem, used to teach about resource-sharing issues in computer science.

### The Setup:
Imagine five philosophers seated around a circular table. In front of each philosopher, there is a single plate of spaghetti and a fork. Philosophers alternate between sleeping, thinking and eating.

### Rules for Eating:
A philosopher can only eat if they have two forks—one in each hand.
Since there are only the same number of forks as of philosophers and each philosopher needs two to eat, they must coordinate with each other to avoid conflicts.

### Objectives:

Avoid Deadlock: Ensure that the philosophers don't get stuck waiting for each other indefinitely.</br>
Avoid Starvation: Every philosopher should eventually be able to eat, even if it’s not their turn yet.</br>
Handle Concurrency Properly: Implement the solution with careful management of threads and processes, ensuring they can operate concurrently without issues.</br>

## Mandatory Part
The logic was implemented in C using threads and mutexes. </br>
Each philosopher corresponds to a thread and synchronization primitives like mutexes are used to manage access to shared resources (the forks). </br>
In this part, every philosopher will have a fork to his left and another to his right.

## Bonus Part
The logic was implemented in C using processes and semaphores. </br>
Each philosopher corresponds to a process and synchronization primitives like semaphores are used to manage access to shared resources (the forks). </br>
In this case, the forks are in the middle of the table instead of each being shared by only two philosophers.  </br>

---

## How to run
1. Clone repository
    ```bash
    git clone git@github.com:mjorgecruz/42_philosophers.git
    ```
### Mandatory part
2. Go inside project directory and run `make`
    ```bash
    cd 42_philosophers
    make
    ```
3. Run `./philosophers {number_of_philosophers} {time_to_die} {time_to_eat} {time_to_sleep} {[number_of_times_each_philosopher_must_eat]}`
    ```bash
    ./philosophers  5 400 100 200
    ```
### Bonus part
2. Go inside project directory and run `make bonus`
    ```bash
    cd 42_philosophers
    make bonus
    ```
3. Run `./philosophers_bonus {number_of_philosophers} {time_to_die} {time_to_eat} {time_to_sleep} {[number_of_times_each_philosopher_must_eat]}`
    ```bash
    ./philosophers_bonus  5 400 100 200 10
    ```
</br>
