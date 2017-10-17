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

3.```static storage class```: Static variables are not visible outside its function and they are not destroyed once the funtion or block has comletd its execution.

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
   free(Ptr);  //memory is deallocated and Ptr now becomes a dangling pointer
}
````
After de-allocating memory, initialize pointer to NULL so that pointer will be no longer dangling.Assigning NULL value means pointer is not pointing to any memory location.

### 11.What is called a void pointer and what are the uses of a void pointer?
A void pointer is nothing but a pointer variable declared using the reserved word in C ‘void’.When a pointer variable is declared using keyword void, Address of any variable of any data type (char, int, float etc.)can be assigned to a void pointer variable.
void *temp; /* temp is a void pointer */
To dereference void pointer we need to typecast pointer variable.This is because a void pointer has no data type associated with it.
## Use of Void pointer:
 If the programmer is not sure about the data type of data inputted by the user. In such a case the programmer can use a void pointer to point to the location of the unknown data type.
Important point about void pointer is that ````pointer arithmatic is not performed on void pointers.```` 
### 12.Have you heard of the term  Modular programming is it different from  structure programming if so how ?
No,Modular programming and structured programming are same.Modular programming means the program can be divided into modules to perform a articular task. 
### 13.Let says we have switch()-case statement in C - Can you tell me what is the use of a switch case statement ?
switch()-case in C is used mainly for menu driven programs.a switch statement compares the value of a variable to the values specified in case statements. When a case statement is found whose value matches that of the variable, the code in that case statement is run.If not matches with the variable control goes to default case.
### 14.Can you Look at the following code ............ will the compiler gives an error ? 
````
     main()
     {
        int i ;
        
        switch(i)
        {
           case 1: {
                      break ;
                   }
           case 2: {
                      break ;
                   }
           default : {
                        break ;
                     }
           case 3:   {
                        break ;
                     }
           case 4:   {
                        break ;
                     }     
        }
     }
  ````
No,it will not give any comilation error.
### 15. Do we really need a break statement in *defualt* condition of a switch() - case: statement?
No,we do not require break in default case as we write the default case at last of switch case.But if we write somewhere in switch() like above program compulsary we need break statement in default condition.
### 16.For doing a file operation we need to open the file. What are the checks and things to be done while handling a file ?
1.If we scan a input file,when user enters filename it checks for the entered file exist or not.
2. we have to check for pointer to the file returns a NULL or not.
3.Upon successfull of file oerations we need to close the file using fclose(pointer) function.  

### 17. What is the function call (or API) to open a files can you  explain all the parameters that this API takes and list all possible variations of the parameters of this function.
To open a file fopen() function is used.
FILE *fopen(const char *filename, const char *mode)
````filename```` refers to the name of a data file to be opened.

````mode```` refers to the type of operaton has to be done on the file either read or write etc.

### 18. Have you heard of a term called enumuration ?
Yes,it is a user defined datatype.It is mainly used to assign names to integral constants.
### 19 In fprintf() which prints a string to a file, what happen if the first parameter is replaced with stdout ?
### 20.Have you heard of word recursion, what is it used ? Can you write a small program which uses recursion ?
A function calls the function by itself is called recursion.
````
#include <stdio.h>

int fibonacci(int i)
{
	if(i == 0) 
	{
            return 0;
   	}
	
   if(i == 1)
   {
      return 1;
   }
   return fibonacci(i-1) + fibonacci(i-2);
}

main()
{
   int i;
   
    for (i = 0; i < 10; i++)
    {
        printf("%d\t\n", fibonacci(i));
    }
}
````
### 21. Can you help to understand what are bit wise operators ?
The bitwise operators assume oerands as string of bits and bit operations are done on this operand.
There are 6 operators

Symbol|Operator
----  |----
&     |bitwise AND
\|    |bitwise inclusive OR
^     |bitwise XOR (eXclusive OR)
<<    |left shift
\>>   |right shift
\~    |bitwise NOT (one's complement) (unary)

### 22. While talking to a friend I heard of a term called variable parameters in C what exactly it is  can you explain to me ?
### 23.Can you explain to me with an example how to use command line program with an example ?
### 24. I wrote a big program, but the entry point main() is empty is there any thing wrong with it ?
Yes,If main is empty there no meaning in writing big program.There has to be call to the functions from the main.

### 25.I have heard of a term called structures in C - what is its relation to structured programming
### 26.In a  C function while declaring variables, I had mentioned a keyword *static* will this make any difference ? if so what it is ?
Yes,there is a difference.If we declare the variable as static,the varible will not be destroyed after completion of function execution.
### 27.I am writing a C  program to accuratly calculate the path of a aeroplane flying in the sky, with help of radar signals. What in the data type I need to use to get accurate value ?
### 28. Arrays are easy to use,still we go with Linked list what is the reason for this ? 
### 29. In C function there are two terms, actual parameters and formal parameters. What are they ?
````Actual argumetes```` are the source of information;calling function will pass the actual pameters to the called function.

````Formal Arguments````: these are comma seerated variables which receives the parameters passed by the calling function.these formal arguments are local to that particaular function. 


