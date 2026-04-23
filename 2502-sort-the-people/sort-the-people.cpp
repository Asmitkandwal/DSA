class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {

        unordered_map<int, string> mpp;

        // Store mapping: height -> corresponding name
        for (int i = 0; i < heights.size(); i++) {
            mpp[heights[i]] = names[i];
        }

        // Sort heights in increasing order first
        sort(heights.begin(), heights.end());

        // Reverse to get tallest to shortest order
        reverse(heights.begin(), heights.end());

        vector<string> new_names;

        // Use sorted heights to fetch names in required order
        for (int i = 0; i < heights.size(); i++) {
            new_names.push_back(mpp[heights[i]]);
        }

        return new_names;
    }
};