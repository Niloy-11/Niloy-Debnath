/* Tic-Tac_Toe game program: 
 * 1 | 2 | 3
 * ---------
 * 4 | 5 | 6
 * ---------
 * 7 | 8 | 9
 * created by- Niloy Debnath
 */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

char tictac_board[SIZE][SIZE] = { {'1', '2', '3'},
                           	  {'4', '5', '6'},
                         	  {'7', '8', '9'} };

int row, col;
void board_drawer();
int place_character(char, char);
char find_winner(int, int);
int main() {
	char _player1_ = 'X', _player2_ = 'O', choose_block;

	board_drawer();
	printf("\n");
	for (int turn = 1; turn <= SIZE * SIZE; ) {
		if (turn % 2) {
			printf("Player 1 turn: ");
			choose_block = getchar();

			if (!place_character(choose_block, _player1_)) turn++;
		} else {
			printf("Player 2 turn: ");
			choose_block = getchar();

			if (!place_character(choose_block, _player2_)) turn++;
		}
		
		getchar();
		if (row >= 0 && col >= 0) {
			char dummy = find_winner(row, col);
			if (dummy == _player1_) {
				system("cls");
				board_drawer();
				puts("\nPlayer 1 winner!\n");
				return 0;
			} else if (dummy == _player2_) {
				system("cls");
				board_drawer();
				puts("\nPlayer 2 winner!\n");
				return 0;
			} else {
				system("cls");
				board_drawer();
			}
			printf("\n");
		}	
	}
	
	puts("Match has drawn\n");
	return 0;
}

void board_drawer() {
	printf("  %c  |  %c  |  %c\n", tictac_board[0][0], tictac_board[0][1], tictac_board[0][2]);
	printf("-----------------\n");
	printf("  %c  |  %c  |  %c\n", tictac_board[1][0], tictac_board[1][1], tictac_board[1][2]);
	printf("-----------------\n");
	printf("  %c  |  %c  |  %c\n", tictac_board[2][0], tictac_board[2][1], tictac_board[2][2]);
}

int place_character(char choose_block, char player_sign) {
	if (choose_block >= 49 && choose_block <= 57) {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				if (tictac_board[i][j] == choose_block) {
					tictac_board[i][j] = player_sign;
					row = i, col = j;
					return 0;
				}
			}
		}
	} else return 1;
}

char find_winner(int row, int col) {
	char character = tictac_board[row][col];
	int winner_flag;

	if (row == col) {
		// check diagonally
		winner_flag = 0;
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				if (i == j && tictac_board[i][j] == character) winner_flag++;
			}
		}
		if (winner_flag == SIZE) return character;
	} else if (row + col == SIZE - 1) {
		// check anti-diagonally
		winner_flag = 0;
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				if (i + j == SIZE - 1 && tictac_board[i][j] == character) winner_flag++; 
			}
		}
		if (winner_flag == SIZE) return character;
	}

	// check vertically
	winner_flag = 0;
	for (int i = 0; i < SIZE; i++) {
		if (tictac_board[row][i] == character) winner_flag++; 
	}
	if (winner_flag == SIZE) return character;


	// check horizontal
	winner_flag = 0;
	for (int i = 0; i < SIZE; i++) {
		if (tictac_board[i][col] == character) winner_flag++;
	}
	if (winner_flag == SIZE) return character;
	
	return '\0';
}
