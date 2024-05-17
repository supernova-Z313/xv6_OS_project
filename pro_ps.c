#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

// struct ans_proc {
// 	char P_name[16];
// 	int Pid; // process id
// 	int P_pid; // parent process id
// 	int P_state;
// };

int main(int argc, char *argv[])
{
	int state_t = 2; // 1: SLEEPING, 2: RUNNING, 3: RUNNABLE
	int pid_t = 4;
	struct ans_proc * process_info_t = malloc(sizeof(struct ans_proc));
	// struct proc process_info_t = malloc(sizeof(struct proc));

	printf(0, "\nNote: P_state values is \n 0: UNUSED, 1: EMBRYO, 2: SLEEPING, 3: RUNNABLE, 4: RUNNING, 5: ZOMBIE\n\n");
	printf(0, "\n Simple test:\n");
	printf(0, " Pid | P_name\t | P_pid | P_state \n");

	ps(state_t, pid_t, process_info_t);

	// kernel cant use user space mallocated struct 
	// printf(0, " %d  | %s\t | %d   | %d \n", process_info_t->Pid, process_info_t->P_name, process_info_t->P_pid, process_info_t->P_state);

	state_t = 1;
	pid_t = 5;

	int test_id;
	test_id = fork();
	// test_id = fork();
	if(test_id == 0){
		printf(0, "\nAll process:\n");
		Sps();
		printf(0, "\nPro answer:\n");
		printf(0, " Pid | P_name\t | P_pid | P_state \n");
		ps(state_t, pid_t, process_info_t);
	}
	if(test_id != 0){
		if(wait() < 0){
			printf(0, "wait stopped early\n");
			exit();
		}
	}

	free(&process_info_t);

	exit();
}
