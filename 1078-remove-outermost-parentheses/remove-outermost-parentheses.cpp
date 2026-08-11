// REMOVE OUTERMOST PARENTHESES USING DEPTH TRACKING

class Solution {
public:
    string removeOuterParentheses(string s) {

        string ans = "";
        int depth = 0;

        for (char c : s) {

            if (c == '(') {

                // If depth > 0 → this is NOT outermost
                // So we keep it
                if (depth > 0) ans += c;

                // Increase depth after processing
                depth++;
            }

            else {

                // Decrease depth first (closing bracket)
                depth--;

                // If depth > 0 → still inside inner layer
                // So keep it
                if (depth > 0) ans += c;
            }
        }

        return ans;
    }
};