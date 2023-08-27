#include <stdio.h>
  
void precisionCompute(int x, int y, int n)
{
    // Base cases
    if (y == 0) {
        printf("Division by Zero error\n");
        return;
    }
    if (x == 0) {
        printf("0\n");
        return;
    }
    if (n <= 0) {
        printf("%d\n", x / y);
        return;
    }
  
    if (((x > 0) && (y < 0)) || ((x < 0) && (y > 0))) {
        printf("-");
        x = x > 0 ? x : -x;
        y = y > 0 ? y : -y;
    }
    int d = x / y;
  
    // Now one by print digits after dot
    // using school division method.
    for (int i = 0; i <= n; i++) {
        printf("%d", d);
        x = x - (y * d);
        if (x == 0)
            break;
        x = x * 10;
        d = x / y;
        if (i == 0)
            printf(".");
    }
}
  
// Driver Program
int main()
{
    printf("Enter x: ");
    int x = 1;
    scanf("%d",&x);
    int y = 1;
    printf("\nEnter y: ");
    scanf("%d", &y);
    int n = 1;
    printf("\nEnter no of digits after decimal: ");
    scanf("%d", &n);

    precisionCompute(x, y, n);
    return 0;
}