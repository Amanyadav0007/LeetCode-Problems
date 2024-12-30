// Problem Easy : 2441(largest +ve integer that exists with it's -ve)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Approach 1: Solve with the help of Sorting
// 1. Sort teh arr in ascending order
// 2. Iterate through the sorted arr from the end
// 3. Return teh first +ve integer and it's -ve counterpart
// TC: O(n log n), SC: O(1)
int findMaxApproach1(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[i] > 0 && binary_search(nums.begin(), nums.end(), -nums[i]))
            return nums[i];
    }
    return -1;
}

// Approach 2: Solve with the help of two pointer:
// 1. Sort the arr in ascending order
// 2. Use two pointers, one starting from the beginning and one from the end
// 3. Move the pointers towards each other until you find a +ve integer with it's -ve counterpart
// 4. Keep track of the largest +ve integer found

// TC: O(n log n), SC: O(1)

// int findMaxApproach2(vector<int> &nums) {
//     sort(nums.begin(), nums.end());
//     int n = nums.size();
//     int left = 0, right = n-1, maxK = -1;
//     while(left < right) {
//         int sum = nums[left] + nums[right];
//         if (sum == 0) {
//             maxK = max(maxK, nums[right]);
//             left++;
//             right--;
//         } else if (sum < 0)
//             left++;
//         else
//             right--;
//     }
//     return maxK;
// }

int main()
{
    vector<int> nums = {-1, 10, 6, 7, -7, 1}; // 7
    // vector<int> nums = {-10, 8, 6, 7, -2, -3}; // -1
    // vector<int> nums = {-1, 2, -3, 3}; // 3
    cout << "Anser is :" << findMaxApproach1(nums);
    // cout << "Anser is :" << findMaxApproach2(nums);
    return 0;
}