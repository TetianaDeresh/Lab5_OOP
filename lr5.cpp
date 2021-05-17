/*Створити базовий клас ЗМАГАННЯ З ФУТБОЛУ 
(задаються назва, дати початку і завершення).
Створити похідні класи ЧЕМПІОНАТ(задається перелік команд - призерів; 
призерам чемпіонату умовно нараховують 5, 3 і 1 бали) 
та СУПЕРКУБОК(задаються команди – переможець і фіналіст, 
яким умовно нараховують 2 і 1 бал).
Для введених даних про змагання різних років обчислити 
сумарну здобутків різного типу для заданої команди 
і її сумарний нарахований бал.*/

#include <iostream>
#include <string>

using namespace std;

class Football_Competitions
{
protected:
	string name;
	string date_start;
	string date_end;
public:
	virtual int GetGoalForTeam(string Team) {
		return 0;
	}
	virtual void PrintData() {}
	virtual void PrintZdobutku(string Team) {}
	string GetName()
	{
		return name;
	}
	string GetDate_start()
	{
		return date_start;
	}
	string GetDate_end()
	{
		return date_end;
	}
	void SetName(string name)
	{
		this->name = name;
	}
	void SetDate_strart(string date_start)
	{
		this->date_start = date_start;
	}
	void SetDate_end(string date_end)
	{
		this->date_end = date_end;
	}
};

class Championship : public Football_Competitions
{
private:
	int goal_team[200];
	int ball[200];
	string teams[200];
	int count;
public:
	Championship()
	{
		cout << "\nHow many teems in Championship? (<200)" << endl;
		cin >> this->count;
		if (this->count > 200)
			this->count = 200;
		cout << "\nEnter Championship name" << endl;
		cin >> this->name;
		cout << "\nEnter Championship date start (2002-02-03)" << endl;
		cin >> this->date_start;
		cout << "\nEnter Championship date end (2002-02-08)" << endl;
		cin >> this->date_end;
		cout << "\n\tEnter teams" << endl;
		for (int i = 0; i < this->count; i++)
		{
			cout << "\nEnter team name" << endl;
			cin >> teams[i];
			cout << "\nEnter points (5, 3 or 1)" << endl;
			cin >> goal_team[i];
		}

		int i, j;
		for (i = 0; i < this->count - 1; i++)
			for (j = 0; j < this->count - i - 1; j++)
				if (goal_team[j] < goal_team[j + 1])
				{
					int temp = goal_team[j];
					string temp_str = teams[j];
					goal_team[j] = goal_team[j + 1];
					teams[j] = teams[j + 1];
					goal_team[j + 1] = temp;
					teams[j + 1] = temp_str;
				}
		if (this->count > 0)
			ball[0] = 5;
		if (this->count > 1)
			ball[1] = 3;
		if (this->count > 2)
			ball[2] = 1;

	}

	int GetGoalForTeam(string Team)
	{
		int ball_te = 0;
		for (int i = 0; i < this->count; i++)
		{
			if (teams[i] == Team)
				ball_te += ball[i];
		}
		return ball_te;
	}
	void PrintData()
	{
		cout << "\n\tName: " << this->name << endl;
		cout << "\nData start: " << this->date_start << endl;
		cout << "\nData end: " << this->date_end << endl;
		cout << "\n\tTeams " << endl;
		for (int i = 0; i < this->count; i++)
		{
			cout << "\nTeam name: " << this->teams[i] << "\tpoints: " << this->goal_team[i] << endl;
		}

	}
	virtual void PrintZdobutku(string Team)
	{
		for (int i = 0; i < this->count; i++)
		{
			if (teams[i] == Team)
			{
				cout << "\nIn " << this->name << " place: " << i + 1 << endl;
			}
		}
	}


};

class SUPER_CUP : public Football_Competitions
{
private:
	int goal_team[2];
	int points[2];
	string teams[2];
public:
	SUPER_CUP()
	{
		cout << "\nEnter SUPER CUP name" << endl;
		cin >> this->name;
		cout << "\nEnter SUPER CUP date start (2002-02-03)" << endl;
		cin >> this->date_start;
		cout << "\nEnter SUPER CUP date end (2002-02-08)" << endl;
		cin >> this->date_end;
		cout << "\n\tEnter teams" << endl;
		for (int i = 0; i < 2; i++)
		{
			cout << "\nEnter team name" << endl;
			cin >> teams[i];
			cout << "\nEnter points ( 2 or 1)" << endl;
			cin >> goal_team[i];
		}
		if (goal_team[0] > goal_team[1])
		{
			points[0] = 2;
			points[1] = 1;
		}
		else
		{
			points[0] = 1;
			points[1] = 2;
		}

	}

	int GetGoalForTeam(string Team)
	{
		int ball_te = 0;
		for (int i = 0; i < 2; i++)
		{
			if (teams[i] == Team)
				ball_te += points[i];
		}
		return ball_te;
	}
	void PrintData()
	{
		cout << "\n\tName: " << this->name << endl;
		cout << "\nData start: " << this->date_start << endl;
		cout << "\nData end: " << this->date_end << endl;
		cout << "\n\tTeams " << endl;
		for (int i = 0; i < 2; i++)
		{
			cout << "\nTeam name: " << this->teams[i] << "\tpoints: " << this->goal_team[i] << endl;
		}
	}
	virtual void PrintZdobutku(string Team)
	{
		for (int i = 0; i < 2; i++)
		{
			if (teams[i] == Team)
			{
				cout << "\nIn " << this->name << " place: " << (points[i] == 2 ? 1 : 2) << endl;
			}
		}
	}


};

int main()
{
	system("chcp 1251");
	system("cls");
	Football_Competitions* arr[500];
	cout << "\nEnter how many Championships/SUPER CUPS you want to write\n" << endl;
	int count;
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		int chose;
		cout << "\nEnter what you want to add!\n" << endl;
		cout << "1 - Championship" << endl;
		cout << "2 - Super Cup" << endl;
		cin >> chose;
		if (chose == 1)
		{
			arr[i] = new Championship();
		}
		else
		{
			arr[i] = new SUPER_CUP();
		}
	}
	cout << "\n\tYour data" << endl;
	for (int i = 0; i < count; i++)
	{
		arr[i]->PrintData();
	}
	cout << "\n\tEnter your team" << endl;
	string team;
	cin >> team;
	int point = 0;
	cout << "\n\tAchievements of your team" << endl;
	for (int i = 0; i < count; i++)
	{
		point += arr[i]->GetGoalForTeam(team);
		arr[i]->PrintZdobutku(team);
	}
	cout << "\nYour team " << team << " gets points: " << point << endl;
	system("pause");
	return 0;
}