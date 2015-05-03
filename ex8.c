/*
Command: ./ex8.out 
Output:
-	The size of an int: 4
-	The size of an areas(int[]): 20
-	The number ints in areas: 5
-	The first area is 10 and the second area is 12
-	The size of an char: 1
-	The size of name(char[]):4
-	The number of chars:4
-	The size of full_name(char[]):12
-	The number of chars:12
-	name="Zed" and full_name="Zed A. Shaw"
*/
#include <stdio.h>
int main(int argc, const char *argv[])
{
	int areas[]={10,12,13,14,15};
	char name[]="Zed";
	char full_name[]={'Z','e','d',' ','A','.',' ','S','h','a','w','\0'};

	printf("The size of an int: %ld\n",sizeof(int));
	printf("The size of an areas(int[]): %ld\n",sizeof(areas));
	printf("The number ints in areas: %ld\n",sizeof(areas)/sizeof(int));
	printf("The first area is %d and the second area is %d\n",areas[0],areas[1]);
	printf("The size of an char: %ld\n",sizeof(char));
	printf("The size of name(char[]):%ld\n",sizeof(name));
	printf("The number of chars:%ld\n",sizeof(name)/sizeof(char));
	printf("The size of full_name(char[]):%ld\n",sizeof(full_name));
	printf("The number of chars:%ld\n",sizeof(full_name)/sizeof(char));
	printf("name=\"%s\" and full_name=\"%s\"\n",name,full_name);
	return 0;
}
