/*
Command: ./ex11.out 
Output:
-	arg 0:./ex11.out
-	sizeof states:32
-	state 0:California
-	state 1:Oregaon
-	state 2:Washington
-	state 3:Texas
*/
#include <stdio.h>
int main(int argc, const char *argv[])
{
	int i=0;
	while(i<argc){
		printf("arg %d:%s\n",i,argv[i]);
		i++;
	}

	char *states[]={
		"California","Oregaon",
		"Washington","Texas"
	};
	printf("sizeof states:%ld\n",sizeof(states));	//32
	int num_states=4;
	i=0;
	while(i<num_states){
		printf("state %d:%s\n",i,states[i]);
		i++;
	}
	return 0;
}
