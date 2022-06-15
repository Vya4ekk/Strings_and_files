#include "Functions.h"

void GoToXY(short position_Y)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hStdOut, { 0, position_Y });
}

void Show_text(const string str)
{
    if (str.empty())
    {
        cout << "строка пустая\n";
    }

    for (auto e : str)
    {
        cout << e;
    }
    cout << endl;
}


void Write_str(string& str)
{   
    cout << "Введите строку\n";
    str.erase();
    cin.ignore();
    getline(cin, str);
}

void Druk(string& str)
{
    int length = 0, wbeg = 0, wend = 0, t = 0;

    string result{}, word{};

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
        {
            length = i;
            break;
        }
    }

    for (int i = 0; i < length; i++)
    {
        word.push_back(str[i]);
    }

    for (int i = length + 1; i < str.size(); i++)
    {
        result.push_back(str[i]);
    }

    int iter = 0, full = 0, z = result.size();

    while (wend != z)
    {
        wend = 0; wbeg = 0;

        for (iter; iter <= result.size(); iter++, t++)
        {
            if (iter == result.size())
            {
                wend = z - 1;
                wbeg = wend - t + 1;
                t = wbeg;
                break;
            }

            if (result[iter] == ' ' && iter != 1)
            {
                wend = iter - 1;
                wbeg = iter - t;
                t = wbeg;
                break;
            }
        }
        
        for (wbeg; wbeg <= wend + 2; wbeg++)
        {
            if (full == wend - t + 1)
            {              
                iter = wend + 2;               
                full = 0;
                t = 0;
                if (wend == z - 1)
                {
                    wend++;
                }
                break;
            }

            for (int i = 0; i <= length; i++)
            {
                if (i == length)
                {
                    if (wend == z - 1)
                    {
                        result.erase(t, wend - (t - 1));
                        full = 0;
                        wbeg = wend + 3;
                        z = result.size();
                        wend = z;
                        break;
                    }
                    result.erase(t, wend - (t - 2));  
                    full = 0;
                    iter = t;
                    t = 0;
                    wbeg = wend + 2;
                    z = result.size();
                    break;
                }

                if (result[wbeg] == word[i])
                {
                    full++;
                    break;
                }
            }
        }
    }

    string s = "\n\nВ данной строке(тексте) все слова из букв первого слова :\n";
    s += result;
    cout << s << endl;
    str += s;
}

void Druk2(string& str)
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

    cout << "Количество повторяющихся элементов из " << a << " строки = " << result << endl;
    string r{};
    r = "Количество символов "; r += to_string(i - a); r += "\n";
    r += "Количество повторяющихся элементов из "; r += to_string(a); r += " строки = "; r += to_string(result);
    str += "\n";str += r;
}

char* Strchr(const char* str, int c) {
    int i = 0;
    while (str[i] != c) i++;
    return c == str[i] ? (char*)str + i : NULL;
}

int Strspn(const char* str1, const char* str2)
{
    int a = 0;
    for (int i = 0; i < strlen(str1); i++)
    {
        for (int j = 0; j <= strlen(str2); j++)
        {
            if (j == strlen(str2))
            {
                return a;
            }
            if (str1[i] == str2[j]) break;
        }       
        a++;
    }
    return a;
}

void Menu1()
{
    system("cls");
    cout << " Показать текст?\n"
        << " Ввести текст вручную\n"
        << " Druk\n"
        << " Druk2\n"
        << " Ввести текст из файла(записанная строка затрётся)\n"
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
                Write_str(str);
                system("pause");
                break;
            case 2:
                system("cls");
                Druk(str);
                system("pause");               
                break;
            case 3:
                system("cls");
                Druk2(str);
                system("pause");
                break;
            case 4:
                system("cls");
                Input_file(str, path);
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
    str.erase();
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
    cout << "Записано\n";
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