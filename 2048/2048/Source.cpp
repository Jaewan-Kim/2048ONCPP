#include <iostream>
#include <string>
#include <vector>
using namespace std;


class game
{
	bool gameover;
	vector<int> values;
	vector<int> lastterm;

public:
	game() :gameover(false)
	{
		values.push_back(0);
		values.push_back(0);
		values.push_back(0);
		values.push_back(0);
		values.push_back(0);
		values.push_back(0);
		values.push_back(0);
		values.push_back(0);
		values.push_back(0);
		values.push_back(0);
		values.push_back(0);
		values.push_back(0);
		values.push_back(0);
		values.push_back(0);
		values.push_back(0);
		values.push_back(0);
		lastterm = values;
		addNew();
	}
	void logiccheck()
	{
		int nofsame = 0;
		for (int i = 0; i < 16; i++)
			if (values[i] == lastterm[i])
				nofsame++;
		int free = howmanyfree();
		if (free == 0&& nofsame==16)
		{
			// i should check if there are adjacent elements that can be merged together
			gameover = true;
			display();
			cout << "Game over!" << endl;
		}
	}
	void display()
	{
		cout << " ___________________________________________________________" << endl;

		for (int i = 0; i < 4; i++)
		{
			cout << "|              |              |              |              |" << endl;
			cout << "|              |              |              |              |" << endl;
			cout << "|              |              |              |              |" << endl;

			for (int j = 0; j < 4; j++)
			{
				int value = values[i * 4 + j];
				cout << "|    ";
				if (value == 0)
					cout << "     ";
				else if (value == 2 || value == 4 || value == 8)
				{
					cout << "  " << value << "  ";
				}
				else if (value == 16 || value == 32 || value == 64)
				{
					cout << " " << value << "  ";
				}
				else if (value == 128 || value == 256 || value == 512)
				{
					cout << " " << value << " ";
				}
				else if (value == 1024 || value == 2048 || value == 4096 || value == 8192)
				{
					cout << value << " ";
				}
				else
				{
					cout << value;
				}
				cout << "     ";
			}

			cout << "|" << endl;
			cout << "|              |              |              |              |" << endl;
			cout << "|              |              |              |              |" << endl;
			cout << "|______________|______________|______________|______________|" << endl;


		}

		cout << "Use WASD to move! Press X if you want to quit!" << endl;
	}
	void readInput(char c)
	{
		if (c == 'X')
			gameover = true;
		else if (c == 'W')
			up();
		else if (c == 'A')
			left();
		else if (c == 'S')
			down();
		else
			right();
	}

	void right()
	{
		lastterm = values;

		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 3; i++)
			{
				if (values[15 - (i + j * 4)] == 0)
				{
					int x = 1;
					int temp = values[15 - (i + j * 4 + x)];
					while (x + i < 3 && temp == 0)
					{
						x++;

						temp = values[15 - (i + j * 4 + x)];
					}
					values[15 - (i + j * 4)] = values[15 - (i + j * 4 + x)];
					values[15 - (i + j * 4 + x)] = 0;
				}
			}
		}
		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 3; i++)
			{
				if (values[15 - (i + j * 4)] != 0 && values[15 - (i + j * 4 + 1)] == values[15 - (i + j * 4)])
				{
					values[15 - (i + j * 4)] = values[15 - (i + j * 4)] * 2;
					values[15 - (i + j * 4 + 1)] = 0;
				}
			}
		}
		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 3; i++)
			{
				if (values[15 - (i + j * 4)] == 0)
				{
					int x = 1;
					int temp = values[15 - (i + j * 4 + x)];
					while (x + i < 3 && temp == 0)
					{
						x++;

						temp = values[15 - (i + j * 4 + x)];
					}
					values[15 - (i + j * 4)] = values[15 - (i + j * 4 + x)];
					values[15 - (i + j * 4 + x)] = 0;
				}
			}
		}
		int nofsame = 0;
		for (int i = 0; i < 16; i++)
		{
			if (values[i] == lastterm[i])
				nofsame++;
		}
		if (nofsame == 16)
			;
		else
			addNew();
		
		
			
	}
	void left()
	{
		lastterm = values;
		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 3; i++)
			{
				if (values[i + j * 4] == 0)
				{
					int x = 1;
					int temp = values[i + j * 4 + x];
					while (x + i < 3 && temp == 0)
					{
						x++;

						temp = values[i + j * 4 + x ];
					}
					values[i + j * 4] = values[i + j * 4 + x];
					values[i + j * 4 + x] = 0;
				}
			}
		}
		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 3; i++)
			{
				if (values[i + j * 4] != 0 && values[i + j * 4 + 1] == values[i + j * 4])
				{
					values[i + j * 4] = values[i + j * 4] * 2;
					values[i + j * 4 + 1] = 0;
				}
			}
		}
		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 3; i++)
			{
				if (values[i + j * 4] == 0)
				{
					int x = 1;
					int temp = values[i + j * 4 + x];
					while (x + i < 3 && temp == 0)
					{
						x++;

						temp = values[i + j * 4 + x];
					}
					values[i + j * 4] = values[i + j * 4 + x];
					values[i + j * 4 + x] = 0;
				}
			}
		}
		int nofsame = 0;
		for (int i = 0; i < 16; i++)
		{
			if (values[i] == lastterm[i])
				nofsame++;
		}
		if (nofsame == 16)
			;
		else
			addNew();
		
	}
	void up()
	{
		lastterm = values;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (values[i + j * 4] == 0)
				{
					int x = 1;
					int temp = values[i + j * 4+x*4];
					while (x + j < 3 && temp == 0)
					{
						x++;
						
						temp = values[i + j * 4 + x*4];
					}
					values[i + j * 4] = values[i + j * 4 + x*4];
					values[i + j * 4 + x*4] = 0;
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (values[i + j * 4] != 0 && values[i + j * 4 + 4] == values[i + j * 4])
				{
					values[i + j * 4] = values[i + j * 4] * 2;
					values[i + j * 4 + 4] = 0;
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (values[i + j * 4] == 0)
				{
					int x = 1;
					int temp = values[i + j * 4 + x * 4];
					while (x + j < 3 && temp == 0)
					{
						x++;

						temp = values[i + j * 4 + x * 4];
					}
					values[i + j * 4] = values[i + j * 4 + x * 4];
					values[i + j * 4 + x * 4] = 0;
				}
			}
		}
		
		int nofsame = 0;
		for (int i = 0; i < 16; i++)
		{
			if (values[i] == lastterm[i])
				nofsame++;
		}
		if (nofsame == 16)
			;
		else
			addNew();
	}
	void down()
	{
		lastterm = values;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (values[15 - (i + j * 4)] == 0)
				{
					int x = 1;
					int temp = values[15 - (i + j * 4 + x * 4)];
					while (x + j < 3 && temp == 0)
					{
						x++;

						temp = values[15 - (i + j * 4 + x * 4)];
					}
					values[15 - (i + j * 4)] = values[15 - (i + j * 4 + x * 4)];
					values[15 - (i + j * 4 + x * 4)] = 0;
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (values[15 - (i + j * 4)] != 0 && values[15 - (i + j * 4 + 4)] == values[15 - (i + j * 4)])
				{
					values[15 - (i + j * 4)] = values[15 - (i + j * 4)] * 2;
					values[15 - (i + j * 4 + 4)] = 0;
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (values[15 - (i + j * 4)] == 0)
				{
					int x = 1;
					int temp = values[15 - (i + j * 4 + x * 4)];
					while (x + j < 3 && temp == 0)
					{
						x++;

						temp = values[15 - (i + j * 4 + x * 4)];
					}
					values[15 - (i + j * 4)] = values[15 - (i + j * 4 + x * 4)];
					values[15 - (i + j * 4 + x * 4)] = 0;
				}
			}
		}
		int nofsame = 0;
		for (int i = 0; i < 16; i++)
		{
			if (values[i] == lastterm[i])
				nofsame++;
		}
		if (nofsame == 16)
			;
		else
			addNew();
	}
	void begin()
	{
		while (!gameover)
		{
			display();
			if (gameover)
				break;
			char c;
			cout << "Input: ";
			cin >> c;
			c = toupper(c);
			while (!(c == 'X' || c == 'W' || c == 'A' || c == 'S' || c == 'D'))
			{
				cout << "Invalid input! Try again: ";
				cin >> c;
				c = toupper(c);
			}
			readInput(c);
			logiccheck();
			if (gameover)
				;
			else
				system("CLS");
		}
	}

	int howmanyfree()
	{
		int free = 0;
		for (int i = 0; i < 16; i++)
		{
			if (values[i] == 0)
			{
				free++;
			}
		}
		return free;
	}

	void addNew()
	{
		vector<int> vec;
		for (int i = 0; i < 16; i++)
		{
			if (values[i] == 0)
				vec.push_back(i);
		}

		int index = vec[rand() % vec.size()];
		int prob = rand() % 10;
		if (prob < 8)
			values[index] = 2;
		else
			values[index] = 4;
	}
};

int main()
{

	game twenty;
	twenty.begin();
}