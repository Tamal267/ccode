map<int,vector<int>> adj;
map<int,int>visited,parent,level,color;

void dfs(int start)
{
  visited[start]=1;
  for (auto child : adj[start])
  {
    if (!visited[child])
    {
      dfs(child);
    }
  }
  visited[start]=2;
}