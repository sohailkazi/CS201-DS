#include<stdio.h>

double binpow(double a, long long b) {
    if (b == 0)
        return 1.0;
    double res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

int main()
{
    double n = 6.7;
    // printf("%f", n);
    long long int e = 5;

    printf("%lf", binpow(n, e));
}