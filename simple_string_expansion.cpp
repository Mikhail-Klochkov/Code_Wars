#include <bits/stdc++.h> 
using namespace std;

string ntimes(string s, int times){
	stringstream os;
	for(int i = 0; i < times; ++i)
		os << s;
	return os.str();
}
string solve_recursion(const string & str, int pos){
	int times = 1;
	string exp;
	int idx = pos;
	while(str[idx] != '(' && str[idx] != ')'){
		if(!isdigit((unsigned char) str[idx])){
			exp.push_back(str[idx++]);
		}else{
			times = atoi((char * ) &str[idx]);
			idx += to_string(times).size();
		}
	}
	if(str[idx] == '('){
		return strcat(&exp[0], &ntimes(solve_recursion(str, idx + 1), times)[0]);
	}else{
		return exp;
	}
}
string solve_ans(string s){
	return solve_recursion(s, 0);
}
string solve(string str){
	if(str.empty()) 
		return str;
	vector<string> exp;
	vector<int> times;
	int idx = 0;
	string curr_exp;
	bool flag = false;
	while(str[idx] != ')'){
		if((!isdigit((unsigned char) str[idx])) && (str[idx] != '(')){
			curr_exp.push_back(str[idx++]);
		}
		else if(isdigit((unsigned char) str[idx])){
			times.push_back(atoi((char * ) &str[idx]));
			idx += to_string(times.back()).size();
			flag = true;
		}else if(str[idx] == '('){
			exp.push_back(curr_exp);
			curr_exp.clear();
			if(!flag)
				times.push_back(1);
			flag = false;
			idx++;
		}
	}
	exp.push_back(curr_exp);
	times.push_back(1);
	string ans = exp.back();
	for(int i = exp.size()-2; i >= 0; i--){
		ans = strcat(&exp[i][0], &ntimes(ans, times[i])[0]);
	}
	return ans;
}
int main()
{
	cout << solve_ans("k(a3(b(a2(c))))") << "\n";
	cout << solve("k(a3(b(a2(c))))") << "\n";
	return 0;
}