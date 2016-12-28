/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(Interval&a, Interval&b){
    if(a.start < b.start){
        return true;
    }
    else if(a.start > b.start){
        return false;
    }
    else{
        return a.end < b.end;
    }
}

class Solution {
public:


    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if(intervals.empty()){return res;}
        sort(intervals.begin(), intervals.end(), compare);
        Interval curr = intervals[0];
        for(int i=1; i< intervals.size(); i++){
            if(intervals[i].start > curr.end){
                res.push_back(curr);
                curr = intervals[i];
            }
            else{
                curr.end = max(intervals[i].end, curr.end);
            }
        }
        res.push_back(curr);
        return res;
    }


};
