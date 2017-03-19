#include<iostream>
#include<algorithm>//sort() function
#include<vector>

template<typename It>
bool BinarySearch(It first, It last, int value)
{
	auto mid = first + (last - first) / 2;
	while (first != last && *mid != value)
	{
		if (value < *mid) last = mid;
		else first = mid + 1;
		mid = first + (last - first) / 2;
	}
	if (first != last) return true;
	return false;
}

int main()
{
	using namespace std;
	int value;
	vector<int> vec;
	cout << "Please input 10 number you like: ";
	for (int i = 0; i != 10; ++i) { cin >> value; vec.push_back(value); }
	sort(vec.begin(), vec.end());
	cout << "Please input one number you like: ";
	cin >> value;
	bool exist = BinarySearch(vec.begin(), vec.end(), value);
	if (exist) cout << "Congratulations!" << endl;
	else cout << "Sorry, the number is not in the ling." << endl;
	return 0;
}