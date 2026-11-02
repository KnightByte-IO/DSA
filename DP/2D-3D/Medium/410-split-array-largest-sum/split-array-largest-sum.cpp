class Solution {
public:
    long long check(vector<int>& nums, int sum){
        long long count = 1;
        long long add = 0;
        for(long long i = 0; i < nums.size(); i++){
            if(add + nums[i] <= sum){
                add += nums[i];
            }
            else{
                count++;
                add = nums[i];
            }
        }

        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        long long n = nums.size();
        long long l = *max_element(nums.begin(), nums.end());
        long long h = accumulate(nums.begin(), nums.end(), 0LL);

        while(l <= h){
            long long mid = l + (h - l) / 2;
            if(check(nums, mid) > k)
                l = mid + 1;
            else
                h = mid - 1;
        }

        return l;
    }
};