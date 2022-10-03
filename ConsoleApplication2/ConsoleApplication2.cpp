// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <windows.h>
#include <cctype>
#include <math.h>

using namespace std;
class fsensor
{
public:
    float get_f()
    {
        
        cout << "enter farenheit";
        float a;
        cin >> a;
        float t = a;
        return t;
    }
};
class sensor
{
public:
    virtual ~sensor() {};
    virtual float get_temp() = 0;
};
class Adapter : public sensor
{
    fsensor* p_fsensor;
public:
    Adapter(fsensor * p):p_fsensor(p){}
    ~Adapter() { delete p_fsensor; }
    float get_temp()
    {
        
        return(p_fsensor->get_f() -32.0) * 5.0 / 9.0;
    }
};///
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    sensor* p = new Adapter(new fsensor);
    cout << p->get_temp();
    delete p;
   

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
