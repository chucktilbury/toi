# toi
Implementation of the Toy Object Interpreter.

This repo is the latest encarnation of the TOI programming language. The general features of TOI are:
1. As simple as possible, but still general purpose.
1. There is exactly one way to do things.
1. Whitespace is totally ignored. (take that Python) You can create an entire program without using any whitespace.
1. The language is very simple, but libraries are supported, including operator and method overloading.
1. Multiple inheritance is supported, similar to the way Python does it. Adding a additional definition for a class adds/overloads the existing one.
1. There is no notion of a global variable. There is no notion of a function defined outside of a class.
1. Singletons are not supported.

## overall structure
The implementation loads the whole program before tring to run anything. During the load phase, the presence and access of symbols is checked and when the data structure for the program is returned, all syntax and symantic checking that can be done without actually running the program has been completed. This is done to completely separate the front end and the back end. Eventually, I would like to use the LLVM infrastrucutre to actually run a program. 

Comments are defined as starting with a "#" and ending with a "#". Newlines are irrelavent. 

There are two classes that must be defined. Start and End. The End class has a default implementation that destroys all of the objects that have been created in the program. The Start class's constructor is the program entry point. No default implementation is defined for this class.

Method parameters include input and output variables. A method definition looks like this:
```cpp
method_defintion(num:var1, string:str)(bool:retv) {
  ...
}
```
The first tuple are input parameters. They are passed by value. The second tuple are output parameters. They are passed by reference. Zero or more items are required in a tuple. For example if the output parameter tuple is empty the the method returns nothing. Assigning to an output parameter changes the value of the parameter in the outer scope. Assigning to an input parameter is a syntax error. Input and output parameters must be referenced by the method implementation or a syntax error is issued.

The class constructors and destructors are named "create" and "destroy". They must have an implementation, but that implementation can be blank. Class definitions look like this:
```cpp
ClassName(SomeOtherClass) {
   create()(){}
   destroy()(){}
}
```
The default scope in a class is "public", but "private" and "protected" are supported as well. The output parameters of the create method must be blank. The destroy must be called explicitly to destroy the class unless it is collected by the garbage collector. The garbage collector calls the destroy method and if it has already been called, it is automatically skipped. Variables can be defined anywhere in the class definition. The tuple following the class name contains zero or more names of other classes to inherit from.

Local variables, including method parameters must be referenced for the program to build. All local variables must be assigned a value when they are defined. Locals that are defined in a {} block are scoped local to that block. For example:
```cpp
some_method()() {
    num:var1 = 0;
    num:var2 = 1;
    {
        # var2 here, is a totally different symbol #
        # a warning is issued for the duplicate name #
        num:var2 = 0;
        # var1 is visible here #
    }
    #  var2 still has the value 1 here #
}
```

Garbage collection is performed by reference counting and is performed automatically.

Importing other files is supported. Imports are global. They are loaded exactly once. All class definitions from an import exist in the root scope. For a class to be importable, it must have an export statement in the file where it is defined. Otherwise, it is considered to be local to the file in which it is defined. Internally, there is a notion of an import path which works similar to Python. It can be modified at runtime and all modifications are global in scope. Import statements must exist outside of any class definition. The actual import statement uses the file name to be imported. An import statement looks like this:
```python
import(filename);
```
There are 3 native types. These types are implemented as built-in classes and my be overridden. When a native type is defined an object for it is created. All of the native types have a ".to_x" method to convert them to the other native types if possible. Note that literals are not objects. The native types:
1. bool. A bool is just as the name implies. True or false. Boolean expressions are implemented using builtin functions. Any native type is acepted by a boolean expression, but comparing different types is naturally false.
    1. eq(p1, p2)  -- returns true if p1 is equal to p2. 
    1. neq(p1, p2) -- returns true if p1 is not equal to p2. 
    1. le(p1, p2)  -- returns true if p1 is less or equal to p2.
    1. ge(p1, p2)  -- returns true if p1 is greater or equal to p2.
    1. not(p1)     -- returns true if p1 is false.
    1. or(p1, p2)  -- returns true of p1 or p2 are true.
    1. and(p1, p2) -- returns true if p1 and p2 are true.
    Example
```cpp
    if(not(eq(1,2))) { # do this # }
```
1. string. A string is a series of characters. The physical format (i.e. whether there is a 0 at the end) is irrelavent. Strings are formatted and concatinated using the "+" operator, which calls the ".to_string" to convert the object, if needed.
1. num. Numbers are prepresented as doubles internally. All of the usual operators apply. There are no built-in methods such as ".cos" or whatever.

## Implementation plan
The language is implemented in stages. Stages are completed when the functionality is implemented with unit and functional tests.

### Stage 1
- The program loader. This is a subset of the syntax that does not have any user defined types such as classes. A very simple runtime is implemented that can run a simple "hello world" program with just one function call.
- Variables can only be defined inside of a method. 
- The first method encountered is the entry point.
- A dumper for loaded programs.
### Stage 2
- Allow functions to call other functions. Connect up input and output parameters.
- Require the Start function to be defined.
- Execute the default End function.
### Stage 3
- Implement a partial version of the import functionality that has the ability to import files, but not search for them.
- Duplicate Start functions is an error.
### Stage 4
- Implement a simple user defined type of strut that has no runnable components. Implement the "." operator.
### Stage 5
- Complete the import functionality.
### Stage 6
- Implement the basic class functionality without inheritance. This will involve changing the parser so that it no longer accepts method definitions outside of a class. Same with vars where vars can now be defined outside of a method, but inside a class.
### Stage 7
- Implement inheritance.
### Stage 8
- Implement garbage collection hooks. Note that most of the functionality for garbage collection is located in the runtime.
### Stage 9
- Replace basic runtime with a real one, such as LLVM.
### Stage 10 
- Finish garbage collection.
- Implement native compilation using LLVM.
### Stage 11
- Implement a debugger, preferably using TOI.
### Stage 12
- Implement an IDE, preferably using TOI.

