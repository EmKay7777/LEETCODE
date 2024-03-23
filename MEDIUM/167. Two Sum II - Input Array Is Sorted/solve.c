/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int *answer = malloc(sizeof(int) * 2);
    for (int i = 0; i < numbersSize; i++) {
        int left = i + 1, right = numbersSize - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            printf("%d %d\n", left, right);
            if (numbers[i] + numbers[mid] < target) left = mid + 1;
            else right = mid;
        }
        if (numbers[right] + numbers[i] == target) {
            answer[0] = i + 1;
            answer[1] = right + 1;
            *returnSize = 2;
            return answer;
        }
    }
    return answer;
}
