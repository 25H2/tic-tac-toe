#include <iostream>
using namespace std;

char board[3][3];

void initBoard() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = ' ';
}

void printBoard() {
    cout << "  1 2 3\n";
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << ' ';
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << '|';
        }
        cout << '\n';
        if (i < 2) cout << "  -+-+-\n";
    }
}

bool isWin(char p) {
    // строки
    for (int i = 0; i < 3; ++i)
        if (board[i][0] == p && board[i][1] == p && board[i][2] == p) return true;
    // столбцы
    for (int j = 0; j < 3; ++j)
        if (board[0][j] == p && board[1][j] == p && board[2][j] == p) return true;
    // диагонали
    if (board[0][0] == p && board[1][1] == p && board[2][2] == p) return true;
    if (board[0][2] == p && board[1][1] == p && board[2][0] == p) return true;
    return false;
}

bool isFull() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == ' ') return false;
    return true;
}

bool makeMove(int r, int c, char p) {
    if (r < 1 || r > 3 || c < 1 || c > 3) return false;
    if (board[r - 1][c - 1] != ' ') return false;
    board[r - 1][c - 1] = p;
    return true;
}

int main() {
    initBoard();
    char player = 'X';
    while (true) {
        printBoard();
        cout << "Игрок " << player << ", введите строку и столбец (через пробел): ";
        int r, c;
        if (!(cin >> r >> c)) {
            cout << "Неверный ввод. Выход.\n";
            break;
        }
        if (!makeMove(r, c, player)) {
            cout << "Неверный ход — попробуйте ещё.\n";
            continue;
        }
        if (isWin(player)) {
            printBoard();
            cout << "Игрок " << player << " победил!\n";
            break;
        }
        if (isFull()) {
            printBoard();
            cout << "Ничья!\n";
            break;
        }
        // смена игрока
        player = (player == 'X') ? 'O' : 'X';
    }
    return 0;
}