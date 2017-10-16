# Part One

### 1.When we talk about variables there is a term called "Scope of a Variable" what is it can you explain to me ?
A scope is a region of program.Scope of a Variable is a region of program where a defined variable can have its existance and beyond that the variable cannot be accessed.

There are two types of variales:

1.Local Variable: These variable have their existance within the function or block where it has declared and it destoys when function execution is comleted.

2.Global Variable: These variables are declared at the to of main(),and they have their existance throughout the life of the program.

### 2.We have to terms related to variables, Declaration and Defintion what are they, explain with an example?
1.Declaring a variable is to tell the compiler what  data tye the variale belongs to and size of that variable.No memeory space is reserved during declaration. However compiler knows how much space to reserve in case a variable of this type is created.

Ex: int x;// x is an integer

float y;//y is a float 

2.Definition of a variable means the memory is allocated for the declared variable and some initial value is assigned.

Ex: x=0;//allocates memory of 2 bytes and the value 0 is assigned to x

y=10;//allocates memory of 4 bytes and the value 10 is assigned to x

### 3.What is you mean by declaring an array ? How is array different from a normal variable declaration?
A variable occupies one memory location ,but many times we need to strore set of values of the same type.For examle,we may need to strore the marks of 100 students.In this case it is very difficlt to define 100 variables to store the marks of each strudent.
In such a situation,it is better to have a single variable that can store all the values with an index,which is calld an array which store the values in a conscutive memory locations.
Declaring an Array means to tell the comiler the type and the size of array(howmany data elements it need to strore)
### 4.When an array is declared where is array created ?
when an array is declared it is created on to the stack.
### 5.What are the different types of Storate Class specifiers in C ? - List all of them When and how they should be used?
A storage class defines the scope (visibility) and life time of variables and/or functions within a C Program.

1.```auto storage class```: The auto storage class is the default storage class for all local variables.

2.```extern storage class```: The extern storage class is used to give a reference of a global variable that is visible to all the program files. When you use 'extern', the variable cannot be initialized however, it points the variable name at a storage location that has been previously defined.When we have multiple files and we define a global variable or function, which will also be used in other files, then extern will be used in another file to provide the reference of defined variable or function

3.```static storage class```:  the global variable by default a static variables utit is restricted to only that file.Static variables are not visible outside its function and they are not destroyed once the funtion or block has comletd its execution.

##Example1: this program explains static variable will not be destroyed after comletion of the block of code.
````
#include<stdio.h>
main()
{
	int count;
	count=3;
	
     /*block of code the static variable has its existance*/
	while(count!=0)
	{
		static int x=10;// x is a static variable
		int y=10;
		printf("x is=%d\n",x++);
		printf("y is=%d\n",y++);
		count--;
	}	
}
output:
x is 10
y is 10
x is 11
y is 10
x is 12
y is 10
````
##Example2: this program exlains that the static variable will not be visible to outside function but not be destroyed when native function comletes its exection.

````
#include<stdio.h>
void printX()
{
	static int x=10; // static variable  dclaration
	x++;
	printf("static x  = %d\n",x);
}
void printY()
{
	int x;
	x=15;
	x++;
	printf("x = %d\n",x);
}
main()
{
	int count;
	count=3;	
	while(count!=0)
	{
		printX();
		count--;
	}
	count=3;
	while(count!=0)
	{
		printY();
		count--;
	}	
}

output:

static x = 11
static x = 12
static x = 13
x =16
x =16
x =16
````

4.```register storage class```: The variables declared with register specifier are allocated memory in the CPU register instaed of RAM.This means the variable has the maximum size equal to the size of the register.The register should only be used for variables that require quick access.
````
#include<stdio.h>
main()
{
	register int x; // the variable belongs to register storage class
	float y;
	
	x=10;
	y=1.414;
	
	printf("the address of x is:%d\n",x);
	printf("the address of y is:%f\n",y);
	
	printf("the address of x is:%x\n",&x);// Compilation Error because the variable x is allocated in the register
}
````
### 6.I have doubt - can you tell me when I should use while() loop and do while() loop ? I really do not under stand the difference betweeb these two, can you explain to me ?
while(): this loop is executes statements untill the condition of the while loop evaluates TRUE.the loop gets terminated when condion becomes FALSE.
do while():If we want to execute the loop body at least once then do while loop is used.It executs the statement secified in the loop body first,and then evaluates the condition.Do while loop executes untill the condition is TRUE.if the condition is FALSE, the loop will be terminated.

### 7.Recently while going through a C program I saw two functions malloc() & calloc() can you tell me what are they used for ?
malloc(): This function is used to allocate the block of memory for the variables from the heap(which is not usd by the a program).It returns a pointer to a block of memory of the secifies size.
It takes the integer as the parameter that secifis th number of bytes to be allocated.
calloc():this function is used for both ,to allocate block of memory and initializes them to 0.
syntax:
ptr=(cast-type*)calloc(n,element-size)
it allocates memory for n blocks in bytes where each block is of the size specified by element-size.

### 8.Can you explain to me with the help of a small program how malloc() is used ?
The below program exlains how to use malloc function:
````
#include<stdio.h>
#include<malloc.h>
main()
{
	int *Ptr;
	int count=2;
	while(count!=0)
	{
		Ptr=(int*)malloc(sizeof(int));	//returns reference to the block of memory of the secified size 
		printf("the ptr is:%x\n",Ptr);
		count--;
	}
	free(Ptr);
}
````
### 9.I keep hearing the term Pointers in C, what is it all about ? Have you used it any time ?
Pointer is a variable which holds the address of another variable stored elsewhere in comuter memory.To declare a pointer * symbol is preended to the variable;
syntax:
int *ptr; // declares a pointer variale ptr of integer data type
float *temp; // declares a pointer variale temp of float data type

Yes, I have used pointer with functions to return multiple values,point to allocate memory at runtime and also used with data structures.

### 10.I had heard of a term called dangling pointer Can you help me to understand what exactly is a dangling pointer?
Dangling pointers arise when an object is deleted or de-allocated, without modifying the value of the pointer, so that the pointer still points to the memory location of the de-allocated memory.
In short pointer pointing to non-existing memory location is called  dangling pointer.
##Example:
````
#include<stdio.h>
#include<malloc.h>

main()
{
   int *Ptr;
   Ptr=(int*)malloc(sizeof(int));
   printf("the ptr is:%x\n",Ptr);
   free(Ptr);  //Ptr now becomes a dangling pointer
}
````


