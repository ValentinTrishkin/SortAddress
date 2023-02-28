// SortAddress.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Windows.h>

#include <iostream>
#include <fstream>
#include <string>

class Adress
{
public:
    Adress()
    {}
    Adress(std::string city, std::string street, int house, int apartment)
    {
        city_ = city;
        street_ = street;
        house_ = house;
        apartment_ = apartment;
    }

    std::string getOutputAdress() { return city_ + ", " + street_ + ", " + std::to_string(house_) + ", " + std::to_string(apartment_); };
private:
    friend void sort(Adress* adress_, int size);
    std::string city_;
    std::string street_;
    int house_ = 0;
    int apartment_ = 0;
};



void sort(Adress* adress_, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (adress_[j].city_ > adress_[j + 1].city_)
            {
                auto a = adress_[j];
                adress_[j] = adress_[j + 1];
                adress_[j + 1] = a;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    system("chcp 1251");
    std::ifstream fin("in.txt");
    if (!fin.is_open())
    {
        std::cout << "Нет файла.";
    }
    int size = 0;
    fin >> size;
    std::string city;
    std::string street;
    int house = 0;
    int apartment = 0;
    /*Adress adress(city, street, house, apartment);*/
    Adress* adress = new Adress[size];
    for (int i = 0; i < size; i++)
    {
        fin >> city >> street >> house >> apartment;
        adress[i] = { city, street, house, apartment };
    }
    fin.close();
    sort(adress, size);
    std::ofstream fout("out.txt");
    fout << size << std::endl;
    for (int i = 0; i < size; i++)
    {
        fout << adress[i].getOutputAdress() << std::endl;
    }
    delete[] adress;
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
