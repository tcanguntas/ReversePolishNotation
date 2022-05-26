/*
 *      Author: tayyipcan.guntas
 */
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int evalRPN(vector<string>& tokens)
{
	stack<int> st;

	for (size_t i = 0; i<tokens.size();i++)
	{
		if ( tokens[i] =="+" ||
				tokens[i] == "-" ||
				tokens[i] == "*" ||
				tokens[i] == "/")
		{
			int v1 = st.top();
			st.pop();
			int v2 = st.top();
			st.pop();

			if ( tokens[i] =="+")
			{
				st.push(v1+v2);
			}
			else if (tokens[i] =="-")
			{
				st.push(v2-v1);
			}
			else if (tokens[i] =="*")
			{
				st.push(v1*v2);
			}
			else if (tokens[i] =="/")
			{
				st.push(v2/v1);
			}
		}
		else
		{
			st.push(atoi(tokens[i].c_str()));
		}
	}
	return st.top();

}

int main()
{
	vector<string> tokens {"4","13","5","/","+"};
	cout<<"ANS "<< evalRPN(tokens);
	return 0;
}
