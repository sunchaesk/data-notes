
// Priority Queues - sorting them by importance
/*
 * Priority Queues operations
 * - Insert(Q, x) - Given an item with key k, insert it
 * - Find Min & Find Max
 * - Delete Min & Delete Max
 * NOTE: Build algorithms around data structures -> clean code
 */

// Stack: LIFO
// code to determine if the parentheses are balanced

/* #include <iostream> */
/* #include <stack> */
/* #include <string> */

/* int main (int argc, char* argv[]) { */
/*     if (argc != 2) { */
/*         std::cout << "pass a string to check if it's parens are balanced" << std::endl; */
/*         exit(1); */
/*     } */

/*     std::stack<int> parens; */
/*     std::string input = argv[1]; */

/*     for (int i = 0; i < input.length(); i++) { */
/*         char ch = input[i]; */
/*         if (ch == ')') { */
/*             if (parens.size() == 0) { */
/*                 std::cout << "unmatched ')' at position: " << i << std::endl; */
/*                 exit(1); */
/*             } */
/*             parens.pop(); */
/*         } */
/*         else if (ch == '(') { */
/*             parens.push(i); */
/*         } */
/*     } */
/*     if (parens.size() != 0) { */
/*         while (parens.size() > 1) { */
/*             parens.pop(); */
/*         } */
/*         std::cout << "unmatched '(' at position: " << parens.top() << std::endl; */
/*         exit(1); */
/*     } */
/*     else { */
/*         std::cout << "parens balanced!" << std::endl; */
/*     } */
/* } */

/* THE CODE IS IN C++ */


// Code above rewrite in C
// Have to implement stack as well
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
typedef struct stack {
    int top;
    unsigned capacity;
    int* array;
} stack;
struct stack* create_stack(unsigned capacity){
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->capacity = capacity;
    s->top = -1;
    s->array = (int*)malloc(s->capacity * sizeof(int));
    return s;
}
int is_full(struct stack* s){
    return (unsigned)s->top == s->capacity -1;
}
int is_empty(struct stack* s){
    return s->top == -1;
}
void push(struct stack* s, int item){
    if (is_full(s)) return;
    s->array[++s->top] = item;
}
int pop(struct stack* s){
    if (is_empty(s)) return INT_MIN;
    return s->array[s->top--];
}
int top(struct stack* s){
    if(is_empty(s)) return INT_MIN;
    return s->array[s->top];
}

int main(int argc, char* argv[]){
    if (argc != 2){
        printf("pass a string as arg\n");
        exit(1);
    }
    struct stack parens = *create_stack(100);
    char* input = argv[1];

    for (int i = 0; (unsigned long)i < strlen(input); i++){
        char ch = input[i];
        if (ch == ')') {
            if (is_empty(&parens)){
                printf("unmatched ')'\n");
                exit(1);
            }
            pop(&parens);
        } else if (ch == '(') {
            push(&parens, i);
        }
    }
    if (!is_empty(&parens)){
        while(parens.top > 0) {
            pop(&parens);
        }
        printf("unmatched '(' at position %d\n", top(&parens));
        exit(1);
    } else {
        printf("parens balanced!\n");
    }
}
