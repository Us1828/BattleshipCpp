#include <iostream>
#include <random>
using namespace std;
random_device rd;
mt19937 gen(rd());


void clear() {
    system("cls");
    cout << "������� ���" << endl << endl;
}


void fillArray(string array[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int d = 0; d < 10; d++) {
            array[i][d] = " ";
        }
    } 
}


void printArray(string array[10][10]) {
    cout << "   ";
    for (int i = 0; i < 10; i++) {
        cout << i << "  ";
    }
    cout << endl;
    cout << "  ";
    for (int i = 0; i < 10; i++) {
        cout << " _ ";
    }
    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << i << " |";
        for (int d = 0; d < 10; d++) {
            cout << array[i][d];
            cout << "  ";
        }
        cout << endl;
    }
    cout << endl;
}


int check(int y, int x, string array[10][10]) {
    if (x >= 0 and x < 10 and y >= 0 and y < 10) {
        if (array[y][x] != "O") {
            return 0;
        }
        else {
            return 1;
        }
    }
    else {
        return 0;
    }
}


int generationArray(string array[10][10], int size) {
    int direct = gen() % 2;
    int x = gen() % 10;
    int y = gen() % 10;
    int x1 = x;
    int y1 = y;

    if (direct == 0) {
        if (x + size-1 >= 0 and x + size-1 < 10) {
            for (int i = 0; i < size; i++) {
                if (check(y, x, array) == 0 and check(y+1, x, array) == 0 and check(y, x+1, array) == 0 and check(y-1, x, array) == 0 and check(y, x-1, array) == 0 and check(y+1, x+1, array) == 0 and check(y-1, x-1, array) == 0 and check(y+1, x-1, array) == 0 and check(y-1, x+1, array) == 0) {
                    x += 1;
                }
                else {
                    generationArray(array, size);
                    return 0;
                    break;
                }
            }
            
            for (int i = 0; i < size; i++) {
                array[y1][x1] = "O";
                x1 += 1;
            }
        }
        else {
            generationArray(array, size);
            return 0;
        }
    }
    
    if (direct == 1) {
        if (y + size-1 >= 0 and y + size-1 < 10) {
            for (int i = 0; i < size; i++) {
                if (check(y, x, array) == 0 and check(y+1, x, array) == 0 and check(y, x+1, array) == 0 and check(y-1, x, array) == 0 and check(y, x-1, array) == 0 and check(y+1, x+1, array) == 0 and check(y-1, x-1, array) == 0 and check(y+1, x-1, array) == 0 and check(y-1, x+1, array) == 0) {
                    y += 1;
                }
                else {
                    generationArray(array, size);
                    return 0;
                    break;
                }
            }
            
            for (int i = 0; i < size; i++) {
                array[y1][x1] = "O";
                y1 += 1;
            }
        }
        else {
            generationArray(array, size);
            return 0;
        }
    }
    
    return 0;
}


int checkPut(int x, int y, int direct, int size, string array[10][10]) {
    int x1 = x, y1 = y;
    if (direct == 0) {
        if (x + size-1 >= 0 and x + size-1 < 10) {
            for (int i = 0; i < size; i++) {
                if (check(y, x, array) == 0 and check(y+1, x, array) == 0 and check(y, x+1, array) == 0 and check(y-1, x, array) == 0 and check(y, x-1, array) == 0 and check(y+1, x+1, array) == 0 and check(y-1, x-1, array) == 0 and check(y+1, x-1, array) == 0 and check(y-1, x+1, array) == 0) {
                    x += 1;
                }
                else {
                    return 0;
                    break;
                }
            }
            for (int i = 0; i < size; i++) {
                array[y1][x1] = "O";
                x1 += 1;
            }
        }
        else {
            return 0;
        }
    }

    if (direct == 1) {
        if (y + size-1 >= 0 and y + size-1 < 10) {
            for (int i = 0; i < size; i++) {
                if (check(y, x, array) == 0 and check(y+1, x, array) == 0 and check(y, x+1, array) == 0 and check(y-1, x, array) == 0 and check(y, x-1, array) == 0 and check(y+1, x+1, array) == 0 and check(y-1, x-1, array) == 0 and check(y+1, x-1, array) == 0 and check(y-1, x+1, array) == 0) {
                    y += 1;
                }
                else {
                    return 0;
                    break;
                }
            }
            for (int i = 0; i < size; i++) {
                array[y1][x1] = "O";
                y1 += 1;
            }
        }
        else {
            return 0;
        }
    }

    return 1;
}


void putArray(string array[10][10]) {
    int x, y, direct;
    int size = 4;
    for (int i = 0; i < 10; i++) {
        if (i == 0) {
            size = 4;
        }
        if (i == 1 or i == 2) {
            size = 3;
        }
        if (i == 3 or i == 4 or i == 5) {
            size = 2;
        }
        if (i == 6 or i == 7 or i == 8 or i == 9) {
            size = 1;
        }
        clear();
        printArray(array);
        cout << "������ � ����������" << endl;
        cout << "4�1 3�2 2�3 1�4" << endl;
        cout << "������ ������� " << size << endl;
        cout << endl << "�������� ����� �� ����������� 0-9" << endl << endl;
        cin >> x;
        cout << endl << "�������� ����� �� ��������� 0-9" << endl << endl;
        cin >> y;
        cout << endl << "�������� �������, ���� ����� �������� 1 ����������� 2 ���������" << endl << endl;
        cin >> direct;
        while (checkPut(x, y, direct-1, size, array) != 1) {
            clear();
            printArray(array);
            cout << "4�1 3�2 2�3 1�4" << endl;
            cout << "�� ����������� ���������� �������" << endl;
            cout << "������ ������� " << size << endl;
            cout << endl << "�������� ����� �� ����������� 0-9" << endl << endl;
            cin >> x;
            cout << endl << "�������� ����� �� ��������� 0-9" << endl << endl;
            cin >> y;
            cout << endl << "�������� �������, ���� ����� �������� 1 ����������� 2 ���������" << endl << endl;
            cin >> direct;
        }
    }
}


void fullGenerationArray(string array[10][10]) {
    generationArray(array, 4);
    generationArray(array, 3);
    generationArray(array, 3);
    generationArray(array, 2);
    generationArray(array, 2);
    generationArray(array, 2);
    generationArray(array, 1);
    generationArray(array, 1);
    generationArray(array, 1);
    generationArray(array, 1);
}


int checkArray(string myField[10][10], string botField[10][10]) {
    int my = 0;
    int bot = 0;
    for (int i = 0; i < 10; i++) {
        for (int d = 0; d < 10; d++) {
            if (myField[d][i] == "X") {
                my++;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int d = 0; d < 10; d++) {
            if (botField[d][i] == "X") {
                bot++;
            }
        }
    }
    if (my >= 20) {
        return 1;
    }
    if (bot >= 20) {
        return 2;
    }
    return 0;
}


int myShoot(string botField[10][10], string myBotField[10][10], string myField[10][10]) {
    int x, y;
    cout << "�������� ��" << endl;
    cout << endl << "�������� ����� �� ����������� 0-9" << endl << endl;
    cin >> x;
    cout << endl << "�������� ����� �� ��������� 0-9" << endl << endl;
    cin >> y;
    if (botField[y][x] == "O") {
        cout << endl << "�� ������ � ";
        if (check(x+1, y, botField) == 0 and check(x-1, y, botField) == 0 and check(x, y+1, botField) == 0 and check(x, y-1, botField) == 0) {
            cout << "�������� �������" << endl;
        }
        else {
            cout << "������ �������" << endl;
        }
        botField[y][x] = "X";
        myBotField[y][x] = "X";
        return 1;
    }
    else if (botField[y][x] == "X") {
        cout << endl << "�� ���������, �� ���� ��� ��������" << endl;
        botField[y][x] = "X";
        myBotField[y][x] = "X";
    }
    else if (botField[y][x] == "*") {
        cout << endl << "�� ���������, �� ���� ��� ��������" << endl;
        botField[y][x] = "*";
        myBotField[y][x] = "*";
    }
    else {
        cout << endl << "�� ���������" << endl;
        botField[y][x] = "*";
        myBotField[y][x] = "*";
    }
    return 0;
}


int botShoot(string myField[10][10]) {
    int x = gen() % 10;
    int y = gen() % 10;
    if (myField[y][x] == "*" or myField[y][x] == "X") {
        botShoot(myField);
        return 0;
    }
    else {
        if (myField[y][x] == " ") {
            myField[y][x] = "*";
            cout << endl << "��������� ��������" << endl;
        }
        if (myField[y][x] == "O") {
            myField[y][x] = "X";
            cout << endl << "��������� �����" << endl;
            return 1;
        }
    }
    return 0;
}


int play(string myField[10][10], string myBotField[10][10], string botField[10][10]) {
    int put, resume;
    clear();

    cout << "1 �� ������� ������� ��� 2 ������?" << endl << endl;
    cin >> put;
    fullGenerationArray(botField);
    if (put == 1) {
        putArray(myField);
    }
    else {
        fullGenerationArray(myField);
    }
    clear();
    cout << "���� ����" << endl;
    printArray(myField);
    cout << "���� ����������" << endl;
    printArray(myBotField);

    cout << "1 ������ ���� 2 �����" << endl << endl;
    cin >> resume;
    if (resume == 1) {
        int first = 1;
        if (first == 0) {
            cout << endl << "��� �������, �� �������� ������" << endl;
        }
        else{
            cout << endl << "��� �� �������, ��� ������� ������" << endl;
        }
        string get;
        while (checkArray(myField, botField) == 0) {
            clear();
            cout << "���� ����" << endl;
            printArray(myField);
            cout << "���� ����������" << endl;
            printArray(myBotField);
            if (first == 0) {
                if (myShoot(botField, myBotField, myField) != 1) {
                    first = 1;
                }
            }
            else {
                if (botShoot(myField) != 1) {
                    first = 0;
                }
            }
            cout << "��������� ���-�� ��� �����������" << endl << endl;
            cin >> get;
        }
    }
    else {
        return 0;
    }
    return 0;
}


int main() {
    setlocale(LC_ALL, "Russian");
    string myField[10][10], myBotField[10][10], botField[10][10];
    fillArray(myField), fillArray(myBotField), fillArray(botField);
    int ask = 0;
    
    clear();
    cout << "1 ������" << endl << "2 �������" << endl << "3 ���������" << endl << "4 �����" << endl << endl;
    cin >> ask;
    switch (ask) {
        case 1:
            play(myField, myBotField, botField);
            break;
        
        case 2:
            
            break;
        
        case 3:
            
            break;
        
        case 4:
            break;
        
        default:
            break;
    }
}