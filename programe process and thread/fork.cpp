#include <sys/types.h>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    pid_t pid = fork();

    if(pid == -1) {
        printf("err!\n");
        return -1;
    } else if(pid == 0) {
        printf("son, fork return: %d, ID : %d, father process %d\n", pid, getpid(), getppid());
    } else {
        printf("fa, fork return %d, ID : %d, father process %d\n", pid, getpid(), getppid());
    }

    return 0;
}
