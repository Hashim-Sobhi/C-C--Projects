/************************************************************/
/** author  :Hashim Sobhy                                  **/
/** Date    :18.5.2021                                      **/
/** Version :1.0                                           **/
/** Title   :Assignment #1 Command Parser                                 **/
/************************************************************/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/* functions decleration */
void print(int argc, char** argv);
void reverse(int argc, char** argv);
void upper(int argc, char** argv);
void shuffle(int argc, char** argv);
void shuffleStatement(int argc, char** argv);
void deleteCommand(int argc, char** argv);
void middle(int argc, char** argv);
void add(int argc, char** argv);
void random(int argc, char** argv);
/************************/
int main(int argc, char** argv)
{
	string command = argv[1];
	if (argc < 2) { cout << "Incorret Number of Arguments"; return 0;}
	if (command != "print" && command != "reverse" && command != "upper" && command != "shuffle" && command != "shuffleStatement" && command != "delete" && command != "middle" && command != "add" && command != "random")
	{
		cout << "Undefined Command";
		return 0;
	}
	if (argc < 3) { cout << "Incorret Number of Arguments"; return 0;}
	/*comands*/
	if (command == "print"){ print(argc, argv); }
	else if (command == "reverse") { reverse(argc, argv); }
	else if (command == "upper") { upper(argc, argv); }
	else if (command == "shuffle") { shuffle(argc, argv); }
	else if (command == "shuffleStatement") { shuffleStatement(argc, argv); }
	else if (command == "delete") { deleteCommand(argc, argv); }
	else if (command == "middle") { middle(argc, argv); }
	else if (command == "add") { add(argc, argv); }
	else if (command == "random") { random(argc, argv); }
	else { cout << "Undefined Command"; }
	return 0;
}

void print(int argc, char** argv)
{
	for (int i = 2; i < argc; i++)
	{
		cout << argv[i] << " "; 
	}
}
void reverse(int argc, char** argv)
{
	for (int i = 1; i <= argc-2; i++)
	{
		cout << argv[argc-i] << " "; 
	}
}
void upper(int argc, char** argv)
{
	for (int i = 2; i < argc; i++)
	{
		string word = argv[i];
		string upperWord = "";
		for (int i = 0; i < word.size(); i++)
		{
			upperWord += toupper(word[i]);
		}
		cout << upperWord << " ";
	}
}
void shuffle(int argc, char** argv)
{
	if (argc > 3)
	{
		cout << "Incorrect Number of Arguments";
		return;
	}
	string word = argv[2];
	int loopCounter = word.size() / 2;
	string shuffledWord;

	for (int i = 0; i < loopCounter; i++)
	{
		shuffledWord += argv[2][(i * 2) + 1];
		shuffledWord += argv[2][(i * 2)];
	}
	if ((word.size() % 2))
		cout << shuffledWord << argv[2][word.size() - 1] << " ";
	else
		cout << shuffledWord << " ";
}
void shuffleStatement(int argc, char** argv)
{
	int loopCounter = (argc - 2) / 2;
	for (int i = 0; i < loopCounter; i++)
	{
		cout << argv[2 * i + 3] << " ";
		cout << argv[2 * i + 2] << " ";
	}
	if (argc % 2)
		cout << argv[argc-1] << " ";
}
void deleteCommand(int argc, char** argv)
{
	if (argc < 4)
	{
		cout << "Incorrect Number of Arguments";
		return;
	}
	string argv2 = argv[2];
	// check if 3rd argu is integer
	for (int i = 0; i < argv2.size(); i++)
	{
		if (!isdigit(argv2[i]))
		{
			cout << "Incorrect Data Type";
			return ;
		}
	}
	//converting string to int num
	int num = stoi(argv[2]);
	//chack argument's num
	if (num > argc - 3)
	{
		cout << "Incorret Number of Arguments";
		return;
	}
	// print arguments
	for (int i = 3; i < argc; i++)
	{
		if (i != 2 + num)
			cout << argv[i] << " ";
	}
}
void middle(int argc, char** argv)
{
	int mid = (argc - 2) / 2;
	
	if(argc % 2)
		cout << argv[2 + mid] << " ";
	else
	{
		cout << argv[1 + mid] << " ";
		cout << argv[2 + mid] << " ";
	}
}
void add(int argc, char** argv)
{
	int sum = 0;
	//check if arguments are integer
	for (int i = 2; i < argc; i++)
	{
		string number = argv[i];
		if (number == "-")
		{
			cout << "Incorrect Data Type";
			return ;
		}
		int j;
		if (number[0] == '-')
			j = 1;
		else
			j = 0;
		while(j < number.size())
		{
			if (!isdigit(number[j]))
			{
				cout << "Incorrect Data Type";
				return;
			}
			j++;
		}
		int num;
		stringstream(number) >> num;
		sum += num;
	}
	cout << sum;
}
void random(int argc, char** argv)
{
	if (argc != 6)
	{
		cout << "Incorrect Number of Arguments";
		return;
	}
	//check if arguments are integer
	for (int i = 2; i < argc; i++)
	{
		string number = argv[i];
		if (number == "-")
		{
			cout << "Incorrect Data Type";
			return ;
		}
		int j=0;
		if (number[0] == '-')
			j = 1;
		else
			j = 0;
		while(j < number.size())
		{
			if (!isdigit(number[j]))
			{
				cout << "Incorrect Data Type";
				return;
			}
			j++;
		}
	}
	int sequenceLength, minNumber, maxNumber, seedValue;
	stringstream(argv[2]) >> sequenceLength;
	stringstream(argv[3]) >> minNumber;
	stringstream(argv[4]) >> maxNumber;
	stringstream(argv[5]) >> seedValue;
	if (sequenceLength < 1 || minNumber > maxNumber)
	{
		cout << "Incorrect Data Type";
		return;
	};
	srand(seedValue);
	for (int i = 0; i < sequenceLength; i++)
	{
		cout << (rand() % maxNumber) + minNumber << " ";
	}
}