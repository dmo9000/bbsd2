#include "bbsd.h"


int main(int argc, char *argv[])
{
    struct sigaction new_actn, old_actn;
    cout << "BBSD/2 Started." << endl;
    cout << "Initializing listener socket on port " << LISTEN_PORT << endl;
    cout << "Creating listener thread ..." << endl;

    new_actn.sa_handler = SIG_IGN;
    sigemptyset (&new_actn.sa_mask);
    new_actn.sa_flags = 0;
    sigaction (SIGPIPE, &new_actn, &old_actn);

    run_toplevel();

    printf("EXITING ...\n");

    exit(0);
}


int run_toplevel()
{
    auto ListenerThread = std::make_unique<AcceptThread>();
    ListenerThread->SetListenPort(LISTEN_PORT);
    ListenerThread->ThreadInitiate();

    while (1) {
        sleep(1);
    }
    return 0;
}
