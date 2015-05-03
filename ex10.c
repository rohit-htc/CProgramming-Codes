/*
Command: ./ex10.out I Love You
Output:
-	arg 1:I
-	arg 2:Love
-	arg 3:You
-	sizeof states:32
-	state 0:California
-	state 1:Oregaon
-	state 2:Washington
-	state 3:Texas
-	state 4:
*/
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

