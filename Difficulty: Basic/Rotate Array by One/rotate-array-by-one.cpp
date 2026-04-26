class Solution {
  public:
    void rotate(vector<int> &arr) {
        int n = arr.size();
        if (n <= 1) return; // Edge case: empty or single-element array

        // 1. Store the last element
        int temp = arr[n - 1];

        // 2. Shift elements to the right starting from the end
        // We move arr[i-1] to arr[i]
        for (int i = n - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }

        // 3. Place the stored element at the first position
        arr[0] = temp;
    }
};