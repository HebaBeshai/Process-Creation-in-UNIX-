#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
#include  <sys/types.h>
#include <unistd.h>

int main() {

//opens text file
    FILE *fp =fopen("lab2.txt", "r");

    int x;

    if (!fp){
        return 1;
    }



//reads text file
    char buf[1000];
    int pid;
    pid=fork();

    if (pid ==0){
        while (fgets(buf, 1000, fp) != NULL){
            printf("%d %s",getpid(), buf);
            //   printf("%s", buf);
            fflush(stdout);

        }
    }
    else{
        while (fgets(buf, 1000, fp) != NULL){
            printf("%d %s",getpid(), buf);
            //  printf("%s", buf);
            fflush(stdout);
        }
    }


//closes text
    fclose(fp);

    return 0;
}


