#include<bits/stdc++.h>
using namespace std;


// O(N^3)

/*
Tries all possible 3-digit combinations (using different indices)
Checks if:
First digit ≠ 0
Last digit is even
Uses set to eliminate duplicates
Converts result to vector<int>
*/
class Solution1 {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> result;  // To avoid duplicates

        int n = digits.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == i) continue;
                for (int k = 0; k < n; ++k) {
                    if (k == i || k == j) continue;

                    int d1 = digits[i];
                    int d2 = digits[j];
                    int d3 = digits[k];

                    // First digit cannot be 0, last digit must be even
                    if (d1 == 0 || d3 % 2 != 0) continue;

                    int num = d1 * 100 + d2 * 10 + d3;
                    result.insert(num);
                }
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};


// optimise

/*
There are only 900 possible 3-digit numbers (100–999).
We check each of them:
Is it even?
Can it be formed using digits from the input without reusing digits more than available?
*/

class Solution2 {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int freq[10] = {0};
        for (int d : digits) {
            freq[d]++;
        }

        vector<int> result;
        for (int num = 100; num <= 999; ++num) {
            if (num % 2 != 0) continue; // Must be even

            int a = num / 100;
            int b = (num / 10) % 10;
            int c = num % 10;

            // Count digits of num
            int count[10] = {0};
            count[a]++;
            count[b]++;
            count[c]++;

            // Check if original freq has enough of each digit
            bool valid = true;
            for (int d = 0; d <= 9; ++d) {
                if (count[d] > freq[d]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                result.push_back(num);
            }
        }

        return result;
    }
};



int main(){

    cout<<"Given an array digits (containing digits 0–9), form all unique 3-digit even numbers using exactly 3 digits from the array, without reusing any digit more than once in a number. You return the list of all such 3-digit even numbers in ascending order."<<endl;
    
    return 0;
}