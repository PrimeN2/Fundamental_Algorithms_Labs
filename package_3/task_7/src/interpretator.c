#include "interpretator.h"
#include "stack_int.h"
#include "stack_str.h"
#include <stdio.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

static bool check_for_variable(char c) {
    return isalpha(c) && isupper(c);
}

static bool check_operation(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

static int get_priority(char op) {
    switch(op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default:  return 0;
    }
}

int power(int a, int n) {
    int result = 1;
    while (n > 0) {
        if (n & 1) result *= a; 
        a *= a;                  
        n >>= 1;                 
    }
    return result;
}

static int exec_op(char op, int a, int b) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return (int)(a / b);
        case '^': return power(a, b);
        default:  return 0;
    }
}

static int handle_equation(interpretator_state *state) {
    char set_name = state->current_str[state->current_idx];
    state->current_idx++;

    stack_int_t nums_stack;
    stack_str_t operations_stack;

    create_int_stack(&nums_stack);
    create_str_stack(&operations_stack);

    bool equal_s = false;
    bool expect_sign = false;
    for (; state->current_str[state->current_idx] != '\0'; state->current_idx++) {
        char c = state->current_str[state->current_idx];

        if (isspace(c)) {
            continue;
        }

        if (!equal_s && c == '=') {
            equal_s = true;
            continue;
        } else if (!equal_s) {
            perror("Equal sign expected.\n");
            return -1;
        }

        if (check_for_variable(c)) {
            if (!isspace(state->current_str[state->current_idx + 1]) && !check_operation(state->current_str[state->current_idx + 1])) {
                perror("SyntaxError: Variables must be named with one upper letter.\n");
                return -1;
            } 
            
            if (expect_sign) {
                perror("SyntaxError: Sign expected.\n");
                return -1;
            }
            
            int value;
            if (get_variable(&state->vs, c, &value) != 0) {
                fprintf(stderr, "No variables named: %c.\n", c);
                return -1;
            }

            push_int(&nums_stack, value);
            expect_sign = true;

            continue;
            
        } else if (isdigit(c)) {
            if (expect_sign) {
                perror("SyntaxError: Sign expected.\n");
                return -1;
            }

            char num[11];
            size_t counter = 0;
            while (isdigit(state->current_str[state->current_idx])) {
                num[counter] = state->current_str[state->current_idx];
                state->current_idx++;
            }

            char *endptr;
            int value = (int)strtol(num, &endptr, 10);
            if (*endptr != '\0') {
                perror("Wrong number were given");
                return -1;
            }

            push_int(&nums_stack, value);
            expect_sign = true;

            continue;

        } else if (check_operation(c)) {
            if (!expect_sign) {
                perror("SyntaxError: Sign expected.\n");
                return -1;
            }

            if (operations_stack.size > 0) {
                char *prev_op;
                if (get_str_stack(&operations_stack, &prev_op) != 0){
                    return -1;
                }
                
                int prev_prio = get_priority(*prev_op);
                int curr_prio = get_priority(c);
                if (prev_prio < curr_prio) {
                    push_string(&operations_stack, &c);
                } else if (curr_prio == prev_prio && curr_prio != 3) {
                    push_string(&operations_stack, &c);
                } else if (prev_prio > curr_prio){
                    pop_str_stack(&operations_stack, &prev_op);

                    int a, b;
                    if (pop_int_stack(&nums_stack, &b) != 0) {
                        perror("Can't pop b value.\n");
                        return -1;
                    }
                    if (pop_int_stack(&nums_stack, &a) != 0) {
                        perror("Can't pop a value.\n");
                        return -1;
                    }

                    int value = exec_op(*prev_op, a, b);
                    if (push_int(&nums_stack, value) != 0) {
                        perror("Can't push calculated value.\n");
                        return -1;
                    }

                    push_string(&operations_stack, &c);
                }
            } else {
                push_string(&operations_stack, &c);
            }

            expect_sign = false;
            continue;

        } else {
            perror("SyntaxError: Wrong syntax equation.\n");
            return -1;
        }
    }
}

int create_interpretator(interpretator_state *state) {
    variables vs;
    create_variables(&vs, INITIAL_CAPACITY);
    state->vs = vs;
    state->current_idx = 0;
    state->current_str = NULL;

    return 0;
}

int interpretate_str(interpretator_state *state, char *str) {
    if (!state->current_str) {
        perror("No string was obtained.\n");
        return -1;
    }

    state->current_str = str;

    for (state->current_idx = 0; state->current_str[state->current_idx] != '\0'; state->current_idx++) {
        if (isspace(state->current_str[state->current_idx])) {
            continue;
        }

        if (check_for_variable(state->current_str[state->current_idx])) {
            if (!check_for_variable(state->current_str[state->current_idx + 1])) {
                if (handle_equation(state) != 0) {
                    perror("Can't handle the equation.\n");
                    return -1;
                }
            } else {
                perror("SyntaxError: Variables must be named with one upper letter.\n");
                return -1;
            }

            break;
        } //else if () { // handle print
          //  break;
        //} 
        else {
            fprintf(stderr, "SyntaxError: Character \'%c\' is undefined.\n", state->current_str[state->current_idx]);
            return -1;
        }
    }

    return 0;
}
