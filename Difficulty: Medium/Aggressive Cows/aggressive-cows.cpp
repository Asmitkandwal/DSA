class Solution {
  public:
  
  
  
  bool isValid(vector<int>& stalls, int cows, int minDistance)
{
   int totalStalls = stalls.size();
   int cowsPlaced = 1;
   int currentIndex = 1;
   int lastPlacedIndex = 0;


   while (currentIndex < totalStalls && cowsPlaced < cows)
   {
       if (stalls[currentIndex] - stalls[lastPlacedIndex] >= minDistance) {
           cowsPlaced++;
           lastPlacedIndex = currentIndex;
       }
       currentIndex++;
   }
   return (cowsPlaced == cows);
   }
   
   
  
  
    int aggressiveCows(vector<int> &stalls, int cows) {
          int totalStalls = stalls.size();
   sort(stalls.begin(), stalls.end());


   int low = 1;
   int high = stalls[totalStalls - 1] - stalls[0];
   int maxMinDistance = 1;


   while (low <= high)
   {
       int mid = (low + high) / 2;


       if (isValid(stalls, cows, mid)) {
           maxMinDistance = mid;
           low = mid + 1;
       } else {
           high = mid - 1;
       }
   }
   return maxMinDistance;
 
        
    }
};