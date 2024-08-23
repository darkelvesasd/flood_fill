class Solution {
public:
int mx[4] = {-1,1,0,0};
int my[4] = { 0,0,-1,1 };
typedef pair<int, int>PII;
void bfs(vector<vector<char>>&board,vector<vector<bool>>&b,int i,int j)
{
	int m = board.size();
	int n = board[0].size();
	queue<PII> q;
	q.emplace(PII(i,j));
	b[i][j] = true;
	while (!q.empty())
	{
		PII t = q.front();
		q.pop();
		for (int k=0;k<4;k++)
		{
			int x = mx[k] + t.first;
			int y = my[k] + t.second;
			if (x >= 0 && x < m && y >= 0 && y < n&&board[x][y]=='O'&&b[x][y]==false)
			{
				q.emplace(x, y);
				b[x][y] = true;
			}
		}
	}
}
void solve(vector<vector<char>>& board) {
	int m = board.size();
	int n = board[0].size();
	vector<vector<bool>>vb(m, vector<bool>(n));
	int mv[4] = { 0,0,m - 1,m - 1 };
	int nv[4] = { 0,n - 1,0,n - 1 };
	for (int i=0;i<m;i++)
	{
		if (board[i][0] == 'O'&&vb[i][0]==false)
		{
			bfs(board, vb, i, 0);
		}
		if (board[i][n - 1] == 'O' && vb[i][n - 1] == false)
		{
			bfs(board, vb, i, n - 1);
		}
	}
	for (int i=0;i<n;i++)
	{
		if (board[0][i] == 'O' && vb[0][i] == false)
		{
			bfs(board, vb, 0, i);
		}
		if (board[m-1][i] == 'O' && vb[m - 1][i] == false)
		{
			bfs(board, vb, m-1, i);
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 'O' && vb[i][j] == false)
			{
				board[i][j] = 'X';
			}
		}
	}
}
};
