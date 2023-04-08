# cy5130projet5
CY 5310
Project 5 – Secure Coding. Input validation and static analysis

  

Prof. Dr. Jose Sierra
 Submitted by:
Avinash Nutalapati
https://github.com/AvinashNutalapati/cy5130projet5.git



# PART-1

 

The script now uses regular expressions to validate the input arguments. The nuid_regex variable holds a regular expression that matches NUIDs that start with '00' and have 9 digits. The email_regex variable holds a regular expression that matches Northeastern student emails that follow the pattern 'firstname.lastname@northeastern.edu'.
The script checks whether the first and second arguments match the respective regular expressions using the =~ operator. If either of the arguments is invalid, the script prints an error message to the standard error stream (>&2) and exits with a non-zero exit code (exit 1).
If both arguments are valid, the script extracts the NUID from the first argument and proceeds to generate the program codes and print the Part 4 Program as before.




# Code 09:



 
## Explanation of changes:
•	Added stdlib.h header for malloc and free functions.
•	Removed unnecessary loop and uninitialized variable sub from array_print function.
•	Fixed the sizeof operand to use int instead of char to allocate the correct amount of memory for the integer array.
•	Initialized the size_array variable to 10.
•	Added a loop to initialize the array with values from 0 to 9.
•	Added free statement to deallocate the dynamically allocated memory.
## CWE: 
1.	Unix API Allocator sizeof operand mismatch: This bug can be mapped to CWE-131: Incorrect Calculation of Buffer Size, which states that "The software does not correctly calculate the size that is needed for an object, buffer, or memory allocation operation, which can lead to a buffer overflow or other memory-related error."
2.	Logic error Array subscript is undefined: This bug can be mapped to CWE-129: Improper Validation of Array Index, which states that "The software does not properly validate input that can affect the index of an array, which could result in an array index out of bounds error or other unspecified impact."
3.	Logic error Uninitialized argument value: This bug can be mapped to CWE-457: Use of Uninitialized Variable, which states that "The software uses a variable that has not been initialized, which can result in unpredictable behavior."
Output & Fixed Code:

 











# Code 10:


 

## Explanation of changes:
Explanation of the changes made:
1.	The null pointer check condition for ptr1 is added inside the function reverse_number() using an if statement.
2.	The reversing logic is implemented using ptr1 in the while loop.
3.	The addresses of the variables first_number and choice are assigned to the pointers ptr_to_first_number and ptr_to_char respectively.
4.	The uninitialized pointers ptr_to_first_number and ptr_to_char are removed from the main function.


## CWE: 
The bug "Dereference of null pointer" in codeN1110.c on line 13, column 4 maps to the Common Weakness Enumeration (CWE) 476: Null Pointer Dereference.
CWE-476 is a common weakness that occurs when a program dereferences a null pointer, which can cause the program to crash or exhibit undefined behavior. In this case, the null pointer is dereferenced without being checked for nullness, which can lead to a crash.



 

# Code 11:


 


## Explanation of changes:

•	Added error handling for memory allocation errors during the matrix creation.
•	Changed the int variables in loops to unsigned int as they cannot be negative.
•	Added freeing memory to avoid memory leaks.
•	Changed the scanf format specifier from %d to %u to match the unsigned int type of matrix_size.
•	Added a return statement if matrix_size exceeds the MAX_LEN.
•	Removed the unnecessary initial value for matrix_size as it is overwritten by the user input.
•	Added a free statement to free the memory allocated for square inside the first if statement in the buildMatrix function.
•	Added a for loop to free the memory allocated for square inside the second if statement in the buildMatrix function.

## CWE:
The following are the vulnerabilities present in the code and their corresponding CWEs:
•	Memory error: This warning indicates a potential memory allocation error in the code. CWE-119: Improper Restriction of Operations within the Bounds of a Memory Buffer is a relevant CWE for this warning.
•	Memory leak: This warning indicates a potential memory leak in the code. CWE-401: Improper Release of Memory Before Removing Last Reference is a relevant CWE for this warning.



 



# Code 12:


 
## Explanation of changes:
The issue reported by the C-Lang static analyzer is related to the uninitialized variable px, which is used as a condition for the if statement without being initialized. This can lead to undefined behavior since the value of px is not deterministic.
To fix this issue, we can initialize px to NULL, which is a well-defined value. We also need to allocate memory for px using the malloc function before dereferencing it.
In the fixed code, we initialize px to NULL, allocate memory for px using malloc, and check if the allocation succeeded. We also check if px is NULL before dereferencing it to avoid undefined behavior.

The static analyzer detected that there is a block of memory that was allocated using malloc, but it is not being freed before the program terminates. This means that the memory is leaked and cannot be used again by the system.
To fix this issue, we can add a call to free to release the memory allocated for px. We need to make sure that the free function is called in all cases where px is allocated, whether or not the condition in the if statement is true.
In the fixed code, we added a call to free after the if statement to release the memory allocated for px. Now the program should not leak any memory.
## CWE:
The issue reported by the C-Lang static analyzer can be mapped to the following Common Weakness Enumeration (CWE) ID:
•	CWE-457: Use of Uninitialized Variable
This CWE describes the use of uninitialized variables, which can lead to undefined behavior and unexpected program output, such as the branch condition evaluating to a garbage value in this case.
The recommended solution for CWE-457 is to initialize all variables before they are used in the program, which prevents them from containing garbage values that can lead to undefined behavior.


 











# Code 13:


 
## Explanation of changes:

The issue with the given code is that it attempts to free the same memory location twice, which can result in undefined behavior or a segmentation fault. To fix this issue, we should remove the second call to free(shellcode_location).
In this updated code, we have removed the second call to free(shellcode_location) to prevent double-freeing of the same memory location.
CWE:
This vulnerability can lead to undefined behavior or a segmentation fault.
The corresponding CWE (Common Weakness Enumeration) for this type of vulnerability is CWE-415: Double Free.



 

# Code 14:

 No Bugs Found
## Secure issues with code:

Hardcoded secrets: The secret key used for encryption/decryption is hardcoded in the program, which is a security risk. An attacker who gains access to the code can easily identify the key and use it to decrypt sensitive information. This can lead to data theft and other security breaches. This issue can be fixed by using a secure key management system that keeps the key separate from the code and provides secure access controls.
    Insecure password storage: The user passwords are stored in plaintext format in the "usersDb" array. This makes it easy for an attacker to access the passwords if they gain access to the system or the file where the passwords are stored. This issue can be fixed by using a secure password hashing algorithm to store the passwords. The hashed passwords can be stored in the "usersDb" array, and the input password can be hashed and compared with the stored hash for authentication.
    Input validation: The code does not perform any input validation for the username and password fields. This can lead to buffer overflows and other security issues if the user enters input that exceeds the allocated buffer size. This issue can be fixed by performing input validation to ensure that the input is within the expected size and format.
    Lack of error handling: The code does not handle errors that may occur during file I/O operations, such as fopen and fprintf. This can lead to unexpected behavior and security issues if the file I/O operations fail. This issue can be fixed by adding error handling code to check for errors during file I/O operations and take appropriate actions based on the error.
    Lack of authentication and authorization: The code does not perform any authentication or authorization checks before allowing users to access the username database. This can lead to unauthorized access and data theft. This issue can be fixed by adding authentication and authorization checks to ensure that only authorized users can access the username database and perform the necessary operations. For example, the code can prompt users to enter their username and password and perform a check to ensure that the entered credentials are valid before allowing access to the database.
  The program does not check whether the file "usernames2.dat" exists before opening it. An attacker could create a file with the same name and overwrite the legitimate file, causing data loss or corruption.
    The program writes the new username to the file without any validation or sanitization. An attacker could inject malicious code or unexpected characters into the file, causing further issues such as a buffer overflow or file corruption.

## Changes:

The one of the main fixes here are:
The fix here is to use MAX_PASSWORD_LEN instead of strlen(usersDb[i].password) as the size parameter in the decrypt() function call. This ensures that the function always processes the password string up to its maximum allowed length, preventing any buffer overflows.
Here are the changes made to the code:
1.	Defined MAX_PASSWORD_LEN constant to avoid buffer overflow vulnerabilities.
2.	Updated the encrypt() and decrypt() functions to take the size of the input string as an argument, to avoid buffer overflow vulnerabilities.
3.	Updated checkCredentials() function to call checkValidUserName() and checkValidPassword() functions, and to return 0 if the username or password is invalid.
4.	Added input validation to check for input buffer overflow vulnerabilities, using strlen() to check the length of the input strings.
5.	Changed the logic in the switch case statements to call checkCredentials() function before allowing access to the corresponding option. Also removed the use of unnecessary variables and consolidated the code.
6.	Check if the username is "admin" before wiping the users database in case 2.
7.	Close the file pointer after writing to the file to prevent resource leaks.
8.	Add an additional check for the admin username in case 2 to ensure that only the admin user can wipe the database.
These changes improve the security and reliability of the program.
This version checks if the user has admin privileges before allowing them to add a new username, opens the file securely, and uses scanf to read the new username from the user input. The scanf function is used with a width specifier of 19 to prevent buffer overflow attacks, and it returns the number of successfully read items, which is checked to ensure that the input is valid. The fclose function is used to close the file after writing the new username.
In the original code, the file is opened for writing without first checking if the user has appropriate credentials. In the fixed code, if the user does not have admin credentials, the program outputs an error message and exits the switch statement without attempting to open the file. If the user does have admin credentials, the file is opened for writing and the appropriate message is printed. Additionally, an error message is printed if the file fails to open.

The program prompts the user to enter a new username to be added to the usernames2.dat file in case the user selects option 1 from the menu. This is because the program assumes that the user wants to add a new user to the system and needs to specify the username for that user.
If the user selects option 2, the program simply wipes the contents of the usernames2.dat file, so there is no need to prompt the user for any input in this case.
In the fixed code, if the password is invalid, the user cannot add the username. The program will display a message indicating that the password is invalid and return 0, meaning the operation failed. Therefore, the prompt to enter the username to be added will not be shown if the password is invalid.
Code Improvements:
1.	Reorganized the code to make it more readable and easier to understand.
2.	Added comments to explain the purpose of each section of code.
3.	Renamed variables to more descriptive names to improve code readability.
The new code now allows users to choose between adding a new username to the usernames file, wiping all usernames from the file, or exiting the program. The program prompts the user to enter a username and password. If the username and password match the admin credentials, the program provides access to the menu. Otherwise, it displays an error message and prompts the user to enter valid credentials. If the user selects the option to add a new username, the program prompts the user to enter the new username and writes it to the usernames file. If the user selects the option to wipe all usernames, the program clears the contents of the usernames file. If the user selects the option to exit the program, the program terminates.
## CWE:

•	CWE-259: Hard-coded Password (fixed by removing the hard-coded password and prompting the user for input)
•	CWE-377: Insecure Temporary File (fixed by generating a random temporary file name and using proper permissions and file handling)
•	CWE-252: Unchecked Return Value (fixed by checking the return value of remove())
•	CWE-20: Improper Input Validation (fixed by adding input validation for the new username)
•	CWE-362: Concurrent Execution using Shared Resource with Improper Synchronization ('Race Condition') (fixed by using file locks to prevent concurrent access to the file)
•	CWE-400: Uncontrolled Resource Consumption ('Resource Exhaustion') (fixed by limiting the input size for the new username to prevent buffer overflow)


 

# Code 15:


 

## Explanation of changes:
Changes made:
•	Initialized the function pointer foo with the address of the current function recurse.
•	Added a valid recursive check mechanism to avoid infinite recursion, by decrementing the size variable and checking if it is still greater than 0 before calling the foo() function pointer.
•	Added stdlib.h header file for NULL macro, in case we need it later.

## CWE:
The code issue mentioned in the report "Called function pointer is an uninitialized pointer value" can be mapped to the following Common Weakness Enumeration (CWE) entry:
CWE-457: Use of Uninitialized Variable
The CWE-457 category is used to describe software faults that occur when a program accesses an uninitialized variable or value. In the given code, the function pointer foo is uninitialized, and therefore the behavior of the code is undefined when foo() is called. The uninitialized function pointer could potentially point to any memory location, leading to unexpected behavior or even a crash.
To fix this issue, the function pointer should be initialized before it is called.


 

# Code 16:


 
## Explanation of changes:
The user_supplied_string parameter in copy_input should be declared as const since it is not modified in the function.
•	The size of the dst_buf buffer in copy_input should be 4 * src_len + 1 instead of 4 * MAX_SIZE to ensure that it can hold the encoded string. Also, the size of the buffer should be in bytes, so sizeof(char) is not necessary.
•	The if statement in copy_input should compare src_len to MAX_SIZE - 1 instead of MAX_SIZE to leave room for the null terminator in the buffer.
•	The encoding of the < character in copy_input was missing. I added it by appending &lt; to the destination buffer.
•	In main, the uss buffer was not initialized before passing it to read, which caused a logic error. I fixed this by declaring uss as an array of MAX_SIZE characters and reading into it.
•	The printf statement in main had a syntax error. I fixed it by adding quotes around the format string and passing dst_buff as the argument.
•	I added a null terminator to the end of dst_buf in copy_input.
•	I added a call to free to release the memory allocated for dst_buf after printing it.

## CWE:
The C-Lang report indicates a logic error caused by an uninitialized argument value in the function call at line 39, column 2 in the main function of the code.
This vulnerability is associated with CWE-457: Use of Uninitialized Variable, which occurs when a program uses a variable without first initializing it to a known value. In this case, the uss pointer in the main function is not initialized before it is passed as an argument to the read function. As a result, the behavior of the program is undefined and may result in a crash or other unexpected behavior.
To fix this issue, the uss pointer should be initialized to a valid memory location before it is passed to the read function.


 

# Code 17:


 

## Explanation of changes:
Here are the mappings of the identified issues in the code to their respective CWE categories:
1.	Unused code - Dead assignment: CWE-563: Unused Variable. This is because the code contains a variable that is declared but not used, which is a common coding mistake. This issue can sometimes be an indicator of other problems in the code, but in this case, it is not significant.
2.	Memory error - Memory leak: CWE-401: Improper Release of Memory Before Removing Last Reference. This is because the code uses malloc to allocate memory for the board pointer but does not release the memory before the program exits. This results in a memory leak, where the memory allocated by malloc remains in use even though it is no longer needed. Over time, this can cause the program to consume an excessive amount of memory, which can lead to performance problems or crashes.

## CWE:
1.	Unused code: The code didn't have any unused code, so no action was needed.
2.	Memory error - Memory leak: The board pointer was allocated memory using malloc, but the memory was never released. To fix this, free was called at the end of the program to release the memory. Additionally, we checked if malloc returned NULL, which could happen if there is not enough memory available.
3.	Potential integer overflow: In the original code, m * n * sizeof(struct board_square_t) could potentially overflow for large values of m and n. However, since we've added the check for m and n against MAX_DIM, this should not be an issue.
4.	Error handling for scanf: The code did not handle the possibility that scanf could return EOF if there was an error or end of file was reached. In the fixed code, we check for this and print an error message and exit the program if it occurs.

#
 



# PART 4

The goal of these four files is to implement a memory allocator that can detect memory leaks in a C program.
The mem.c file contains a sample program that has a memory leak. It calls the w_malloc function to allocate memory, and depending on user input, may allocate memory that is not freed before the program exits. The program also calls the whole_free function at the end, which is meant to free all the memory that was allocated using w_malloc, but not freed using w_free.
The wrapped_malloc.c file contains implementations of w_malloc, w_free, and whole_free. These functions wrap the malloc, free, and memset functions respectively. They keep track of all the memory that is allocated using w_malloc in a static array, and free all the allocated memory that was not freed explicitly by the program.
The wrapped_malloc.h file contains declarations of the functions in wrapped_malloc.c.
The Makefile is used to build the executable a.out by compiling the mem.c and wrapped_malloc.c files and linking them together.
The changes made to the code in this challenge are aimed at fixing a memory leak vulnerability in the original code. Memory leaks can be a serious security issue as they can lead to the exhaustion of system resources, leading to crashes, instability, and even denial of service attacks. By properly managing allocated memory through functions like w_malloc, w_free, and whole_free, we can avoid such memory leaks and prevent potential security vulnerabilities.
Furthermore, this challenge demonstrates the importance of secure coding practices. Writing secure code means that we need to be aware of potential vulnerabilities in our code and take steps to mitigate them. In this case, by properly handling memory allocation and freeing, we have made the code more secure and less vulnerable to attacks that may exploit memory leaks. The use of safe coding practices and secure coding guidelines can help prevent many common vulnerabilities, making our code more resilient to attacks and enhancing overall system security.


## Modifications Made in mem.c file:

The changes made to the mem.c file are as follows:
•	wrapped_malloc.h header file is included to use the custom memory allocation and deallocation functions.
•	Calls to malloc have been replaced with calls to w_malloc.
•	Calls to free have been replaced with calls to w_free.
•	whole_free function is called at the end of main to free all the pointers that were not properly freed by the w_free function.
These changes will ensure that all memory allocated using w_malloc is properly freed using w_free or the whole_free function at the end of the program, fixing the memory leak issue.
The changes made to the wrapped_malloc.c file are as follows:
•	The w_malloc function wraps the standard malloc function and first calls it to allocate memory. If malloc fails to allocate memory, w_malloc prints an error message and returns NULL. If malloc succeeds, w_malloc stores the pointer returned by malloc in the shelf array for bookkeeping purposes. If the number of allocations exceeds MAX_ALLOC, an error message is printed and NULL is returned.
•	The w_free function iterates through the shelf array to find the pointer to be freed. If the pointer is found, it is freed using the standard free function and removed from the shelf array. If the pointer is not found, an error message is printed.
•	The whole_free function iterates through the shelf array and frees all the remaining pointers. After that, it sets numAlloc to zero, indicating that there are no pointers stored in the array anymore.
These changes ensure that all memory allocated using w_malloc is properly tracked and freed using w_free or whole_free, fixing the memory leak issue.
wrapped_malloc.h:

The wrapped_malloc.h file doesn't need any modification as it already contains the function prototypes for w_malloc, w_free, and whole_free, which are implemented in wrapped_malloc.c.
However, as per the instructions, we have to add a preprocessor definition for MAX_ALLOC in this file, which we can add. 

## Makefile 
In the modified Makefile, we have added two new rules for compiling mem.c and wrapped_malloc.c separately, and linked the resulting object files together to create the a.out executable.

The modifications made to the above 4 files (mem.c, wrapped_malloc.c, wrapped_malloc.h, and Makefile) ensure that all allocated memory is properly freed at the end of the main function. This is done by wrapping the standard malloc and free functions with custom w_malloc and w_free functions that maintain a record of all allocated memory, allowing for proper cleanup using the whole_free function at the end of the program.


