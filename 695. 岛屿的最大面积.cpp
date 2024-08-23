class Solution {
public:
int mx[4] = { 0,0,-1,1 };
int my[4] = { -1,1,0,0 };
typedef pair<int, int> PII;
int maxAreaOfIsland(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<bool>>vb(m,vector<bool>(n));
	queue<PII> q;
	int ret = 0;
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (vb[i][j] == false && grid[i][j] == 1)
			{
				int sum = 0;
				q.emplace(PII(i,j));
				while (!q.empty())
				{
					PII t = q.front();
					q.pop();
					vb[i][j] = true;
					sum += 1;
					for (int k = 0; k < 4; k++)
					{
						int x = mx[k]+t.first;
						int y = my[k]+t.second;
						if (x >= 0 && x < m && y >= 0 && y < n&&vb[x][y] == false )
						{
							vb[x][y] = true;
							if (grid[x][y] == 1)
							{
								q.emplace(PII(x,y));
							}
						}
					}
				}
				ret = max(ret,sum);
			}
		}
	}
	return ret;
}
};
