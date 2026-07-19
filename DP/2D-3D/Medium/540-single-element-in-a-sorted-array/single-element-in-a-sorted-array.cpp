class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        int l = 0;
        int r = n-1;

        while(l < r){
            int mid = l + (r - l)/2;
            //a,a
            if(arr[mid] == arr[mid+1]){
                //a,a.....odd..length
                if((r-mid-1)%2){
                    l = mid + 2;
                }
                else{
                    r = mid-1;
                }
            }
            else {
                //a,b.....odd..length
                if((r-mid-1)%2){
                   r = mid;
                }
                else{
                    l = mid + 1;
                }
            }
        }

        return arr[r];
    }
};

