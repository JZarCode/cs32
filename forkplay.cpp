// Joel Zarley, Sagar Saija,
// May 2, 2014
#include <sys/wait.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

int main() {
    void showIDs(int, string);

    int pid = fork();
    if(pid > 0 ){
        showIDs(pid, string("I am the PARENT"));
    }
    else if(pid == 0){
      showIDs(pid, string("I am the CHILD"));
    }
    else{
        cout << "fork was not successful" << endl;
    }
    return 0;
}

void showIDs(int childPid, string msg) {
    cout << msg << " (pid=" << getpid()
         << ", ppid=" << getppid()
	 << ", child=" << childPid << ")" << endl;
}
