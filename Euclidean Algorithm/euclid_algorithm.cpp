#include <iostream>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int gcd(int a , int b);

int main() {
	char ted;
	do {
		system("cls");
		int a, b;
		cout << "Give me the values of gcd(a , b) " << endl;
		cin >> a >> b;
		int c = gcd(a, b);
		printf(" \n GCD{%d,%d} = %d", a, b, c);
		printf(" \n do you wish to continue? y/n.");
		cin >> ted;
	} while (ted == 'y');

	return 0;
}

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}