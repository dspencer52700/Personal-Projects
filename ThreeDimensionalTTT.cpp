/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Name: David Spencer
Lab #10
Date: 3/29/2019
Description: A program that plays three dimensional tic-tac-toe 
			 against the user

 I'm so sorry you have to look at this
 
this wouldve been so much easier if i didnt have to use inheritance but here I am 650 lines later
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>

using namespace std;

class TTTBuilder
{
	
public:
	int position;
	char value;
	
	char getValue();
	void setValue(char);
	
	TTTBuilder(int);
	TTTBuilder();
};

TTTBuilder::TTTBuilder(int a)
{
	position = a;
	value = ' ';
}

TTTBuilder::TTTBuilder()
{
	position = 0;
	value = ' ';
}

char TTTBuilder::getValue()
{
	return value;
}

void TTTBuilder::setValue(char a)
{
	value = a;
}

class TTTBoard : public TTTBuilder
{

public:
	char dimension;
	int level;
	TTTBuilder spot1, spot2, spot3, spot4, spot5, spot6, spot7, spot8, spot9;
	
	char getDimension();
	char getLevel();
	
	TTTBoard(TTTBuilder, TTTBuilder, TTTBuilder,
			 TTTBuilder, TTTBuilder, TTTBuilder,
			 TTTBuilder, TTTBuilder, TTTBuilder,
			 char, int);
	
	TTTBoard();
};

TTTBoard::TTTBoard(TTTBuilder spotA, TTTBuilder spotB, TTTBuilder spotC,
		 		   TTTBuilder spotD, TTTBuilder spotE, TTTBuilder spotF,
		 		   TTTBuilder spotG, TTTBuilder spotH, TTTBuilder spotI,
		 		   char dimensionInput, int levelInput)
{
	spot1 = spotA;
	spot2 = spotB;
	spot3 = spotC;
	spot4 = spotD;
	spot5 = spotE;
	spot6 = spotF;
	spot7 = spotG;
	spot8 = spotH;
	spot9 = spotI;
	
	dimension = dimensionInput;
	level = levelInput;
}

TTTBoard::TTTBoard()
{
}

void printBoard(TTTBoard board);
int checkWinEventTotal(TTTBoard board1, TTTBoard board2, TTTBoard board3);
int checkAxis(TTTBoard board, char check);
int checkDiagonal(TTTBoard board, char check);
int startingPlayer();

int endCondition = 1;
int XScore = 0, OScore = 0;



int main()
{
	int turnCount = 0;
	int currentPlayer;
	int success;
	
	srand(time(NULL));
	
	TTTBuilder spotA(1);
	TTTBuilder spotB(2);
	TTTBuilder spotC(3);
	TTTBuilder spotD(4);
	TTTBuilder spotE(5);
	TTTBuilder spotF(6);
	TTTBuilder spotG(7);
	TTTBuilder spotH(8);
	TTTBuilder spotI(9);
	
	TTTBoard boardX1(spotA, spotB, spotC, spotD,
					 spotE, spotF, spotG, spotH,
					 spotI, 'X', 1);
					 
	TTTBoard boardX2(spotA, spotB, spotC, spotD,
					 spotE, spotF, spotG, spotH,
					 spotI, 'X', 2);
					 
	TTTBoard boardX3(spotA, spotB, spotC, spotD,
					 spotE, spotF, spotG, spotH,
					 spotI, 'X', 3);
					 
	TTTBuilder *boardArray1 = new TTTBoard[9];
	TTTBuilder *boardArray2 = new TTTBoard[9];
	TTTBuilder *boardArray3 = new TTTBoard[9];
	
	boardArray1[0] = spotA; boardArray1[1] = spotB; boardArray1[2] = spotC;
	boardArray1[3] = spotD; boardArray1[4] = spotE; boardArray1[5] = spotF;
	boardArray1[6] = spotG; boardArray1[7] = spotH; boardArray1[8] = spotI;
		
	boardArray2[0] = spotA; boardArray2[1] = spotB; boardArray2[2] = spotC;
	boardArray2[3] = spotD; boardArray2[4] = spotE; boardArray2[5] = spotF;
	boardArray2[6] = spotG; boardArray2[7] = spotH; boardArray2[8] = spotI;
	
	boardArray3[0] = spotA; boardArray3[1] = spotB; boardArray3[2] = spotC;
	boardArray3[3] = spotD; boardArray3[4] = spotE; boardArray3[5] = spotF;
	boardArray3[6] = spotG; boardArray3[7] = spotH; boardArray3[8] = spotI;
	
	currentPlayer = startingPlayer();
	
	//Instructions
	
	cout << "Step 1: Select your level." << endl;
	cout << "Top board is level 1. Middle is 2. Bottom is 3." << endl;
	cout << endl;
	cout << "Step 2: Select your spot on the board." << endl;
	cout << "The boards are numbered like this: " << endl;
	cout << 1 << "|" << 2 << "|" << 3 << endl;
	cout << "-+-+-" << endl;
	cout << 4 << "|" << 5 << "|" << 6 << endl;
	cout << "-+-+-" << endl;
	cout << 7 << "|" << 8 << "|" << 9 << endl;
	cout << endl;
	
	cout << "Press enter to continue" << endl;
	getchar();
	
	printBoard(boardX1);
	printBoard(boardX2);
	printBoard(boardX3);
	
	
	while (endCondition)
	{
		
		if (turnCount == 27)
		{
			endCondition = 0;
			break;
		}
		if (currentPlayer == 1)
		{
			cout << "It is currently the computer's turn" << endl;
			
			success = 1;
			turnCount++;
		}
		else
		{
			cout << "It is currently your turn" << endl;
			success = 1;
			turnCount++;
		}
		
		if (currentPlayer == 1)
		{
			while (success)
			{
				int computerChoicePosition;
				int computerChoiceLevel;
				
				computerChoiceLevel = rand() % 3 + 1;
				computerChoicePosition = rand() % 9 + 1;
				
				if (computerChoiceLevel == 1)
				{
					if (boardArray1[computerChoicePosition - 1].value == ' ')
					{
						switch(computerChoicePosition)
						{
							case 1:
								boardX1.spot1.setValue('O');
								break;
							case 2:
								boardX1.spot2.setValue('O');
								break;
							case 3:
								boardX1.spot3.setValue('O');
								break;
							case 4:
								boardX1.spot4.setValue('O');
								break;
							case 5:
								boardX1.spot5.setValue('O');
								break;
							case 6:
								boardX1.spot6.setValue('O');
								break;
							case 7:
								boardX1.spot7.setValue('O');
								break;
							case 8:
								boardX1.spot8.setValue('O');
								break;
							case 9:
								boardX1.spot9.setValue('O');
								
						}
						
						boardArray1[computerChoicePosition - 1].setValue('O');
						success = 0;
						currentPlayer = 2;
						
					}
				}
				
				if (computerChoiceLevel == 2)
				{
					if (boardArray2[computerChoicePosition - 1].value == ' ')
					{
						switch(computerChoicePosition)
						{
							case 1:
								boardX2.spot1.setValue('O');
								break;
							case 2:
								boardX2.spot2.setValue('O');
								break;
							case 3:
								boardX2.spot3.setValue('O');
								break;
							case 4:
								boardX2.spot4.setValue('O');
								break;
							case 5:
								boardX2.spot5.setValue('O');
								break;
							case 6:
								boardX2.spot6.setValue('O');
								break;
							case 7:
								boardX2.spot7.setValue('O');
								break;
							case 8:
								boardX2.spot8.setValue('O');
								break;
							case 9:
								boardX2.spot9.setValue('O');
								
						}
						boardArray2[computerChoicePosition - 1].setValue('O');
						success = 0;
						currentPlayer = 2;
						
					}
				}
				
				if (computerChoiceLevel == 3)
				{
					if (boardArray3[computerChoicePosition - 1].value == ' ')
					{
						switch(computerChoicePosition)
						{
							case 1:
								boardX3.spot1.setValue('O');
								break;
							case 2:
								boardX3.spot2.setValue('O');
								break;
							case 3:
								boardX3.spot3.setValue('O');
								break;
							case 4:
								boardX3.spot4.setValue('O');
								break;
							case 5:
								boardX3.spot5.setValue('O');
								break;
							case 6:
								boardX3.spot6.setValue('O');
								break;
							case 7:
								boardX3.spot7.setValue('O');
								break;
							case 8:
								boardX3.spot8.setValue('O');
								break;
							case 9:
								boardX3.spot9.setValue('O');
								
						}
						boardArray3[computerChoicePosition - 1].setValue('O');
						success = 0;
						currentPlayer = 2;
						
					}
				}
				
			}
		}
		
		if (currentPlayer == 2)
		{ 
			while (success)
			{
				cout << "Which level would you like to play?" << endl;
				cout << "Top - 1   Middle - 2   Bottom - 3" << endl;
				int playerChoiceLevel;
				cin >> playerChoiceLevel;
				
				if (playerChoiceLevel == 1)
				{
					cout << "Which spot would you like to play?" << endl;
					int playerChoiceSpot;
					cin >> playerChoiceSpot;
					
					if (boardArray1[playerChoiceSpot - 1].value == ' ')
					{
						switch (playerChoiceSpot)
						{

						case 1:
							boardX1.spot1.setValue('X');
						break;
						
						case 2:
							boardX1.spot2.setValue('X');
						break;
						
						case 3:
							boardX1.spot3.setValue('X');
						break;
						
						case 4:
							boardX1.spot4.setValue('X');
						break;
						
						case 5:
							boardX1.spot5.setValue('X');
						break;
						
						case 6:
							boardX1.spot6.setValue('X');
						break;
						
						case 7:
							boardX1.spot7.setValue('X');
						break;
						
						case 8:
							boardX1.spot8.setValue('X');
						break;
						
						case 9:
							boardX1.spot9.setValue('X');
						break;
						}
						
						boardArray1[playerChoiceSpot - 1].value = 'X';
						currentPlayer = 1;
						success = 0;
					}
					else 
					{
						cout << "Please pick a different spot" << endl;
					}				
				}
				
				if (playerChoiceLevel == 2)
				{
					
					cout << "Which spot would you like to play?" << endl;
					int playerChoiceSpot;
					cin >> playerChoiceSpot;
						
					if (boardArray2[playerChoiceSpot - 1].value == ' ')
					{
						switch (playerChoiceSpot)
						{

						case 1:
							boardX2.spot1.setValue('X');
						break;
						
						case 2:
							boardX2.spot2.setValue('X');
						break;
						
						case 3:
							boardX2.spot3.setValue('X');
						break;
						
						case 4:
							boardX2.spot4.setValue('X');
						break;
						
						case 5:
							boardX2.spot5.setValue('X');
						break;
						
						case 6:
							boardX2.spot6.setValue('X');
						break;
						
						case 7:
							boardX2.spot7.setValue('X');
						break;
						
						case 8:
							boardX2.spot8.setValue('X');
						break;
						
						case 9:
							boardX2.spot9.setValue('X');
						break;
						}
						
						boardArray2[playerChoiceSpot - 1].value = 'X';
						currentPlayer = 1;
						success = 0;
					}
					else 
					{
						cout << "Please pick a different spot" << endl;
					}	
				}

				if (playerChoiceLevel == 3)
				{
					
					cout << "Which spot would you like to play?" << endl;
					int playerChoiceSpot;
					cin >> playerChoiceSpot;
						
					if (boardArray3[playerChoiceSpot - 1].value == ' ')
					{
						switch (playerChoiceSpot)
						{

						case 1:
							boardX3.spot1.setValue('X');
						break;
						
						case 2:
							boardX3.spot2.setValue('X');
						break;
						
						case 3:
							boardX3.spot3.setValue('X');
						break;
						
						case 4:
							boardX3.spot4.setValue('X');
						break;
						
						case 5:
							boardX3.spot5.setValue('X');
						break;
						
						case 6:
							boardX3.spot6.setValue('X');
						break;
						
						case 7:
							boardX3.spot7.setValue('X');
						break;
						
						case 8:
							boardX3.spot8.setValue('X');
						break;
						
						case 9:
							boardX3.spot9.setValue('X');
						break;
						}
						
						boardArray3[playerChoiceSpot - 1].value = 'X';
						currentPlayer = 1;
						success = 0;
					}
					else 
					{
						cout << "Please pick a different spot" << endl;
					}	
				}
	
			}
		}
		checkWinEventTotal(boardX1, boardX2, boardX3);
		
		printBoard(boardX1);
		printBoard(boardX2);
		printBoard(boardX3);
	}
	checkWinEventTotal(boardX1, boardX2, boardX3);
}

void printBoard(TTTBoard board)
{
	char charA, charB, charC;
	char charD, charE, charF;
	char charG, charH, charI;
	
	charA = board.spot1.value; charB = board.spot2.value; charC = board.spot3.value; 
	charD = board.spot4.value; charE = board.spot5.value; charF = board.spot6.value;
	charG = board.spot7.value; charH = board.spot8.value; charI = board.spot9.value;
	
	cout << endl;
	cout << charA << "|" << charB << "|" << charC << endl;
	cout << "-+-+-" << endl;
	cout << charD << "|" << charE << "|" << charF << endl;
	cout << "-+-+-" << endl;
	cout << charG << "|" << charH << "|" << charI << endl;
	cout << endl;
}

int checkWinEventTotal(TTTBoard board1, TTTBoard board2, TTTBoard board3)
{
	XScore = 0; OScore = 0;
	TTTBoard BoardX1 = board1;
	TTTBoard BoardX2 = board2;
	TTTBoard BoardX3 = board3;
	TTTBoard BoardY1(board1.spot1, board1.spot4, board1.spot7,
					 board2.spot1, board2.spot4, board2.spot7,
					 board3.spot1, board3.spot4, board3.spot7, 'Y', 1);

	TTTBoard BoardY2(board1.spot2, board1.spot5, board1.spot8,
					 board2.spot2, board2.spot5, board2.spot8,
					 board3.spot2, board3.spot5, board3.spot8, 'Y', 2);	
										
	TTTBoard BoardY3(board1.spot3, board1.spot6, board1.spot9,
					 board2.spot3, board2.spot6, board2.spot9,
					 board3.spot3, board3.spot6, board3.spot9, 'Y', 3);	
										
	TTTBoard BoardZ1(board1.spot7, board1.spot8, board1.spot9,
					 board2.spot7, board2.spot8, board2.spot9,
					 board3.spot7, board3.spot8, board3.spot9, 'Z', 1);
										
	TTTBoard BoardZ2(board1.spot4, board1.spot5, board1.spot6,
			   	     board2.spot4, board2.spot5, board2.spot6,
				     board3.spot4, board3.spot5, board3.spot6, 'Z', 2);
										
	TTTBoard BoardZ3(board1.spot1, board1.spot2, board1.spot3,
					 board2.spot1, board2.spot2, board2.spot3,
					 board3.spot1, board3.spot2, board3.spot3, 'Z', 3);
				
				

							
	XScore = ((checkAxis(BoardX1, 'X') + checkAxis(BoardX2, 'X') + checkAxis(BoardX3, 'X') +
			   checkAxis(BoardY1, 'X') + checkAxis(BoardY2, 'X') + checkAxis(BoardY3, 'X') +
	  		   checkAxis(BoardZ1, 'X') + checkAxis(BoardZ2, 'X') + checkAxis(BoardZ3, 'X')) / 2);			  	  

	XScore += (checkDiagonal(BoardX1, 'X') + checkDiagonal(BoardX2, 'X') + checkDiagonal(BoardX3, 'X') +
			   checkDiagonal(BoardY1, 'X') + checkDiagonal(BoardY2, 'X') + checkDiagonal(BoardY3, 'X') +
			   checkDiagonal(BoardZ1, 'X') + checkDiagonal(BoardZ2, 'X') + checkDiagonal(BoardZ3, 'X'));
			  	  
	OScore = ((checkAxis(BoardX1, 'O') + checkAxis(BoardX2, 'O') + checkAxis(BoardX3, 'O') +
			   checkAxis(BoardY1, 'O') + checkAxis(BoardY2, 'O') + checkAxis(BoardY3, 'O') +
			   checkAxis(BoardZ1, 'O') + checkAxis(BoardZ1, 'O') + checkAxis(BoardZ3, 'O')) / 2);		  	  

	OScore += (checkDiagonal(BoardX1, 'O') + checkDiagonal(BoardX2, 'O') + checkDiagonal(BoardX3, 'O') +
			   checkDiagonal(BoardY1, 'O') + checkDiagonal(BoardY2, 'O') + checkDiagonal(BoardY3, 'O') +
			   checkDiagonal(BoardZ1, 'O') + checkDiagonal(BoardZ1, 'O') + checkDiagonal(BoardZ3, 'O'));	 
		
	cout << "X's score: " << XScore << endl;
	cout << "O's score: " << OScore << endl; 	
}

int checkAxis(TTTBoard board, char check)
{
	int total = 0;
	
	if (board.spot1.value == check && board.spot1.value == board.spot2.value && board.spot2.value == board.spot3.value)
	{
		total += 1;
	}
	
	if (board.spot4.value == check && board.spot4.value == board.spot5.value && board.spot5.value == board.spot6.value)
	{
		total += 1;
	}
	
	if (board.spot7.value == check && board.spot7.value == board.spot8.value && board.spot8.value == board.spot9.value)
	{
		total += 1;
	}
	
	if (board.spot1.value == check && board.spot1.value == board.spot4.value && board.spot4.value == board.spot7.value)
	{
		total += 1;
	}
	
	if (board.spot2.value == check && board.spot2.value == board.spot5.value && board.spot5.value == board.spot8.value)
	{
		total += 1;
	}
	
	if (board.spot3.value == check && board.spot3.value == board.spot6.value && board.spot6.value == board.spot9.value)
	{
		total += 1;
	}
	return total;
}

int checkDiagonal(TTTBoard board, char check)
{
	int total = 0;
	
	if (board.spot1.value == check && board.spot1.value == board.spot5.value && board.spot5.value == board.spot9.value)
	{
		total += 1;
	}
	
	if (board.spot3.value == check && board.spot3.value == board.spot5.value && board.spot5.value == board.spot7.value)
	{
		total += 1;
	}
	
	return total;
}
int startingPlayer()
{
	int flip;
	flip = rand() % 2 + 1;
	
	if (flip == 1)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}
