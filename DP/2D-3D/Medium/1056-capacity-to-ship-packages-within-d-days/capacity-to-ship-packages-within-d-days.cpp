class Solution {
public:
    int checker(vector<int>&w, int m){
        int cnt = 1, sum = 0;
        for(int i = 0; i < w.size(); i++){
            if(m >= w[i] + sum)
                sum += w[i];
            else{
                cnt++;
                sum = w[i];
            }   
        }
        return cnt;
    }
    int shipWithinDays(vector<int>& w, int d) {
        int l = *max_element(w.begin(), w.end());
        int h = accumulate(w.begin(), w.end(), 0);

        while(l <= h){
            int mid = l + (h - l)/2;
            if(checker(w, mid) > d)
                l = mid + 1;
            else 
                h = mid - 1;
        }
        return l;
    }
};