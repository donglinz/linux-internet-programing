#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/sem.h>

using namespace std;
typedef int sem_t;
union semun {
    int val;
    semid_ds *buf;
    unsigned short *array;
} arg;
sem_t CreateSem(key_t key, int value);

int main() {
    key_t key = ftok("/home/ubuntu/ipc/msg/", 1);
    if(key == -1) printf("err!\n");
    sem_t semid = CreateSem(key, 0);
    printf("%d\n", semid);
    return 0;
}

sem_t CreateSem(key_t key, int value) {
    union semun sem;
    sem_t semid;
    sem.val = value;

    semid = semget(key, 0, IPC_CREAT);
    if(semid == -1) {
        printf("create semaphore fail!\n");
        return semid;
    } else {
        printf("create semaphore sussess!\n");
    }
    
    semctl(semid, 0, SETVAL, sem);
    return semid;
}

