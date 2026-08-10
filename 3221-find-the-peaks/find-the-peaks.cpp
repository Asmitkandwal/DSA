// FIND ALL PEAK ELEMENT INDICES

class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {

        vector<int> ans;

        // We skip first and last element
        // because they cannot have two neighbors
        for (int i = 1; i < mountain.size() - 1; i++) {

            // A peak must be strictly greater than both neighbors
            if (mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};