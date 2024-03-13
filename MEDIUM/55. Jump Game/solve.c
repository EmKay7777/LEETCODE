bool canJump(int* nums, int numsSize) {
    if(numsSize == 0) return true;
    int farthest = nums[0], current = 0;

    while (true) {
        if (nums[current] + current > farthest) farthest = nums[current] + current;
        if (farthest >= numsSize - 1) return true;
        else if (nums[farthest] == 0 && current == farthest - 1) return false;
        else if (farthest == current) return false;
        current++;
    }
    
}
