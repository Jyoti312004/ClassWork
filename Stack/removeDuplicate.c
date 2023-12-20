#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char* removeDuplicateLetters(char* s) {
    char stack[strlen(s)];
    bool visited[26];
    int freq[26];
    for(int i=0;i<26;i++){
        visited[i] = false;
        freq[i] = 0;
    }

    for(int i=0;i<strlen(s);i++){
        freq[s[i]-'a'] = freq[s[i]-'a']+1;
    }

    int top = -1;
    for(int i=0;i<strlen(s);i++){
        freq[s[i]-'a'] = freq[s[i]-'a']-1;
        if(visited[s[i]-'a'] == true){
            continue;
        }

        if(top==-1){
            top=top+1;
            visited[s[i]-'a'] = true;
            stack[top] = s[i];
        }
        else{
            while(top!=-1 && stack[top]>s[i] && freq[stack[top]-'a']>0){
                visited[stack[top]-'a'] = false;
                top = top -1;
            }
            top = top+1;
            visited[s[i]-'a'] = true;
            stack[top] = s[i];
        }
    }

    char* ans = (char*)malloc(sizeof(char)*(top+2));
    ans[top+1] = '\0';
    while(top!=-1){
        ans[top] = stack[top];
        top = top-1;
    }

    return ans;

}