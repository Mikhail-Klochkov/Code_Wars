#include <iostream>
#include <string>
#include <algorithm>

std::string  accum(const std::string & base){
	int size = base.size();
	std::string ans;
	unsigned char current;
	for(int i = 0; i < size; ++i){
		current = base[i];
		for(int j = 0; j < (i + 1); ++j){
		    if(j == 0)
		      ans.push_back(std::toupper(current));    
		    else ans.push_back((std::isupper(current)) ? std::tolower(current) : current); 
		}
		if(i != size - 1)
		    ans.push_back('-');
	}
	return ans;
}
int main(){
	std::string str = "ZpglnRxqenU";
	std::cout << accum(str);
	return 0;
}
