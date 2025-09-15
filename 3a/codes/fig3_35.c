/* 
Name: Sushant Aryal
Course: CSC 306 – Operating Systems
Date: 2025-09-14
Lab: Lab 3A (Figures 3.30–3.35)
File: fig3_35.c
*/
/**
 * Figure 3.35
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SIZE 5

int nums[SIZE] = {0, 1, 2, 3, 4};

int main() {
    int i;
    pid_t pid;

    pid = fork();

    if (pid == 0) { /* child process */
        for (i = 0; i < SIZE; i++) {
            nums[i] *= -i;
            printf("CHILD: %d\n", nums[i]); /* LINE X */
        }
    } 
    else if (pid > 0) { /* parent process */
        wait(NULL);
        for (i = 0; i < SIZE; i++) {
            printf("PARENT: %d\n", nums[i]); /* LINE Y */
        }
    }

    return 0;
}
