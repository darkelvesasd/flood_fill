class Solution {
public:
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
	queue<pair<int,int>>q;
	int m = image[0].size();
	int n = image.size();
	if (m == 0)
	{
		return {};
	}
	q.emplace(sr, sc);
	int tv = image[sr][sc];
	if (color == tv)
	return image;
	while (!q.empty())
	{
		pair<int, int> t = q.front();
		q.pop();
		int a = t.first;
		int b = t.second;
		image[a][ b] = color;
		if (a-1>=0&&image[a-1][b]==tv)
		{
			q.emplace(a-1,b);
		}
		if(b-1>=0&&image[a][b-1]==tv)
		{
			q.emplace(a, b - 1);
		}
		if(b+1<m&&image[a][b+1]==tv)
		{
			q.emplace(a, b + 1);
		}
		if(a+1<n&&image[a+1][b]==tv)
		{
			q.emplace(a+1,b);
		}
	}
	return image;
}
};
