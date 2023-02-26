#include <iostream>
#include <cstdlib>
#include <iomanip>

void printBoard(char board[100], int p1, int p2);
int newPos(char board[100], int currentPos, int roll);

int main() {
	char board[100] = { 100, 99, 101, 97, 102, 95, 94, 93, 92, 91,
						81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
						80, 79, 78, 77, 76, 102, 74, 73, 72, 103,
						61, 104, 63, 64, 65, 66, 67, 68, 69, 70,
						60, 59, 58, 101, 56, 55, 54, 53, 103, 51,
						41, 42, 105, 44, 45, 107, 106, 48, 49, 50,
						104, 39, 38, 37, 36, 35, 34, 33, 32, 31,
						21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
						20, 105, 18, 17, 16, 15, 14, 13, 12, 11,
						1, 2, 3, 4, 5, 107, 7, 8, 106, 10};
	
	
	int dice;
	bool player1turn = true;
	char ch = 'p'; //A letter which isn't q
	srand(time(nullptr));
	while (ch != 'q') {
		int player1pos = 90;
		int player2pos = 90;
		printBoard(board, player1pos, player2pos);
		do {
			std::cout << "Player " << (player1turn ? 'A' : 'B') << " to roll\n";
			std::cout << "Roll the dice! (press enter)\n";
			std::cin.ignore();
			dice = rand() % 6 + 1;
			std::cout << "You rolled a " << dice << '\n';

			
			if (player1turn) {
				player1pos = newPos(board, player1pos, dice);
			}
			else {
				player2pos = newPos(board, player2pos, dice);
			}
			player1turn = !player1turn;
			printBoard(board, player1pos, player2pos);
		} while (player1pos != 0 && player2pos != 0);
		std::cout << "Player " << (player1pos == 0 ? 'A' : 'B') << " wins!\n"
			<< "Input q to quit or any other character to play again\n";
		std::cin >> ch;
	}
}

void printBoard(char board[100], int p1, int p2) {
	for (int i = 0; i < 100; ++i) {
		if (i % 10 == 0) {
			std::cout << '\n';
		}
		std::cout << std::setw(4);
		if (i == p1 && i == p2) {
			std::cout << "AB";
		}
		else if (i == p1) {
			std::cout << "A";
		}
		else if (i == p2) {
			std::cout << "B";
		}

		else {
			switch (board[i]) {
			case 101:
				std::cout << "L1";
				break;
			case 102:
				std::cout << "S1";
				break;
			case 103:
				std::cout << "L2";
				break;
			case 104:
				std::cout << "S2";
				break;
			case 105:
				std::cout << "L3";
				break;
			case 106:
				std::cout << "S4";
				break;
			case 107:
				std::cout << "L3";
				break;
			default:
				std::cout << (int)board[i];
			}
		}

	}
	std::cout << "\n\n";
}

int newPos(char board[100], int currentPos, int roll) {
	int direction = (currentPos / 10) % 2 == 0 ? -1 : 1; //Left or right
	int wrapAround = (currentPos % 10) + direction * (roll % 10); //Go up
	if (currentPos - roll < 0) {
		return currentPos;
	}
	else if (wrapAround < 0) { //going left
		int distToEdge = (currentPos % 10);
		currentPos -= distToEdge;
		roll -= distToEdge % 10; //remaining spaces to move
		currentPos -= 10; //go up one square
		--roll; //one less squares to move after moving up
		currentPos += roll; //move rest of the way
	}
	else if (wrapAround >= 10) { //going right
		std::cout << currentPos;
		int change = ((10 - currentPos % 10) - 1);
		currentPos += change;
		std::cout << currentPos;
		roll -= change;
		currentPos -= 10;
		std::cout << currentPos;
		--roll; //one less squares to move after moving up
		currentPos -= roll; //move rest of the way
	}
	else {
		currentPos += roll * direction; //no going up, simply move
	}
	if (board[currentPos] > 100) {
		int i = 0;
		while (i < 100 && board[i] != board[currentPos] || i == currentPos) ++i;
		bool isSnakeHead = i > currentPos && (int)(board[currentPos]) % 2 == 0; /*landed in snake's mouth. 
		Snakes represented with even numbers in board*/ 
		if (isSnakeHead) std::cout << "SNAKE! SNAKE! SNAKE!\n"; //AAAAAAAAAHHHH
		bool isLadderStart = i < currentPos && (int)(board[currentPos]) % 2 == 1; //similar for ladders with odd numbers
		if (isSnakeHead || isLadderStart) {
			currentPos = i;
		}
	}
	return currentPos;
}