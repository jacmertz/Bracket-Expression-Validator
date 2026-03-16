# Bracket Expression Validator

---

## Overview

This program reads arithmetic-like expressions from a file and validates whether their grouping symbols — parentheses `()`, square brackets `[]`, and curly braces `{}` — are correctly paired and properly nested.

Validation is performed using a **stack** implemented with an array (LIFO behavior).

---

## Features

- Reads expressions from `expressions.txt`
- Validates bracket pairing and nesting order
- Reports each expression as **Correct Expression:** or **Incorrect Expression:**
- Detects and reports invalid characters in expressions

---

## Example Input / Output

**`expressions.txt`**
```
5
{[[()]{()()}()][()]}
{(})
[{()}]
[]{()[()]}
{[()][{()]}}
```

**Output**
```
Correct expression: {[[()]{()()}()][()]}
Incorrect expression: {(})
Incorrect expression: [{()]}
Correct expression: []{()[()]}
Incorrect expression: {[()][{()]}}
```

---

## File Structure

```
project1/
├── main.c            # Entry point; loads expressions and prints results
├── expressions.txt   # Input file (must be present to run)
└── README.md
```

> **Note:** File structure may vary. At minimum the project must compile from a single `.c` file or a zipped project folder.

---

## How to Compile & Run

```bash
gcc -o main.c 
./main
```

The program reads exclusively from `expressions.txt` in the working directory. No command-line arguments are needed.

---

## Documentation

Every function includes a comment block in the following format:

**Function header:**
```c
/**********************************************
* Description:                                *
* Input:                                      *
* Output:                                     *
* Precondition:  (optional)                   *
* Postcondition: (optional)                   *
***********************************************/
```