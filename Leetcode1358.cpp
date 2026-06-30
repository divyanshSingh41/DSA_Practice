#include<bits/stdc++.h>
using namespace std;

/*
Given a string s consisting only of characters a, b and c.
Return the number of substrings containing at least one occurrence of all these characters a, b and c.

Example 1:
Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c 
are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" 
*/

/*
**********************************1. Brute Force — O(n³)******************************************************
Generate every substring and check whether it contains all three characters.
Steps
Pick every starting index.
Pick every ending index.
Scan the substring and check if a, b, and c are present.
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                bool a = false, b = false, c = false;

                for (int k = i; k <= j; k++) {
                    if (s[k] == 'a') a = true;
                    else if (s[k] == 'b') b = true;
                    else c = true;
                }

                if (a && b && c)
                    ans++;
            }
        }

        return ans;
    }
};

/*
******************************************************2. Better — O(n²)*************************************************
Instead of rescanning every substring, maintain frequencies while extending the right end.
For each starting index:

Keep a frequency array.
Expand the right pointer.
As soon as all three characters appear, every longer substring is also valid.
So add: n - j
*/

class Solution2 {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {

            vector<int> freq(3, 0);

            for (int j = i; j < n; j++) {

                freq[s[j] - 'a']++;

                if (freq[0] && freq[1] && freq[2]) {
                    ans += (n - j);
                    break;
                }
            }
        }

        return ans;
    }
};

/*
******************************************3. Optimal (Sliding Window) — O(n)****************************************
Whenever the current window contains
a, b, and c,
then every extension to the right is also valid.
So while the window is valid,
answer += n - right
then shrink from the left until it becomes invalid.
*/

class Solution3 {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        vector<int> freq(3, 0);
        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {

            freq[s[right] - 'a']++;

            while (freq[0] && freq[1] && freq[2]) {

                ans += (n - right);

                freq[s[left] - 'a']--;
                left++;
            }
        }

        return ans;
    }
};

int main() {

    return 0;
}