class Solution {
public:
    int check(vector<int>& num, int mid){
        int count = 1;
        int student = 0;
        for(int i = 0; i < num.size(); i++){
            if(student + num[i] <= mid){
                student += num[i];
            }
            else{
                count++;
                student = num[i];
            }
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(check(nums, mid) > k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
};