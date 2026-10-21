class Solution {
public:
    long long check(vector<int>&p, int& k){
        long long sum = 0;
        for(int i = 0; i < p.size(); i++){
            sum += (p[i] + k - 1) / k;
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = 1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(check(piles, mid) > h){
                low = mid + 1;
            }
            else{
                ans = mid;
                high = mid - 1;
            }
        }

        return low;
    }
};