#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int i = 0,
		j = 0,
		z = 0,
		d = 0,
		max = -1,
		k = 0,
		n = 0;
	string row;
	char words[10][50];
	char word1[50];
	char word2[50];
	bool check = true;
	ifstream F1("F1.txt"); 
	ofstream F2("F2.txt"); 
	while (F1.eof() == false)
	{
		getline(F1, row);
		for (i = 0; i < 10; i++) 
			for (j = 0; j < 50; j++)
				words[i][j] = '*';
		j = 0; z = 0;
		for (i = 0; i < row.length(); i++) 
		{
			if (row[i] != ' ')
			{
				words[j][z] = row[i];
				z++;
			}
			if (row[i] == ' ' && row[i + 1] != ' ')
			{
				j++;
				z = 0;
			}
		}
		d = 0;
		for (i = 0; i < 10; i++) 
			if (words[i][0] != '*')
				d++;
		for (i = 0; i < d - 1; i++)
		{
			for (z = 0; z < 50; z++)
				word1[z] = '*';
			for (z = 0; z < 50; z++)
				word1[z] = words[i][z]; 
			for (j = i + 1; j < d; j++)
			{
				for (z = 0; z < 50; z++)
					word2[z] = words[j][z]; 
				check = true;
				for (z = 0; z < 50; z++) 
					if (word1[z] != word2[z])
					{
						check = false;
						break;
					}
				if (check == true)
				{
					F2 << row << endl;
					break;
				}
				check = true;
				for (z = 0; z < 50; z++)
					word2[z] = '*';
			}
		}
		k = 0; max = -1;
		for (i = 0; i < d; i++)
		{
			for (j = 0; j < 50; j++)
				if (words[i][j] == 'a' || words[i][j] == 'A')
					k++;
			if (k > max)
			{
				max = k;
				n = i + 1;
			}
			k = 0;
		}
		cout << "Больше всего 'A' в строке  (" << row << ") и слове под номером " << n << endl;
	}
	F1.close();
	F2.close();
}
