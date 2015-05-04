/*
Command: ./ex18.out 7 6 5 4 8 6 43
Output:
-	45667843
-	43876654
-	76584643
*/
/*
Command: ./ex18.out 23 45 0 3 5 45
Output:
-	035234545
-	454523530
-	234504535
*/
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
void die(const char *message)
{
	if (errno) {
		perror(message);
	}
	else {
		printf("Error: %s\n",message);
	}
	exit(1);
}
typedef int (*compare_cb)(int a, int b);

int *bubble_sort(int *numbers,int count,compare_cb cmp)
{
	int temp=0;
	int i=0;
	int j=0;
	int *target = malloc(count* sizeof(int));
	if(!target) die("Memory Error");

	//copy the passed numbers
	memcpy(target,numbers,count*sizeof(int));
	for (i = 0; i < count; i++) {
		for (j = 0; j < count-1; j++) {
			if (cmp(target[j],target[j+1])>0) {
				temp=target[j+1];
				target[j+1]=target[j];
				target[j]=temp;
			}
		}
	}
	return target;
}

int sorted_order(int a, int b)
{
	return a-b;
}

int reverse_order(int a,int b)
{
	return b-a;
}
int strange_order(int a,int b)
{
	if (a==0 || b==0) {
		return 0;
	}
	else {
		return a%b;
	}
}
void test_sorting(int *numbers,int count, compare_cb cmp)
{
	int i=0;
	int *sorted=bubble_sort(numbers,count,cmp);

	if(!sorted) die("failed to sort as requested");
	for (i = 0; i < count; i++) {
		printf("%d",sorted[i]);
	}
	printf("\n");
	free(sorted);
}
int main(int argc, char *argv[])
{
	if(argc<2) die("Usage: ./ex18.out 4 3 5 1 2");
	int count=argc-1;
	int i=0;
	char **inputs=argv+1;
	int *numbers=malloc(count*sizeof(int));
	if(!numbers) die("Memory Error");

	for (i = 0; i < count; i++) {
		numbers[i]=atoi(inputs[i]);
	}
	test_sorting(numbers,count,sorted_order);
	test_sorting(numbers,count,reverse_order);
	test_sorting(numbers,count,strange_order);

	free(numbers);
	return 0;
}
