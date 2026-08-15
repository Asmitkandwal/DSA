class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mpp;
        string ans = "";
        vector<pair<char,int>> freq;
        for(int i = 0;i<s.length();i++){
            mpp[s[i]]++;
        }
        for(auto it:mpp){
            freq.push_back({it.first,it.second});
        }
        
        sort(freq.begin(), freq.end(), [](auto a, auto b) {
        return a.second > b.second;
        });

        for(auto it : freq){
            for(int i = 0;i<it.second;i++){
                ans += it.first;
            }
        }
        return ans;
    }
};