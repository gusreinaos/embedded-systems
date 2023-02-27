## Dynamic Memory Allocation
**Memory allocation:**
- Stack: were regular variables are stored, as the program needs moroe memory for variables.
- Heap: dynamic allocation of memory, we can request blocks of memory on the heap of different sizes at runtime
    - We use **malloc(number of bytes)** allocating space on the heap, it returns a **void pointer** to this block of memory (**it could be assigned to any type**)
    - After we are done using that space we should use **free(variable)**
    - **Calloc(number of things, size of things)** this will declare space for 10 integers. Calloc zeroes the space first, it will set the space to all zeros
- Memory leak: forget to free the space (loss of memory), gives us manual memory management