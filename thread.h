#ifndef __THREAD_H__
#define __THREAD_H__
#include "bbsd.h"

class Thread : public Object
{
private:
protected:
	pthread_t thread;
public:
	void (Thread::*ThreadPointer)() = NULL;
	Thread();
	~Thread();
	int ThreadInitiate();
	static void  *ThreadMainHelper(void *classRef);
	void ThreadMain();

};

#endif /* __THREAD_H__ */
