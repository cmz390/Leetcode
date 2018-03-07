#include <cmath>
#include <iostream>
using namespace std;
class Solution {
public:
    int findComplement(int num) {
        int bits[32];
        long index =pow(2,31);
        int temp = num;
        int p;

        for(int i =32; i >0; i--)
        {
        	if(index&temp) 
        		{p=(int)pow(2,i)-1;
        			break;
        			}
        	temp = temp << 1;
        }
        temp = num^p;
        return temp;
    }
};

int main(int argc, char const *argv[])
{
	Solution a;
	cout <<a.findComplement(5) <<"\n";
	return 0;
}


// class Solution {
// public:
//     int findComplement(int num) {
//         unsigned mask = ~0;
//         while (num & mask) mask <<= 1;
//         return ~mask & ~num;
//     }
// };


