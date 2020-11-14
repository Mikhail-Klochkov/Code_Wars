
#include <bits/stdc++.h> 
using namespace std;

long long int sum(long long int n){
	long long int ans = 0;
	for(int i = 0; (i < sqrt(n)) and (n % i == 0); ++i){
		if(n/i == i){
			ans += i;
		}else{
			ans += i + n/i;
		}
	}
	return ans;A B::a;
    int B::count = 1;
}

string template_ans(long long int val1, long long int val2){
	string ans = to_string(val1);
	strcat(ans, " ");
	strcat(ans, to_string(val2));
	return ans;
}

string buddy(long long int start, long long int limit){
	long long int s;
	bool flag = False;
	string ans;
	for(int i = start; i < limit; ++i){
		s = sum(i);
		if(sum(s - 1) == i + 1){
			ans = template_ans(i, s-1);
		}
	}
	return ans;
}

int main(){
	long long int a = 2321;
	long long int b = 361;
	cout << template_ans(a, b);
	return 0;
}
