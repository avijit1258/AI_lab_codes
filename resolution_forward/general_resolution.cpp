#include <bits/stdc++.h>



using namespace std;


vector<string> clauses;
vector<string> new_cs;

int num_of_clause;
int num_of_clause_in_query;

void read()
{
	freopen("gc.txt","r",stdin);
	cout << "Enter number of clauses in KB : ";
	cin >> num_of_clause;
	string s;
	for(int i = 0; i < num_of_clause; i++)
	{
		cin >> s;
		clauses.push_back(s);
	}

	cout << "Enter number of clause in query : ";
	cin >> num_of_clause_in_query;
	for(int i = 0; i < num_of_clause_in_query; i++)
	{
		cin >> s;	
		clauses.push_back(s);
	}


}

//PL_RESOLVE methods works well and primarily tested
string PL_RESOLVE(int ci, int cj)
{
	string s1 = clauses[ci], s2 = clauses[cj];
	string s3 = "";
	//cout << clauses[ci].size() << " " << clauses[cj].size() << endl;
	for(int i = 0; i < clauses[ci].size(); i++)
	{
		
		for(int j = 0; j < clauses[cj].size(); j++)
		{
			//cout << abs( (clauses[ci][i]-'a') - (clauses[cj][j]-'a')) << endl;
			if(abs( (clauses[ci][i]-'a') - (clauses[cj][j]-'a')) == 32)
			{
				
				s1.erase(remove(s1.begin(), s1.end(), clauses[ci][i]), s1.end());
				s2.erase(remove(s2.begin(), s2.end(), clauses[cj][j]), s2.end());
				
			}else if(clauses[ci][i] == clauses[cj][j])
			{
				s2.erase(remove(s2.begin(), s2.end(), clauses[cj][j]), s2.end());
			}

		}
		
	}
	s3 += s1;
	s3 += s2;
	
	return s3;
}

bool is_subset()
{
	bool subset[new_cs.size()+1];

	for(int i = 0; i < new_cs.size(); i++)
	{
		subset[i] = false;
		for(int j = 0; j < clauses.size(); j++)
		{
			if(new_cs[i] == clauses[j])
			{

				subset[i] = true;
				break;
			}
		}

	}

	for(int i = 0; i < new_cs.size(); i++)
	{
		if(subset[i] == false)
			return false;
	}

	return true;
}

bool general_resolution()
{
	int k = 1;
	while(1)
	{
			cout << "here" << endl;
			for(int i = 0; i < clauses.size(); i++)
			{
				
				for(int j = i+1; j < clauses.size(); j++)
				{
					string resovents = PL_RESOLVE(i, j);
					cout << resovents << endl;
					if(resovents.size() == 0)
						return true;
					new_cs.push_back(resovents);	
				}

			}

			if(is_subset())
			{
				return false;
			}

			for(int i = 0; i < new_cs.size(); i++)
			{

				if( find(clauses.begin(), clauses.end(),new_cs[i])!=clauses.end() )
				{
					
				}else
				{
					clauses.push_back(new_cs[i]);
				}
			}
			//new_cs.clear();
			k++;
			cout << "For iteration " << k << endl;
	}
}


int main()
{
	//freopen("gco.txt","w",stdout);
	read();
	//cout << PL_RESOLVE(0, 1) << "Size" << PL_RESOLVE(0,1).size() <<  endl;
	cout << general_resolution() << endl;
	// new_cs.push_back("PQR");
	// new_cs.push_back("S");
	// new_cs.push_back("L");

	// clauses[0] = "pqr";
	// clauses[1] = "QRP";
	// cout << PL_RESOLVE(0, 1) << "Size" << PL_RESOLVE(0,1).size() <<  endl;
	// cout << is_subset() << endl;


	return 0;
}