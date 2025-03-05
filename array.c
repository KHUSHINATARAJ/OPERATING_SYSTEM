#include <stdio.h>
#include <math.h>

int ssmall(int nums[], int size) {
    int small = nums[0];
    int ssmall = nums[0];
    
    for (int i = 1; i < size; i++) {
        if (nums[i] < small) {
            ssmall = small;
            small = nums[i];
        }
        else if (nums[i] < ssmall && nums[i] != small) {
            ssmall = nums[i];
        }
    }
    
    return ssmall;
}

int main() {
    int nums[] = {0, 1, 2, 3, -1};
    int size = sizeof(nums) / sizeof(nums[0]); 
    printf("%d", ssmall(nums, size)); 
    return 0;
}
