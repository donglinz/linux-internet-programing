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
using namespace std;

void func1();
void func2();
void func3();
void msg_show_attr(int msg_id, msqid_ds msg_info);


int main() {
    func3();
    return 0;
}


void func1() { 
    key_t key;
    key = ftok("/home", 'a');
    if(key != -1) printf("success!\n");
    else printf("err!\n");
}

void func2() {
    key_t key = ftok("/home", 'a');
    int msg_id = msgget(key, IPC_CREAT | IPC_EXCL | 0x0666);
    if(msg_id == -1) printf("create message queue fail!\n");
    else printf("success!\n");
}

void func3() {
    int ret = -1;
    int msg_flags, msg_id;
    key_t key;
    struct msgmbuf {
        int mtype;
        char mtext[15];
    };

    msqid_ds msg_info;
    msgmbuf msg_mbuf;
    int msg_sflags, msg_rflags;
    char msgpath[] = "/home/ubuntu/ipc/msg/";
    key = ftok(msgpath, 'a');
    if(key != -1) printf("create key success!\n");
    else printf("create key fail!\n");
    //sleep(100);
    
    msg_flags = IPC_CREAT;
    msg_id = msgget(key, msg_flags);
    if(msg_id == -1) {
        printf("create messege queue fail!\n");
        return;
    } else printf("create messege queue success!\n");

    msg_show_attr(msg_id, msg_info);
    
    msg_sflags = IPC_NOWAIT;
    msg_mbuf.mtype = 10;
    memcpy(msg_mbuf.mtext, "test msg", sizeof("test msg"));
    ret = msgsnd(msg_id, &msg_mbuf, sizeof("test msg"), msg_sflags);
   

   if(ret == -1) {
       printf("send messege fail!\n");
       return ;
   } else printf("send messege success!\n");

   msg_show_attr(msg_id, msg_info);

   msg_rflags = IPC_NOWAIT | MSG_NOERROR;
   ret = msgrcv(msg_id, &msg_mbuf, 10, 10, msg_rflags);
   if(ret == -1) {
       printf("receive messege fail!\n");
       return ;
   } else {
       printf("receive messege success! length is %d\n", ret);
   }
   msg_show_attr(msg_id, msg_info);

   msg_info.msg_perm.uid = 8;
   msg_info.msg_perm.gid = 8;

   msg_info.msg_qbytes = 12345;
   ret = msgctl(msg_id, IPC_SET, &msg_info);
   if(ret == -1) {
       printf("set messege info fail!\n");
       return;
   } else printf("set messege info success!\n");

   msg_show_attr(msg_id, msg_info);

   ret = msgctl(msg_id, IPC_RMID, NULL);
   if(ret == -1) {
       printf("del messege fail!\n");
       return;
   } else printf("del messege success!\n");

   return ;
}

void msg_show_attr(int msg_id, msqid_ds msg_info) {
    int ret = -1;
    sleep(1);
    ret = msgctl(msg_id, IPC_STAT, &msg_info);
    
    if(ret == -1) {
        printf("Get messege fail!\n");
        return;
    } else printf("Get messege success!\n");

    puts("*****************************************");
    cout << msg_info.msg_cbytes << endl;
    cout << msg_info.msg_qnum << endl;
    cout << msg_info.msg_qbytes << endl;
    cout << msg_info.msg_lspid << endl;
    cout << msg_info.msg_lrpid << endl;
    cout << ctime(&msg_info.msg_stime) << endl;
    cout << ctime(&msg_info.msg_rtime) << endl;
    cout << ctime(&msg_info.msg_ctime) << endl;
    cout << msg_info.msg_perm.uid << endl;
    cout << msg_info.msg_perm.gid << endl;
}

