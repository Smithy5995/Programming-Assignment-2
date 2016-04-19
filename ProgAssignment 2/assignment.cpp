#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	cout << "Word Search Program";
	cout << endl;
	cout << endl;
	cout << endl;

	bool found = false;
	int b;

	//Tells the program which files to search for
	ifstream infile("text1.txt");
	infile >> noskipws;
	ifstream searchfile("search1.txt");
	
	char searchArray[18];
	char myArray[14];

	int maxinfile = 13;
	int maxsearchfile = 17;
	int startvalue = 0;
	int searchincrement = 3;
	int searchdecrement = 2;


	//Opens the files displays the text on screen, looping around until all text is displayed
	if (infile.is_open())
	{
		

		for (int i = startvalue; i < maxinfile; i++)
		{
			infile >> myArray[i];
			cout << " " << myArray[i];

		}
	}
	//if it can't find the file or input the text to the screen, an error message will appear
	else
	{
		cout << "ERROR: ";
		cout << "Can't open input file\n";
	}

	cout << endl;
	cout << endl;
	//The same thing happens here, the search file is open
	if (searchfile.is_open())
	{
		

		for (int i = startvalue; i <= maxsearchfile; i++)
		{
			searchfile >> searchArray[i];
			

		}
	}
	//The error message here again if nothing happens
	else
	{
		cout << "ERROR: ";
		cout << "Can't open search file\n";
	}
	cout << endl;


	//The main loop searches each individual letter until it finds one that is recognises as the right letter for the answer.
	//Once it's found one letter, it will try to find the rest to complete the answer and make a word
	//This is repeated until all the answers are found. It will display which word has been found and at which location
	//If it can't find a word, then it will say it couldn't find the word
	for (int a = startvalue; a <= maxsearchfile; a += searchincrement)
	{

		cout << searchArray[a];
		a++;
		cout << searchArray[a];
		a++;
		cout << searchArray[a];
		a -= searchdecrement;
		for (b = startvalue; b <= maxinfile; b++)
		{

			if (searchArray[a] == myArray[b])
			{
				a++;
				b++;
				if (searchArray[a] == myArray[b])
				{
					a++;
					b++;
					if (searchArray[a] == myArray[b])
					{
						found = true;
						a -= searchdecrement;
					}
					else
					{
						a -= searchdecrement;
					}
				}
				else
				{
					a--;
				}
			}
			if (found)
			{
				break;
			}
		}
		if (found)
		{
			b--;
			cout << " FOUND, " << "AT LOCATION: " << b;
			found = false;
		}
		else
		{
			cout << " NOT FOUND";
		}

		cout << endl;

	}

	system("pause");

}

