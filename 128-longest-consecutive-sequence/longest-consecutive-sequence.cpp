class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        unordered_set<int> st(nums.begin(),nums.end());
        for(int i : st){
            if(st.find(i-1) == st.end()){
                int current = i;
                int count = 1;

                while(st.find(current +1) != st.end()){
                    current += 1;
                    count += 1;
                }
                longest = max(longest,count);
            }
        }

        return longest;
    }
};