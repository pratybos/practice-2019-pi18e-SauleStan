#include <stdio.h>
int ackermann(int m, int n){
    if (m == 0)
        return(n + 1);
    else if (n == 0)
        return ackermann(m -1, 1);
    else
        return ackermann(m - 1, ackermann(m, n - 1));
}

int main(){
    int m, n;
    printf("what is the value of m?\n");
    scanf("%d", &m);

    printf("what is the value for n?\n");
    scanf("%d", &n);

    printf("Result according to the Ackermann function: %d", ackermann(m, n));
}
