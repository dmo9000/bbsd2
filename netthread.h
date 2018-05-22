#ifndef __NETTHREAD_H__
#define __NETTHREAD_H__
#include "bbsd.h"
#include "object.h"

class NetThread : public Thread
{
private:
	/* read/write sockets */
protected:
	int rsockfd = -1;
	int wsockfd = -1;
public:
	NetThread();
	~NetThread();
  int ThreadInitiate();
  static void  *ThreadMainHelper(void *classRef);
	void ThreadMain();

};

#endif /* __NETTHREAD_H__ */
