class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> mpp;
        int vowel = 0;
        int consonent = 0;
        for(int i = 0;i<s.length();i++){
            mpp[s[i] - 'a']++;
            int temp = mpp[s[i]-'a'] ;
            if(s[i] == 'a'||s[i] == 'e'||s[i] == 'i'||s[i] == 'o'||s[i] == 'u'){
                vowel = max(temp,vowel);
            }
            else {
                consonent = max(temp,consonent);
            }
        }
        return (vowel+consonent);

    }
};