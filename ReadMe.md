DESCRIPTION:

Binary Semaphore can be used to: 
(1) control mutually exclusive access to shared devices or data structures or
(2) synchronize multiple tasks, or task-level and interrupt-level processes.

From VxWorks Description:

A binary semaphore can be viewed as a cell in memory whose contents are in one of two states, full or empty. When a task takes a binary semaphore, using semTake( ), subsequent action depends on the state of the semaphore:
(1)	If the semaphore is full, the semaphore is made empty, and the calling task continues executing.
(2)	If the semaphore is empty, the task will be blocked, pending the availability of the semaphore. If a timeout is specified and the timeout expires, the pended task will be removed from the queue of pended tasks and enter the ready state with an ERROR status. A pended task is ineligible for CPU allocation. Any number of tasks may be pended simultaneously on the same binary semaphore.
When a task gives a binary semaphore, using semGive( ), the next available task in the pend queue is unblocked. If no task is pending on this semaphore, the semaphore becomes full. Note that if a semaphore is given, and a task is unblocked that is of higher priority than the task that called semGive( ), the unblocked task will preempt the calling task.