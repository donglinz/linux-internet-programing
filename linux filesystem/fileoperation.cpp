#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <iostream>
#include <cstdio>
#include <unistd.h>
using namespace std;
const int MAXN = 1010;
char buf[MAXN];
int main() {
    int size = 1;
    int fd = open("a", O_RDONLY);
    printf("%d~~~\n", lseek(fd, 0, SEEK_CUR));
    while(size) {
        size = read(fd, buf, 1000);
        if(size == 0) {
            printf("end\n");
        }
        if(size == -1) {
            printf("err\n");

        }
        write(1, buf, size);
        printf("%d~~\n", lseek(1, 0, SEEK_CUR));
    }
    printf("%d~~~\n", lseek(fd, 0, SEEK_CUR));
    close(fd);
            
    return 0;
}
