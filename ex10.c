#include <stdio.h>
int main(int argc, const char *argv[])
{
	int i=0;
	for (i = 1; i < argc; i++) {
		printf("arg %d:%s\n",i,argv[i]);
	}

	char *states[]={
		"California","Oregaon",
		"Washington","Texas"
	};
	printf("sizeof states:%ld\n",sizeof(states));	//32
	int num_states=4;
	for (i = 0; i < num_states; i++) {
		printf("state %d:%s\n",i,states[i]);
	}
	return 0;
}
//	sizeof states:32
//	state 0:California
//	state 1:Oregaon
//	state 2:Washington
//	state 3:Texas
