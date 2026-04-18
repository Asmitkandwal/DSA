class Solution {
public:
    bool isPalindrome(int x) {

        // Store original value to compare later
        int temp = x;

        // long long to escape from overflow
        long long rev = 0;

        // Negative numbers are never palindrome
        if (x < 0) return false;

        // Reverse the number
        while (temp != 0) {

            // Get last digit
            int t = temp % 10;

            // Add digit to reversed number
            rev = (rev * 10) + t;

            // Remove last digit from temp
            temp = temp / 10;
        }

        // Check if original number and reversed number are same
        if (rev == x) return true;

        // If not same, it's not a palindrome
        return false;
    }
};