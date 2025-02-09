/*The problem entails building a brick wall of specific dimensions, height and width, using bricks that come in different fixed widths (each brick is 1 unit high).
In the array bricks, each brick's width is given, and we have an unlimited number of bricks of each size. The objective is to calculate the total number of ways to build the wall without aligning the joints of bricks from adjacent rows—except at the ends of the wall—to ensure the wall's sturdiness.

Each row must be exactly width units wide, and bricks may not be stacked atop each other; each brick spans the entire height of its row (which is 1 unit tall).
The answer could be quite large, so we require the total count modulo 10^9 + 7.
*/

#include <vector>

class Solution
{
public:
    std::vector<int> bricks;
    int wallWidth;
    int mod = 1e9 + 7;
    std::vector<std::vector<int>> layerPatterns;
    std::vector<int> currentPattern;

    // Main function to compute the number of ways to build the wall
    int buildWall(int height, int width, std::vector<int> &bricks)
    {
        wallWidth = width;
        this->bricks = bricks;

        // Generate all possible patterns for a single layer of the wall
        generatePatterns(0);
        currentPattern.resize(0);

        // Count patterns excluding same crack patterns
        int patternCount = layerPatterns.size();
        std::vector<std::vector<int>> graph(patternCount);

        // Build a graph representing compatible patterns
        for (int i = 0; i < patternCount; ++i)
        {
            if (canPlaceAdjacent(layerPatterns[i], layerPatterns[i]))
            {
                graph[i].push_back(i);
            }
            for (int j = i + 1; j < patternCount; ++j)
            {
                if (canPlaceAdjacent(layerPatterns[i], layerPatterns[j]))
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        // Prepare for dynamic programming
        std::vector<std::vector<int>> dp(height, std::vector<int>(patternCount));

        // Initialize the base cases
        for (int j = 0; j < patternCount; ++j)
            dp[0][j] = 1;

        // Build up solutions from the base cases
        for (int i = 1; i < height; ++i)
        {
            for (int j = 0; j < patternCount; ++j)
            {
                for (int k : graph[j])
                {
                    dp[i][j] += dp[i - 1][k];
                    dp[i][j] %= mod;
                }
            }
        }

        // Sum all possible configurations for the top layer
        int result = 0;
        for (int j = 0; j < patternCount; ++j)
        {
            result += dp[height - 1][j];
            result %= mod;
        }
        return result;
    }

    // Helper function to check if two layer patterns can be placed one over the other
    bool canPlaceAdjacent(std::vector<int> &a, std::vector<int> &b)
    {
        int sum1 = a[0], sum2 = b[0];
        int i = 1, j = 1;
        while (i < a.size() && j < b.size())
        {
            if (sum1 == sum2)
                return false;
            if (sum1 < sum2)
            {
                sum1 += a[i++];
            }
            else
            {
                sum2 += b[j++];
            }
        }
        return true;
    }

    // Depth-first search algorithm to generate all possible layer patterns
    void generatePatterns(int sum)
    {
        // If the current sum exceeds the width of the wall, stop the search
        if (sum > wallWidth)
            return;

        // If the current sum equals the width of the wall, add the pattern to the results
        if (sum == wallWidth)
        {
            layerPatterns.push_back(currentPattern);
            return;
        }

        // Try each type of brick as a possible continuation of the pattern
        for (int brick : bricks)
        {
            currentPattern.push_back(brick);
            generatePatterns(sum + brick);
            // Backtrack
            currentPattern.pop_back();
        }
    }
};
