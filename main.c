/***********************************************
* * Description:
* This program reads arithmetic-like expressions 
* containing only parentheses '()', square brackets 
* '[]', and curly braces '{}' from a file named 
* "expressions.txt". It validates each expression 
* to determine if it is well-formed, meaning that 
* all opening symbols are properly matched and 
* closed in the correct order.
*
* The program uses a stack implemented with an array 
* and provides modular functions to push, pop, and 
* peek elements, as well as check if the stack is 
* full or empty. Each expression is checked one line 
* at a time, and the program outputs whether each 
* expression is correct or contains errors, including 
* invalid characters.
***********************************************/

#include <stdio.h>

int main();
void ReadFromFile();
int ValidateData(char data[]);
int Push(char data);
char Pop();
char Peek();
int isFull();
int isEmpty();

int MAXSIZE = 30;
char stack[30];
int top = -1;

/**********************************************
* Description: Entry point of the program. Calls 
* ReadFromFile to read expressions from the file 
* and validate them
* Input: None
* Output: Returns 0 upon successful execution
* Precondition: expressions.txt exists and is readable
* Post condition: All expressions in the file are processed
***********************************************/
int main() {
    ReadFromFile();

    printf("Press any key to exit...");
    getchar();

    return 0;
}

/**********************************************
* Description: Reads expressions from expressions.txt 
* line by line and validates each using ValidateData()
* Input: None (reads from a hardcoded file)
* Output: Prints results of validation for each expression
* Precondition: expressions.txt exists and is readable
* Post condition: Reads each line, calls ValidateData() 
* for each expression, and prints results
***********************************************/
void ReadFromFile() {
    FILE *file = fopen("expressions.txt", "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    int numExpressions;
    if (fscanf(file, "%d\n", &numExpressions) != 1) {
        printf("Failed to read number of expressions.\n");
        fclose(file);
        return;
    }

    char line[31];
    for (int i = 0; i < numExpressions; i++) {
        fgets(line, sizeof(line), file);
        
        for (int j = 0; line[j] != '\0'; j++) {
            if (line[j] == '\n') {
                line[j] = '\0';
                break;
            }
        }

        ValidateData(line);
    }

    fclose(file);
}

/**********************************************
* Description: Checks whether a bracker expression 
* is well-formed using a stack
* Input: data - null-terminated string containing 
* the expression to validate
* Output: 1 if the expression is correct; 0 if it 
* is incorrect or contains invalid characters. 
* Prints result to console
* Precondition: data[] is a null-terminated string 
* containing only valid characters
* Post condition: Returs 1 if expression is well-formed, 
* 0 otherwise; prints results
***********************************************/
int ValidateData(char data[]) {
    top = -1;
    for (int i = 0; data[i] != '\0'; i++) {
        if (data[i] == '(' || data[i] == '{' || data[i] == '[') {
            Push(data[i]);
        } 
        else if (data[i] == ')' || data[i] == '}' || data[i] == ']') {
            if (top == -1) {
                printf("Incorrect expression: %s\n", data);
                return 0;
            }
            else if (data[i] == ')' && Peek() != '(') {
                printf("Incorrect expression: %s\n", data);
                return 0;
            }
            else if (data[i] == '}' && Peek() != '{') {
                printf("Incorrect expression: %s\n", data);
                return 0;
            }
            else if (data[i] == ']' && Peek() != '[') {
                printf("Incorrect expression: %s\n", data);
                return 0;
            }
            else {
                Pop();
            }
        }
        else {
            printf("Invalid character in expression: %s\n", data);
            return 0;
        }
    }
    if (top != -1){
        printf("Incorrect expression: %s\n", data);
        return 0;
    }

    printf("Correct expression: %s\n", data);
    return 1;
}

/**********************************************
* Description: Checks if the stack is empty
* Input: None
* Output: 1 if the stack is empty, 0 otherwise
* Precondition: None
* Post condition: Returns 1 (true) or 0 (false) 
* depending on stack state
***********************************************/
int isEmpty() {
    if (top == -1) {
        return 1;
    } else {
        return 0;
    }
}

/**********************************************
* Description: Checks if the stack is full
* Input: None
* Output: 1 if the stack is full, 0 otherwise
* Precondition: None
* Post condition: Returns 1 (true) or 0 (false) 
* depending on stack state
***********************************************/
int isFull() {
    if (top == MAXSIZE - 1) {
        return 1;
    } else {
        return 0;
    }
}

/**********************************************
* Description: Returns the character at the top 
* of the stack without removing it
* Input: None
* Output: The character at the top of the stack
* Precondition: Stack is not empty (top != 1)
* Post condition: Returns the current top 
* element; stack is unchanged
***********************************************/
char Peek() {
    return stack[top];
}

/**********************************************
* Description: Removes and returns the top character 
* from the stack
* Input: None
* Output: The character removed from the top of 
* the stack; returns '\0' if the stack is empty
* Precondition: Stack is not empty (top != 1)
* Post condition: top element is removed from the 
* stack, top is decremented
***********************************************/
char Pop() {
    char data;
    if (!isEmpty()) {
        return stack[top--];
    } else {
        printf("Could not retrieve data, Stack is empty.\n");
        return '\0';
    }
}

/**********************************************
* Description: Adds a character to the top of the 
* stack if the stack is not full
* Input: data - the character to he pushed onto 
* the stack
* Output: 1 if push succeeded, 0 if the stack was full
* Precondition: Stack is not full (top < MAXSIZE - 1)
* Post condition: data is added to the top of the 
* stack, top is incremented
***********************************************/
int Push(char data) {
    if(!isFull()) {
        top = top + 1;
        stack[top] = data;
        return 1;
    } else {
        printf("Could not insert data, Stack is full.\n");
        return 0;
    }
}