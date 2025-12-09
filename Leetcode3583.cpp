// Count Special Triplets
/*
You are given an integer array nums.
A special triplet is defined as a triplet of indices (i, j, k) such that:
0 <= i < j < k < n, where n = nums.length
nums[i] == nums[j] * 2
nums[k] == nums[j] * 2
Return the total number of special triplets in the array.
Since the answer may be large, return it modulo 109 + 7.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

    int specialTriplets(vector<int>& arr){
        const long long MOD = 1e9 + 7;
        long long n = arr.size();

        unordered_map<long long, long long>left, right;

        for(auto &x : arr){
            right[x]++;
        }

        long long ans = 0;
        for(int j=0; j<n; j++){
            right[arr[j]]--;

            long long target = arr[j] * 2LL;
            long long leftCnt = left[target];
            long long rightCnt = right[target];
            ans += leftCnt * rightCnt;

            left[arr[j]]++;
        }
        return ans % MOD;
    }

};

int main(){

    /*
    1. Build a frequency map right of all elements (counts of elements to the right of the 
    current j, initially the whole array).
    2. Initialize an empty frequency map left (counts of elements to the left of j).
    3. Iterate j from 0 to n-1:
        --> Remove nums[j] from right (we are considering j now, so it shouldn’t be counted in right).
        --> Let target = 2LL * nums[j].
        --> leftCount = left[target] (how many i < j have nums[i] == target)
        --> rightCount = right[target] (how many k > j have nums[k] == target)
        --> Add leftCount * rightCount to the answer.
        --> Add nums[j] to left (we move j into the left side for future iterations).
    */

    return 0;
}