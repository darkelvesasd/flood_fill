class Solution {
public:
  typedef pair<int, int> PII;
int mx[4] = { -1,0,0,1 };
int my[4] = { 0,-1,1,0 };
int numIslands(vector<vector<char>>& grid) {
	if (grid.size() == 0)
	{
		return 0;
	}
	int count=0;
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<bool>> vb(m,vector<bool>(n));
	queue<PII>q;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (grid[i][j] == '1'&&vb[i][j]==false)
			{
				count++;
				q.push(PII(i,j));
				while (!q.empty())
				{
					PII pt = q.front();
					q.pop();
					for (int k=0;k<4;k++)
					{
						int x = pt.first+mx[k];
						int y = pt.second+my[k];
						if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1'&&vb[x][y]==false)
						{
							q.emplace(PII(x,y));
							vb[x][y] = true;
						}
					}
				}
				vb[i][j] = true;
			}
		}
	}
	return count;
}
};
