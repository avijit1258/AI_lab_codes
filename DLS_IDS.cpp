#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef pair<int, int> ii;      // In this chapter, we will frequently use these
typedef vector<ii> vii;      // three data type shortcuts. They may look cryptic
typedef vector<int> vi;   // but shortcuts are useful in competitive programming

#define DFS_WHITE -1 // normal DFS, do not change this with other values (other than 0), because we usually use memset with conjunction with DFS_WHITE
#define DFS_BLACK 1

vector<vii> AdjList;

void printThis(char* message) {
  printf("==================================\n");
  printf("%s\n", message);
  printf("==================================\n");
}

vi dfs_num;     // this variable has to be global, we cannot put it in recursion
int numCC;
int ids_limit = 0;

void dfs(int u) {          // DFS for normal usage: as graph traversal algorithm
      printf(" %d", u);                                    // this vertex is visited
      dfs_num[u] = DFS_BLACK;      // important step: we mark this vertex as visited
      for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];                      // v is a (neighbor, weight) pair
        if (dfs_num[v.first] == DFS_WHITE)         // important check to avoid cycle
          dfs(v.first);      // recursively visits unvisited neighbors v of vertex u
    }
}

void dfs_limit(int u, int limit) {          // DFS for normal usage: as graph traversal algorithm
      printf("visited %d\n", u);
      //int limit_for_child = limit - 1;
      //printf("\nLimit %d",limit);          // this vertex is visited
      dfs_num[u] = DFS_BLACK;// important step: we mark this vertex as visited
      printf("\n Limit %d ", limit);
      if(limit == ids_limit)
          return;

      for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];                      // v is a (neighbor, weight) pair
        if (dfs_num[v.first] == DFS_WHITE){
             printf("DFS child %d and with limit %d ",v.first, limit+1);
             dfs_limit(v.first,limit+1);      // recursively visits unvisited neighbors v of vertex u

        }         // important check to avoid cycle

    }
}

int main()
{
    int V, total_neighbors, id, weight;
  freopen("dfs.txt", "r", stdin);

  scanf("%d", &V);
  AdjList.assign(V, vii()); // assign blank vectors of pair<int, int>s to AdjList
  for (int i = 0; i < V; i++) {
    scanf("%d", &total_neighbors);
    for (int j = 0; j < total_neighbors; j++) {
      scanf("%d %d", &id, &weight);
      AdjList[i].push_back(ii(id, weight));
    }
  }

  //printThis("Standard DFS Demo (the input graph must be UNDIRECTED)");
  numCC = 0;

  /*    // this sets all vertices' state to DFS_WHITE
  for (int i = 0; i < V; i++)                   // for each vertex i in [0..V-1]
    if (dfs_num[i] == DFS_WHITE)            // if that vertex is not visited yet
      printf("Component %d:", ++numCC), dfs(i), printf("\n");   // 3 lines here!
  printf("There are %d connected components\n", numCC);

    */
   //printf("DFS for source 0 is ");
   for(int i = 0; i <= 3; i++)
   {
        dfs_num.assign(V, DFS_WHITE);
        ids_limit=i;
        dfs_limit(0, 0);
        //printf("In main %d\n",ids_limit);
   }

   //dfs_limit(0, 0);
   //dfs_limit(0, 1);

    return 0;
}
