// 2161. Partition Array According to Given Pivot

#include<bits/stdc++.h>
using namespace std;

/*
You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums such that the following conditions are satisfied:
Every element less than pivot appears before every element greater than pivot.
Every element equal to pivot appears in between the elements less than and greater than pivot.
The relative order of the elements less than pivot and the elements greater than pivot is maintained.
More formally, consider every pi, pj where pi is the new position of the ith element and pj is the new position of the jth element. 
If i < j and both elements are smaller (or larger) than pivot, then pi < pj.
Return nums after the rearrangement.
*/

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, equal, greater;
        for (int num : nums) {
            if (num < pivot) {
                less.push_back(num);
            } else if (num == pivot) {
                equal.push_back(num);
            } else {
                greater.push_back(num);
            }
        }
        less.insert(less.end(), equal.begin(), equal.end());
        less.insert(less.end(), greater.begin(), greater.end());
        return less;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {9, 12, 5, 10, 14, 3, 10};
    int pivot = 10;
    vector<int> result = solution.pivotArray(nums, pivot);
    
    cout << "Rearranged array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}