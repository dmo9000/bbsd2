#ifndef __TCPPD_H__
#define __TCPPD_H__
#include <iostream>
#include <memory>
#include <vector>
#include <unistd.h>
#include <pthread.h>
#include <assert.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <fcntl.h>
#include "object.h"
#include "thread.h"
#include "netthread.h"
#include "acceptthread.h"
#include "echothread.h"

using std::cout;
using std::endl;
using std::vector;


#define LISTEN_PORT			8025
#define CONNECT_BACKLOG	32	

int run_toplevel();

#endif /* __TCPPD_H__ */
