# Thread and Process Quiz - Questions, Answers, and Explanations

This document contains 20 multiple-choice questions about **threads**, **processes**, and **operating system concepts**, along with detailed explanations for each.

---

## **Question 1**
**Q:** The processes that are residing in main memory and are ready and waiting to execute are kept on a list called:

- [ ] Execute queue  
- [ ] Device queue  
- [ ] Job queue  
- [x] Ready queue ✅

**Correct Answer:** Ready queue  

**Explanation:**  
- The **ready queue** holds processes in **main memory** that are ready to run as soon as the CPU is free.  

**Why others are wrong:**
- **Execute queue:** Not a standard OS term.  
- **Device queue:** For processes waiting for **I/O operations**, not CPU time.  
- **Job queue:** Contains all processes in the system, including those **not yet in memory**.

---

## **Question 2**
**Q:** When a process creates a new thread, what do the threads within the same process share?

- [ ] Process IDs  
- [x] Code, data, and open files ✅  
- [ ] Stack memory  
- [ ] Registers  

**Correct Answer:** Code, data, and open files  

**Explanation:**  
- Threads in the same process share **code**, **data segments**, and **open file descriptors** to communicate and work efficiently.

**Why others are wrong:**
- **Process IDs:** The process ID is shared, but this is not what defines thread sharing.  
- **Stack memory:** Each thread has **its own stack** for local variables.  
- **Registers:** Each thread has **its own set of registers**.

---

## **Question 3**
**Q:** Which of the following is used to uniquely identify a thread within a process?

- [x] Thread ID (TID) ✅  
- [ ] File descriptor  
- [ ] Stack pointer  
- [ ] Process ID (PID)

**Correct Answer:** Thread ID (TID)

**Explanation:**  
- Each thread inside a process is identified by a **unique TID**.

**Why others are wrong:**
- **File descriptor:** Used for files, not threads.  
- **Stack pointer:** Part of thread state but not unique.  
- **Process ID (PID):** Identifies the **whole process**, not individual threads.

---

## **Question 4**
**Q:** If only user-level threads are used and there are no kernel-level threads, can the system allocate resources effectively to multiple threads at user level?

- [ ] True  
- [x] False ✅

**Correct Answer:** False

**Explanation:**  
- The **kernel is unaware of user-level threads**, so it treats them as a single process and cannot schedule them independently.

**Why others are wrong:**
- **True:** Incorrect because no real parallelism occurs without kernel-level awareness.

---

## **Question 5**
**Q:** What happens if the main thread of a process terminates before its child threads?

- [ ] The operating system crashes  
- [ ] The process becomes a zombie  
- [ ] All child threads continue running independently  
- [x] All child threads are terminated ✅

**Correct Answer:** All child threads are terminated  

**Explanation:**  
- When the main thread ends, the **entire process terminates**, including all child threads.

**Why others are wrong:**
- **OS crashes:** Threads end gracefully, not crash the OS.  
- **Zombie process:** Happens only when parent process fails to read exit status.  
- **Independent run:** Threads cannot survive outside their parent process.

---

## **Question 6**
**Q:** Which of the following is a reason to use threads instead of processes?

- [ ] Threads cannot share memory  
- [ ] Threads are more isolated than processes  
- [ ] Threads require more resources  
- [x] Threads have lower context switching overhead ✅

**Correct Answer:** Threads have lower context switching overhead  

**Explanation:**  
- Threads are lightweight and switching between them is **faster** than between processes.

**Why others are wrong:**
- **Cannot share memory:** False, threads **do share memory**.  
- **More isolated:** Processes are more isolated, not threads.  
- **Require more resources:** Threads are **cheaper** than processes.

---

## **Question 7**
**Q:** Which of the following is NOT a valid thread state?

- [ ] Terminated  
- [ ] Waiting  
- [x] Compiling ✅  
- [ ] Running  

**Correct Answer:** Compiling  

**Explanation:**  
- Valid thread states: **New, Ready, Waiting, Running, Terminated**.

**Why others are wrong:**
- **Terminated, Waiting, Running:** These are valid states for threads.

---

## **Question 8**
**Q:** Which of the following is NOT shared between threads of the same process?

- [x] Stack memory ✅  
- [ ] File descriptors  
- [ ] Heap memory  
- [ ] Global variables  

**Correct Answer:** Stack memory  

**Explanation:**  
- Each thread has its **own stack** for local variables and function calls.

**Why others are wrong:**
- **Heap, global variables, file descriptors:** These are **shared** between threads.

---

## **Question 9**
**Q:** Which function is used to terminate a thread in the POSIX thread library?

- [x] pthread_exit() ✅  
- [ ] thread_kill()  
- [ ] exit_thread()  
- [ ] kill_thread()

**Correct Answer:** pthread_exit()

**Explanation:**  
- `pthread_exit()` safely ends a thread and cleans up resources.

**Why others are wrong:**
- The others are **not valid POSIX functions**.

---

## **Question 10**
**Q:** Which of the following is the primary function of a thread in an operating system?

- [x] To execute a sequence of instructions independently within a process ✅  
- [ ] To manage hardware devices  
- [ ] To schedule processes for execution  
- [ ] To allocate memory to processes  

**Correct Answer:** Execute a sequence of instructions independently within a process

**Explanation:**  
- Threads are designed to **execute instructions concurrently** within a process.

**Why others are wrong:**
- Hardware, scheduling, memory are managed by the **OS**, not threads directly.

---

## **Question 11**
**Q:** Which of the following best describes a multithreaded process?

- [x] A process with multiple program counters ✅  
- [ ] A process that cannot share resources  
- [ ] A process that runs only on a single core  
- [ ] A process with a single thread of execution  

**Correct Answer:** A process with multiple program counters

**Explanation:**  
- Each thread has **its own program counter**, allowing concurrent execution.

**Why others are wrong:**
- **Cannot share resources:** False, threads **share resources**.  
- **Single core:** Threads can run on **multiple cores**.  
- **Single thread:** Opposite of multithreaded.

---

## **Question 12**
**Q:** What is the main advantage of using threads within a process?

- [ ] Threads cannot communicate with each other  
- [ ] Threads are slower than processes  
- [x] Threads allow parallel execution and resource sharing within a process ✅  
- [ ] Threads require more memory than processes  

**Correct Answer:** Parallel execution and resource sharing  

**Explanation:**  
- Threads allow **faster execution** and **easy communication** through shared memory.

**Why others are wrong:**
- **Cannot communicate:** They can communicate easily.  
- **Slower:** Threads are **faster** than processes.  
- **More memory:** Threads are **lighter** than processes.

---

## **Question 13**
**Q:** What Windows call is used for a parent process to wait on a child process or for a process to wait on its threads?

- [ ] WaitForClone(...)  
- [x] WaitForSingleObject(...), WaitForMultipleObjects(...) ✅  
- [ ] WaitForChildObject(...)  
- [ ] WaitP(...), WaitT(...)  

**Correct Answer:** WaitForSingleObject(...) and WaitForMultipleObjects(...)

**Explanation:**  
- These functions **pause execution** until one or more threads or processes are complete.

---

## **Question 14**
**Q:** Which system call is commonly used in UNIX-like OS to create a new thread?

- [x] pthread_create() ✅  
- [ ] wait()  
- [ ] exec()  
- [ ] fork()  

**Correct Answer:** pthread_create()

**Explanation:**  
- POSIX threads are created using **pthread_create()**.

**Why others are wrong:**
- **wait():** Used for process synchronization.  
- **exec():** Replaces process image.  
- **fork():** Creates a new **process**, not a thread.

---

## **Question 15**
**Q:** Which of the following is a disadvantage of kernel-level threads?

- [ ] They cannot be preempted  
- [x] Thread operations are slower due to kernel involvement ✅  
- [ ] They do not support multi-core processors  
- [ ] They cannot run in parallel  

**Correct Answer:** Thread operations are slower due to kernel involvement

**Explanation:**  
- Kernel-level threads require **system calls**, causing **overhead**.

---

## **Question 16**
**Q:** Which method is used to make the main thread wait for all child threads in POSIX?

- [ ] Sleep()  
- [ ] Wait()  
- [ ] Stop()  
- [x] Join() ✅  

**Correct Answer:** Join()

**Explanation:**  
- `pthread_join()` is used to wait for a thread to finish execution.

---

## **Question 17**
**Q:** Which method is used to wait for a thread to finish execution in POSIX threads?

- [ ] join_thread()  
- [x] pthread_join() ✅  
- [ ] thread_wait()  
- [ ] pthread_wait()  

**Correct Answer:** pthread_join()

**Explanation:**  
- Correct POSIX standard function for **waiting for a thread to finish**.

---

## **Question 18**
**Q:** Which of the following is true about user-level threads?

- [ ] Managed by the operating system kernel  
- [x] Managed by a user-level library ✅  
- [ ] Cannot be created by user programs  
- [ ] Require hardware support  

**Correct Answer:** Managed by a user-level library

**Explanation:**  
- User-level threads exist entirely in **user space**, managed by libraries like `pthreads`.

---

## **Question 19**
**Q:** What is the instruction or call to create a thread in Windows?

- [ ] CreateAThread()  
- [ ] ThreadCreate()  
- [x] CreateThread() ✅  
- [ ] MakeThread()  

**Correct Answer:** CreateThread()

**Explanation:**  
- `CreateThread()` is the official Windows API call to **start a new thread**.

---

## **Question 20**
**Q:** Which of the following is NOT a valid reason for thread termination?

- [x] Thread is waiting for I/O ✅  
- [ ] Thread is cancelled by another thread  
- [ ] Thread completes its task  
- [ ] Thread encounters an unhandled exception  

**Correct Answer:** Thread is waiting for I/O

**Explanation:**  
- Waiting for I/O **blocks a thread**, but it does not terminate it.

**Valid reasons include:**
- Cancellation by another thread  
- Completing its task  
- Unhandled exceptions

---
