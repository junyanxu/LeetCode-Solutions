class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        int bucket_size = (mx-mn)/nums.size() + 1;
        vector<int> bucket_min(nums.size(), INT_MAX);
        vector<int> bucket_max(nums.size(), INT_MIN);
        unordered_set<int> s;
        for(int d:nums){
            int idx = (d - mn)/bucket_size;
            bucket_min[idx] = min(bucket_min[idx], d);
            bucket_max[idx] = max(bucket_max[idx], d);
            s.insert(idx);
        }
        int pre=0, res=0;
        for(int i=1; i<nums.size(); i++){
            if(!s.count(i)) continue;
            res = max(res, bucket_min[i] - bucket_max[pre]);
            pre = i;
        }
        return res;
    }
};
