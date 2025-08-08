#include<bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mpp;
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]]==2){
                return nums[i];
            }
        }
        return -1;
    }
};

class Solution2 {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow==fast) break;
        }

        slow = nums[0];
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};


int main(){

    /*
    Given an array of integers nums containing n + 1 integers where each integer is in 
    the range [1, n] inclusive.
    There is only one repeated number in nums, return this repeated number.
    You must solve the problem without modifying the array nums and using only constant extra space.
    */

    return 0;
}