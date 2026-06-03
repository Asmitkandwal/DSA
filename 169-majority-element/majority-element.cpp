class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 'candidate' stores the number we currently think is the majority.
        // 'count' is like a health bar or a vote tracker for that candidate.
        int count = 0;
        int candidate = 0;

        // Loop through every number in the array
        for (int num : nums) {
            
            // 1. IF THE HEALTH BAR HITS 0:
            // This means the previous candidate's votes were completely 
            // wiped out/canceled by other numbers. 
            // We must now crown the current number as the new candidate.
            if (count == 0) {
                candidate = num;
            }
            
            // 2. IF THE CURRENT NUMBER MATCHES OUR CANDIDATE:
            // Awesome! They get another vote. Their health bar goes up.
            if (num == candidate) {
                count++;
            } 
            
            // 3. IF IT'S A DIFFERENT NUMBER:
            // It fights our candidate. They cancel each other out, 
            // so our candidate loses a vote (health bar goes down).
            else {
                count--;
            }
        }

        // After all the cancellations, whoever is left standing is guaranteed
        // to be the majority element (since it had more than 50% of the total votes).
        return candidate;
    }
};