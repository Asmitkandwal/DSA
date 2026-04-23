class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {

        int n = heights.size();

        // Place correct tallest person at each position
        for (int i = 0; i < n; i++) {

            int maxIndex = i;

            // Find tallest person from remaining unsorted part
            for (int j = i + 1; j < n; j++) {
                if (heights[j] > heights[maxIndex]) {
                    maxIndex = j;
                }
            }

            // Put tallest height at current position
            swap(heights[i], heights[maxIndex]);

            // Swap name too, so mapping stays correct
            swap(names[i], names[maxIndex]);
        }

        return names;
    }
};