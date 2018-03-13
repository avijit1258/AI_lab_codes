#include <bits/stdc++.h>


using namespace std;


int p[4][8] = {{2, 4, 7, 4, 8, 5, 5, 2}, {3, 2, 7, 5, 2, 4, 1, 1}, {2, 4, 4, 1, 5, 1, 2, 4}, {3, 2, 5, 4, 3, 2, 1, 3}};

int np[4][8];
int mini = -100000;

set<int> s;

void show_fit();

void GA()
{
    int x[8];
    int y[8];
    int child[8];
    int ci, xi, yi;

    for(int i = 0; i < 4; i++)
    {
        //selection
        xi = rand()%3;
        yi = rand()%3;
        for(int j = 0; j < 8; j++)
        {
            x[j] = p[xi][j];
            y[j] = p[yi][j];

        }

        // reproduce
        ci = rand() % 7;
        for(int j = 0; j < 8; j++)
        {
            if(j > ci)
                child[j] = x[j];
            else
                child[j] = y[j];
        }
        ci = rand() % 7;
        child[ci] = 1 + rand() % 7;


        //new population to old
        for(int j = 0; j < 8; j++)
        {
            np[i][j] = child[j];

        }



    }
    for(int i = 0; i < 8 ; i++)
        for(int j = 0; j < 8; j++)
        {
            p[i][j] = np[i][j];

        }
    show_fit();

}


int fitness_function(int i)
{
    int mis_match = 0;
    for(int j = 0; j < 8; j++)
    {
        for(int k = j; k < 8; k++)
        {
            if( (p[i][k] == p[i][j]) || (k == j) || (abs(p[i][k] - p[i][j]) == abs(k - j)) )
                continue;
            mis_match++;
        }

    }

    return mis_match;
}

void show_fit()
{
    for(int i = 0; i < 4; i++)
    {
        //cout << "Fitness function for individual :"<< i+1 << " " << fitness_function(i) << endl;
        mini = max(mini, fitness_function(i));
        s.insert(-mini);
    }

}

int main()
{


    int n;
    cin >> n;
    srand(NULL);
    for(int i = 0; i < n; i++)
    {

        GA();
        //cout << "For population " << i+1 << "max is" << mini <<endl;
    }
    //cout << mini << endl;
    for(set<int>::iterator it= s.begin(); it != s.end(); it++)
        cout << " " << *it << endl;


    return 0;
}
