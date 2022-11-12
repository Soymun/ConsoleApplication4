// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class MyClass {
private:
    string S;
public:
    string* str;
    MyClass() {
        string st = "";
        str = &st;
    }

    MyClass(string st) {
        S = st;
        str = &S;
    }

    void saveFromArray(char chars[]) {
        string g = "";
        size_t size = strlen(chars);
        for (int i = 0; i < size; i++) {
            g += chars[i];
        }
        S = string(g);
        str = &S;
    }

    void saveFromFile(string fileName) {
        string file = fileName + ".txt";
        ifstream file1(file);
        getline(file1, S);
        str = &S;
    }

    void saveFromClass(MyClass myClass) {
        S = myClass.S;
        str = &S;
    }

    string getCopyString() {
        string S1 = S;
        return S1;
    }

    void writeToFile(string fileName) {
        string file = fileName + ".txt";
        ofstream file1(file);
        file1 << S;
    }
};
int main()
{
    setlocale(LC_ALL, "ru");
    MyClass myClass = MyClass();
    int z;
    string S;
    char* c = new char[10];
    int i = 0;
    char ch = '/';
    string filename;
    MyClass myclass1;
    while (true) {
        cout << "1)Ввести новую строку\n2)Обнулить строку\n3)Сохранить строку из массива символов\n4)Сохранить строку из файла\n5)Сохранить строку из другого класса\n6)Копия строки\n7)Запись строки в файл\n8)Выход\n";
        cin >> z;
        switch (z)
        {
        case 1:
            cout << "Введите строку\n";
            cin >> S;
            myClass = MyClass(S);
            break;
        case 2:
            myClass = MyClass();
            cout << "Строка обнулена\n";
            break;
        case 3:
            cout << "Введите строку заканчивающей знаком /\n";
            cin >> ch;
            while (ch != '/')
            {
                c[i] = ch;
                cin >> ch;
                i++;
            }
            myClass.saveFromArray(c);
            cout << "Массив введён\n";
            break;
        case 4:
            cout << "Введите название файла\n";
            cin >> filename;
            myClass.saveFromFile(filename);
            break;
        case 5:
            cout << "Введите строку\n";
            cin >> S;
            myclass1 = MyClass(S);
            myClass.saveFromClass(myclass1);
            break;
        case 6:
            cout << myClass.getCopyString() << "\n";
            break;
        case 7:
            cout << "Введите название файла\n";
            cin >> filename;
            myClass.writeToFile(filename);
            break;
        }
        if (z == 8) {
            delete[] c;
            break;
        }
    }

}