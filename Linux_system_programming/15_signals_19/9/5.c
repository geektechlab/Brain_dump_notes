#include <stdlib.h>
#include <stdio.h>

#include <signal.h> /*for signal() and raise()*/


int main(){
    kill(-1, SIGKILL);
}
