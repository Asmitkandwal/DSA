// PROBLEM: Convert Roman numeral string to integer
// CORE IDEA:
// Instead of memorizing special pairs (IV, IX, XL...),
// use ONE RULE:
//    If a smaller value comes before a bigger value → subtract
//    Otherwise → add

class Solution {
public:
    int romanToInt(string s) {

        // Step 1: Map each Roman symbol to its numeric value
        unordered_map<char,int> mpp = {
            {'I',1}, {'V',5}, {'X',10},
            {'L',50}, {'C',100}, {'D',500}, {'M',1000}
        };

        int val = 0; // final answer

        // Step 2: Traverse string from left → right
        for (int i = 0; i < s.length(); i++) {

            // Look at current symbol and the NEXT symbol
            // (we need next to decide add or subtract)
            if (i + 1 < s.length() && mpp[s[i]] < mpp[s[i + 1]]) {

                // CASE 1: current < next → subtract
                // Example: I before V → IV = 5 - 1 = 4
                val -= mpp[s[i]];
            } 
            else {

                // CASE 2: current >= next OR last element → add
                // Example: V → just add 5
                val += mpp[s[i]];
            }
        }

        // Step 3: return computed value
        return val;
    }
};