
#include <iostream>
#include <vector>
#include <algorithm>

class Features{
	public:
		Features(bool val) : value(val) {};
		bool operator==(bool value){
			return true;
		}
	private:
		bool value;
};

int BouncingTimes(double h, double bounce, double window){
	if(bounce <= 0 || bounce >= 1 || h <= window || h <= 0 || window <= 0)
		return -1;
	int times = 1;
	while(bounce * h > window){
		times += 2;
		h *= bounce;
	}
	return times;
}

void wave_sort(std::vector<int> &v) {
	std::vector<int> v_sort = v;
	std::sort(v_sort.begin(), v_sort.end());
	int n_down = (int) (v.size() / 2); 
	int id, iu;
	id = 0;
	iu = n_down;
	int curr = 0;
	while(id < n_down &&  curr < v.size()){
		v[curr++] = v_sort[iu++];
		v[curr++] = v_sort[id++];
	}
	if(v.size() % 2 != 0 and iu == v.size() - 1){
		v[curr] = v_sort[iu];
	}
 }

void print(const std::vector<int> & v){
	for(auto elem : v)
		std::cout << elem << " ";
	std::cout << "\n";
}

bool is_wave_sorted(const std::vector<int> & v){
	int i1, i2;
	i1= 0;
	i2= 1;
	while(i2 < v.size()){
		if(v[i1] < v[i2] && i1 % 2 == 0)
			return false;
		if(v[i1] > v[i2] && i1 % 2 != 0)
			return false;
		++i1;
		++i2;
	}
	return true;
}
int main(){
	//Features omnibool(true);
	//std::cout << (omnibool == true && omnibool == false);
	std::vector<int> example = {9, 47, 22, 23, 33, 14, 46, 9, 29, 39, 13, 29, 44, 91};
	wave_sort(example);
	print(example);
	if(is_wave_sorted(example))
		std::cout << "is wave sorted array\n"; 
	else std::cout << "is not wave sorted array\n"; 
	std::cout << BouncingTimes(3, 0.66, 1.5) << "\n";
	return 0;
}