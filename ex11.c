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

//	arg 0:./ex11.out
//	arg 1:I
//	arg 2:am
//	arg 3:a
//	arg 4:bunch
//	arg 5:of
//	arg 6:arguments
//	sizeof states:32
//	state 0:California
//	state 1:Oregaon
//	state 2:Washington
//	state 3:Texas
