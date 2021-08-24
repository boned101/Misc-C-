C program to calculate keys which can be exchanged over a secure channel. 

It assumes the base and modulus in A^e mod N are already agreed upon securely.
The public keys once generated is assumed to be exchanged then it calculates the public keys for Alice and Bob individually. 


Uses some fast exponentiation to reduce computation time.
