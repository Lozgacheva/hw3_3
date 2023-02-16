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


std::string make_string(size_t n)
{
	std::string h = std::to_string(n);     	
	for(int i = h.size(); i >= 0; i -= 3)
	{
		if(i - 3 > 0)
		{
			char sb[] = {(char)(stoi(h.substr(i-3, 3)))};
			h.replace(i - 3, 3, sb);
		}
		else
		{
			char sb[] = {(char)(stoi(h.substr(0, i)))};
			h.replace(0, i, sb);
			break;
		}
	}
	return h;
}


std::string collision(std::string s1, int a, int m)
{
	size_t h = 0;
	for(int i = 0; i < s1.size(); i++)
	{
		h += ((int) s1[i] * pow(a, s1.size()-1-i));
	}
	size_t ans = h % m;
	while(true)
	{
		h += m;
		size_t buf = h;
		while (buf!=0)
		{
			if (((buf % 1000) < 127) && ((buf % 1000) > 31)) buf /= 1000;
			else break;
		}
		if (buf == 0) 
		{
			return make_string(h);
		}
	}
}



int main()
{
	int a = 1000;
	int m = 123987123;
	std::cout << collision("ead", a, m) << std::endl;//коллизия
	std::cout << hash("ead", a, m) << std::endl;
	std::cout << hash("}PuT", a, m) << std::endl;
	return 0;
}