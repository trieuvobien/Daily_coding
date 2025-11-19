#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    int n = strlen(s);
    char stack[n];    
    int top = -1;      

    for (int i = 0; i < n; i++) {
        char c = s[i];

        
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } 
        
        else {
            if (top < 0) return false; 

            char open = stack[top--];

            if ((c == ')' && open != '(') ||
                (c == '}' && open != '{') ||
                (c == ']' && open != '[')) {
                return false;
            }
        }
    }
    return top == -1;
}
