class Solution {
  public:
    /**
     * @param heights: a matrix of integers
     * @return: an integer
     */
    struct Cell{
      int i; int j; int height;
    };
    class Compare {
      public:
	bool operator()(const Cell& a, const Cell& b) {
	  return a.height > b.height;
	}
    };
    int trapRainWater(vector<vector<int> > &heights) {
      // write your code here
      priority_queue<Cell ,vector<Cell>, Compare> pq;
      int m = heights.size();
      if(!m) return 0;
      int n = heights[0].size();
      vector<vector<bool> > is_visited(m, vector<bool>(n, false));
      for(int i = 0; i < m; i++) {
	pq.emplace(Cell{i, 0, heights[i][0]});
	pq.emplace(Cell{i, n - 1, heights[i][n - 1]});
	is_visited[i][0] = 1;
	is_visited[i][n - 1] = 1;
      }
      for(int j = 0; j < n; j++) {
	pq.emplace(Cell{0, j, heights[0][j]});
	pq.emplace(Cell{m - 1, j, heights[m - 1][j]});
	is_visited[0][j] = 1;
	is_visited[m - 1][j] = 1;
      }
      int dx[4] = {1,-1,0,0};
      int dy[4] = {0,0,1,-1};
      int result = 0;
      while(!pq.empty()) {
	Cell c = pq.top();
	pq.pop();
	for(int i = 0; i < 4; i++) {
	  int nx = c.i + dx[i];
	  int ny = c.j + dy[i];
	  if(nx >= 0 && nx < m && ny >= 0 && ny < n && !is_visited[nx][ny]) {
	    is_visited[nx][ny] = 1;
	    pq.emplace(Cell{nx, ny, max(c.height, heights[nx][ny])});
	    result += max(0, c.height - heights[nx][ny]);
	  }
	}
      }
      return result;
    }
};

// v2
class Solution {
  public:
    /**
     * @param heights: a matrix of integers
     * @return: an integer
     */
    struct Cell {
      int x, y, h;
    };
    class Compare {
      public:
	bool operator() (Cell a, Cell b) {
	  return a.h > b.h;
	}
    };
    int trapRainWater(vector<vector<int> > &heights) {
      // write your code here
      int m = heights.size();
      if(!m) return 0;
      int n = heights[0].size();
      priority_queue<Cell, vector<Cell>, Compare> pq;
      vector<vector<bool>> is_visited(m, vector<bool>(n, false));
      for(int i = 0; i < m; i++) {
	pq.emplace(Cell{i, 0, heights[i][0]});
	pq.emplace(Cell{i, n - 1, heights[i][n - 1]});
	is_visited[i][0] = 1;
	is_visited[i][n - 1] = 1;
      }
      for(int j = 0; j < n; j++) {
	pq.emplace(Cell{0, j, heights[0][j]});
	pq.emplace(Cell{m - 1, j, heights[m - 1][j]});
	is_visited[0][j] = 1;
	is_visited[m - 1][j] = 1;
      }
      int result = 0;
      while(!pq.empty()) {
	Cell c = pq.top();
	pq.pop();
	int dx[] = {1, -1, 0, 0};
	int dy[] = {0, 0, 1, -1};
	for(int i = 0; i < 4; i++) {
	  int nx = c.x + dx[i];
	  int ny = c.y + dy[i];
	  if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
	  if(is_visited[nx][ny]) continue;
	  is_visited[nx][ny] = 1;
	  result += max(0, c.h - heights[nx][ny]);
	  pq.emplace(Cell{nx, ny, max(c.h, heights[nx][ny])});
	}
      }
      return result;
    }
};

