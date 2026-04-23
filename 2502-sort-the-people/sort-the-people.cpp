class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int,string> mpp;
        for(int i = 0;i<heights.size();i++){
            mpp.insert({heights[i],names[i]});
        }
        sort(heights.begin(),heights.end());
        reverse(heights.begin(),heights.end());

        vector<string> new_names;
        for(int i = 0;i<heights.size();i++){
            new_names.push_back(mpp[heights[i]]);
        }
        return new_names;


    }
};