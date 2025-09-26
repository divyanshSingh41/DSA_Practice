#include<bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, return the number of triplets chosen from the array that can 
make triangles if we take them as side lengths of a triangle.
*/

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for(int r=n-1; r>=2; r--){
            int i=0, j=r-1;
            while(i<j){
                if(nums[i] + nums[j] > nums[r]){
                    cnt += (j-i);
                    j--; 
                }else{
                    i++;
                }
            }
        }
        return cnt;
    }
};


int maiun(){

    // Sort the array.
    // Fix the largest side r in a loop (from n-1 down to 2).
    // Use two pointers i=0 and j=r-1:
    // If arr[i] + arr[j] > arr[r] → all elements between i and j-1 also work, so add (j - i) to count, then move j--.
    // Else → move i++.

    // Brute force
    vector<int> arr = {2, 2, 3, 4}; // Example input
    int n = arr.size();
    int cnt = 0;

    for (int r = n - 1; r >= 2; r--) {
        for (int i = 0; i < r; i++) {
            for (int j = i + 1; j < r; j++) {
                if (arr[i] + arr[j] > arr[r]) {
                    cnt++;
                }
            }
        }
    }

    return 0;
}