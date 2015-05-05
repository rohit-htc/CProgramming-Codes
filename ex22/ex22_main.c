/*
 Compile:
	cc -Wall -g -c -o ex22.o ex22.c
	 cc -Wall -g ex22_main.c ex22.o -o ex22_main.out
 *
 */
/*
Command: ./ex22_main.out 
Output:
-	[INFO] (ex22_main.c:18: errno: None) My name: Rohit Anand, age: 37
-	[INFO] (ex22_main.c:20: errno: None) My age is now: 24
-	[INFO] (ex22_main.c:22: errno: None) The Size is: 1000
-	[INFO] (ex22.c:25: errno: None) I think size is: 1000
-	[INFO] (ex22_main.c:26: errno: None) The Size is now: 9
-	[INFO] (ex22.c:25: errno: None) I think size is: 9
-	[INFO] (ex22_main.c:29: errno: None) Ratio at first: 1.000000
-	[INFO] (ex22_main.c:30: errno: None) Ratio again: 2.000000
-	[INFO] (ex22_main.c:31: errno: None) Ratio once more: 10.000000
-	[INFO] (ex22_main.c:6: errno: None) Count is: 4
-	[INFO] (ex22_main.c:12: errno: None)  Count is at exit: 4
-	[INFO] (ex22_main.c:14: errno: None) Count after assign: 3000
-	[INFO] (ex22_main.c:6: errno: None) Count is: 80
-	[INFO] (ex22_main.c:9: errno: None) Count in this scope is: 100
-	[INFO] (ex22_main.c:12: errno: None)  Count is at exit: 80
-	[INFO] (ex22_main.c:14: errno: None) Count after assign: 3000
-	[INFO] (ex22_main.c:37: errno: None) Count after calling scope_demo: 4
*/
#include "ex22.h"
#include "dbg.h"
const char *MY_NAME="Rohit Anand";
void scope_demo(int count)
{
	log_info("Count is: %d",count);
	if(count>10){
		int count=100;
		log_info("Count in this scope is: %d",count);

	}
	log_info(" Count is at exit: %d",count);
	count=3000;
	log_info("Count after assign: %d",count);
}
int main(int argc, const char *argv[])
{
	log_info("My name: %s, age: %d",MY_NAME,get_age());
	set_age(24);
	log_info("My age is now: %d",get_age());

	log_info("The Size is: %d",THE_SIZE);
	print_size();

	THE_SIZE=9;
	log_info("The Size is now: %d",THE_SIZE);
	print_size();

	log_info("Ratio at first: %f",update_ratio(2.0));
	log_info("Ratio again: %f",update_ratio(10.0));
	log_info("Ratio once more: %f",update_ratio(300.0));

	int count=4;
	scope_demo(count);
	scope_demo(count*20);

	log_info("Count after calling scope_demo: %d",count);
	return 0;

	return 0;
}
