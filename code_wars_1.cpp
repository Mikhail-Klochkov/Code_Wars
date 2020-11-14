#include <bits/stdc++.h> 
using namespace std;

vector<vector<int>> multiplication_table(int n){
	vector<vector<int>> A;
	A.resize(n);
	for(int i = 0; i < n; i++){
		A[i].resize(n);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; ++j){
			if(i == 0){
				A[i][j] = j + 1;
			}else{
				A[i][j] = A[i-1][j] + (j + 1);
			}
		}
	}
	for_each(A.begin(), A.end(), [](vector<int> row){
		for_each(row.begin(), row.end(), [](int elem){
			cout << elem << " ";
		});
		cout << "\n";
	});
	return A;
}

int main(){
	int n = 3;
	vector<vector<int>> ans = multiplication_table(n);
	return 0;
}