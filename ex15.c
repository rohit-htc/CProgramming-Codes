/*
Command: ./ex15.out 
Output:
-	Alan has lived 21 years
-	Frank has lived 24 years
-	Tom has lived 76 years
-	Mark has lived 45 years
-	Lisa has lived 23 years
-	---
-	Alan has lived 21 years
-	Frank has lived 24 years
-	Tom has lived 76 years
-	Mark has lived 45 years
-	Lisa has lived 23 years
-	---
-	Alan has lived 21 years
-	Frank has lived 24 years
-	Tom has lived 76 years
-	Mark has lived 45 years
-	Lisa has lived 23 years
*/
#include <stdio.h>
int main(int argc, const char *argv[])
{
	int ages[]={21,24,76,45,23};
	char *names[]={"Alan","Frank","Tom","Mark","Lisa"};
	int count=sizeof(ages)/sizeof(int);
	int i=0;
	for (i = 0; i < count; i++) {
		printf("%s has lived %d years\n",names[i],ages[i]);
	}
	printf("---\n");

	int *cur_age=ages;
	char **cur_name=names;

	for (i = 0; i < count; i++) {
		printf("%s has lived %d years\n",*(cur_name+i),*(cur_age+i));
	}
	printf("---\n");

	for (cur_name = names,cur_age=ages;(cur_age-ages)<count; cur_name++,cur_age++) {
		printf("%s has lived %d years\n",*cur_name,*cur_age);
	}

	return 0;
}
