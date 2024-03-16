// Solved with O(1) memory complexity by suboptimally calculating all the cycles length in the nums Array and swapping elements in cycles in place.

void rotate(int* nums, int numsSize, int k) {
    if(numsSize > 1 && numsSize != k && k!= 0) {
        int cycleCount = 0, elemCount = 1, cycleLen, help = 0;
        while (elemCount <= numsSize) {
            help += k;
            if (help % numsSize == 0) {
                cycleLen = elemCount, cycleCount = numsSize / elemCount;
                break;
            }
            elemCount++;
        }
        if (cycleCount == 1) {
            int firstElem = nums[0], secondElem;
            for (int counter = 1; counter <= numsSize; counter++) {
                secondElem = nums[k * counter % numsSize];
                nums[k * counter % numsSize] = firstElem;
                firstElem = secondElem;
            }
        }
        else {
            int firstElem, secondElem;
            for (int i = 0; i < cycleCount; i++) {
                firstElem = nums[i];
                for (int counter = 1; counter <= cycleLen; counter++) {
                    secondElem = nums[(i + k * counter) % numsSize];
                    nums[(i + k * counter) % numsSize] = firstElem;
                    firstElem = secondElem;
                }
            }
        } 
    }
}
