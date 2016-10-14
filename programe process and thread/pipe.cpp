#include <unistd.h>
#include <cstdio>
#include <sys/types.h>
#include <cstring>
using namespace std;

int main() {

    int ok = -1;
    int fd[2];
    int *write_fd = &fd[1];
    int *read_fd = &fd[0];
    
    char str[] = "hello pipe!";
    char strbuffer[100];
    char strbuffer2[100];
    ok = pipe(fd);

    if(ok == -1) {

        printf("err!\n");
        return -1;
    }

    pid_t pid = fork();

    if(pid == -1) {
        printf("fork err!\n");
        return -1;
    }

    if(pid == 0) { //son
        //close(*read_fd);
        write(*write_fd, str, strlen(str));
        read(*read_fd, strbuffer2, sizeof strbuffer);
        printf("son! %s\n", strbuffer2);
    } else {
        close(*write_fd);
        read(*read_fd, strbuffer, sizeof strbuffer);
        printf("fa! %s\n", strbuffer2);
    }


    

    return 0;
}
