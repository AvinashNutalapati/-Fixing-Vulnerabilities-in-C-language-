#include<stdio.h>

// custom method to reverse a number (without using third variable/pointer) passed to it as arguments from main()
void reverse_number(int *ptr1, char* ptr2){
    int reverse = 0; //will be used as reversing variable.
    printf("Original First Number is : %d \n ", (*ptr1));
    printf("Choice is : %c \n ", (*ptr2));

    // ----------------------- Secure Coding Task -------------------------------////
    // Task 1: Implement a NULL pointer check condition (use if statement) (most important secure coding practice)

    if(ptr1 != NULL && *ptr2 == 'Y' && ptr2 != NULL)
    {
        //Task 2 : complete logic for reversing a number (Hint: required statements 2)
        //----- add logic here ------
        while(*ptr1 > 0)
        {
            reverse = reverse * 10 + (*ptr1 % 10);
            *ptr1 /= 10;
        }
        *ptr1 = reverse;
        //print statements
        printf("Reversed First Number is : %d \n", (*ptr1));
        printf("Confirmed choice is : %c \n", (*ptr2));
    }
    else{
        printf("Sorry Not allowed\n");
    }

}

int main(){
    // variable initializations
    int first_number = 12345;
    char choice = 'Y';

    //Note for developers(students): use variables in method using defined pointers (not directly)

    int* ptr_to_first_number = &first_number;
    char *ptr_to_char = &choice;
    // Hint:: add and assign the references to the pointers here:


    //function call statements
    reverse_number(ptr_to_first_number, ptr_to_char);

    return 0;

}
