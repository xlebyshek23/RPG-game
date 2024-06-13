#define _CRT_SECURE_NO_WARNINGS
#include "rapidjson/document.h" 
#include "rapidjson/filereadstream.h" 
#include <iostream> 
#include <string> 
#include <Windows.h>
#include <cstdio>
using namespace rapidjson;
using namespace std;

Document d;
void dialog(int index)
{
    system("cls");
    int choise;
    cout << d["dialogs"][index]["text"].GetString() << "\n";
    cin >> choise;
    if (d["dialogs"][index]["var2"].GetInt() == -1 and d["dialogs"][index]["var1"].GetInt() == -1)
    {
        cout << "The end!";
    }
    if (choise != 1)
    {
        if (choise == 2)
        {
            if (d["dialogs"][index]["var2"].GetInt() != -1)
            {
                dialog(d["dialogs"][index]["var2"].GetInt());
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
        dialog(d["dialogs"][index]["var1"].GetInt());
    }
}
int main()
{
    /*SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IOFBF, 100000);
    setlocale(LC_ALL, "Russian");*/
    FILE* fp = fopen("dialogs.json", "r");
    char readBuffer[999999];

    FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    d.ParseStream(is);
    fclose(fp);
    dialog(0);
}

