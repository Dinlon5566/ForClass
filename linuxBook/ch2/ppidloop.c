#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
	for(;;){
		getppid();
	}
	return 0;
}