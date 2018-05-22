#include "bbsd.h"

extern vector<NetThread*> NetworkThreads;

EchoThread::EchoThread()
{
    cout << "+++ EchoThread created" << endl;
}


EchoThread::~EchoThread()
{
    cout << "+++ EchoThread destroyed" << endl;
}


void *EchoThread::ThreadMainHelper(void *classRef)
{
    cout << "++ EchoThreadMainHelper()" << endl;
    ((EchoThread*) classRef)->ThreadMain();
    return NULL;
}

int EchoThread::ThreadInitiate()
{
    int rc = 0;
    cout << "++ Initiating Thread" << endl;
    rc = pthread_create(&thread, NULL, &ThreadMainHelper, this);
    return 1;
}


void EchoThread::ThreadMain()
{
    cout << "+++ EchoThread main thread started" << endl;
    while (1) {
        cout << "+++ EchoThread TICK (" << rsockfd << "," << wsockfd << ")" << endl;
        sleep(1);
    }

}


int EchoThread::SetRSockFD(int fd)
{
    cout << "+++ EchoThread::SetRsockFD = " << fd << endl;
    rsockfd = fd;
    return 1;
}

int EchoThread::SetWSockFD(int fd)
{
    cout << "+++ EchoThread::SetRsockFD = " << fd << endl;
    wsockfd = fd;
    return 1;
}




