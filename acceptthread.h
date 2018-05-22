#ifndef __ACCEPTTHREAD_H__
#define __ACCEPTTHREAD_H__
#include "bbsd.h"

class AcceptThread : public NetThread
{
private:
	int listen_port = -1;
	int sockfd = -1;
	struct sockaddr_in serv_addr, cli_addr;
	socklen_t clilen = 0;
	int portno = -1;
		
protected:

public:
	AcceptThread();
	~AcceptThread();
  int ThreadInitiate();
  static void  *ThreadMainHelper(void *classRef);
	void ThreadMain();
	int SetListenPort(int port);

};

#endif /* __ACCEPTTHREAD_H__ */
