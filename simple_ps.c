#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(void)
{
	int test_id;
	test_id = fork();
	if(test_id == 0){
		Sps();
	}
	if(test_id != 0){
		if(wait() < 0){
			printf(0, "wait stopped early\n");
			exit();
		}
	}
	exit();
}
