class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        int n = A.size();
        int i=0;
        while(i<n) {
            if(A[i]!=i+1 && A[i]>0 && A[i]<=n && A[i]!=A[A[i]-1])
                swap(A[i],A[A[i]-1]);
            else
                i++;
            for(auto x: A){cout << x << " ";}
            cout << "i:" << i;
            cout << endl;
        }
        for(int i=0; i<n; i++) {
            if(A[i]!=i+1) return i+1;
        }
        return n+1;
    }
};
