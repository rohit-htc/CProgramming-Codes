/*
Command: ./ex20.out test
Output:
-	DEBUG ex20.c,8: I have brown hair
-	DEBUG ex20.c,9: I am 24 years old
-	[WARN] (ex20.c:19: errno: None) You can safely ignore this
-	[WARN] (ex20.c:20: errno: None) May be consider looking at you console
-	[ERROR] (ex20.c:13: errno: None) I believe everything is broken
-	[ERROR] (ex20.c:14: errno: None) There are 0 problems in space
-	[INFO] (ex20.c:24: errno: None) Testing log info here
-	[INFO] (ex20.c:25: errno: None) It happened 1.300000 times here
-	[ERROR] (ex20.c:36: errno: No such file or directory) Failed to open test
-	[INFO] (ex20.c:53: errno: None) It worked
-	[ERROR] (ex20.c:95: errno: None) test_sentinel failed
*/
/*
Command: ./ex20.out 
Output:
-	[ERROR] (ex20.c:88: errno: None) Need an argument
*/
#include "dbg.h"
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

void test_debug()
{
	debug("I have brown hair");
	debug("I am %d years old",24);
}
void test_log_err()
{
	log_err("I believe everything is broken");
	log_err("There are %d problems in %s",0,"space");

}
void test_log_warn()
{
	log_warn("You can safely ignore this");
	log_warn("May be consider looking at you %s","console");
}
void test_log_info()
{
	log_info("Testing log info here");
	log_info("It happened %f times here",1.3f);
}
int test_check(char *filename)
{
	FILE *input=NULL;
	char *block=NULL;

	block=malloc(100);
	check_mem(block);

	input=fopen(filename,"r");
	check(input,"Failed to open %s",filename);

	free(block);
	fclose(input);
	return 0;
error:
	if(block) free(block);
	if(input) fclose(input);
	return -1;
}

int test_sentinel(int code)
{
	char *temp=malloc(100);
	check_mem(temp);
	switch(code){
		case 1:
			log_info("It worked");
			break;
		default:
			sentinel("I shouldn't run");

	}
	free(temp);
	return 0;
error:
	if(temp) free(temp);
	return -1;
	
}

int test_check_mem()
{
	char *test=NULL;
	check_mem(test);

	free(test);
	return 1;
error:
	return -1;
}

int test_check_debug()
{
	int i=0;
	check_debug(i != 0,"Oops, i was 0.");
	return 0;
error:
	return -1;
}
int main(int argc, char *argv[])
{
	check(argc==2, "Need an argument");
	test_debug();
	test_log_warn();
	test_log_err();
	test_log_info();
	check(test_check("ex20.c")==0,"failed with ex20.c");
	check(test_check(argv[1])==-1, "failed with argv");
	check(test_sentinel(1)==-1, "test_sentinel failed");
	check(test_sentinel(100)==-1, "test_sentinel failed");
	check(test_check_mem()==-1,"test_check_mem failed")
	check(test_check_debug()==-1,"test_check_debug failed")


	return 0;
error:
	return 1;
}
