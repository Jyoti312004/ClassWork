#include <stdio.h>
#include <assert.h>
int xor(int val1,int val2){
    return (~(val1&val2)&(~(~val1&~val2)));
}

int main(){
    printf("%d",xor(2,3));

}