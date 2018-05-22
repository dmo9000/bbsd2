#include "bbsd.h"

AcceptThread::AcceptThread()
{
    cout << "+++ AcceptThread created" << endl;
}


AcceptThread::~AcceptThread()
{
    cout << "+++ AcceptThread destroyed" << endl;
}


void *AcceptThread::ThreadMainHelper(void *classRef)
{
    cout << "++ AcceptThreadMainHelper()" << endl;
    ((AcceptThread*) classRef)->ThreadMain();
    return NULL;
}

int AcceptThread::ThreadInitiate()
{
    int rc = 0;
    cout << "++ Initiating Thread" << endl;
    rc = pthread_create(&thread, NULL, &ThreadMainHelper, this);
    return 1;
}


void AcceptThread::ThreadMain()
{
    int optval = 1;
    int flags = 0;
    int newsockfd = -1;

    cout << "+++ AcceptThread main thread started" << endl;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    cout << "    sockfd = " << sockfd << endl;

    if (sockfd < 0) {
        cout << "    error opening socket" << endl;
        assert(NULL);
    }

    if (setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&optval,sizeof(int)) == -1) {
        perror("setsockopt") ;
        assert(NULL);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    portno = listen_port;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0) {
        cout << "ERROR on binding" << endl;
        assert(NULL);
    }

    listen(sockfd, CONNECT_BACKLOG);

    flags = fcntl(sockfd, F_GETFL, 0);
    /* fcntl(sockfd, F_SETFL, flags | O_NONBLOCK); */


    while (1) {
        clilen = sizeof cli_addr;
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
        cout << "    accepted new connection on fd " << newsockfd << endl;
        auto NewEchoThread = std::make_unique<EchoThread>();
        /* TCP connections have a single file descriptor, share for read/write */
        NewEchoThread->SetRSockFD(newsockfd);
        NewEchoThread->SetWSockFD(newsockfd);
        NewEchoThread->ThreadInitiate();
    }
}

int AcceptThread::SetListenPort(int port)
{
    cout << "+++ AcceptThread::SetListenPort " << port << endl;
    listen_port = port;
    return 1;
}
