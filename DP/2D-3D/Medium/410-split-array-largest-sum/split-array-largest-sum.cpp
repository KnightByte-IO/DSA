class Solution {
public:
    int checker(vector<int>&arr, int mid){
        int paints = 1;
        long long painted = 0;
        for(int i = 0; i < arr.size(); i++){
            if(painted + arr[i] <= mid){
                painted += arr[i];
            }
            else{
                paints++;
                painted = arr[i];
            }
        }
        return paints;
    }
    int splitArray(vector<int>& n, int k) {
        int size = n.size();
        if(size < k) return -1;

        long long low = *max_element(n.begin(), n.end());
        long long high = accumulate(n.begin(), n.end(), 0);

        while(low <= high){
            int mid = low + (high - low)/2;
            if(checker(n, mid) > k){
                low = mid + 1;
            } 
            else{
                high = mid - 1;
            }
        }

        return low;
    }
};