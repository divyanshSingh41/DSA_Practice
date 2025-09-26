#include<bits/stdc++.h>
using namespace std;

/*
Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int left = 0;
        int right = n-1;
        while(left<right){
            char c = s[left];
            char d = s[right];
            s[left] = d;
            s[right] = c;
            left++;
            right--;
        }
    }
};

// Or

class Solution2 {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());  // one-liner
    }
};

// Or
class Solution3 {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            swap(s[left], s[right]);  // built-in swap
            left++;
            right--;
        }
    }
};


int main(){
    return 0;
}