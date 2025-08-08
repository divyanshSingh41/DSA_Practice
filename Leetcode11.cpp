#include<bits/stdc++.h>
using namespace std;

// Brute Force
class Solution1 {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int h = min(height[i], height[j]);
                int area = h * (j - i);
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};


// OPTIMAL - Using Two Pointers
class Solution2 {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;
        int area = 0, maxArea = 0;
        while(start<end){
            int h = min(height[start], height[end]);
            area = (end-start) * h;
            maxArea = max(area, maxArea);
            if(height[start]<height[end]){
                start++;
            } else{
                end--;
            }
        }
        return maxArea;
    }
};

int main(){

    cout<<"You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]). Find two lines that together with the x-axis form a container, such that the container contains the most water. Return the maximum amount of water a container can store."<<endl;
    /*
    You are given an integer array height of length n. There are n vertical lines drawn such that the two 
    endpoints of the ith line are (i, 0) and (i, height[i]).
    Find two lines that together with the x-axis form a container, such that the container contains the most water.
    Return the maximum amount of water a container can store.
    */

    return 0;
}