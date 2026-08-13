class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // If the vector of strings is empty, there is no common prefix
        if (strs.empty()) return "";

        string ans = "";

        // Loop character by character through the FIRST string (column by column)
        for (int i = 0; i < strs[0].size(); i++) {
            char ch = strs[0][i];

            // Compare this character against the same column 'i' in all other strings
            for (int j = 1; j < strs.size(); j++) {
                
                // STOP CONDITION:
                // 1. Index 'i' goes past the end of string strs[j]
                // 2. Character in strs[j] does not match character 'ch'
                if (i >= strs[j].size() || ch != strs[j][i]) {
                    return ans; // Return the common prefix found so far
                }
            }

            // If all strings matched at index 'i', append character to answer
            ans += ch;
        } 

        return ans; // Whole first string is the common prefix
    }
};