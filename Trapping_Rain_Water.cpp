/*
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, 
 * compute how much water it is able to trap after raining.
 */
class Solution {
  public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
      // write your code here
      if(heights.size() < 3) return 0;
      int i = 0, j = heights.size() - 1;
      int currLevel = min(heights[i], heights[j]);
      int result = 0;
      while(i < j) {
	if(heights[i] < heights[j]) {
	  if(heights[i + 1] < currLevel) {
	    result += currLevel - heights[i + 1];
	  }
	  currLevel = max(currLevel, min(heights[i + 1], heights[j]));
	  i++;
	}
	else {
	  if(heights[j - 1] < currLevel) {
	    result += currLevel - heights[j - 1];
	  }
	  currLevel = max(currLevel, min(heights[i], heights[j - 1]));
	  j--;
	}
      }
      return result;
    }
};

