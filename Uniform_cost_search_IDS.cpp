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
vi p, solve, level, goal;
int g;                                // addition: the predecessor/parent vector

void printPath(int u) {    // simple function to extract information from `vi p'
  if (u == s) { printf("%d", u); return; }
  printPath(p[u]);   // recursive call: to make the output format: s -> ... -> t
  printf(" %d", u);

}

void ids_ucs(int limit)
{
  vi dist(V, 1000000000); dist[s] = 0;      // distance to source is 0 (default)

  ii pair_s(0,s);
  priority_queue< ii > q;
  q.push(pair_s);                                  // start from source
  p.assign(V+2, -1); // to store parent information (p must be a global variable!)
  solve.assign(V+2, -1);
  int layer = -1;                             // for our output printing purpose
  level.assign(V+2, -1);
  level[s] = 0;

  while (!q.empty()) {
    ii u = q.top(); q.pop();
    //cout << level[u.second] << endl;

    if(solve[u.second] == -1)
    {
        solve[u.second] = 1;
    }else
        continue;
    /*
    if(level[u.second] == limit)
        return;
    */

    if(level[u.second] != layer) printf("\nLayer %d: ", level[u.second]);
        layer = level[u.second];


    printf("weight %d node %d, ",-1*u.first, u.second);

    //printf(" %d", (int)AdjList[u.second].size());
            for (int j = 0; j < (int)AdjList[u.second].size(); j++) {
              ii v = AdjList[u.second][j];                           // for each neighbors of u
              if ( (dist[v.second] == 1000000000) || (level[u.second] < limit-1) ) {
                dist[v.second] = dist[u.second] + v.first;
                level[v.second] = level[u.second] + 1;
                //cout  << "distance " << v.second << "  " << dist[v.second] << endl;                  // v unvisited + reachable
                p[v.second] = u.second;
                v.first = dist[v.second];         // addition: the parent of vertex v->first is u
                q.push(v);


              }

          }

  }

  if(dist[5] < dist[6])
  {
      cout << "Minimum goal is "<< 6 << " and cost is "<< -1*dist[6]<<endl;
      cout << "Minimum goal is "<< 5 << " and cost is "<< -1*dist[5]<< endl;
  }
  else
  {
    cout << "Minimum goal is "<< 5 << " and cost is "<< -1*dist[5]<< endl;
    cout << "Minimum goal is "<< 6 << " and cost is "<< -1*dist[6]<< endl;
  }

    /*
    int mini = 100000000;
    int min_i = -1;
    for(int i = 0; i < g; i++)
      {
        if(dist[goal[i]] < mini)
        {
            mini = dist[goal[i]];
            min_i = goal[i];
        }
      }

    cout << "Minimum goal is "<< mini << "and cost is "<< min_i << endl;
    */
}

int main() {
  /*
  // Graph in Figure 4.3, format: list of unweighted edges
  // This example shows another form of reading graph input
  13 16
  0 1    1 2    2  3   0  4   1  5   2  6    3  7   5  6
  4 8    8 9    5 10   6 11   7 12   9 10   10 11  11 12
  */

  freopen("lab_graph.txt", "r", stdin);
  /*
  cout << "Enter goal number" << endl;
  cin >> g;
  cin >> goal[0] >> goal[1];
  /*
  for(int i = 0; i < g; i++)
  {
    cin >> goal[i];
  }
  */
  //cin >> V;
  scanf("%d ", &V);
    //cin >> V;
  AdjList.assign(V+5, vii()); // assign blank vectors of pair<int, int>s to AdjList

  for (int i = 1; i <= V; i++) {
    scanf("%d", &total_neighbors);
    for (int j = 0; j < total_neighbors; j++) {
      scanf("%d %d", &id, &weight);
      AdjList[i].push_back(ii(-weight, id));
      //AdjList[id].push_back(ii(-weight, i));
    }
  }
  /*
    for(int i = 1; i <= 8; i++)
    {
    printf("index %d:",i);
        for (int j = 0; j < (int)AdjList[i].size(); j++) {
            printf("%d %d ",AdjList[i][j].second, AdjList[i][j].first);

        }
        cout << endl;
    }
    */

  s = 1;
  for(int i = 1; i <= 4; i++)
  {
    cout << "Depth limit is :"<< i << endl;
     ids_ucs(i);
  }



  return 0;
}

