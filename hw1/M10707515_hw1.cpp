#include <iostream>
#include <fstream>
using namespace std;
int main()
{	int x, y; //x為猜的數字,y為隨機產生終極密碼
	int low , high;
	ifstream fin("input.txt");
	fin >> low >> high >> y;
	do
	{
		cout << "Please guess an integer between " << low << " and " << high << endl;
		cin >> x;
		if (x > high || x < low)
		{
			cout << "The number you entered is not within the valid range." << endl << "Please try again!" << endl;
			continue;
		}
		else if (y == x)
		{
			cout << "Bingo! You hit the bomb." << endl;
			break;
		}
		else
		{
			(x > y) ? high = x :low = x ;
		}
	} while (x != y);
	system("pause");
	return 0; 
}
