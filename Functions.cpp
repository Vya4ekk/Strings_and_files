#include "Functions.h"

void GoToXY(short position_Y)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hStdOut, { 0, position_Y });
}

void Show_text(const string str)
{
    for (auto e : str)
    {
        cout << e;
    }
    cout << endl;
}

void Druk(const string str)
{
    char ch{};

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != ' ')
        {                 
            ch = str[i];
            break;
        }
       
    }

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ch || str[i] == tolower(ch))
        {
            for (int j = i; j < str.size(); j++)
            {
                cout << str[j];
                if (str[j] == '\n') break;
                if (str[j] == ' ')
                {
                    cout << endl;
                    break;
                }
            } 
            
        }
    }
    cout << endl;
    
    /*|| '!' || '?' || '.' || ',' || ';' || ':' || '-'*/
}

void Druk2(const string str)
{
    string temp_str;
    int i = 0, j = 0, a = 0, b = 0,result = 0, counter = 0;

    for (i ; i < str.size(); i++)
    {
        if (str[i] == '\n') counter++;
        if (str[i] == ' ') a++;
    }

    cout << "Количество символов " << i - a << endl
        << "Введите номер строки "; cin >> a;
    while (a > counter || a == 0)
    {
        cout << "Строки с таким номером нет введите снова ";
        cin >> a;
    }
    i = 0; counter = 0;

    for (i; i < str.size(); i++)
    {
        if (str[i] == '\n') b++;
        if (b == a - 1)
        {
            i++;
            while (str[i] != '\n')
            {
                temp_str.insert(temp_str.begin(), str[i]);
                i++;
            }
            break;
        }
    }

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '\n')
        {
            counter++;
        }
        if (counter < b || counter > a)
        {
            for (int j = 0; j < temp_str.size(); j++)
            {
                if (str[i] == temp_str[j])
                {
                    result++;
                    break;
                }
            }
        }       
    }

    cout << "Количество повторяющихся элементов из " << a << " строке = " << result << endl;
}

void Strchr()
{
    string text;
    char element;
    cout << "Введите текст\n";
    cin.ignore();
    getline(cin, text);
    cout << "какой элемент нужно найти\n";
    cin >> element;
    cout << "Элемент из текста на таких позициях\n";
    for (int i = 0; i < text.size(); i++)
    {
        if (element == text[i]) cout << i << endl;
    }

}

void Strspn()
{
    SetConsoleCP(1251);
    string s1, s2;
    int amount = 0;
    cout << "Введите строку 1\n";
    
    getline(cin, s1);
    cout << "Введите сроку 2\n";
    getline(cin, s2);
    for (auto e1 : s1)
    {
        for (auto e2 : s2)
        {
            if (e1 != ' ' || e2 != ' ')
            {
                if (e1 == e2)
                {
                    amount++;
                }
            }
        }
    }
    cout << " Количество совпадений " << amount << endl;
    SetConsoleCP(866);
}

void Menu1()
{
    system("cls");
    cout << " Показать текст?\n"
        << " strchr()\n"
        << " strspn()\n"
        << " Druk\n"
        << " Druk2\n"
        << " Продолжить\n";
}

void Menu2()
{
    system("cls");
    cout << " \t\tЗаписать в файл полученный текст?\n"
        << " Да\n"
        << " Нет\n";
}

void First_page(int func, int& pos_key, int& key, string& str, string path, bool menu)
{
    Input_file(str, path);
    system("pause");
    system("cls");
    while (menu)
    {
        Menu1();
        GoToXY(pos_key);
        key = _getch();
        if (key == 224) key = _getch();
        switch (key)
        {
        case 27: //выход
            exit(0);
            break;
        case 80: //стрелка вниз
            pos_key++;
            break;
        case 72: //стрелка вверх
            pos_key--;
            break;
        case 13: //Энтер
            switch (pos_key)
            {
            case 0:
                system("cls");
                Show_text(str);
                system("pause");               
                break;
            case 1:
                system("cls");
                Strchr();
                system("pause");                
                break;
            case 2:
                system("cls");
                Strspn();
                system("pause");               
                break;
            case 3:
                system("cls");
                Druk(str);
                system("pause");               
                break;
            case 4:
                system("cls");
                Druk2(str);
                system("pause");
                break;
            case 5:
                system("cls");
                menu = false;
                break;
            }
            break;
        default:            
            break;
        }
        if (pos_key <= 0) pos_key = 0;
        if (pos_key > func) pos_key = func;
    }
}

void Second_page(int func, int& pos_key, int& key, string& str, string path, bool menu)
{
    system("cls");

    while (menu)
    {       
        Menu2();
        GoToXY(pos_key);
        key = _getch();
        if (key == 224) key = _getch();
        switch (key)
        {
        case 27: //выход
            exit(0);
            break;
        case 80: //стрелка вниз
            pos_key++;
            break;
        case 72: //стрелка вверх
            pos_key--;
            break;
        case 13: //Энтер
            switch (pos_key)
            {
            case 1:
                system("cls");
                Output_file(str);               
                cout << "Записано!\n";
                menu = false;
                break;
            case 2:
                exit(0);
                menu = false;
                break;
            }
            break;
        default:
            break;
        }
        if (pos_key <= 1) pos_key = 1;
        if (pos_key > func) pos_key = func;
    }
}

void Input_file(string& str, string path)
{
    SetConsoleCP(1251);
    ifstream file;
    char ch;
    file.open(path);
    while (!file.is_open())
    {
        cout << "Путь к файлу не верный, введите снова\n";
        cin >> path;
        file.open(path);
    }

    while (file.get(ch))
    {
        str.push_back(ch);
    }

    file.close();
    SetConsoleCP(866);
}

void Output_file(string& str)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string path;
    fstream file;
    cout << "Введите путь к файлу для записи\n";
    cin >> path;
    file.open(path, fstream::out | fstream::app);
    while (!file.is_open())
    {
        cout << "Файл не найден введите ещё раз\n";
        cin >> path;
        file.open(path, fstream::out | fstream::app);
    }
    
    for (int i = 0; i < str.size(); i++)
    {
        file << str[i];
    }
    file << "\n\n";
    file.close();
    SetConsoleOutputCP(866);
    SetConsoleCP(866);
}