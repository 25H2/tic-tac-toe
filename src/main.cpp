#include <iostream>
#include <locale>
using namespace std;

// Функция для вывода игрового поля
void printBoard(char b[3][3]) {
    cout << endl;
    for (int i = 0; i < 3; i++) {

        // Вывод строки
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << b[i][j];            // вывод клетки
            if (j < 2) cout << " | ";   // разделитель между колонками
        }
        cout << endl;

        // Горизонтальная линия между строками
        if (i < 2) cout << "-----------" << endl;
    }
    cout << endl;
}

// Проверка победителя
char checkWin(char b[3][3]) {
    // Проверяем строки
    for (int i = 0; i < 3; i++)
        if (b[i][0] == b[i][1] && b[i][1] == b[i][2])
            return b[i][0];

    // Проверяем столбцы
    for (int j = 0; j < 3; j++)
        if (b[0][j] == b[1][j] && b[1][j] == b[2][j])
            return b[0][j];

    // Диагональ 1
    if (b[0][0] == b[1][1] && b[1][1] == b[2][2])
        return b[0][0];

    // Диагональ 2
    if (b[0][2] == b[1][1] && b[1][1] == b[2][0])
        return b[0][2];

    return ' '; // нет победителя
}

int main() {
    setlocale(LC_ALL, "");
    // Игровое поле 3х3 с цифрами
    char board[3][3] = {
        { '1','2','3' },
        { '4','5','6' },
        { '7','8','9' }
    };

    char player = 'X'; // текущий игрок
    int move;          // введённый ход

    while (true) {

        printBoard(board); // выводим поле

        cout << "Ход игрока " << player << ". Введите номер клетки: ";
        cin >> move;

        // Проверка введённого числа
        if (move < 1 || move > 9) {
            cout << "Неверный номер клетки!" << endl;
            continue;
        }

        // Вычисление строки и столбца по номеру клетки
        int r = (move - 1) / 3;
        int c = (move - 1) % 3;

        // Проверка занятости клетки
        if (board[r][c] == 'X' || board[r][c] == 'O') {
            cout << "Клетка занята!" << endl;
            continue;
        }

        // Записываем символ игрока
        board[r][c] = player;

        // Проверка победы
        char win = checkWin(board);
        if (win == 'X' || win == 'O') {
            printBoard(board);
            cout << "Победил игрок " << win << "!" << endl;
            break;
        }

        // Проверка ничьи — если все клетки заняты
        bool full = true;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] != 'X' && board[i][j] != 'O')
                    full = false;

        if (full) {
            printBoard(board);
            cout << "Ничья!" << endl;
            break;
        }

        // Смена игрока
        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    return 0;
}
