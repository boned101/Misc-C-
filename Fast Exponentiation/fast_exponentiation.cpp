#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <bits/stdc++.h>

using namespace::std;


int main() {
    printf("enter the base and exponent! \n");
    long base=0, exponent=0, result=0;                        //32 bit number for exponent and base//
    cout << "base==>"; cin >> base;
    cout << "exponent==>"; cin >> exponent;

    result = pow(base, exponent);
    cout << "the result of fast exponentiation is ==>" << result;
	return 0;
}


long pow(long a, long n) {                                //recursive function which checks for even/odd exponent//
    if (n == 0) return 1;                                      //in case of even exponent, the function will give 0//
    if (n == 1) return a;                                      //in case of even exponent, the function will give 1//
    long t = pow(a, n / 2);
    return t * t * pow(a, n % 2);
}

