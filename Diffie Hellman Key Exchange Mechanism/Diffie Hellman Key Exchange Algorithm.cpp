#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<bits/stdc++.h>
#include <stdio.h>

using namespace::std;
int calc(int A, int e, int N);                                                    //this function computes the A^e mod N//


int main()                                                                       // the main Diffie-Hellman algorithm//
{
    int modulus, base;  
    cout << "Please Enter Base and then the Modulus \n" << endl;
    cin >>  base >> modulus;
    int aliceskey, bobskey;                   
    int A, B;                                 
    cout << "Enter Alice's secret key=";cin >> aliceskey;
    cout << "Enter Bob's secret key="; cin >> bobskey;

    A = calc(base, aliceskey, modulus);                   //Alice and Bob's Public Key is made using a^m mod n//
    B = calc(base, bobskey, modulus);

                                                         // /now through a secure channel Alice and Bob Exchange their public keys with each other //

    int KAlice = calc(B, aliceskey, modulus);            // Alice calc's Bobs key and Bob calc's Alice's key //
    int KBob = calc(A, bobskey, modulus);

    printf("The secret key has been exchanged. \n Alice has the secret key %d and Bob got the secret key %d", KAlice, KBob);
    return 0;
}
int calc(int A, int e, int N)                               //calculates the fucntion of a^m mod n and return the result//
{
    int temp, res = 1;

    while (e > 0)
    {
        temp = e % 2;

                                                            // fast exponention done here to save time//
        if (temp == 1) {
            res = (res * A) % N;
        }
        A= A * A % N;
        e= (e / 2);
    }

    return res;
}