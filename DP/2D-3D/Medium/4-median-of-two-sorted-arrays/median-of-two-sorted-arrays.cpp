class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        long long n1 = nums1.size();
        long long n2 = nums2.size();
        
        long long hv = (n1 + n2 + 1)/2;
        long long low = 0, high = n1;

        while(low <= high){
            long long mid1 = low + (high - low) / 2;
            long long mid2 = hv - mid1;
            long long l1, l2, r1, r2;

            if(mid1 == 0) l1 = INT_MIN;
            else l1 = nums1[mid1-1];
            if(mid2 == 0) l2 = INT_MIN;
            else l2 = nums2[mid2-1];
            if(mid1 == n1) r1 = INT_MAX;
            else r1 = nums1[mid1];
            if(mid2 == n2) r2 = INT_MAX;
            else r2 = nums2[mid2];

            if(l1 <= r2 && l2 <= r1){
                if((n1+n2) % 2 == 0) return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
                else return max(l1, l2);
            }
            else if(l1 > r2) high = mid1 - 1;
            else low = mid1 + 1;

        }
        return 0.0;
    }
};