#include<bits/stdc++.h>
using namespace std;

/*
A conveyor belt has packages that must be shipped from one port to another within days days.
The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on 
the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity 
of the ship.
Return the least weight capacity of the ship that will result in all the packages on the conveyor belt 
being shipped within days days.
*/

int findDays(vector<int> &weights, int cap) {
    
    int days = 1; //First day.
    int load = 0;
    int n = weights.size(); //size of array.

    for (int i = 0; i < n; i++) {
        if (load + weights[i] > cap) {
            days += 1; //move to next day
            load = weights[i]; //load the weight.
        }
        else {
            //load the weight on the same day.
            load += weights[i];
        }
    }
    return days;
}

int leastWeightCapacity(vector<int> &weights, int d) {
    //Find the maximum and the summation:
    int maxi = *max_element(weights.begin(), weights.end());
    int sum = accumulate(weights.begin(), weights.end(), 0);

    for (int i = maxi; i <= sum; i++) {
        if (findDays(weights, i) <= d) {
            return i;
        }
    }
    //dummy return statement:
    return -1;
}


// Optimal 

class Solution {
public:

    int FindDays(vector<int>& weights, int cap){
        int day = 1;
        int load = 0;
        int n = weights.size();
        for(int i=0; i<n; i++){
            if(load + weights[i] > cap){
                day = day + 1;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return day;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low<=high){
            int mid = (low+high)/2;
            int noOfDays = FindDays(weights, mid);
            if(noOfDays <= days){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};

int main()
{
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;
    int ans = leastWeightCapacity(weights, d);
    cout << "The minimum capacity should be: " << ans << "\n";
    return 0;
}