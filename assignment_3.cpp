/*		This program belongs to
 *		Name		: Tehzeeb Ul Hassan
 *		Student ID	: BC230430833
 */

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<iomanip>

#ifdef _WIN32
#include<windows.h>
#else
#include<unistd.h>
#endif

using namespace std;

class Player
{
	private:
		string player_name;
		int total_score, balls_played;
	public:
		Player(string player = "", int score = 0, int balls = 0)
		{
			player_name = player;
			total_score = score;
			balls_played = balls;
		}
		
		void setName(string);
		void setScore(int);
		void setBalls(int);
		
		string getName(void) const
		{
			return player_name;
		}
		
		int getScore(void) const
		{
			return total_score;
		}
		
		int getBalls(void) const
		{
			return balls_played;
		}
};

void Player::setName(string name)
{
	player_name = name;
}

void Player::setBalls(int balls)
{
	balls_played = balls;
}

void Player::setScore(int score)
{
	total_score += score;
}

void assignName(Player [], int);
void inputScore(Player [], int);
void matchSummary(Player [], int);
void manOfMatch(Player [], int);

int main(void)
{
	system("color E");
	
	const int tot_players = 11;
	Player *players = new Player[tot_players];
	
	assignName(players, tot_players);
	
	inputScore(players, tot_players);
	
	matchSummary(players, tot_players);
	
	cout << endl;
	
	cout << "Total runs: ";
	int sum = 0;
	for (int i = 0; i < tot_players; i++)
	{
		sum += players[i].getScore();
	}
	cout << sum << "\t\t";
	
	sum = 0;
	cout << "Overs: ";
	for (int i = 0; i < tot_players; i++)
	{
		sum += players[i].getBalls();
	}
	float overs = (sum / 6) + (static_cast<float> (sum % 6) / 10);
	cout << fixed <<setprecision(1) << overs;
	
	manOfMatch(players, tot_players);
	
	delete[] players;
	
	return 0;
}

void assignName(Player object[], int size)
{
	const string names[] = {
        "Babar Azam", "Naseem Shah", "Agha Salman", "Mohammad Amir",
        "Shaheen Afridi", "Shadab Khan", "Imad Wasim", "Fakhar Zaman",
        "Haris Rauf", "Muhammad Rizwan", "Iftikhar Ahmed"
    };

    for (int i = 0; i < size; ++i) {
        object[i].setName(names[i]);
    }
}

void inputScore(Player object[], int size)
{
	srand(static_cast<unsigned int>(time(0)));
	
	const int lower = -1, upper = 6;
	int count = 0;
	
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ". " << object[i].getName() << endl;
		
		cout << "Scores per ball: ";
		int score;
		
		count = 0;
		
		do
		{
			score = lower + rand() % (upper - lower + 1);
			
			if (score == 5)
			{
				continue;
			}
			
			else if(score != -1)
			{
				cout << score << ", ";
				object[i].setScore(score);
				count ++;
			}
			
			else
			{
				cout << "Out";
				count ++;
			}
#ifdef _WIN32
            Sleep(350); // Windows Sleep function (milliseconds)
#else
            usleep(350000); // Linux usleep function (microseconds)
#endif
		} while(score != -1);
		object[i].setBalls(count);
		cout << endl;
		
		cout << "Total Score: " << object[i].getScore();
		cout << "\t\t";
		cout << "Balls Played: " << object[i].getBalls();
		cout << endl << endl;
	}
	cout << endl << endl << endl;
}

void matchSummary(Player object[], int size)
{
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "*\t\t     Match Summary\t\t    *" << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl << endl;
	
	cout << "* * * * * * * *\t      * * * * *\t      * * * * * * * *" << endl;
	cout << "* Player Name *" << "\t      ";
	cout << "* Score *" << "\t      ";
	cout << "* Balls Faced *" << endl;
	cout << "* * * * * * * *\t      * * * * *\t      * * * * * * * *" << endl;
	
	for(int i = 0; i < size; i++)
	{
#ifdef _WIN32
            Sleep(350); // Windows Sleep function (milliseconds)
#else
            usleep(350000); // Linux usleep function (microseconds)
#endif
		cout << object[i].getName() << "\t\t  ";
		cout << object[i].getScore() << "\t\t    ";
		cout << object[i].getBalls();
		cout << endl;
	}
}

void manOfMatch(Player object[], int size)
{
	int highest_score = object[0].getScore();
	int index = 0;
	
	for (int i = 1; i < size; i++)
	{
		if(highest_score < object[i].getScore())
		{
			highest_score = object[i].getScore();
			index = i;
		}
	}
	
	cout << endl << endl;
	cout << "Man of the match:  " << object[index].getName();
}
