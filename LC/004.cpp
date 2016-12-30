
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if((nums1.size()+nums2.size())%2==1){
            return findKth(nums1, nums2, 0, 0, nums1.size(), nums2.size(), (nums1.size()+nums2.size())/2+1);
        }
        else{
            return 0.5*(findKth(nums1, nums2, 0, 0, nums1.size(), nums2.size(), (nums1.size()+nums2.size())/2) +
            findKth(nums1, nums2, 0, 0, nums1.size(), nums2.size(), (nums1.size()+nums2.size())/2+1));
        }
    }
    int findKth(vector<int>&nums1, vector<int>&nums2, int s1, int s2, int l1, int l2, int k){
        int mid1 = s1 + l1/2;
        int mid2 = s2 + l2/2;
        if(l1==0) return nums2[s2+k-1];
        if(l2==0) return nums1[s1+k-1];
        if(nums1[mid1] <= nums2[mid2]){
            if(k > l1/2 + l2/2 +1){
                return findKth(nums1, nums2, mid1+1, s2, l1-l1/2-1, l2, k-l1/2-1);
            }
            else{
                return findKth(nums1, nums2, s1, s2, l1, l2/2, k);
            }
        }
        else{
            if(k > l1/2 + l2/2 +1){
                return findKth(nums1, nums2, s1, mid2+1, l1, l2-l2/2-1, k-l2/2-1);
            }
            else{
                return findKth(nums1, nums2, s1, s2, l1/2, l2, k);
            }
        }
    }
};
