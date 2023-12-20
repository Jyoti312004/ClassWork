#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include<string.h> 

int postfix(char* s) {
    int top = -1;
    int stack[100];
    int len = strlen(s);
    int i = 0;
    while (s[i] != '?') {
        if (s[i] == ' ') {
            i++;
            continue;
        }
        if (s[i] >= '0' && s[i] <= '9') {
            top = top + 1;
            int val = 0;
            while (s[i] != ' ') {
                val = val * 10 + (s[i] - '0');
                i++;
            }
            stack[top] = val;
            i++;
        } else {
            int val2 = stack[top];
            top--;
            int val1 = stack[top];
            top--;

            switch (s[i]) {
                case '+':
                    stack[++top] = val1 + val2;
                    break;
                case '-':
                    stack[++top] = val1 - val2;
                    break;
                case '*':
                    stack[++top] = val1 * val2;
                    break;
                case '/':
                    stack[++top] = val1 / val2;  
                    break;
            }
            i++;
        }
    }

    return stack[0];
}

int main() {
    char* s = " 12 23 + ?";
    int ans = postfix(s);
    printf("%d\n", ans);
    return 0;
}
