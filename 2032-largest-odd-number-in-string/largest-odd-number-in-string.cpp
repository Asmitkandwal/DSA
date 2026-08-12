// BRUTE FORCE - FIND LAST ODD DIGIT

class Solution {
public:
    string largestOddNumber(string num) {

        int lastodd = -1;

        // Traverse entire string to find last odd digit
        for (int i = 0; i < num.size(); i++) {

            // Convert char to int → check odd
            if ((num[i] - '0') % 2 != 0) {
                lastodd = i;  // keep updating → last odd index
            }
        }

        // If no odd digit found → no valid answer
        if (lastodd == -1) {
            return "";
        }

        // Return substring from start to last odd index
        return num.substr(0, lastodd + 1);
    }
};