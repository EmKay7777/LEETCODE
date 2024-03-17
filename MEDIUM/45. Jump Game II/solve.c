// Beats 98%+ users in C at runtime.

int jump(int* nums, int numsSize) {
    if (nums[0] == 0) return 0;
    if (numsSize == 1) return 0;
    int searchBegin = 0, searchEnd = nums[0], answer = 1;
    while (searchEnd < numsSize - 1) {
        int maxDist = 0, i = searchBegin++;
        while (i <= searchEnd) {
            if (nums[i] + i > maxDist) {
                maxDist = nums[i] + i;
            }
            i++;
        }
        searchBegin = searchEnd++;
        searchEnd = maxDist;
        answer++;
    }
    return answer;
}
