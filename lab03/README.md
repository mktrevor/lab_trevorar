# Lab 03: Dynamic Array-Based List

### Design Document
There is no design writeup due with this lab.

### Grading
This assignment is worth 10 points.

This lab assignment must be demonstrated to a TA or Course Producer (CP).

### Lab Goal
To create list of Users (create a class called User) representing who have other Users as friends, using a dynamic array-based list to store each User's friend list.

## Part 1 (3 points)
Create a dynamic array-based List class for storing C++ strings `string` type. It is to have at least a constructor, a destructor, `push_back`, `size` and `at` methods.

## Part 2 (2 points)
Create a `User` class. The `User` class is for storing information about someone and who their friends (other Users) are.  (This will be the beginnings of a social network data structure). This class is to have the following data members:
  + Name (a `string`)
  + Age (an `int`)
  + Friends (a list of `string` - you must use your list class from step 1 in this lab assignment)

## Part 3 (3 points)
Create a main method that creates a `vector<User*>` (a.k.a. `userList`) and prompts the user to enter a first name (only... no last name) and age of people at the command prompt (1 pair of name and age per line) until the user types in "`done`" as the name.  Make a `User` object (allocate it dynamically on the heap) for each user (name and age) entered and adding the resulting pointer to your `vector<User*>`.

Finally enter a while loop that asks for two strings per line of text until the user enters "`done`".  The first name entered corresponds to a User and the second name corresponds to that first user’s friend.  Add the second name to the list of friends of the first User.

## Part 4 (2 points)
Add a `printUser` method to your `User` class.  Then in `main()`, call that method for each `User` call to nicely output all the information about the users that you've collected. Your output for each user should look like this:
```
	User name: <output name here>
	User age: <output age here>
	User friends: <output all the friends' names here with a space between them>
```

NOTE: If you want, you can put all this code into a single `.cpp` file. It makes compiling it easier.
