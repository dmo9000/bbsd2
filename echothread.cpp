#include "bbsd.h"


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
    int wr = 0;
    int st = 0;
    cout << "+++ EchoThread main thread started" << endl;
    while (1) {
        cout << "+++ EchoThread TICK (" << rsockfd << "," << wsockfd << ")" << endl;
        st = fcntl(wsockfd, F_GETFD);
        cout << "+++ Socket status = " << st << endl;
        wr = write(wsockfd, "ECHO\n", 5);
        if (wr != 5) {
            cout << "+++ WRITE FAILURE, ERRNO = " << errno << ":" << strerror(errno) << endl;
            switch(errno) {
                case 32:
                    cout << "+++ PIPE WAS BROKEN!" << endl;
                    pthread_cancel(thread);
                    /* TODO: mark for cleanup? */
                    break;
                default:
                    cout << "+++ UNHANDLED ERRNO CODE, ABORTING" << endl;
                    assert(NULL);
                    break;
                }


        }
        sleep(1);
    }
    printf("ECHOTHREAD, TERMINATING!!\n");

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




