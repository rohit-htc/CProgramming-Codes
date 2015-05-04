/*
Command: ./ex16.out 
Output:
-	Joe is at memory location 0xfa6010:
-	Name: Joe Alex
-		Age: 32
-		Height: 64
-		Width: 140
-	-----
-	Frank is at memory location 0xfa6050:
-	Name: Frank Alardo
-		Age: 27
-		Height: 53
-		Width: 103
-	-----
-	Name: Joe Alex
-		Age: 52
-		Height: 24
-		Width: 150
-	--
-	Name: Frank Alardo
-		Age: 47
-		Height: 93
-		Width: 93
*/
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
	char *name;
	int age;
	int height;
	int width;
};
struct Person *Person_create(char *name,int age,int height,int width)
{
	struct Person *who = malloc(sizeof(struct Person));
	assert(who != NULL);
	//create a duplicate string having a separete memory
	who->name=strdup(name);
	who->age=age;
	who->height=height;
	who->width=width;
	return who;
}
void Person_destroy(struct Person *who)
{
	assert(who != NULL);
	free(who->name);
	free(who);
}
void Person_print(struct Person *who)
{
	printf("Name: %s\n",who->name);
	printf("\tAge: %d\n",who->age);
	printf("\tHeight: %d\n",who->height);
	printf("\tWidth: %d\n",who->width);
}
int main(int argc, const char *argv[])
{
	struct Person *joe=Person_create("Joe Alex",32,64,140);
	struct Person *frank=Person_create("Frank Alardo",27,53,103);
	//data type to be noticed here
	printf("Joe is at memory location %p:\n",joe);
	Person_print(joe);
	printf("-----\n");
	printf("Frank is at memory location %p:\n",frank);
	Person_print(frank);
	printf("-----\n");

	joe->age += 20;
	joe->height -= 40;
	joe->width += 10;
	Person_print(joe);
	printf("--\n");

	frank->age += 20;
	frank->height += 40;
	frank->width -= 10;
	Person_print(frank);

	Person_destroy(joe);
	Person_destroy(frank);
	return 0;
}
