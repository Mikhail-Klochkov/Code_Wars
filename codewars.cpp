

#include <bits/stdc++.h>
#include <algorithm>
#include <iterator>
#include <fstream>
using  namespace std;

bool narcissistic(int value){
	int sum = 0;
	int value_old = value; 
	vector<int> digits_arr;
	int new_value = value, digit = 0;
	while(value / 10 != 0){
		new_value = value / 10;
		digit =  value - new_value * 10;
		digits_arr.push_back(digit);
		value = new_value;
	}
	digits_arr.push_back(new_value);
	for(auto d: digits_arr){
		sum += pow(d, digits_arr.size());
	}
	if(sum == value_old){
		return true;
	}else{
		return false;
	}
}
int foo_1(int num){
	int sum = 0;
	for(int i = 0; i < num; i++){
		if( i % 3 == 0 || i % 5 == 0){
			sum += i;
		}
	}
	return sum;
}
int main(){
	ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n = 10;
   	if(foo_1(n) == 23){
   		cout << "OK!";
   	}
   	std::cout << narcissistic(4887);

	return 0;
}