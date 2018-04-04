#include <bits/stdc++.h>


using namespace std;


struct clause
{
	vector<string> premise;
	string conclusion;
	int num_of_premise;	
};

set<string> infer;
queue<string> agenda;
vector<clause> clauses;
map<string,bool> c_infer;
string st;
string q;
int num_horn;
int num_init_agenda;

void read()
{
	freopen("fc.txt","r",stdin);
	cout << "Enter number of Horn clauses : ";
	cin >> num_horn;
	for(int i = 0; i < num_horn; i++)
	{
		clause Cl;
		
		cout << "Enter num of premises for clause :" << i+1 << endl;
		cin >> Cl.num_of_premise;
		for(int j = 0; j < Cl.num_of_premise; j++)
		{
			cin >> st;
			Cl.premise.push_back(st);
			infer.insert(st);
		}
		cout << "Enter Conclusion for clause "<< i+1 << endl;
		cin >> Cl.conclusion;
		infer.insert(Cl.conclusion);
		clauses.push_back(Cl);
	}
	cout << "Enter number of initial symbol known to be true : ";
	cin >> num_init_agenda;
	for(int i = 0; i < num_init_agenda; i++)
	{
		cin >> st;
		agenda.push(st);
	}
	for(set<string>::iterator it = infer.begin(); it != infer.end(); it++)
	{
		//cout << *it << " ";
		c_infer[*it] = false;
	}

	cout << "Enter query symbol" << endl;
	cin >> q;

}

void read_test()
{
	for(int i = 0; i < num_horn; i++)
	{
		for(int j = 0; j < clauses[i].premise.size(); j++)
		{
			cout << clauses[i].premise[j] << " ";
		}
		cout << endl;
		cout << clauses[i].conclusion << endl;

	}

	for(set<string>::iterator it = infer.begin(); it != infer.end(); it++)
	{
		cout << *it << " ";
		cout << c_infer[*it] << " ";
	}
}

bool forward_chain()
{
	string p;
	while(!agenda.empty())
	{
		p = agenda.front();
		agenda.pop();

		if( p == q)
			return true;

		if(c_infer[p] == false)
		{
			c_infer[p] = true;
			for(int i = 0; i < num_horn; i++)
			{
				if( find(clauses[i].premise.begin(), clauses[i].premise.end(),p)!= clauses[i].premise.end() )
					clauses[i].num_of_premise -= 1;
				if(clauses[i].num_of_premise == 0)
					agenda.push(clauses[i].conclusion);

			}
		}
	}

	return false;

}


int main()
{
	read();
	//read_test();
	cout << forward_chain() << endl;
	return 0;
}