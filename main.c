#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include "header.h"

int main(int argc, char* argv[]) {
    int len = 7;
    int arr[] = {23,12,6,5,4,2,21};
    pid_t pid;
    if ((pid = fork())) {
        /* proceso padre */
        merge_sort(arr, 0, (len/2) - 1);
        int status =0;
        waitpid(pid, &status, 0);
        waitpid(pid, &status, 0);
        status = WEXITSTATUS(status);
        printf("res padre = %d\n", res);
        printf("total = %d\n", res + status);
    }
    else {
        /* proceso hijo */
        merge_sort(arr, (len/2) - 1,len-1);
        printf("res hijo = %d\n", res);
        exit(res);
    }
    print_array(arr, len);
    return 0;
}
