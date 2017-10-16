# Part one

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

2.```extern storage class```: When extern storage specifier is used with a variable declaration then no storage is allocated to that variable and it is assumed that the variable has already been defined elsewhere in the program.

3.```static storage class```: Static variables are not visible outside its function and they are not destroyed once the funtion or block has finished its execution.

4.```register storage class```: The variables declared with register specifier are allocated memory in the CPU register instaed of RAM.This means the variable has the maximum size equal to the size of the register.
#include<stdio.h>
```main()
{
	register int x; // the variable belongs to register storahe class
	float y;
	
	x=10;
	y=1.414;
	
	printf("the address of x is:%d\n",x);
	printf("the address of y is:%f\n",y);
	
	printf("the address of x is:%x\n",&x);// Compilation Error because the variable x is allocated in the register
}```
