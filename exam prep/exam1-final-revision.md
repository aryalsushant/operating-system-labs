# ⚡ Flashcards – IPC, Scheduling, Threads, System Calls

- **Q:** What provides an interface to OS services?  
  **A:** System calls  

- **Q:** Three methods to pass parameters to the OS?  
  **A:** Stack, Registers, Memory  

- **Q:** Only gateway between user space & kernel space?  
  **A:** System calls  

- **Q:** System calls run in which mode?  
  **A:** Kernel mode  

- **Q:** What happens if exec() comes before fork()?  
  **A:** exec() overwrites child code, fork() never runs  

- **Q:** Which IPC requires shared memory?  
  **A:** Shared memory  

- **Q:** Which IPC is easier in distributed systems?  
  **A:** Message passing  

- **Q:** Named pipes require parent-child relation?  
  **A:** False  

- **Q:** Ordinary pipes are unidirectional?  
  **A:** True  

- **Q:** In FCFS scheduling, what main issue occurs?  
  **A:** Convoy effect  

- **Q:** Two modes of operating in OS?  
  **A:** User mode & Kernel mode  

- **Q:** Events that remove a process from CPU?  
  **A:** Time slice expiry, I/O request, fork → All  

- **Q:** Running process interrupted → goes to which state?  
  **A:** Ready  

- **Q:** Context switch: P0 → P1. States saved where?  
  **A:** P0 → PCB0, P1 ← PCB1  

- **Q:** Data structure managing processes in Linux?  
  **A:** Linked list  

- **Q:** Do modern OS support SMP?  
  **A:** True  

- **Q:** Models of user↔kernel threads?  
  **A:** One-to-one, many-to-one, many-to-many, two-level (All)  

- **Q:** Two benefits of thread pools?  
  **A:** Performance (reuse), Resource management  

- **Q:** Threads share what across same process?  
  **A:** Files, Code, Data  

- **Q:** In multithreaded server, what handles new request?  
  **A:** New thread  

- **Q:** Benefits of multithreaded programming?  
  **A:** Responsiveness, Economy, Scalability, Resource sharing (All)  

- **Q:** Formula for performance gains with cores?  
  **A:** Amdahl’s Law  

- **Q:** Not a challenge in multicore design?  
  **A:** Ensuring enough cores  
