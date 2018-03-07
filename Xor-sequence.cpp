#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int A[100];
int B[100];


int main(int argc, char const *argv[])
{
	/* code */
	long L = 1;

	int i = 0;
	A[0] = 0;
	for(i = 1; i < 100; i++)
		A[i] = A[i - 1] ^ i;
	B[0] = 0;
	for(i = 1; i < 100; i++)
	{
		B[i] = B[i -1 ] ^ A[i];

		cout <<B[i] <<endl;
	}

	return 0;
}