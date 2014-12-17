#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
		if(grid.size()==0)
			return 0;
		int **dp=new int*[grid.size()];
		for(int i=0;i<grid.size();i++)
		{
			dp[i]=new int[grid[i].size()];
			for(int j=0;j<grid[i].size();j++)
				dp[i][j]=0;
		}

		dp[0][0]=grid[0][0];
		for(int i=1;i<grid.size();i++)
			dp[i][0] = grid[i][0] + dp[i-1][0];
		for(int j=1;j<grid[0].size();j++)
			dp[0][j] = grid[0][j] + dp[0][j-1];

		for(int i=1;i<grid.size();i++)
			for(int j=1;j<grid[i].size();j++)
				dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);

		return dp[grid.size()-1][grid[0].size()-1];
    }
};

int main()
{
	Solution t;
	vector<vector<int> > grid;
	vector<int> v(2,1);
	grid.push_back(v);
	grid.push_back(v);
	grid[0][0]=1;
	grid[0][1]=2;
	grid[1][0]=1;
	grid[1][1]=1;
	t.minPathSum(grid);

}