#include<bits/stdc++.h>
using namespace std;
/*
Problem Summary
Koko has n piles of bananas.
piles[i] = bananas in the ith pile.
She can eat k bananas per hour.
In one hour, she chooses only one pile.
If the pile has fewer than k bananas, she eats all of them and waits until the next hour.
You are given h hours.
Find the minimum eating speed k so that Koko finishes all bananas within h hours.
*/

bool canFinish(vector<int>& piles, int speed, int h) {
    long long hours = 0;

    for (int x : piles) {
        hours += (x + speed - 1) / speed;
    }

    return hours <= h;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int l = 1;
    int r = *max_element(piles.begin(), piles.end());

    int ans = r;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (canFinish(piles, mid, h)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return ans;
}


int main(){

    return 0;
}