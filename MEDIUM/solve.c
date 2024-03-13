/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    long int suff = 1, pref = 1;
    int *Asuff = malloc(numsSize * sizeof(long int));
    int *Apref = malloc(numsSize * sizeof(long int));
    
    Asuff[numsSize - 1] = 1, Apref[0] = 1;

    for (int i = 1; i < numsSize; i++) {
        pref *= nums[i - 1];
        Apref[i] = pref;
        suff *= nums[numsSize - i];
        Asuff[numsSize - i - 1] = suff;
    }  

    int *answer = malloc(numsSize * sizeof(long int));

    for (int j = 0; j < numsSize; j++) {
        answer[j] = Apref[j] * Asuff[j];
    }
    *returnSize = numsSize;
    return answer;
}
