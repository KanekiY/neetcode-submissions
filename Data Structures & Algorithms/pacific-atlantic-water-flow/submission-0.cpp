class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> results;
        int rows = heights.size();
        int columns = heights[0].size();
        for(int row = 0; row < rows; row++)
        {
            for(int column = 0; column < columns; column++)
            {
                vector<vector<int>> visited(rows,vector<int>(columns, false));
                queue<pair<int,int>> q;
                bool canGoPacific = false;
                bool canGoAtlantic = false;
                q.push({row, column});
                while(!q.empty())
                {

                    auto[currentRow, currentColumn] = q.front();
                    q.pop();
                    if(visited[currentRow][currentColumn]) continue;
                    
                    visited[currentRow][currentColumn] = true;
                    if(currentRow<= 0 || currentColumn<=0) 
                    {
                        canGoPacific = true;
                    }

                    if(currentRow >= rows-1 || currentColumn >= columns-1) 
                    {
                        canGoAtlantic = true;
                    }
                    if(canGoPacific && canGoAtlantic) 
                    {

                        results.push_back({row, column});
                        break;
                    }
                    int dx[4] = {0,0,1,-1};
                    int dy[4] = {1,-1,0,0};

                    for(int i = 0; i<4; i++)
                    {
                        int newRow = currentRow + dy[i];
                        int newColumn = currentColumn + dx[i];
                       
                        if(newRow<0 || newRow >= rows || newColumn <0 || newColumn>= columns || heights[currentRow][currentColumn] <heights[newRow][newColumn] )
                        {
                            continue;
                        }
                        if(visited[newRow][newColumn]) continue;
                       q.push({newRow, newColumn});

                    }



                }
            }
        }
        return results;
    }
};
