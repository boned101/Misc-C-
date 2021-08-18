#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<conio.h>

using namespace::std;
int findMaxConsecutiveOnes(int nums[], int numsSize);

int main()
{
    int nums[] = { 1, 0, 0, 0, 1, 1 };
    int numsSize = 5;
    int a=findMaxConsecutiveOnes(nums,numsSize);
    return 0;
}
int findMaxConsecutiveOnes(int nums[], int numsSize) {

    int count = 0, result = 0;
    for (int i = 0; i <= 5; i++)
    {
        int k = nums[i];
        if (nums[i] == 0) {
            count = 0;
        }
        else {
            count++;
            if (count>=2)
            {
                result = count;
            }
            printf("current count of consec 1's is [ %d ]for array value: [%d] at pos [%d]\n", result, k, i);
        }
    }
    printf("\n %d  is final result ", result);
    return result;

}