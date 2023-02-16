#include <iostream>
#include <string>
#include <list>
#include "tablehash.h"


int main()
{
    TableHash set;
    int n;
    std::cin >> n;
    std::cin.ignore();
    for(int i = 0; i < n; i++)
        {
            std::string str;
            getline(std::cin,str);
            set.add(str);
        }
    std::cout << std::endl;
    std::cout << set << std::endl;
	return 0;
}


// 9
// вышивание крестиком
// рисование мелками на асфальте
// игры в крестики нолики
// игры в крестики нолики
// приготовление пирожков
// шахматы
// си плюс плюс
// таракановедение
// таракановедение

