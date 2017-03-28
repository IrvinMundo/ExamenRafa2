#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "header.h"

#define MSGSIZE  7

int main(int argc, char* argv[]) {
    int len = 7;
    int arr[] = {23,12,6}; //Padre
    int arr1[]={5,4,2,21}; //Hijo

    int p[2];

    pipe(p);

    if (fork() == 0) {
        /* proceso hijo */
        printf("Termine hijo\n");
        merge_sort(arr1, 0, len - 1);
        close(p[2]);
        dup2(p[1], 1);
        dup2(p[0],0);
        print_array(arr1,3);
        char are[7];
        read(p[0],are,7);
        write(p[1],are,7);
    }else{
        char inbuf[4];
        close(p[1]);
        close(p[2]);
        int status;
        wait(&status);
        dup2(p[0], 0);
        read(p[0],inbuf,7);
        merge_sort(arr, 0, len - 1);
        printf("%s",inbuf);
        //inbuf es arreglo hijo
        //arr es arreglo padre

    }

    /* proceso padre
    close(p[1]);
    close(p[2]);
    merge_sort(arr, 0, len - 1);
    int d;
    scanf("%d",&d); */

    //print_array(arr, len);
    return 0;
}