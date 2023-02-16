class TableHash
{
public:
	TableHash();
	~TableHash();
	void add(std::string name);
	void pop(std::string name);
	int get_count();
	friend std::ostream& operator <<(std::ostream& os, TableHash& table);
private:
	int size = 100;
	std::list<std::string>* items;
	int count = 0;
	int a = 9;
	int m = 100;
	int ratio = 0.5;//коэффицииент заполнения
};