#include <stdio.h>

char board[3][3];

void initializeBoard() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}
void displayBoard() {
    int i, j;
    printf("-------------\n");
    for (i = 0; i < 3; i++) {
        printf("| ");
        for (j = 0; j < 3; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n-------------\n");
    }
}
int checkWin() {
    int i;
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1;

    return 0;
}
int checkDraw() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

int main() {
    int row, col;
    char player = 'X';
    int turns = 0;

    initializeBoard();

    printf("Tic-Tac-Toe Game\n");
    printf("Player 1: X | Player 2: O\n");

    while (1) {
        displayBoard();

        printf("Player %c, enter your move (row[1-3] col[1-3]): ", player);
        scanf("%d %d", &row, &col);

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        board[row - 1][col - 1] = player;

        if (checkWin()) {
            displayBoard();
            printf("Player %c wins!\n", player);
            break;
        }
        if (checkDraw()) {
            displayBoard();
            printf("It's a draw!\n");
            break;
        }
        player = (player == 'X') ? 'O' : 'X';
        turns++;
    }

    return 0;
}
