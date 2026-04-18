class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x;
        long long rev = 0;
        if (x<0) return false;

        while(temp != 0){
            int t = temp%10;
            rev = (rev*10)+t;
            temp = temp/10;

        }

        if(rev == x) return true;
        return false;
    }
};