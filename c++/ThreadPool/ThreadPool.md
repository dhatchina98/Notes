# Thread Pool

- Pool with many threads.
- Threads are always running(waiting) and its waiting for tasks.
- we can create a `N` threads and keep using those for different tasks and once ur application close that time u can stop these threads. so, u no need create and stop it again and again when u need it.

![see image](https://github.com/dhatchina98/Notes/blob/main/ref_images/thpl.png) 

### Thread Pool Members

1. `Queue` - we should add jobs/tasks to this data structure 
2. `Mutex` - single resource (queue) is accessed by multiple threads so, avoid race conditions
3. `Worker Threads` - we have to store the threads in vector to use when its need.

### Enqueue and Signaling

- Adding `Tasks` to the queue 

- `N` Threads are created when thread pool initialized but it doesn't check all the time queue has tasks are not so,after adding task to queue we have to give the `Signal` to threads to do the task. that signal is created here by `condition variable`.  