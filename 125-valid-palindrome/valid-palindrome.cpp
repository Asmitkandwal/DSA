class Solution {
public:
    bool isPalindrome(string s) {
        string rev ;
        for(int i = 0;i<s.length();i++){
            if(isalnum(s[i])){
                rev += tolower(s[i]);
            }
        }
        string rev2 = rev;
        reverse(rev.begin(),rev.end());
        return rev==rev2;

    }
};