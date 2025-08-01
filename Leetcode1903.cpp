#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string largestOddNumber(string num){
        int n = num.length();
        for(int i=n-1; i>=0;i--){
            int x = num[i] - '0';
            if(x % 2 != 0 ){
                return num.substr(0, i+1);
            }
        }
        return "";
    }
};

/*
Why this works:
It goes from end to start (greedy step).
Finds the rightmost odd digit.
Returns substring from 0 to that index (inclusive).
If no odd digit, returns empty string.
*/


int main(){

    cout<<"You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string. if no odd integer exists.A substring is a contiguous sequence of characters within a string."<<endl;

    return 0;
}