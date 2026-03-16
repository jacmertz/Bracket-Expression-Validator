# Bracket Expression Validator

---

## Overview

This program reads arithmetic-like expressions from a file and validates whether their grouping symbols — parentheses `()`, square brackets `[]`, and curly braces `{}` — are correctly paired and properly nested.

Validation is performed using a **stack** implemented with an array (LIFO behavior).

---

## Features

- Reads expressions from `expressions.txt`
- Validates bracket pairing and nesting order
- Reports each expression as **Correct** or **Incorrect**
- Detects and reports invalid characters in expressions
- Highlights the location of the first error in an incorrect expression

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
{[[()]{()()}()][()]} → Correct
{(})                 → Incorrect
[{()}]               → Correct
[]{()[()]}           → Correct
{[()][{()]}}         → Incorrect
```

---

## File Structure

```
project1/
├── main.c            # Entry point; loads expressions and prints results
├── stack.c           # Stack implementation (push, pop, peek)
├── stack.h           # Stack header / declarations
├── validator.c       # Expression validation logic
├── validator.h       # Validator header
├── expressions.txt   # Input file (not submitted — must be present to run)
└── README.md
```

> **Note:** File structure may vary. At minimum the project must compile from a single `.c` file or a zipped project folder.

---

## How to Compile & Run

```bash
gcc -o validator main.c stack.c validator.c
./validator
```

Or, if implemented as a single file:

```bash
gcc -o validator main.c
./validator
```

The program reads exclusively from `expressions.txt` in the working directory. No command-line arguments are needed.

---

## Implementation Requirements

| Requirement | Details |
|---|---|
| Stack | Array-based, max size 30, LIFO order |
| Stack operations | `push`, `pop`, and `peek` each in their own function |
| File input | Reads from `expressions.txt` only |
| File format | First line = number of expressions; max 10 expressions |
| Valid characters | `{`, `}`, `[`, `]`, `(`, `)` only — no spaces |
| Invalid character handling | Prints: `Invalid character in expression: <expression>` |
| Data loading | Dedicated function to load expressions from file |
| Validation | Separate function (not in `main()`) to validate each expression |

---

## Error Highlighting

The error location within an incorrect expression is highlighted — mismatched characters are printed in **bold** or a different color using ANSI escape codes.

Example:
```
[{()]}  → Incorrect  (the { and ] are highlighted)
```

---

## Documentation

Every file and every function includes a comment block in the following format:

**File header:**
```c
/**********************************************
* Name:       Your Name                       *
* Date:       Due Date                        *
* Assignment: Project 1 - Sequence and Order  *
***********************************************
* Description of the program                  *
***********************************************/
```

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