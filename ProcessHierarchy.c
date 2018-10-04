#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv) {

    int h, c;
    if (argc == 3) {
        h = atoi(argv[1]);
        c = atoi(argv[2]);
        if (h < 1 || c < 1) {
            printf("\nError : H or C cannot be less than 1\n");
            exit(1);
        }
        printf("Process tree will be created for H = %d, and C = %d\n", h, c);
    } else {
        printf("\nError: two command-line arguments H and C are expected.\n");
        exit(1);
    }

    pid_t pid = getpid();
    pid_t ppid = getppid();

    printf("(%d) : Process starting \n", pid);
    printf("(%d) : Parent's id = %d \n", pid, ppid);
    printf("(%d) : Height in the tree = %d \n", pid, h);

    if (h > 1) {
        printf("(%d) : Creating %d children at height %d\n", pid, c, h - 1);
        for (int i = 0; i < c; i++) {

            pid_t pid = fork();
            if (pid == -1) {
                fprintf(stderr, "fork() failed\n");
                exit(1);
            }

            if (pid == 0) {
                char c_string[10], h_string[10];

                sprintf(c_string, "%d", c);
                sprintf(h_string, "%d", h - 1);

                char *arg_v[] = {argv[0], h_string, c_string, NULL};
                if (execv(arg_v[0], arg_v) == -1) {
                    fprintf(stderr, "execv() failed\n");
                }
            }
        }
        while ((wait(NULL) < 0)) {
            fprintf(stderr, "wait() failed\n");
        }
    }

    if (h == 1) {
        printf("(%d) : Process tree competed on this branch\n", pid);
    }
    sleep(1);
    printf("(%d) : Terminating at height = %d \n", pid, h);

    sleep(1);
    for (int i = 0; i < h; i++) {
        printf("\t");
    }

    printf("(%d) \n", pid);


    return 0;
}