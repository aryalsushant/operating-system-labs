#include <stdio.h>
#include <pthread.h> // Required for Pthreads functions
#include <unistd.h> // Required for sleep()

// Function to be executed by the first thread
void *thread_function_1(void *arg) {
    printf("Thread 1: Starting execution.\n");
    sleep(2); // Simulate some work
    printf("Thread 1: Finishing execution.\n");
    pthread_exit(NULL); // Terminate the thread
}

// Function to be executed by the second thread
void *thread_function_2(void *arg) {
    printf("Thread 2: Starting execution.\n");
    sleep(1); // Simulate some work
    printf("Thread 2: Finishing execution.\n");
    pthread_exit(NULL); // Terminate the thread
}

int main() {
    pthread_t thread_id_1, thread_id_2; // Declare thread IDs

    printf("Main thread: Creating Thread 1.\n");
    // Create the first thread
    pthread_create(&thread_id_1, NULL, thread_function_1, NULL);

    printf("Main thread: Creating Thread 2.\n");
    // Create the second thread
    pthread_create(&thread_id_2, NULL, thread_function_2, NULL);

    printf("Main thread: Waiting for threads to complete.\n");
    // Wait for Thread 1 to finish
    pthread_join(thread_id_1, NULL);

    // Wait for Thread 2 to finish
    pthread_join(thread_id_2, NULL);

    printf("Main thread: All threads have completed.\n");
    return 0;
}
