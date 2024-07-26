#define _CRT_SECURE_NO_WARNINGS
#include "rapidjson/document.h" 
#include "rapidjson/filereadstream.h" 
#include <iostream> 
#include <string> 
#include <Windows.h>
#include <cstdio>
using namespace rapidjson;
using namespace std;
struct stats_str
{
    int helth;
    int force;
    int intel;
    int magic_know;
    int dex;
    int rel_with_Alex;
};
stats_str stats = { 3, 0, 0, 0, 0, 0 };
int pass = 7583;
int temp_pass;
int pins[4] = { 3, 1, 2, 4 };
Document d;

string choose = "";
string choose2 = "";
string choose3 = "";
int choise;

int enemy1_health = 5;
int enemy2_health = 6;

void restart();
void key(int key_ind);
void dialog(int index)//отображение диалогов
{
    system("cls");
    cout << "Your characteristics: " << endl;
    cout << "Strenght: " << stats.force << "\tIntelligence: " << stats.intel << endl;;
    cout << "Agility: " << stats.dex << "\tMagical knowledges: " << stats.magic_know << endl << endl;
    cout << d["dialogs"][index]["text"].GetString() << "\n";
    if (d["dialogs"][index]["var2"].GetInt() == -1 and d["dialogs"][index]["var1"].GetInt() == -1)//проверка на наличие ответвлений диалогов
    {
        restart();
    }
    cin >> choise;
    if (choise != 1)
    {
        if (choise == 2)
        {
            if (d["dialogs"][index]["var2"].GetInt() != -1)
            {
                if (d["dialogs"][index]["key2"].GetInt() != -1)
                {
                    key(d["dialogs"][index]["key2"].GetInt());
                }
                dialog(d["dialogs"][index]["var2"].GetInt());//переход к ответвлению 2
            }
            else
            {
                cout << "Wrong enter!";
                dialog(index);
            }
        }
        else
        {
            cout << "wrong enter!";
            dialog(index);
        }
    }
    else
    {
        if (d["dialogs"][index]["key1"].GetInt() != -1)
        {
            key(d["dialogs"][index]["key1"].GetInt());
        }
        dialog(d["dialogs"][index]["var1"].GetInt());//переход к ответвлению 1
    }
}
void key(int key_ind)//игровые события
{
    switch (key_ind)
    {
    case 1:
        if (stats.intel == 1)
        {
            cout << "The characteristic check has been passed";
            Sleep(2000);
            dialog(3);
        }
        else
        {
            cout << "The characteristic check has not been passed";
            Sleep(2000);
            dialog(1);
        }
    case 2:
        if (stats.force == 1)
        {
            cout << "The characteristic check has been passed";
            Sleep(2000);
            dialog(3);
        }
        else
        {
            cout << "The characteristic check has not been passed";
            Sleep(2000);
            dialog(1);
        }
    case 3:
        cout << "enter the password: ";
        cin >> temp_pass;
        if (temp_pass == pass)
        {
            dialog(15);
        }
        else
        {
            dialog(14);
        }
    case 4:
        if (stats.magic_know == 1)
        {
            cout << "The characteristic check has been passed";
            Sleep(2000);
            dialog(8);
        }
        else
        {
            cout << "The characteristic check has not been passed";
            Sleep(2000);
            dialog(13);
        }
    case 5:
        if (stats.dex == 1)
        {
            cout << "The characteristic check has been passed";
            Sleep(2000);
            dialog(9);
        }
        else
        {
            cout << "The characteristic check has not been passed";
            Sleep(2000);
            dialog(10);
        }
    case 6:
        while (stats.helth > 0 or enemy1_health > 0) {
            cout << "Your health: " << stats.helth << endl;    //отображение здоровья игрока
            cout << "Opponent's health: " << enemy1_health << endl; //отображение здововья противника

            if (stats.force != 0) {//атака противника с помощью физической силы
                enemy1_health--;
                if (enemy1_health <= 0) break;//проверка на то что противник умер
                if (stats.helth <= 0) break;
                cout << "You've attacked the enemy, using your strenght" << endl;
            }
            else if (stats.intel != 0) {//атака противника с помощью магии
                enemy1_health--;
                if (enemy1_health <= 0) break;//проверка на то что противник умер
                if (stats.helth <= 0) break;
                cout << "You've attacked the enemy, using your spells" << endl;
            }
            Sleep(2000);

            if (stats.dex != 0) {
                if ((rand() % (2)) == 0) {// 50% процентый шанс на уклонение от атаки с помощью ловкости
                    cout << "Enemy's attacked you" << endl;
                    stats.helth--;
                }
                else {
                    cout << "Enemy attaked you, but you dodged it, because of your dexterity!" << endl;
                }
            }
            else if (stats.magic_know != 0) {// 50% процентый шанс на уклонение от атаки с помощью магических знаний
                if ((rand() % (2)) == 0) {
                    cout << "Enemy's attacked you" << endl;
                    stats.helth--;
                }
                else {
                    cout << "Enemy attaked you, but using your magical knowledges you predicted an attack and dodged it!" << endl;
                }
            }
            Sleep(2000);
            system("cls");
        }

        if (stats.helth <= 0) dialog(12); //диалог поражения
        else if (enemy1_health <= 0) dialog(11);//диалог победы

    case 7:
        stats.rel_with_Alex++;
        dialog(18);
    case 8:
        int temp;
        cout << "you are digging into the lock device, there are 4 pins, it looks like they need to be hooked in the correct sequence";
        while (1)
        {
            cout << "What is the first pin: ";
            cin >> temp;
            if (temp == pins[0])
            {
                cout << "What is the second pin: ";
                cin >> temp;
                if (temp == pins[1])
                {
                    cout << "What is the third pin: ";
                    cin >> temp;
                    if (temp == pins[2])
                    {
                        cout << "What is the fourth pin: ";
                        cin >> temp;
                        if (temp == pins[3])
                        {
                            cout << "You've picked the lock";
                            Sleep(2000);
                            if (stats.rel_with_Alex == 0)
                            {
                                dialog(23);
                            }
                            else
                            {
                                dialog(24);
                            }
                        }
                        else
                        {
                            cout << "Wrong!\n";
                        }
                    }
                    else
                    {
                        cout << "Wrong!\n";
                    }
                }
                else
                {
                    cout << "Wrong!\n";
                }
            }
            else
            {
                cout << "Wrong!\n";
            }
        }
    case 9:
        stats.helth++;
        dialog(25);
    case 10:
        stats.rel_with_Alex++;
        dialog(26);
    case 11:
        while (stats.helth > 0 or enemy2_health > 0) {
            cout << "Your health: " << stats.helth << endl;    //отображение здоровья игрока
            cout << "Opponent's health: " << enemy2_health << endl; //отображение здововья противника

            if (stats.force != 0) {//атака противника с помощью физической силы
                enemy2_health--;
                if (enemy2_health <= 0) break;//проверка на то что противник умер
                if (stats.helth <= 0) break;
                cout << "You've attacked the enemy, using your strenght" << endl;
            }
            else if (stats.intel != 0) {//атака противника с помощью магии
                enemy2_health--;
                if (enemy2_health <= 0) break;//проверка на то что противник умер
                if (stats.helth <= 0) break;
                cout << "You've attacked the enemy, using your spells" << endl;
            }
            Sleep(2000);

            if (stats.dex != 0) {
                if ((rand() % (2)) == 0) {// 50% процентый шанс на уклонение от атаки с помощью ловкости
                    cout << "Enemy's attacked you" << endl;
                    stats.helth--;
                }
                else {
                    cout << "Enemy attaked you, but you dodged it, because of your dexterity!" << endl;
                }
            }
            else if (stats.magic_know != 0) {// 50% процентый шанс на уклонение от атаки с помощью магических знаний
                if ((rand() % (2)) == 0) {
                    cout << "Enemy's attacked you" << endl;
                    stats.helth--;
                }
                else {
                    cout << "Enemy attaked you, but using your magical knowledges you predicted an attack and dodged it!" << endl;
                }
            }
            Sleep(2000);
            system("cls");
        }

        if (stats.helth <= 0) dialog(12); //диалог поражения
        else if (enemy2_health <= 0) dialog(28);//диалог победы
        dialog(28);
    case 12:
        if (stats.rel_with_Alex == 0)
        {
            cout << "...But nobody came";
            Sleep(2000);
            dialog(29);
        }
        else if (stats.rel_with_Alex == 1)
        {
            dialog(35);
        }
        else
        {
            dialog(34);
        }
    }
}
void restart()//рестарт
{
    cout << "The end!";
    cout << endl << "Want to restart? (1) - yes, (2) - no" << endl;
    while (true) {
        cin >> choose3;
        if (choose3 == "1" or choose3 == "2") break;
        else cout << "Wrong input" << endl;
    }
    if (choose3 == "1") {
        stats = { 3, 0, 0, 0, 0, 0 };
        choose = "";
        choose2 = "";
        choose3 = "";

        enemy1_health = 5;
        enemy2_health = 6;

        cout << "Before start of your journey, choose you characteristics: " << endl;
        cout << "(1) - strenght" << endl;
        cout << "(2) - intelligence" << endl;
        cout << "Print number of characteristic: ";

        while (true) {
            cin >> choose;
            if (choose == "1" or choose == "2") break;
            else cout << "Wrong input" << endl;
        }
        switch (choose[0]) {
        case '1':
            stats.force = 1;
            break;
        case '2':
            stats.intel = 1;
            break;
        }
        cout << endl;

        cout << "Now choose, something from these: " << endl;
        cout << "(1) - dexterity" << endl;
        cout << "(2) - magical knowledges" << endl;
        cout << "Print number of characteristic: ";

        while (true) {
            cin >> choose2;
            if (choose2 == "1" or choose2 == "2") break;
            else cout << "Wrong input" << endl;
        }
        switch (choose2[0]) {
        case '1':
            stats.dex = 1;
            break;
        case '2':
            stats.magic_know = 1;
            break;
        }

        dialog(0);
    }
    else exit(0);
}
int main()
{
    //если запускаете в Visual studio или других IDE использовать путь "..\\x64\\Debug\\dialogs.json"
    FILE* fp = fopen("dialogs.json", "r");
    char readBuffer[999999];

    FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    d.ParseStream(is);
    fclose(fp);
    cout << "Before start of your journey, choose you characteristics: " << endl;
    cout << "(1) - strenght" << endl;
    cout << "(2) - intelligence" << endl;
    cout << "Print number of characteristic: ";

    while (true) {
        cin >> choose;
        if (choose == "1" or choose == "2") break;
        else cout << "Wrong input" << endl;
    }
    switch (choose[0]) {
    case '1':
        stats.force = 1;
        break;
    case '2':
        stats.intel = 1;
        break;
    }
    cout << endl;

    cout << "Now choose, something from these: " << endl;
    cout << "(1) - dexterity" << endl;
    cout << "(2) - magical knowledges" << endl;
    cout << "Print number of characteristic: ";
    while (true) {
        cin >> choose2;
        if (choose2 == "1" or choose2 == "2") break;
        else cout << "Wrong input" << endl;
    }
    switch (choose2[0]) {
    case '1':
        stats.dex = 1;
        break;
    case '2':
        stats.magic_know = 1;
        break;
    }


    dialog(0);
}
