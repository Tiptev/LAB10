#include <iostream>
#include <vector> //нужен для создания вектора
#include <fstream> //нужен для логирования
#include <stdlib.h> // нужен для вызова функций rand(), srand()
#include <locale.h>
#include <time.h> // нужен для вызова функции time()

using namespace std;

int main()
{
    vector <int> number;//вектор бочонков
    int N;//кол-во бочноков
    int addit;//вспомогательная переменная
    bool check;//переменная для проверки
    setlocale(LC_CTYPE, "rus");
    ofstream file;//подключения файла log_LAB10.txt
    file.open("C:\\Users\\acer\\OneDrive\\Рабочий стол\\LAB10\\log_LAB10.txt", ios::app);
    cout << "Введите количество бочонков. N = ";
    cin >> N;
    if (file.is_open() == true)
        file << endl << "Программа запущена:" << endl << "    Кол-во бочонков. N =" << N << endl;
    else
        cout << "Файл не открыт";
    number.resize(N);//динамический масссив длинны N 
    srand(time(NULL));//для рандомайзера не знаю для чего она нужна 
    for (int i = 0; i < N; i++)//присвавает каждому бонченку номер
    {
        do
        {
            check = 0;
            addit = (1 + rand() % (N));//рандомайзер от 1 до N
            for (int j = 0; j < N; j++)
            {
                if (addit == number[j])//если бонченок с таким номером уже есть, то переменная присваивает значение 1
                    check = 1;
            }
            if (check == false)
            {
                number[i] = addit;//если номер бонченка не использовался, то элемент вектора присваивает значение себе
                cout << "   Бочонок №" << i + 1 << " - " << number[i] << endl;
            }
        } while (check == true);//если номер бончока уже использовался, то цикл вайл повторяется, пока не найдется не занятый номер броченка
        if (file.is_open() == true)
            file << "       Бочонок №" << i + 1 << " - " << number[i] << ";" << endl;
    }
    cout << endl << "Выходные данные: ";
    if (file.is_open() == true)
        file << endl << "Выходные данные: ";
    for (int f = 0; f < N; f++)//выводит все номера бочков подряд в строку.
    {
        cout << number[f] << ", ";
        if (file.is_open() == true)
            file << number[f] << ", ";
    }
    if (file.is_open() == true)
        file << endl << "Программа завершена." << endl;
    file.close();
    return 0;
}

