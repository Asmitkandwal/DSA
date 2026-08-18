class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int n = s.length();

        // Skip leading whitespaces
        while (i < n && s[i] == ' ')
            i++;

        // Determine sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        // Skip leading zeros
        while (i < n && s[i] == '0')
            i++;

        long long ans = 0;

        while (i < n && isdigit(s[i])) {

            int digit = s[i] - '0';

            // Check if adding this digit causes overflow
            if (ans > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            ans = ans * 10 + digit;
            i++;
        }

        return sign * ans;
    }
};