#include <iostream>
using namespace std;

void addColumn(int**& arr, int rows, int& cols, int position, int value) {
    int** newArr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        newArr[i] = new int[cols + 1];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= cols; j++) {
            if (j < position) {
                newArr[i][j] = arr[i][j];
            } else if (j == position) {
                newArr[i][j] = value;
            } else {
                newArr[i][j] = arr[i][j - 1];
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    arr = newArr;
    cols++;
}

void removeColumn(int**& arr, int rows, int& cols, int position) {
    int** newArr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        newArr[i] = new int[cols - 1];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols - 1; j++) {
            if (j < position) {
                newArr[i][j] = arr[i][j];
            } else {
                newArr[i][j] = arr[i][j + 1];
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    arr = newArr;
    cols--;
}

void printArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    const int rows = 2;
    int cols = 3;

    int** arr = new int*[rows];
    arr[0] = new int[cols]{1, 2, 3};
    arr[1] = new int[cols]{4, 5, 6};

    cout << "Начальный массив:\n";
    printArray(arr, rows, cols);

    while (true) {
        cout << "\nВыберите действие:\n1. Добавить столбец\n2. Удалить столбец\n3. Вывести массив\n0. Выйти\n";
        int choice;
        cin >> choice;

        if (choice == 1) {
            int position, value;
            cout << "Введите позицию для нового столбца (0-" << cols << ") и его значение: ";
            cin >> position >> value;
            if (position >= 0 && position <= cols) {
                addColumn(arr, rows, cols, position, value);
                cout << "Столбец добавлен.\n";
            } else {
                cout << "Неверная позиция.\n";
            }
        } else if (choice == 2) {
            int position;
            cout << "Введите номер удаляемого столбца (0-" << cols - 1 << "): ";
            cin >> position;
            if (position >= 0 && position < cols) {
                removeColumn(arr, rows, cols, position);
                cout << "Столбец удалён.\n";
            } else {
                cout << "Неверная позиция.\n";
            }
        } else if (choice == 3) {
            cout << "Текущий массив:\n";
            printArray(arr, rows, cols);
        } else if (choice == 0) {
            break;
        } else {
            cout << "Неверный выбор.\n";
        }
    }

    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
