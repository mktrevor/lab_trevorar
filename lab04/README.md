# Lab 04: Templates, Exceptions, and Operators

### Design Document
There is no design writeup due with this lab.

### Grading
This assignment is worth 10 points.

This lab assignment must be demonstrated to a TA or Course Producer (CP).

### General Information
Review the lecture notes on templates, exceptions, and operator overloading.

The `MyList` class you create in this lab will be used as part of your first programming assignment (in fact you will be doing one of your milestones for that assignment in this lab). You will be modifying your current dynamic array list class (the one you used in Lab 03) and converting it to a template class.

### Prepare Your Private Repository
Assuming that you cloned your private repository into your `$HOME` directory and your list code in Lab 03 was in `List.h`, follow the following instructions to prepare for this lab:
```shell
#Change directory to your home directory
cd

#Change directory to your private lab repository
#   replace usc-username with your USCNet username
cd lab_usc-username

#Make a directory for lab04
mkdir lab04

#Copy lab03's List to lab04 (rename the copy to be mylist.h)
#   Change the file name in the command if you used a filename other than List.h
cp lab03/List.h lab04/mylist.h

#Now, we commit the initial state of lab04
git add lab04
git commit -m "Lab04 initial commit using the list class from lab03 as a starting point"

#Push the initial state to the server
git push

#Change directory to lab04 and start working on the lab
cd lab04
```

## Part 1 (4 points)
Create a templated version of your dynamic array based list class in `mylist.h`. Edit your `mylist.h` file.  Change the name of the class to `MyList` and update that name wherever appropriate in this file.  Modify the appropriate member data and function arguments and return values to use the template type.  Now open your old `List.cpp` from lab03 and copy and paste the function implementations from your old `List.cpp` to `mylist.h` below the class declaration. (recall that a templated class requires declaration and function bodies to all be in the header file) and modify them to use the template type appropriately.

Write a simple program in a separate file (`part1.cpp`) that has a `main()` function.  Include your list header file (`mylist.h`).  In `main()`, instantiate two of your templated list objects:  one object should be a list of `int`'s while the other should be a list of `string`'s.  Perform a few `push_back` and other member function calls on each of the lists to ensure your code works.

Demonstrate to your TA/CP that your templated class is working.

### Commandline Hints

+ To create an empty file from the commandline:

```shell
#Create an empty file called part1.cpp
touch part1.cpp
```
+ To edit a file from the commandline using emacs ([cheat](http://refcards.com/docs/gildeas/gnu-emacs/emacs-refcard-a4.pdf) [sheet](https://ccrma.stanford.edu/guides/package/emacs/emacs.html)) or gedit:

```shell
#The '&' at the end sends the process in the background so you have your commandline back
emacs part1.cpp &
#or
gedit part1.cpp &
```

+ To commit changes you made to both `part1.cpp` and `mylist.h`

```shell
#Check the status of the repository
git status

#Add changes
git add part1.cpp mylist.h

#Commit changes '-m' adds a message. If you don't use '-m' an editor will automatically open for you to enter a message
git commit -m "added test cases for integer push_back"

#Push the changes to the server
git push

#Check the status of the repository again
git status
```


## Part 2 (4 points)
Add the following member functions to your `MyList<T>` class:
```C++
bool remove(T val);    // If "val" occurs in the list, remove the first
                       // occurrence of "val" and return true. Return false
                       // otherwise

int pop(int loc);      // return the value at index "loc"
```

Add code to your `MyList<T>` class such that it will throw appropriate `invalid_argument` exceptions for any function that might have an invalid argument. Tell your TA/CP which functions those are and add the appropriate code to throw an `invalid_argument` exception.

Copy your `part1.cpp` file to `part2.cpp` and modify/add code to exercise `remove()` and `pop()` to ensure they work in non-exception cases. Compile and run your program.

Next add `try`/`catch` blocks around calls to the functions that may generate an exception and purposefully pass invalid arguments. Catch the exceptions and print an appropriate error message.

Demonstrate your part2 program to your TA/CP.

### Commandline Hints
  + To copy `part1.cpp` to a new file named `part2.cpp` in the same directory:

```shell
#Copy syntax is: cp SRC_FILE DEST_FILE
cp part1.cpp part2.cpp

#Check the contents of the directory
ls -l
```


## Part 3 (2 points)
Add an `operator[]` member function to your `MyList<T>` class which performs the same operation as the `at()` function.  

Copy your `part1.cpp` to `part3.cpp`.  Add code to exercise the `[]` operator for retrieving a value at a particular index/location (i.e. `int x = my_list[1];`).

Compile and run your part3 program and ensure it works.

In a normal C/C++ array you can modify the element at a particular location by writing a line of code similar to the 3rd line below:
```C++
MyList<int> my_list; 
my_list.push_back(99);
my_list[0] = 5; // replaces 99 with 5.
cout << my_list[0] << endl;
```

Try to perform a similar set of instructions in your `part3.cpp` where the `operator[]` appears on the _left-hand_ side of an assignment. Compile and run the program.
  + Does it compile?
  + Why or why not?

Think carefully about what type of thing `operator[]()` and `at()` return.  [Hint:  Would it be valid to write `5 = 7;` in C/C++?  Can you assign an integer constant to another integer constant?  Remember, you can only assign to things that have a corresponding memory location... ie. a variable.]

Change the return type of `operator[]()` and `at()` from `T` to `T&` in both the class declaration and below where the function body is (you should not need to modify anything else... just the return type).  Now recompile.  Does it compile now?

Talk to your TA/CP why a reference needs to be returned by `operator[]()` and `at()`.
