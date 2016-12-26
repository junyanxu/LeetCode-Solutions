class Solution {
public:
    vector<int> searchRange(vector<int>A, int target) {
        int n = A.size();
        vector<int> range;
        range.push_back(findLeft(A, target));
        range.push_back(findRight(A, target));
        return range;
    }

    int findLeft(vector<int>A, int target){
        int left = 0;
        int right = A.size()-1;
        int mid;
        while(left <= right){
            mid = (left + right)/2;
            if(A[mid] == target){right = mid-1;}
            else if(A[mid] > target){right = mid -1;}
            else {left = mid+1;}
        }
        if(left > -1&& left < A.size() && A[left] == target){return left;}
        return -1;
    }

    int findRight(vector<int>A, int target){
        int left = 0;
        int right = A.size()-1;
        int mid;
        while(left <= right){
            mid = (left + right)/2;
            cout << mid << endl;
            if(A[mid] == target){left = mid+1;}
            else if(A[mid] > target){right = mid -1;}
            else {left = mid+1;}
            cout << right << endl;
        }
        if(right > -1 && right < A.size() && A[right] == target){return right;}
        return -1;
    }
};
