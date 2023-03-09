# Multithreading

Para poder creat threads tenemos que usar la pthread library

**Functions:**

    - pthread_create: We give it a function that we want to run in its own thread
        As parameters it takes:
        - Pointer to the pthread_t variable
        - NULL (not passing any extra attributes, we continue with the basic functionality)
        - Functions
        - Pass arguments to the previous function, in order to pass arguments we need to create a (void *)&data which is a void pointer to the data that we want to pass

    - pthread_join: It is going to join the thread to the main one, it is going to WAIT until the thread is done and then join it back again
        As parameters it takes:
        - The thread that we want to join back
        - NULL (return value for the function)

    - pthread_t thread1; -- Example for declaring a thread
    - pthread_exit: exits the thread

