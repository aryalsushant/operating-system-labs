/* 
Name: Sushant Aryal
Course: CSC 306 – Operating Systems
Date: 2025-09-14
Lab: Lab 3A (Figures 3.30–3.35)
File: fig3_30.c
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int value = 5;

int main() {
    pid_t pid;
    pid = fork();

    if (pid == 0) { /* child process */
        value += 15;
        printf("Child: value = %d\n", value); /* LINE B */
        return 0;
    } 
    else if (pid > 0) { /* parent process */
        wait(NULL);
        printf("PARENT: value = %d\n", value); /* LINE A */
        return 0;
    }
}

