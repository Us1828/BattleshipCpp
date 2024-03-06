#include <iostream>
#include <random>
#include <conio.h>
#include <vector>
#include <stdlib.h>
using namespace std;
random_device rd;
mt19937 gen(rd());


void clear(string text) {
    system("cls");
    cout << "Морской Бой" << " " << text << endl << endl;
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
        cout << endl <<  "Ошибка, вы неправильно написали" << endl << endl;
        cin.clear();
        cin.ignore(32767,'\n');
        cin >> ask;
    }
    return ask;
}


void wait() {
    cout << endl << "Нажмите любую клавишу для продолжения" << endl << endl;
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
        clear("Игра Расстановка кораблей");
        printArray(array);
        cout << "Размер Х Количество" << endl;
        cout << "4х1 3х2 2х3 1х4" << endl;
        cout << "Размер корабля " << size << endl;
        cout << endl << "Выберите точку по горизонтале 0-9" << endl << endl;
        x = input(0, 9);
        cout << endl << "Выберите точку по вертикале 0-9" << endl << endl;
        y = input(0, 9);
        cout << endl << "Выберите сторону, куда будет смотреть 1 горизонталь 2 вертикаль" << endl << endl;
        direct = input(1 ,2);
        while (checkPut(x, y, direct-1, size, array) != 1) {
            clear("Игра Расстановка кораблей");
            printArray(array);
            cout << "4х1 3х2 2х3 1х4" << endl;
            cout << "Вы неправильно разместили корабль" << endl;
            cout << "Размер корабля " << size << endl;
            cout << endl << "Выберите точку по горизонтале 0-9" << endl << endl;
            x = input(0, 9);
            cout << endl << "Выберите точку по вертикале 0-9" << endl << endl;
            y = input(0, 9);
            cout << endl << "Выберите сторону, куда будет смотреть 1 горизонталь 2 вертикаль" << endl << endl;
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


int checkArray(string myField[10][10], string botField[10][10], int &my, int &bot) {
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
    cout << "Атакуете вы" << endl;
    cout << endl << "Выберите точку по горизонтале 0-9" << endl << endl;
    x = input(0, 9);
    cout << endl << "Выберите точку по вертикале 0-9" << endl << endl;
    y = input(0, 9);
    if (botField[y][x] == "O") {
        cout << "Вы попали и ";
        if (checkIsKill(x, y, botField) == 0) {
            cout << "ранили корабль" << endl;
        }
        else {
            cout << "потопили корабль" << endl;
        }
        botField[y][x] = "X";
        myBotField[y][x] = "X";
        return 1;
    }
    else if (botField[y][x] == "X") {
        cout << endl << "Вы промазали, вы туда уже стреляли" << endl;
        botField[y][x] = "X";
        myBotField[y][x] = "X";
    }
    else if (botField[y][x] == "*") {
        cout << endl << "Вы промазали, вы туда уже стреляли" << endl;
        botField[y][x] = "*";
        myBotField[y][x] = "*";
    }
    else {
        cout << endl << "Вы промазали" << endl;
        botField[y][x] = "*";
        myBotField[y][x] = "*";
    }
    return 0;
}


int botCheckShoot(int &x, int &y, string botMyField[10][10], string text){
    vector<int> arrX(0);
    vector<int> arrY(0);
    for (int i = 0; i < 10; i++){
        for (int d = 0; d < 10; d++){
            if (botMyField[i][d] == text){
                arrX.push_back(d);
                arrY.push_back(i);
            }
        }
    }
    if (arrX.size() > 0) {
        int num = gen() % (arrX.size());
        x = arrX[num];
        y = arrY[num];
        return 0;
    }
    return 1;
}


void paint(int x, int y, string array[10][10], string text) {
    if (x >= 0 and x < 10 and y >= 0 and y < 10) {
        if (array[y][x] == " " or array[y][x] == "o") {
            array[y][x] = text;
        }
    }
}


void paintingBotShoot(int x, int y, string array[10][10]) {
    int x1 = 0, y1 = 0, direct = 0;
    if (checkForIsKill(y+1, x, array) == 2 and checkForIsKill(y-1, x, array) == 2 and checkForIsKill(y, x+1, array) == 2 and checkForIsKill(y, x-1, array) == 2) {
        paint(x+1, y, array, ".");
        paint(x-1, y, array, ".");
        paint(x, y+1, array, ".");
        paint(x, y-1, array, ".");
        paint(x+1, y-1, array, ".");
        paint(x-1, y+1, array, ".");
        paint(x+1, y+1, array, ".");
        paint(x-1, y-1, array, ".");
    }
    else {
        for (int i = 0; i < 2; i++) {
            while (checkForIsKill(y+y1, x+x1, array) != 2) {
                if (checkForIsKill(y+1, x, array) != 2 or checkForIsKill(y-1, x, array) != 2) {
                    paint(x+x1+1, y+y1, array, ".");
                    paint(x+x1-1, y+y1, array, ".");
                    if (direct == 0) {
                        y1++;
                    }
                    else {
                        y1--;
                    }
                }
                else if (checkForIsKill(y, x+1, array) != 2 or checkForIsKill(y, x-1, array) != 2) {
                    paint(x+x1, y+y1+1, array, ".");
                    paint(x+x1, y+y1-1, array, ".");
                    if (direct == 0) {
                        x1++;
                    }
                    else {
                        x1--;
                    }
                }
            }
            if (checkForIsKill(y+1, x, array) != 2 or checkForIsKill(y-1, x, array) != 2) {
                paint(x+x1+1, y+y1, array, ".");
                paint(x+x1-1, y+y1, array, ".");
                paint(x+x1, y+y1, array, ".");
            }
            else {
                paint(x+x1, y+y1+1, array, ".");
                paint(x+x1, y+y1-1, array, ".");
                paint(x+x1, y+y1, array, ".");
            }
            x1 = 0, y1 = 0, direct = 1;
        }
    }
}


void clearBotMyShoot(string botMyField[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int d = 0; d < 10; d++) {
            if (botMyField[i][d] == "o") {
                botMyField[i][d] = " ";
            }
        }
    }
}


void paintBotShoot(int x, int y, string array[10][10], int botHit) {
    int x1 = 0, y1 = 0, direct = 0;
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
        }
        if (checkForIsKill(y+1, x, array) != 2 or checkForIsKill(y-1, x, array) != 2) {
            paint(x+x1, y+y1, array, "o");
        }
        else {
            paint(x+x1, y+y1, array, "o");
        }
        x1 = 0, y1 = 0, direct = 1;
    }
}


int botShoot(string myField[10][10], string botMyField[10][10], int &botHit) {
    int x = 0, y = 0;
    if (botCheckShoot(x, y, botMyField, "o") == 1) {
        botCheckShoot(x, y, botMyField, " ");
    }
    else {
        botCheckShoot(x, y, botMyField, "o");
    }
    if (myField[y][x] == " ") {
        myField[y][x] = "*";
        botMyField[y][x] = "*";
        cout << "Противник промазал" << endl;
    }
    else if (myField[y][x] == "O") {
        myField[y][x] = "X";
        botMyField[y][x] = "X";
        if (checkIsKill(x, y, myField) == 0) {
            if (botHit == 0){
                paint(x+1, y, botMyField, "o");
                paint(x-1, y, botMyField, "o");
                paint(x, y+1, botMyField, "o");
                paint(x, y-1, botMyField, "o");
                botHit = 1;
            }
            else if (botHit == 1) {
                clearBotMyShoot(botMyField);
                paintBotShoot(x, y, botMyField, botHit);
            }
        }
        else {
            clearBotMyShoot(botMyField);
            paintingBotShoot(x, y, botMyField);
            botHit = 0;
        }
        cout << "Противник попал" << endl;
        return 1;
    }
    return 0;
}


void play(string myField[10][10], string myBotField[10][10], string botField[10][10], string botMyField[10][10]) {
    int put, resume, botTry = 0, myTry = 0, botHit = 0, bot = 0, my = 0;
    string get;

    clear("Игра Расстановка кораблей");
    cout << "1 Вы ставите корабли или 2 рандом?" << endl << endl;
    put = input(1, 2);
    fullGenerationArray(botField);
    if (put == 1) {
        putArray(myField);
    }
    else {
        fullGenerationArray(myField);
    }

    clear("Игра");
    cout << "Ваше поле" << endl;
    printArray(myField);
    cout << "Поле противника" << endl;
    printArray(myBotField);

    cout << "1 Начать игру 2 Выйти" << endl << endl;
    resume = input(1, 2);

    if (resume == 1) {
        int first = gen() % 2;
        if (first == 0) {
            cout << endl << "Вам повезло, вы атакуете первым" << endl;
        }
        else{
            cout << endl << "Вам не повезло, вас атакуют первым" << endl;
        }

        while (checkArray(myField, botField, my, bot) == 0) {
            bot = 0, my = 0;
            clear("Игра");
            cout << "Ваше поле" << endl;
            printArray(myField);
            cout << "Поле противника" << endl;
            printArray(myBotField);

            if (first == 0) {
                if (myShoot(botField, myBotField) != 1) {
                    first = 1;
                    myTry++;
                }
            }
            else {
                if (botShoot(myField, botMyField, botHit) != 1) {
                    first = 0;
                    botTry++;
                }
            }
            wait();
        }

        clear("Игра");
        cout << "Ваше поле" << endl;
        printArray(myField);
        cout << "Поле противника" << endl;
        printArray(myBotField);

        bot = 0, my = 0;
        if (checkArray(myField, botField, my, bot) == 1) {
            cout << "Победил противник!" << endl;
        }
        else {
            cout << "Вы победили!" << endl;
        }
        cout << "Ваши попытки: " << myTry << " " << "Бота попытки: " << botTry << endl << "Ваши удачные попытки: " << bot << " " << "Бота удачные попытки: " << my << endl;
        wait();
    }
}


void rules() {
    string array[10][10]; fillArray(array);
    fullGenerationArray(array);
    clear("Правила");
    cout << "Ответы на вопросы даются числом, который задан в ответе" << endl;
    cout << "В игре существует ваше поле и поле противника, все они 10х10 клеток" << endl << "В игре пользователю видно 2 поля - его личное и поле противника для удобства попадания" << endl;
    cout << "После начала игры выбор - игрок сам ли расстановит корабли, или за него рандом сделает" << endl;
    cout << "При расстановки кораблей существуют правила." << endl << "Должно быть Количество палуб x Количество кораблей в таком виде 4x1 3x2 2x3 1x4" << endl;
    cout << "Корабли не должны соприкасаться, а быть в расстоянии друг от друга в 1 клетку" << endl;
    cout << "Вид правильной расстановки при рандом варианте:" << endl << endl;
    printArray(array);
    cout << "Целая палуба корабля позначается O, разрушенная палуба корабля позначается X, пустое место никак не позначается, промазанная клетка при выстреле позначается *" << endl << endl;
    cout << "После расстановки кораблей рандомно выбирается первый кто стреляет - вы или противник" << endl; 
    cout << "При стрельбе следует помнить, что бессмысленно стрелять в одну и ту же клетку, и после каждого выстрела пишется - попал или не попал, а также ранил или потопил корабль" << endl;
    cout << "Первый игрок, который потопил все палубы у всех кораблей - побеждает" << endl;
    wait();
}


void game(string myField[10][10], string myBotField[10][10], string botField[10][10], string botMyField[10][10]) {
    int ask = 0;
    clear("Главное меню");
    cout << "1 Играть" << endl << "2 Правила" << endl << "3 Выйти" << endl << endl;
    ask = input(1, 3);
    switch (ask) {
        case 1:
            play(myField, myBotField, botField, botMyField);
            break;
        
        case 2:
            rules();
            game(myField, myBotField, botField, botMyField);
            break;
        
        case 3:
            break;
        
        default:
            break;
    }
}


int main() {
    setlocale(LC_ALL, "Russian");
    system("title Морской Бой");
    string myField[10][10], myBotField[10][10], botField[10][10], botMyField[10][10];
    fillArray(myField), fillArray(myBotField), fillArray(botField), fillArray(botMyField);
    game(myField, myBotField, botField, botMyField);
}
