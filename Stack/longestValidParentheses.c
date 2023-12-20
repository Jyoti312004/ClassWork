int longestValidParentheses(char* s) {
    int stack[50000];
    int top = 0;
    stack[top] = -1;
    int len = 0;
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='('){
            top = top+1;
            stack[top] = i;
        }
        else{
            top = top-1;
            if(top == -1){
                top = top + 1;
                stack[top] = i;
            }
            else{
                int vals = i-stack[top];
                if(vals>len){
                    len = vals;
                }
            }
        }
    }

    return len;
}