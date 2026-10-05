#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Ensure nums1 is smaller to avoid negative cuts in nums2
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n1 = nums1.size();
        int n2 = nums2.size();
        int total = n1 + n2;

        // ====================================================
        // CASE 1: EVEN TOTAL LENGTH
        // ====================================================
        if (total % 2 == 0) {
            int half = total / 2; 
            int low = 0, high = n1;

            while (low <= high) {
                int cut1 = low + (high - low) / 2;
                int cut2 = half - cut1;

                // Pick values (or INT_MIN / INT_MAX if cut is at boundary)
                int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
                int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
                int r1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
                int r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

                // Check valid partition
                if (l1 <= r2 && l2 <= r1) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                } 
                else if (l1 > r2) {
                    high = cut1 - 1;
                } 
                else {
                    low = cut1 + 1;
                }
            }
        } 
        // ====================================================
        // CASE 2: ODD TOTAL LENGTH (e.g., total = 7)
        // ====================================================
        else {
            int half = (total + 1) / 2; // Left side gets 1 extra element
            int low = 0, high = n1;

            while (low <= high) {
                int cut1 = low + (high - low) / 2;
                int cut2 = half - cut1;

                int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
                int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
                int r1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
                int r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

                // Check valid partition
                if (l1 <= r2 && l2 <= r1) {
                    // The median is simply the largest element in the left half
                    return max(l1, l2);
                } 
                else if (l1 > r2) {
                    high = cut1 - 1;
                } 
                else {
                    low = cut1 + 1;
                }
            }
        }

        return 0.0;
    }
};