#include "bbsd.h"

Thread::Thread()
{
    int rc = 0;
    cout << "++ Thread created" << endl;
}

void *Thread::ThreadMainHelper(void *classRef)
{
    cout << "++ ThreadMainHelper()" << endl;
    ((Thread*) classRef)->ThreadMain();
    return NULL;
}

int Thread::ThreadInitiate()
{
    int rc = 0;
    cout << "++ Initiating Thread" << endl;
    rc = pthread_create(&thread, NULL, &ThreadMainHelper, this);
    return 1;
}

Thread::~Thread()
{
    cout << "++ Thread deleted" << endl;
}


void Thread::ThreadMain()
{
    cout << "++ ThreadMain() entered" << endl;
    while (1) {
        cout << "++ ThreadMain() TICK " << endl;
        sleep(1);
    }
    return;
}
