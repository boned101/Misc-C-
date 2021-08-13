#include <iostream>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


using namespace std;
int gcdex(int a, int b, int* x, int* y);

int main() {
    int a, b, x, y;
    printf("Welcome to Euclid's Extended Algorithm Calculator  GCD(a,b)\n");
    printf("enter value one [a] \n");
    cin >> a;
    printf("enter value two [b] \n");
    cin >> b;
    cout << "GCD is ==>" << gcdex(a, b, &x, &y);
    return 0;
}

int gcdex(int a, int b, int* x, int* y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdex(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}