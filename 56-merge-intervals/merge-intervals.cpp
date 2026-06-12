class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int i = 0;
        while(i<n){
            int start = intervals[i][0];
            int end = intervals[i][1];

            int j = i+1;
            while(j<n && intervals[j][0] <= end){
                end = max(intervals[j][1],end);
                j++;
            }

            ans.push_back({start,end});

            i = j;
        }

        return ans;
    }
};