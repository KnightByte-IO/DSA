class Solution {
public:
    int check(vector<int>&b, int k, int d){
        int ans = 0;
        int counter = 0;
        for(int i = 0; i < b.size(); i++){
            if(b[i] <= d){
                counter++;
            }
            else{
                ans += (counter/k);
                counter = 0;
            }
        }
        ans += (counter/k);
        return ans;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        long long val = m*1LL*k*1LL;

        if(val > bloomDay.size()) return -1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(check(bloomDay, k, mid) >= m){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};