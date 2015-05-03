/*
Command: ./ex14.out testing it
Output:
-	'e' == 101 'x' == 120 'o' == 111 'u' == 117 't' == 116 
-	't' == 116 'e' == 101 's' == 115 't' == 116 'i' == 105 'n' == 110 'g' == 103 
-	'i' == 105 't' == 116 
*/
/*
Command: ./ex14.out rohit anand
Output:
-	'e' == 101 'x' == 120 'o' == 111 'u' == 117 't' == 116 
-	'r' == 114 'o' == 111 'h' == 104 'i' == 105 't' == 116 
-	'a' == 97 'n' == 110 'a' == 97 'n' == 110 'd' == 100 
*/
#include <stdio.h>
#include <ctype.h>

int can_print_it(char ch);
void print_letters(char arg[]);

void print_arguments(int argc,char *argv[]){
	int i=0;
	for (i = 0; i < argc; i++) {
		print_letters(argv[i]);
	}
}

void print_letters(char arg[]){
	int i=0;
	for (i = 0; arg[i] != '\0'; i++) {
		char ch=arg[i];
		if(can_print_it(ch)){
			printf("'%c' == %d ",ch,ch);

		}
	}
	printf("\n");
}
int can_print_it(char ch){
	return isalpha(ch) || isblank(ch);
}
int main(int argc, const char *argv[])
{
	print_arguments(argc,argv);
	return 0;
}
