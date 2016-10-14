#include <sys/types.h>
#include <unistd.h>
#include <cstdio>


using namespace std;

int main() {
    pid_t pid, ppid;
    pid = getpid();
    ppid = getppid();

    printf("pid of current process is %d\n pid of father process is %d\n", pid, ppid);
    return 0;
}
