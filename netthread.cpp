#include "bbsd.h"

NetThread::NetThread()
{
    cout << "+++ NetThread created" << endl;
}


NetThread::~NetThread()
{
    cout << "+++ NetThread destroyed" << endl;
}


void *NetThread::ThreadMainHelper(void *classRef)
{
    cout << "++ NetThreadMainHelper()" << endl;
    ((NetThread*) classRef)->ThreadMain();
    return NULL;
}

int NetThread::ThreadInitiate()
{
    int rc = 0;
    cout << "++ Initiating Thread" << endl;
    rc = pthread_create(&thread, NULL, &ThreadMainHelper, this);
    return 1;
}


void NetThread::ThreadMain()
{
    cout << "+++ NetThread main thread started" << endl;
    while (1) {
        cout << "+++ NetThread TICK" << endl;
        sleep(1);
    }

}
