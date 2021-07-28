#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>						       //needed for random number seed//
using namespace std;


int sem_produced = 0;						      //semaphores for produced value and bufferspace//
int sem_bufferspace = 20;

int pro = sem_produced;						      //global variables used to control queue//									
int buf = sem_bufferspace;

int Q[20];							      //Queue used for operations//						

int  producer()
{
	pro = sem_produced;
	buf = sem_bufferspace;
	int i;
	int temp[20];
	for (i = 0; i <= sem_bufferspace; i++)		      //random value generator//
	{
		int x = rand();
		cout << x << " --> ";
		temp[i] = x;
	}
	cout << endl;
	for (i = pro; i <= buf; i++)                          //Produced item goes into buffer queue//
	{
		if (sem_bufferspace == sem_produced)           //producer checks bufferspace//
		{
			cout << "<><><>-- BUFFER IS FULL NOW --<><><>" << endl;
			return 0;
		}
		++sem_produced;                               //allocates buffer space and tells semaphore about produced value//
		--sem_bufferspace;
		Q[i] = temp[i];
		cout << Q[i] << " --> ";
	}
	cout << endl;
	return 0;
}
int consumer()
{
	pro = sem_produced;
	buf = sem_bufferspace;
	int i;
	for (i = 0; i < buf; i++)
	{
		if (sem_bufferspace == 0)
		{
			cout << "<><>--BUFFER IS EMPTY NOW --<><>" << endl;
			return 0;
		}
		--sem_produced;
		++sem_bufferspace;
	}
	return 0;
}
int main()
{
	srand((unsigned)time(NULL));                                //random number generator tied to system time as random seed//
	char a;
	do {
		producer();
		consumer();
		cout << "wish to continue?" << endl;
		cin >> a;
	} while (a == 'Y' || a == 'y');
	return 0;
}