#include <vector>
#include <algorithm> // Required for std::max

class Solution {
public:
    std::vector<int> replaceElements(std::vector<int>& arr) {
        // 1. INITIALIZE THE 'NOTEPAD'
        // The problem states that the last element has no elements to its right,
        // so its replacement value must always be -1.
        int max_so_far = -1;
        
        // 2. LOOP BACKWARDS (Right to Left)
        // We start at the last index (arr.size() - 1) and move down to 0.
        // NOTE: We use a signed 'int' for 'i'. If we used unsigned 'size_t',
        // 'i >= 0' would always be true, causing an infinite loop.
        for (int i = arr.size() - 1; i >= 0; --i) {
            
            // 3. TEMPORARILY SAVE THE CURRENT VALUE
            // We must remember the original value of arr[i] before we overwrite it,
            // because we will need this original value to update 'max_so_far' 
            // for the next element to the left.
            int current_val = arr[i];
            
            // 4. OVERWRITE THE CURRENT ELEMENT
            // Replace the current element with the largest value found to its right
            // (which is conveniently stored in our 'max_so_far' variable).
            arr[i] = max_so_far;
            
            // 5. UPDATE THE 'NOTEPAD' FOR THE NEXT ITERATION
            // The next element to the left will consider this current element as part
            // of its "right side". So, we update 'max_so_far' to be the higher value
            // between what it already was and the original value we just replaced.
            max_so_far = std::max(max_so_far, current_val);
        }
        
        // 6. RETURN THE MODIFIED ARRAY
        // Since we modified 'arr' in-place, we just return it. 
        // This gives us a space complexity of O(1).
        return arr;
    }
};