// MAX DEPTH OF PARENTHESES

class Solution {
public:
    int maxDepth(string s) {

        int depth = 0;       // current nesting level
        int maxDepth = 0;    // maximum seen so far

        for (char c : s) {

            if (c == '(') {

                // Going deeper into nesting
                depth++;

                // Track maximum depth reached
                maxDepth = max(maxDepth, depth);
            }

            else if (c == ')') {

                // Coming out of nesting
                depth--;
            }
        }

        return maxDepth;
    }
};