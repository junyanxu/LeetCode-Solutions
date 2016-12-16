class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int i = 0, j = 0, mid1 = 0, mid2 = 0;
        int count = 0;
           //check input
           if (len1 + len2 == 0)return NULL;
           while (1){
                  count++;
                  if (count == (len1 + len2) / 2){
                        if (i == len1) { mid1 = nums2[j]; j++; }
                        else if (j == len2) { mid1 = nums1[i]; i++; }
                        else if (nums1[i]<nums2[j]) { mid1 = nums1[i]; i++; }
                        else { mid1 = nums2[j]; j++; }
                        continue;
                  }
                  else if (count == (len1 + len2) / 2 + 1){
                        if (i == len1) { mid2 = nums2[j]; j++; }
                        else if (j == len2) { mid2 = nums1[i]; i++; }
                        else if (nums1[i]<nums2[j]) { mid2 = nums1[i]; i++; }
                        else { mid2 = nums2[j]; j++; }
                        break;
                  }
                  //updtate the index
                  if (i == len1) { j++; }
                  else if (j == len2) { i++; }
                  else if (nums1[i]<nums2[j]) { i++; }
                  else { j++; }
           }
           //calculate median
           double fn = (len1 + len2) % 2 == 0 ? double(mid1 + mid2) / 2 : mid2;
           return fn;
    }
};
