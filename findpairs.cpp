
#include <bits/stdc++.h>
#include <utility>

using namespace std;
 pair<int, int> findpairs(int * , int , int );
int main(){
	int arr [10] = {1,2,3,4,5,6,7,8,9,0};
	pair<int, int > ans = findpairs(arr, 10, 10);
	cout << "finaly: " << "( " << ans.first << " , "<< ans.second <<  " )" << "\n"; 
	return 0;
}
pair<int, int> findpairs(int arr[], int len, int sum){
	int i = 0;
	int j = len - 1;
	pair<int, int> pair(0, len);
	sort(arr, arr + len);
	while(i < j){
		while(arr[i] + arr[j] <= sum && i < j){
			if(arr[i] + arr[j] == sum){
				if (j < pair.second){
					pair.first = i;
					pair.second= j;
				}
				cout << "( " << arr[i] << ", " << arr[j] << " )" << "\n";
			}
			i++;
		}
		j--;
		while(arr[i] + arr[j] >= sum && i < j){
			if(arr[i] + arr[j] == sum){
				if (j < pair.second){
					pair.first = i;
					pair.second= j;
				}
				cout << "( " << arr[i] << ", " << arr[j] << " )" << "\n";
			}
			j--;
		}
	}
	return pair;
}
