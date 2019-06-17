#include <stdio.h>

int fact(int n){
    if (n > 0)
        return n*fact(n-1);
    else return 1;
}

int main(){
    int x;

    printf("Enter a number: \n");
    scanf("%d", &x);
    printf("The factorial of %d is: %lu", x, (unsigned long)fact(x));
    return 0;
}
