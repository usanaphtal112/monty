# Project Title

## Table of Contents
1. [Introduction](#introduction)
2. [Tasks](#tasks)
    - [Task 0: push, pall](#task-0-push-pall)
    - [Task 1: pint](#task-1-pint)
    - [Task 2: pop](#task-2-pop)
    - [Task 3: swap](#task-3-swap)
    - [Task 4: add](#task-4-add)
    - [Task 5: nop](#task-5-nop)
    - [Task 6: sub](#task-6-sub)
    - [Task 7: div](#task-7-div)
    - [Task 8: mul](#task-8-mul)
    - [Task 9: mod](#task-9-mod)
    - [Task 10: comments](#task-10-comments)
3. [Data Structures](#data-structures)
4. [Compilation & Output](#compilation--output)

## Introduction
Provide a brief introduction to the project.

## Tasks

### Task 0: push, pall
Implement the push and pall opcodes.

**The push opcode:**
- Usage: `push <int>`
- Prints error message and exits if <int> is not an integer or if no argument is given.
- Use the `atoi` function.

**The pall opcode:**
- Usage: `pall`
- Prints all values on the stack starting from the top.

### Task 1: pint
Implement the pint opcode.

**The pint opcode:**
- Usage: `pint`
- Prints the value at the top of the stack.

### Task 2: pop
Implement the pop opcode.

**The pop opcode:**
- Usage: `pop`
- Removes the top element of the stack.

### Task 3: swap
Implement the swap opcode.

**The swap opcode:**
- Usage: `swap`
- Swaps the top two elements of the stack.

### Task 4: add
Implement the add opcode.

**The add opcode:**
- Usage: `add`
- Adds the top two elements of the stack.

### Task 5: nop
Implement the nop opcode.

**The nop opcode:**
- Usage: `nop`
- Does nothing.

### Task 6: sub
Implement the sub opcode.

**The sub opcode:**
- Usage: `sub`
- Subtracts the top element from the second top element.

### Task 7: div
Implement the div opcode.

**The div opcode:**
- Usage: `div`
- Divides the second top element by the top element.

### Task 8: mul
Implement the mul opcode.

**The mul opcode:**
- Usage: `mul`
- Multiplies the second top element with the top element.

### Task 9: mod
Implement the mod opcode.

**The mod opcode:**
- Usage: `mod`
- Computes the rest of the division of the second top element by the top element.

### Task 10: comments
Implement the capability of commenting using the `#` symbol.

### Data Structures
Use the following data structures:

```c
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
