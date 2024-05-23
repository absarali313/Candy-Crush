#include "Functions.h"
using namespace MenuDriver;
using namespace GamePlayFuncs;

int main()
{
	int Size, timer{}, hurdles, CandyTypes, Matches;
	bool exit = false;
	int GameDuration;
	bool GameOver;
	string Name;
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE); // maximize screen 
	PlaySound(TEXT("music.wav"), NULL, SND_ASYNC); // play music
	GameLogo(); // display game logo
	while (!exit)  // Loop until user quits
	{
	
		switch (Selected)
		{
		case 0:  // If Selected is 0
			CreateMainMenu(); //Main menu appears
			break;
		// GamePlay
		case 1:  // If Selected is 1
			DisplayChooseDifficulty(); // Ask difficulty level from user
			cout << "Please Enter Your Name : " << endl;
			cin >> Name; // Input name from user
			PointingRow = 0; PointingColumn = 0; // Set Default value
			GameOver = false; // Default value
			if ( Option == 1) // if easy
			{
				Size = 8; timer = 60; hurdles = 5, CandyTypes = 5;
			}
			else if( Option == 2) { // if hard
				Size = 12; timer = 40; hurdles = 10, CandyTypes = 8;
			}
			Moves = 15; // Reset moves
			Score = 0; // Reset score
			CandyRandomize(Size, CandyTypes ,hurdles); // Create random candies
			GameDuration = clock()/1000; // Check when game is started
			t = clock()/1000 - GameDuration; // Set timer

			while (!GameOver) // Loop until game ends
			{
				if(SwapAvailable(Size) == false) // If no match is possible then shuffle
					CandyRandomize(Size, CandyTypes, hurdles);
				CreateTable(Size); // Create table
				CandyMover(PointingRow, PointingColumn, Size, CandyTypes); // allow user to move 
				DestroyCandy(Size,CandyTypes); // Destroy matched candies
				if (t >= timer) // if time is over game over
					GameOver = true;
				t = clock()/1000 - GameDuration; // Update time
				if (Moves <= 0) // if out of moves game over
					GameOver = true;
			}
			SaveScore(Name); // Save score
			GameOverFunc(); // Display game over
			if (t >= timer) // if game over due to time
				cout << "=====> TIMES UP <=====" << endl;
			else // if game over due to moves
				cout << "=====> Out Of Moves <=====" << endl;
			cout << setw(80) << "Score  : " << Score << endl << endl;
			system("pause");
			ReturnToMainMenu(); 
			break;
		case 2:  // If Selected is 2
			CreateCredit(); // Display credits
			break;
		case 3:  // If Selected is 3
			Instructions(); // Display Rules/instructions
			break;
		// Exits the program	
		case 4:  // If Selected is 4
			LoadScores(); // Load Scores and display top 3 score with names
			break;
		case 5:  // If Selected is 5
			exit = Exit(); // Confirm if user wants to exit
			if (exit) // if user want to exit
			{
				cout << "/Closing Files........\n..\n..\n..\n/Exiting Program.........\n..\n..\n..\nSuccesfully Quited\n";
			}
			break;
		}
		
	}
	
	return 0;
}



