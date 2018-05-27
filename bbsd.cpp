#include "bbsd.h"


int main(int argc, char *argv[])
{
    cout << "BBSD/2 Started." << endl;
    cout << "Initializing listener socket on port " << LISTEN_PORT << endl;
    cout << "Creating listener thread ..." << endl;

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
