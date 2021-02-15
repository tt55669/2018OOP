#include <iostream>
#include<string>
using namespace std;
void  sorting_string(string str_arr[], string check_str, int c);
int main()
{
	int number, total = 0;
	cout << "Please input the max number of words to be stored." << endl;
	cin >> number;
	cin.get();
	string *str_arr = new string[number];
	while (1)
	{
		string check_str;
		cout << "Please input the word, or command(print/exit) :";
		getline(cin, check_str);

		if (check_str == "exit")
		{
			break;
		}
		else if (check_str == "print")
		{
			for (int i = 0; i < total; i++) {
				cout << str_arr[i] << " ";
			}
			cout << endl;
		}
		else
		{
			if (number == total) {
				cout << "The array is full!" << endl;
			}
			else {
				sorting_string(str_arr, check_str, ++total);
			}
		}
	}
	system("pause");
	return 0;
}
void sorting_string(string str_arr[], string check_str, int c) {
	int i = 0;
	while (i < c) {

		if (check_str < str_arr[i]) {
			for (int j = c - 1; j > i; j--) {
				str_arr[j] = str_arr[j - 1];
			}
			str_arr[i] = check_str;
			break;
		}
		i++;
	}
	if (i == c) str_arr[i - 1] = check_str;
}
