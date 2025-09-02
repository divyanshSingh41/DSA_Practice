/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and 
removing all non-alphanumeric characters, 
it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string newS = "";
        for(int i=0; i<s.size();i++){
            char c = s[i];

            if((c>='A' && c<='Z')){
                c = c + 32;
                newS += c;
            }
            else if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
                newS += c;
            }
        }
  
        int left = 0, right = newS.size() - 1;
        while (left < right) {
            if (newS[left] != newS[right]) return false;
                left++;
                right--;
            }
        return true; 
    }
};


int main(){


    return 0;
}