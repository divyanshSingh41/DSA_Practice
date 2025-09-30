#include<bits/stdc++.h>
using namespace std;

// Brute force
int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int minLen = INT_MAX;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            if (sum >= target) {
                minLen = min(minLen, j - i + 1);
                break; // no need to check longer subarrays starting at i
            }
        }
    }

    return (minLen == INT_MAX) ? 0 : minLen;
}

// Optimal - Sliding Window

int minSubArrayLen2(int target, vector<int>& nums) {
    int n = nums.size();
    int left = 0, sum = 0;
    int minLen = INT_MAX;

    for (int right = 0; right < n; right++) {
        sum += nums[right];

        while (sum >= target) {
            minLen = min(minLen, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }

    return (minLen == INT_MAX) ? 0 : minLen;
}

int main(){

    // Given an array of positive integers nums and a positive integer target, 
    // return the minimal length of a subarray whose sum is greater than or equal to target. 
    // If no such subarray exists, return 0.





    return 0;
}