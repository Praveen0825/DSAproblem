void dfs(int i, int j, vector<vector<int>>& g, int& areas, int colour){
        if(i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j] != 1) return;
        
        g[i][j] = colour;
        areas++;
        
        dfs(i + 1, j, g, areas, colour);
        dfs(i - 1, j, g, areas, colour);
        dfs(i, j + 1, g, areas, colour);
        dfs(i, j - 1, g, areas, colour);
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int colour = 1000;
        unordered_map<int, int> sizes;
        int maxm = INT_MIN;
        
        vector<vector<int>> g = grid;
        for(int i = 0; i < g.size(); i++){
            for(int j = 0; j < g[0].size(); j++){
                int areas = 0;

                if(g[i][j] == 1){
                    dfs(i, j, g, areas, colour);

                    sizes[colour] = areas;

                    colour++;


                    maxm = max(maxm, areas);
                }
            }
        }
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0){
                    int curr = 0;
                    set<int> seen_colour;
                    if(i > 0 && g[i-1][j] != 0){

                        curr += sizes[g[i-1][j]];
                        
                        seen_colour.insert(g[i-1][j]);
                    }
                    if( j > 0 && g[i][j-1] != 0){
                        if(seen_colour.count(g[i][j-1]) == 0){

                            curr += sizes[g[i][j-1]];

                            seen_colour.insert(g[i][j-1]);
                        }
                    }
                    if(i < grid.size() - 1 && g[i+1][j] != 0){
                        if(seen_colour.count(g[i+1][j]) == 0){

                            curr += sizes[g[i+1][j]];

                            seen_colour.insert(g[i+1][j]);
                        }
                    }
                    if(j < grid[0].size() - 1 && g[i][j+1] != 0){
                        if(seen_colour.count(g[i][j+1]) == 0){
                            curr += sizes[g[i][j+1]];
                        }
                    }
                    maxm = max(maxm, curr + 1);
                }
            }
        }
        return maxm;
    }