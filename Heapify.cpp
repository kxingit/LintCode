/*
 * Given an integer array, heapify it into a min-heap array.
 */
class Solution {
  public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
      // write your code here
      for(int i = A.size() - 1; i >= 0; i--) {
	siftdown(A, i);
      }
    }
    void siftdown(vector<int> &A, int i) {
      while(i < A.size()) {
	int small = i;
	int child = i * 2 + 1;
	if(child < A.size() && A[child] < A[small]) {
	  small = child;
	}
	child = i * 2 + 2;
	if(child < A.size() && A[child] < A[small]) {
	  small = child;
	}
	if(small == i) return;
	swap(A[i], A[small]);
	i = small;
      }
    }
};

