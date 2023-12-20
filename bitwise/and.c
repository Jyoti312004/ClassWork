#include <assert.h>
#include <stdio.h>

int and(int val1,int val2){
    return ~(~val1|~val2);
}

int main(){
    printf("%d",and(2,3));
}