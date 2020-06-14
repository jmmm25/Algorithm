#include <iostream>
#include <vector>

using namespace std;

// This is the custom function interface.
// You should not implement it, or speculate about its implementation
class CustomFunction
{
public:
    int f(int x, int y);
};

class Solution
{
public:
    vector<vector<int>> findSolution(CustomFunction &customfunction, int z)
    {
        {
            vector<vector<int>> res;
            for (int i = 1; i < 1001; i++)
            {
                for (int j = 1; j < 1001; j++)
                {
                    if (customfunction.f(i, j) == z)
                    {
                        res.push_back({i, j});
                    }
                }
            }
            return res;
        }
    }
};