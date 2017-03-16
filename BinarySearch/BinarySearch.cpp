#include<iostream>
#include<algorithm>//sort() function
#include<vector>
#include<ctime>

template<typename It>
bool BinarySearch(It first, It last, const int value)
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
	srand(static_cast<unsigned>(time(0)));                           //随机数种子
	vector<int> vec;
	for (int i = 0; i != 49; ++i) vec.push_back(rand() % 50);
	sort(vec.begin(), vec.end());
	cout << "Low-to-High: ";
	for (auto& value : vec) cout << value << "   "; cout << endl;

	cout << "Please input a number that you like between 0 and 49: "; int value; cin >> value;
	bool exist = BinarySearch<vector<int>::iterator>(vec.begin(), vec.end(), value);
	if (exist) cout << "Congratulations! The number you have input is in the line." << endl;
	else cout << "ERROR!!! The number you have input is NOT in the line." << endl;
	return 0;
}