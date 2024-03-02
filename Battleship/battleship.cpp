#include <iostream>
#include <random>
#include <conio.h>
using namespace std;
random_device rd;
mt19937 gen(rd());


void clear(string text) {
    system("cls");
    cout << "������� ���" << " " << text << endl << endl;
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


int input(int min, int max) {
    int ask;
    cin >> ask;
    while (cin.fail() or ask < min or ask > max) {
        cout << endl <<  "������, �� ����������� ��������" << endl << endl;
        cin.clear();
        cin.ignore(32767,'\n');
        cin >> ask;
    }
    return ask;
}


void wait() {
    cout << endl << "������� ����� ������� ��� �����������" << endl << endl;
    getch();
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


int checkForIsKill(int y, int x, string array[10][10]) {
    if (x >= 0 and x < 10 and y >= 0 and y < 10) {
        if (array[y][x] == "O") {
            return 0;
        }
        else if (array[y][x] == "X") {
            return 1;
        }
        else {
            return 2;
        }
    }
    else {
        return 2;
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
        clear("���� ����������� ��������");
        printArray(array);
        cout << "������ � ����������" << endl;
        cout << "4�1 3�2 2�3 1�4" << endl;
        cout << "������ ������� " << size << endl;
        cout << endl << "�������� ����� �� ����������� 0-9" << endl << endl;
        x = input(0, 9);
        cout << endl << "�������� ����� �� ��������� 0-9" << endl << endl;
        y = input(0, 9);
        cout << endl << "�������� �������, ���� ����� �������� 1 ����������� 2 ���������" << endl << endl;
        direct = input(1 ,2);
        while (checkPut(x, y, direct-1, size, array) != 1) {
            clear("���� ����������� ��������");
            printArray(array);
            cout << "4�1 3�2 2�3 1�4" << endl;
            cout << "�� ����������� ���������� �������" << endl;
            cout << "������ ������� " << size << endl;
            cout << endl << "�������� ����� �� ����������� 0-9" << endl << endl;
            x = input(0, 9);
            cout << endl << "�������� ����� �� ��������� 0-9" << endl << endl;
            y = input(0, 9);
            cout << endl << "�������� �������, ���� ����� �������� 1 ����������� 2 ���������" << endl << endl;
            direct = input(1, 2);
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


int checkIsKill(int x, int y, string array[10][10]) {
    int x1 = 0, y1 = 0, direct = 0;
    cout << endl << "�� ������ � ";
    if (checkForIsKill(y+1, x, array) == 0 or checkForIsKill(y-1, x, array) == 0 or checkForIsKill(y, x+1, array) == 0 or checkForIsKill(y, x-1, array) == 0) {
        return 0;
    }
    if (checkForIsKill(y+1, x, array) == 2 and checkForIsKill(y-1, x, array) == 2 and checkForIsKill(y, x+1, array) == 2 and checkForIsKill(y, x-1, array) == 2) {
        return 1;
    }
    for (int i = 0; i < 2; i++) {
        while (checkForIsKill(y+y1, x+x1, array) != 2) {
            if (checkForIsKill(y+1, x, array) != 2 or checkForIsKill(y-1, x, array) != 2) {
                if (direct == 0) {
                    y1++;
                }
                else {
                    y1--;
                }
            }
            else if (checkForIsKill(y, x+1, array) != 2 or checkForIsKill(y, x-1, array) != 2) {
                if (direct == 0) {
                    x1++;
                }
                else {
                    x1--;
                }
            }
            if (checkForIsKill(y+y1, x+x1, array) == 0) {
                return 0;
            }
        }
        x1 = 0, y1 = 0, direct = 1;
    }
    return 1;
}


int myShoot(string botField[10][10], string myBotField[10][10]) {
    int x, y;
    cout << "�������� ��" << endl;
    cout << endl << "�������� ����� �� ����������� 0-9" << endl << endl;
    x = input(0, 9);
    cout << endl << "�������� ����� �� ��������� 0-9" << endl << endl;
    y = input(0, 9);
    if (botField[y][x] == "O") {
        if (checkIsKill(x, y, botField) == 0) {
            cout << "������ �������" << endl;
        }
        else {
            cout << "�������� �������" << endl;
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
            cout << "��������� ��������" << endl;
        }
        if (myField[y][x] == "O") {
            myField[y][x] = "X";
            cout << "��������� �����" << endl;
            return 1;
        }
    }
    return 0;
}


void play(string myField[10][10], string myBotField[10][10], string botField[10][10]) {
    int put, resume;
    string get;

    clear("���� ����������� ��������");
    cout << "1 �� ������� ������� ��� 2 ������?" << endl << endl;
    put = input(1, 2);
    fullGenerationArray(botField);
    if (put == 1) {
        putArray(myField);
    }
    else {
        fullGenerationArray(myField);
    }

    clear("����");
    cout << "���� ����" << endl;
    printArray(myField);
    cout << "���� ����������" << endl;
    printArray(myBotField);

    cout << "1 ������ ���� 2 �����" << endl << endl;
    resume = input(1, 2);

    if (resume == 1) {
        int first = gen() % 2;
        if (first == 0) {
            cout << endl << "��� �������, �� �������� ������" << endl;
        }
        else{
            cout << endl << "��� �� �������, ��� ������� ������" << endl;
        }

        while (checkArray(myField, botField) == 0) {
            clear("����");
            cout << "���� ����" << endl;
            printArray(myField);
            cout << "���� ����������" << endl;
            printArray(myBotField);

            if (first == 0) {
                if (myShoot(botField, myBotField) != 1) {
                    first = 1;
                }
            }
            else {
                if (botShoot(myField) != 1) {
                    first = 0;
                }
            }
            wait();
        }

        if (checkArray(myField, botField) == 1) {
            cout << endl << "������� ���������!" << endl;
        }
        else {
            cout << endl << "�� ��������!" << endl;
        }
        cout << endl << "��������� ���-�� ��� ������" << endl << endl;
        cin >> get;
    }
}


void rules() {
    string array[10][10]; fillArray(array);
    fullGenerationArray(array);
    clear("�������");
    cout << "������ �� ������� ������ ������, ������� ����� � ������" << endl;
    cout << "� ���� ���������� ���� ���� � ���� ����������, ��� ��� 10�10 ������" << endl << "� ���� ������������ ����� 2 ���� - ��� ������ � ���� ���������� ��� �������� ���������" << endl;
    cout << "����� ������ ���� ����� - ����� ��� �� ����������� �������, ��� �� ���� ������ �������" << endl;
    cout << "��� ����������� �������� ���������� �������." << endl << "������ ���� ���������� ����� x ���������� �������� � ����� ���� 4x1 3x2 2x3 1x4" << endl;
    cout << "������� �� ������ �������������, � ���� � ���������� ���� �� ����� � 1 ������" << endl;
    cout << "��� ���������� ����������� ��� ������ ��������:" << endl << endl;
    printArray(array);
    cout << "����� ������ ������� ����������� O, ����������� ������ ������� ����������� X, ������ ����� ����� �� �����������, ����������� ������ ��� �������� ����������� *" << endl << endl;
    cout << "����� ����������� �������� �������� ���������� ������ ��� �������� - �� ��� ���������" << endl; 
    cout << "��� �������� ������� �������, ��� ������������ �������� � ���� � �� �� ������, � ����� ������� �������� ������� - ����� ��� �� �����, � ����� ����� ��� ������� �������" << endl;
    cout << "������ �����, ������� ������� ��� ������ � ���� �������� - ���������" << endl;
    wait();
}


void game(string myField[10][10], string myBotField[10][10], string botField[10][10]) {
    int ask = 0;
    clear("������� ����");
    cout << "1 ������" << endl << "2 �������" << endl << "3 �����" << endl << endl;
    ask = input(1, 3);
    switch (ask) {
        case 1:
            play(myField, myBotField, botField);
            break;
        
        case 2:
            rules();
            game(myField, myBotField, botField);
            break;
        
        case 3:
            break;
        
        default:
            break;
    }
}


int main() {
    setlocale(LC_ALL, "Russian");
    string myField[10][10], myBotField[10][10], botField[10][10];
    fillArray(myField), fillArray(myBotField), fillArray(botField);
    game(myField, myBotField, botField);
}