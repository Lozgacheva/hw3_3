#include <list>
#include <string>
#include "tablehash.h"
#include <iostream>

size_t pow(int a, int power)
{
	if(power == 1)
		return a;
	if (power == 0){
		return 1;
	}
	if (power & 1)
	{
		return pow(a, power - 1) * a;
	}
	return pow(a, power / 2) * pow(a, power / 2);
}

size_t hash(std::string s, int a, int m)
{
	size_t ans = 0;
	int size = s.size();
	for(int i = 0; i < size; i++)
	{
		ans += ((int) s[i] * pow(a, size-1-i)) % m;
	}
	ans %= m;
	return ans;
}

TableHash::TableHash()
{
	items = new std::list<std::string> [size];
}

TableHash::~TableHash()
{
	delete[] items;
}

void TableHash::add(std::string name)
{
	size_t h = hash(name, a, m);
	bool flag = true;
	if(count == size || items[h].size()/size > ratio)//перестраиваем таблицу в два раза больше
	{
		m *= 2;
		size *= 2;
		ratio /= 1.1;
		std::list <std::string>* time_p = items;
		items = new std::list <std::string> [size];
		for(int i = 0; i < size / 2; i++)
		{
			for(std::string val : time_p[i])
			{
				items[hash(val, a, m)].push_back(val);
			}
		}
		delete[] time_p;

	}
	else if(!items[h].empty())//если непустой, то нужно проверить, что такого значения раньше не было
	{
		for(std::string val : items[h])
		{
			if(val == name)
			{
				flag = false;
				break;
			}
		}

	}
	if(flag)//сюда автоматически попадает условие, что цепочка еще пустая
	{
		items[h].push_back(name);
		count += 1;
	}

}

void TableHash::pop(std::string name)
{
	size_t h = hash(name, a, m);
	auto it = items[h].begin();
	bool flag = true;
	for(auto it = items[h].begin(); it != items[h].end(); it++)
	{
		if(*it == name)
		{
			items[h].erase(it);
			count -= 1;
			flag = false;
			break;
		}
	}
	if(flag)
		std::cout << "There's no element " << name << ", nothing to pop." <<  std::endl;

}

int TableHash::get_count()
{
	return count;
}

std::ostream& operator <<(std::ostream& os, TableHash& table)
{
	int c = 0;
	for(int i = 0; i < table.size; i++)
	{
	    for (auto iter = table.items[i].begin(); iter != table.items[i].end(); iter++)
	    {
	        os << *iter;

	        if(c != table.count-1)
	        	os << '\n';
	    	c++;
	    }
	}
    return os;
}