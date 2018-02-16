#include <bits/stdc++.h>


using namespace std;


vector<int> initial = {2,1,0,3,-1,5,6,4,7};
vector<int> goal = {2,-1,5,1,3,6,4,0,7};

int number_of_states = 0;

void generate_child(vector<int> a);

bool is_goal(vector<int> a)
{
	bool test = true;
	for(int i = 0; i < 9 ; i++)
	{
		if(goal[i] != a[i])
		{
			test = false;
			break;
		}

	}
	return test;

}

int heuristic_result(vector<int> a)
{
    int num = 0;
	for(int i = 0; i < 9 ; i++)
	{
		if(goal[i] == a[i])
		{
			num++;
		}

	}
	return num;

}

int where_is_blank(vector<int> a)
{
    for(int i = 0; i < 9; i++)
        if(a[i] == -1)
        {
            cout << i << " " << a[i] << endl;
            return i;
        }

}

void dfs(vector<int> xy)
{
    number_of_states++;
    if(is_goal(xy))
    {
        cout << number_of_states << endl;

        return;
    }
    else
        generate_child(xy);


}





int main()
{

	//cout << is_goal(goal) << endl;
    //dfs(initial);
    //cout << where_is_blank(initial) << endl;
    //cout << is_goal(goal) << endl;
    generate_child(initial);
	return 0;
}

void print_board()
{
    for(int i = 0; i < 9; i++)
    {

        //cout << a[i] << " ";
        //if( (i+1) % 3 == 0 )
            //cout << endl;
    }


}

void generate_child(vector<int> a)
{

    int b = where_is_blank(a);
    cout << number_of_states << "generated" << "and heurictic is " << heuristic_result(a) << endl;
    for(int i = 0; i < 9; i++)
    {

        cout << a[i] << " ";
        if( (i+1) % 3 == 0 )
            cout << endl;
    }
    number_of_states++;
    if(is_goal(a))
    {
        cout << number_of_states << endl;

        return;
    }
    if(number_of_states == 10)
        return;
    vector<int> v1(12), v2(12), v3(12), v4(12);

    copy(a.begin(), a.end(), v1.begin());
    copy(a.begin(), a.end(), v2.begin());
    copy(a.begin(), a.end(), v3.begin());
    copy(a.begin(), a.end(), v4.begin());
    if(b == 0)
    {
        swap(v1[0], v1[1]);
        //generate_child(v1);
        swap(v2[0], v2[3]);
        //generate_child(v2);
        int a1 = heuristic_result(v1);
        int a2 = heuristic_result(v2);
        if(a1 < a2)
            generate_child(v2);
        else
            generate_child(v1);


    }else if(b == 1)
    {
        swap(v1[1], v1[0]);
        generate_child(v1);
        swap(v2[1], v2[2]);
        generate_child(v2);
        swap(v2[1], v3[4]);
        generate_child(v3);

    }else if(b == 2)
    {
        swap(v1[2], v1[1]);
        generate_child(v1);
        swap(v2[2], v2[5]);
        generate_child(v2);

    }else if(b == 3)
    {
        swap(v1[3], v1[0]);
        generate_child(v1);
        swap(v2[3], v2[4]);
        generate_child(v2);
        swap(v2[3], v3[6]);
        generate_child(v3);

    }else if(b == 4)
    {
        swap(v1[4], v1[1]);
        generate_child(v1);
        cout << v1[4] << " " << v1[1] << endl;
        swap(v2[4], v2[3]);
        generate_child(v2);
        cout << v2[4] << " " << v2[3] << endl;
        swap(v3[4], v3[5]);
        generate_child(v3);
        cout << v3[4] << " " << v3[5] << endl;
        swap(v2[4], v4[7]);
        generate_child(v4);
        cout << v4[4] << " " << v4[7] << endl;
    }else if(b == 5)
    {
        swap(v1[5], v1[2]);
        generate_child(v1);
        swap(v2[5], v2[4]);
        generate_child(v2);
        swap(v2[5], v3[8]);
        generate_child(v3);


    }else if(b == 6)
    {
        swap(v1[6], v1[3]);
        generate_child(v1);
        swap(v2[6], v2[7]);
        generate_child(v2);

    }else if(b == 7)
    {
        swap(v1[7], v1[4]);
        generate_child(v1);
        swap(v2[7], v2[6]);
        generate_child(v2);
        swap(v2[7], v3[8]);
        generate_child(v3);

    }else if(b == 8)
    {
        swap(v1[8], v1[5]);
        generate_child(v1);
        swap(v2[8], v2[7]);
        generate_child(v2);

    }
}
