#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;      // In this chapter, we will frequently use these
typedef vector<ii> vii;      // three data type shortcuts. They may look cryptic
typedef vector<int> vi;   // but shortcuts are useful in competitive programming

int V, total_neighbors, id, weight, s;
vector<vii> AdjList;
vi p, solve;                                 // addition: the predecessor/parent vector

void printPath(int u) {    // simple function to extract information from `vi p'
  if (u == s) { printf("%d", u); return; }
  printPath(p[u]);   // recursive call: to make the output format: s -> ... -> t
  printf(" %d", u); }

int main() {
  /*
  // Graph in Figure 4.3, format: list of unweighted edges
  // This example shows another form of reading graph input
  13 16
  0 1    1 2    2  3   0  4   1  5   2  6    3  7   5  6
  4 8    8 9    5 10   6 11   7 12   9 10   10 11  11 12
  */

  freopen("dfs.txt", "r", stdin);

  scanf("%d ", &V);

  AdjList.assign(V+5, vii()); // assign blank vectors of pair<int, int>s to AdjList

  for (int i = 0; i <= V; i++) {
    scanf("%d", &total_neighbors);
    for (int j = 0; j < total_neighbors; j++) {
      scanf("%d %d", &id, &weight);
      AdjList[i].push_back(ii(-weight, id));
      //AdjList[id].push_back(ii(-weight, i));
    }
  }

  // as an example, we start from this source, see Figure 4.3
  s = 0;

  // BFS routine
  // inside int main() -- we do not use recursion, thus we do not need to create separate function!
  vi dist(V, 1000000000); dist[s] = 0;      // distance to source is 0 (default)
  ii pair_s(0,s);
  priority_queue< ii > q;
  q.push(pair_s);                                  // start from source
  p.assign(V, -1); // to store parent information (p must be a global variable!)
  solve.assign(V+2, -1);
  int layer = -1;                             // for our output printing purpose


  while (!q.empty()) {
    ii u = q.top(); q.pop();
    if(solve[u.second] == -1)
    {
        solve[u.second] = 1;
    }else
        continue;

    printf("weight %d node %d, \n",u.first, u.second);
    //printf(" %d", (int)AdjList[u.second].size());
    for (int j = 0; j < (int)AdjList[u.second].size(); j++) {
      ii v = AdjList[u.second][j];                           // for each neighbors of u
      if (dist[v.second] == 1000000000) {
        dist[v.second] = dist[u.second] + v.first;
        //cout  << "distance " << v.second << "  " << dist[v.second] << endl;                  // v unvisited + reachable
        p[v.second] = u.second;
        v.first = dist[v.second];         // addition: the parent of vertex v->first is u
        q.push(v);

        //printf("I am here");                             // enqueue v for next step
      }

  }

  }

  printf("\nShortest path: ");
  printPath(5), printf("\n");
  //printf("isBipartite? %d\n", isBipartite);

  return 0;
}
