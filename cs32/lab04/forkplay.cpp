#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main() {
    void showIDs(int, string);

    int childPid = fork();

    if (childPid == 0) {
        showIDs(childPid, string("I am the child"));
    }
    else if (childPid > 0) {
	waitpid(childPid,0 , 0);
        sleep(10);
        showIDs(childPid, string("I am the parent"));
	execl("/bin/ps", "ps", "-l", (char*)0);
    }
    else
        cout << "fork was not successful" << endl;

    return 0;
}

void showIDs(int childPid, string msg) {
    cout << msg << " (pid=" << getpid()
         << ", ppid=" << getppid()
	 << ", child=" << childPid << ")" << endl;
}
