#ifndef __ECHOTHREAD_H__
#define __ECHOTHREAD_H__
#include "bbsd.h"

class EchoThread : public NetThread
{
private:
protected:
public:
	EchoThread();
	~EchoThread();
  int ThreadInitiate();
  static void  *ThreadMainHelper(void *classRef);
	void ThreadMain();
	int SetRSockFD(int fd);
	int SetWSockFD(int fd);
};

#endif /* __ECHOTHREAD_H__ */
