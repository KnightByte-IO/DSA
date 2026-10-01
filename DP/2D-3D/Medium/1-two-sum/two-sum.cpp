class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int n = 0; n < nums.size(); n++){
            if(mp.find(target - nums[n]) != mp.end()){
                return {n, mp[target - nums[n]]}; 
            }
            mp[nums[n]] = n;
        }
        return {};
    }
};