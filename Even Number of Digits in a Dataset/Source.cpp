#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include <iostream>

using namespace::std;

int findNumbers(int* nums, int numsSize) {

    int val = 0, finleven = 0;

    for (int i = 0; i < numsSize; i++) {
        val = nums[i];
        int count = 0;
        while (val){
            count++;
            val = val / 10;
        }
        if ( count % 2 == 0)
        {
            finleven++;
        }
    }
    return finleven;
}
int main()
{
    int nums[] = {555, 901, 4822, 1771};
    int numsSize= (sizeof(nums) / sizeof(nums[0]));
    cout << findNumbers(nums, numsSize) <<" numbers in Dataset with even digits." << endl;
    return 0;
}