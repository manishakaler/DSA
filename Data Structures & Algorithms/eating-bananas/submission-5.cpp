#include<cmath>
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = 1;
        int n = piles.size();

        for(int i = 0; i < n ; ++i){
            maxPile = max(maxPile, piles[i]);
        }
        int res = maxPile;

        int left = 1;
        int right = res;

        while(left <= right){
            int midk = left + (right - left)/2;
            long long totalTime = 0;

            for(int pile: piles){
                totalTime += (int)ceil((double)pile/midk);
            }

            if(totalTime <= h){
                res = midk;
                right = midk-1;
            } else {
                left = midk + 1;
            }

        }

        return res;

    }
};
